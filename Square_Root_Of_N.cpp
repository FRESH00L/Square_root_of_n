#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double oblY(double n, double x, double Y_biez, double Y_pop)
{
	Y_biez = (1 / n) * ((n - 1) * Y_pop + (x / pow(Y_pop, n - 1)));
	cerr << "Y poprzednie = " << Y_pop << " Y bieżące = " << Y_biez << endl;
	return Y_biez;
}

double oblPierw(double n, double x, bool& error, double roznica)
{
	double Y_biezacej = 0;
	int licznik = 1;
	bool powtarzaj = true;
	double Y_poprzedniej;

	Y_poprzedniej = x;

	if (n <= 0 || x <= 0.0)
	{
		error = true;
		return 0;
	}

	while (powtarzaj == true)
	{
		Y_biezacej = oblY(n, x, Y_biezacej, Y_poprzedniej);
		cerr << "Przybliżona wartość pierwiastka dla iteracji nr " << licznik << " = " << Y_biezacej << endl;
		licznik++;
		if (abs(Y_biezacej - Y_poprzedniej) <= roznica)
		{
			return Y_biezacej;
		}
		Y_poprzedniej = Y_biezacej;
	}
}


int main()
{
	setlocale(LC_ALL, "");

	int n;
	double x;
	double wynik;
	bool error = false;
	double bladObl;
	double roznica = 0.01;

	cout << "Podaj wartość x która jest liczbą rzeczywistą dodatnią" << endl;
	cin >> x;
	cout << "Podaj wartość n która jest liczbą naturalną" << endl;
	cin >> n;



	wynik = oblPierw(n, x, error, roznica);

	if (error == true)
	{
		cout << "Podano niepoprawne wartości dla zmiennych n i/lub x" << endl;
		return 1;
	}

	bladObl = wynik - pow(x, (1.0 / n));

	cout << fixed << "\nPrzybliżona wartość y jest równa " << wynik << ". Różni się ona od wartości pierwiastka z funkcji bibliotecznej o " << bladObl << endl;
}
