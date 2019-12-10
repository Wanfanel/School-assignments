import java.util.Random;
import java.util.Scanner;

public class Algorytm {

	static Random generator = new Random();
	/// pk=0,75 = 75%
	static int pk = 75;
	static /// pm=0,15 = 15%
	int pm = 15;

	static double highest_negative_value = 0;
	static int best_genotyp;
	static String best_bin_genotyp;
	static double best_fenotyp = 0;

	public static Osobnik[] osobnik;

	static {
		osobnik = new Osobnik[6];
		for (int i = 0; i < 6; i++)
			osobnik[i] = new Osobnik();

	}

	public static void main(String[] args) {

		boolean exit = false;
		int iteration = 1000;
		int powtórzeñ = 10;
		Scanner odczyt = new Scanner(System.in);

		System.out.println("PROGRAM");
		while (!exit) {
			System.out.println("[a]=" + Osobnik.a + ", [b]=" + Osobnik.b + ", [limit iteracji]=" + iteration
					+ ", [limit powtórzeñ]=" + powtórzeñ);
			System.out.println(
					"1.Ustaw[a], 2.Ustaw[b], 3.Ustaw[limit iteracji] 4.Ustaw[limit powtórzeñ], 5.START!, 0.EXIT.");
			switch (odczyt.nextInt()) {
			case 0:
				exit = true;
				break;
			case 1:
				System.out.println("podaj nowe [a]:");
				Osobnik.a = odczyt.nextDouble();
				break;
			case 2:
				System.out.println("podaj nowe [b]:");
				Osobnik.b = odczyt.nextDouble();
				break;
			case 3:
				System.out.println("podaj nowy limit:");
				iteration = odczyt.nextInt();
				break;
			case 4:
				System.out.println("podaj nowy limit:");
				powtórzeñ = odczyt.nextInt();
				break;
			case 5:
				int j = 0;
				best_fenotyp = 0f;
				double old_best_fenotyp = 0f;
				for (int i = 0; i < iteration; i++) {
					if (best_fenotyp == old_best_fenotyp) {
						j++;
						if (j >= powtórzeñ) {
							System.out.println("Iteracja:[" + i + "] KONIEC\n\n");
							i = iteration;
						}
					} else {
						old_best_fenotyp = best_fenotyp;
						j = 0;
						System.out.println("Iteracja:[" + i + "]:");
						print_best();
					}
					Krzy¿owanie();
					Mutacja();
					Selekcja();

				}
				break;
			}

		}
		odczyt.close();

		/*
		 * //testy operatorów bitowych ===> for (int i = 1; i < 32; i = i << 1)
		 * { System.out.println(i + ","); } int a = 6; int b = 5; int c = 3;
		 * 
		 * c = c&(a^b); System.out.println((~(a&c)&c) + (a&(~c&7)));
		 * System.out.println((~(b&c)&c) + (b&(~c&7)));
		 * System.out.println("testy"); System.out.println(~(a&c)&c);
		 * System.out.println(c); System.out.println(a&(~c&7));
		 */

	}

	public static void Krzy¿owanie() {
		for (int i = 0; i < 6; i = i + 2) {
			if (generator.nextInt(100) < pk) {
				osobnik[i].Krzy¿owanie(osobnik[i + 1]);
			}
		}
	}

	public static void Mutacja() {
		for (int i = 0; i < 6; i = i + 1) {
			if (generator.nextInt(100) < pm) {
				osobnik[i].Mutacja();
			}
		}
	}

	public static void Selekcja() {
		double[] szansa_osobnika = new double[6];
		int[] buffor_genotyp = new int[6];
		double omega_przystosowania = 0;
		for (int i = 0; i < 6; i++) {
			if (osobnik[i].fenotyp() > best_fenotyp) {
				best_fenotyp = osobnik[i].fenotyp();
				best_genotyp = osobnik[i].getGenotyp();
				best_bin_genotyp = osobnik[i].binary_genotyp();
			}
			if (highest_negative_value > osobnik[i].fenotyp()) {
				highest_negative_value = osobnik[i].fenotyp();
			}
		}
		for (int i = 0; i < 6; i++) {
			omega_przystosowania += osobnik[i].fenotyp() + 1.0 - highest_negative_value;
		}
		szansa_osobnika[0] = (osobnik[0].fenotyp() + 1.0 - highest_negative_value) / omega_przystosowania;
		for (int i = 1; i < 6; i++) {
			szansa_osobnika[i] = ((osobnik[i].fenotyp() + 1.0 - highest_negative_value) / omega_przystosowania)
					+ szansa_osobnika[i - 1];
		}
		for (int i = 0; i < 6; i++) {
			double los = generator.nextDouble();
			int j = 0;

			while ((double) los > (double) szansa_osobnika[j]) {
				j++;

			}
			// System.out.println("los osobnik[" + i + "]" + j + "]");
			buffor_genotyp[i] = osobnik[j].getGenotyp();

		}
		for (int i = 0; i < 6; i++) {
			osobnik[i].setGenotyp(buffor_genotyp[i]);
		}

	}

	static void print_all() {
		for (int i = 0; i < 6; i++) {
			System.out.println("Osobnik[" + i + "]");
			System.out.println("Genotyp(DEC):" + osobnik[i].getGenotyp() + ",(BIN):" + osobnik[i].binary_genotyp()
					+ ", Fenotyp:" + osobnik[i].fenotyp() + ",\n");

		}
	}

	static void print_best() {
		System.out.println("Najlepsze rozwiazanie:");
		System.out.println(
				"Genotyp(DEC):" + best_genotyp + ",(BIN):" + best_bin_genotyp + ", Fenotyp:" + best_fenotyp + ",\n");

	}
}