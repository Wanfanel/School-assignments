import java.util.Random;

public class Osobnik {

	public static double a;
	public static double b;
	static Random generator;

	static {
		a = 2;
		b = 5;
		generator = new Random();
	}

	/// <0,31>
	private int genotyp = generator.nextInt(31); // "zasiêg od 0 do 31"

	public double fenotyp() {
		/// y=ax^2+bx
		return Math.pow(a * genotyp, 2) + (b * genotyp);

	}

	public int getGenotyp() {
		return genotyp;
	}

	public void setGenotyp(int gen) {
		genotyp = gen;
	}

	public String binary_genotyp() {

		String binary_gen = "";

		for (int i = 4; i >= 0; i = i - 1) {
			if (bitCheck(genotyp, i))
				binary_gen += "1";
			else
				binary_gen += "0";
		}

		return binary_gen;
	}

	public void Krzy¿owanie(Osobnik osobnik) {
		int obszar = generator.nextInt(29) + 1;
		int rodzic_01 = this.getGenotyp();
		int rodzic_02 = osobnik.getGenotyp();
		obszar = obszar & (rodzic_01 ^ rodzic_02);
		this.setGenotyp((~(rodzic_01 & obszar) & obszar) + (rodzic_01 & (~obszar & 31)));
		osobnik.setGenotyp((~(rodzic_02 & obszar) & obszar) + (rodzic_02 & (~obszar & 31)));
	}

	public void Mutacja() {
		int index = generator.nextInt(4);
		index = 1 << index;
		genotyp = (~(genotyp & index) & index) + (genotyp & (~index & 31));
	}

	public Boolean bitCheck(int object, int index) {

		int i = 1 << index;
		if ((object & i) == i)
			return true;

		return false;
	}

}
