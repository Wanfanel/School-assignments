using System;

namespace ConsoleApp1
{
    class Program
    {
        public static int a = 9;
        public static int b = 2;
        public static int Pm = 20; // od 0 do 100% szansa na mutacje;
        public static int Pk = 85; // od 0 do 100% szansa na krzyżowanie;
        public static Random rnd = new Random();
        public static int best_score = 0;
        public static int POPULACJA = 6;


        static void CheckScore(int[] osobnik)
        {
            for (int i = 0; i < POPULACJA; i++)
            {
                if (best_score < Funkcja(osobnik[i]))
                {
                    best_score = Funkcja(osobnik[i]);
                    Print(osobnik[i], i, " Osiagnał najlepszy Wynik " + best_score + " ! ! !\n");
                }

            }
        }
        static void Evaluation(int[] osobnik)
        {
            int omega = 0;
            int draw;
            int[] buffer = new int[POPULACJA];
            for (int i = 0; i < POPULACJA; i++)
            {
                omega += Funkcja(osobnik[i]);
            }
            for (int i = 0; i < POPULACJA; i++)
            {
                draw = rnd.Next(1, omega);

                int j = 0;
                int evaluation_score = 0;
                while (evaluation_score <= draw)
                {
                    evaluation_score += Funkcja(osobnik[j]);
                    j++;

                }

                buffer[i] = osobnik[j - 1];
            }
            for (int i = 0; i < POPULACJA; i++)
            {
                osobnik[i] = buffer[i];
            }
        }
        static void Crossover(int[] osobnik)
        {
            for (int i = 0; i < POPULACJA; i += 2)
            {
                if (rnd.Next(1, 100) <= Pk)
                {
                    Print(osobnik[i], i, " ORAZ");
                    Print(osobnik[i + 1], i + 1, " KRZYZUJA się na");

                    int crossover = rnd.Next(1, 30); // miejsca wymiany genów
                    int child_one = 0, child_two = 0;

                    for (int j = 1; j < 32; j = j << 1)
                    {

                        if ((crossover & j) == 0)
                        {
                            child_one += osobnik[i] & j;
                            child_two += osobnik[i + 1] & j;

                        }
                        else
                        {

                            child_one += osobnik[i + 1] & j;
                            child_two += osobnik[i] & j;
                        }

                    }
                    osobnik[i] = child_one;
                    osobnik[i + 1] = child_two;


                    Print(osobnik[i], i, " Child one,");
                    Print(osobnik[i + 1], i + 1, " Child two, \n");

                }

            }

        }
        static void Mutation(int[] osobnik)
        {
            for (int i = 0; i < POPULACJA; i++)
            {
                if (rnd.Next(1, 100) <= Pm)
                {
                    int losowygen = 1 << rnd.Next(0, 4);
                    Print(osobnik[i], i, " MUTUJE na");
                    if ((osobnik[i] & losowygen) == 0)
                    {
                        osobnik[i] += losowygen;
                    }
                    else
                    {
                        osobnik[i] -= losowygen;
                    }
                    Print(osobnik[i], i, "\n");


                }

            }

        }
        static int Funkcja(int x)
        {
            return a * x * x + b;
        }
        static string IntToBinaryString31(int osobnik)
        {
            string buffor = "";
            for (int i = 1; i < 32; i = i << 1)
            {
                if ((osobnik & i) == 0)
                {
                    buffor = "0" + buffor;
                }
                else
                {
                    buffor = "1" + buffor;
                }
            }
            return buffor;
        }

        static void Print(int[] osobnik)
        {
            for (int i = 0; i < POPULACJA; i++)
            {
                Print(osobnik[i], i, " Wynik przystosowania = " + Funkcja(osobnik[i]));
            }
        }
        static void Print(int osobnik, int num = -1, string txt = "")
        {
            Console.WriteLine("Osobnik=[" + num + "] " + osobnik + " Binarnie[" + IntToBinaryString31(osobnik) + "]" + txt);
        }

        // MAIN
        static void Main(string[] args)
        {

            int[] osobnik;
            osobnik = new int[POPULACJA];

            Console.WriteLine("<< 1.Losowanie poczatkowej populacji " + POPULACJA + " osobników >>");
            for (int i = 0; i < POPULACJA; i++)
            {
                osobnik[i] = rnd.Next(0, 31);
            }
            Console.WriteLine("<< Populacja: >>");
            Print(osobnik);
            Console.WriteLine("\n<< 2.Obliczanie Funkcji przystosowania >>");
            CheckScore(osobnik);
            Console.WriteLine("<< 3.Selekcja kołem ruletki >>");
            Evaluation(osobnik);
            Console.WriteLine("<< Wyniki koła ruletki: >>");
            Print(osobnik);
            Console.WriteLine("\n<< 4a.Krzyżowanie >>");
            Crossover(osobnik);
            Console.WriteLine("<< 4b.Mutacja >>");
            Mutation(osobnik);
            Console.WriteLine("<< 5a.Nowa Populacja: >>");
            Print(osobnik);
            Console.WriteLine("\n<< 5b.Funjcja przystosowania nowej populacji >>");
            CheckScore(osobnik);




            Console.WriteLine("Press any Key to finish!");
            Console.ReadKey();

        }


    }


}
