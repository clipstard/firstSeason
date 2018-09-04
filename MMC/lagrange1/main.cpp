#include <iostream>
#include <iomanip>
#include <conio.h>
#include <math.h>
enum { num = 3 };
using namespace std;
double PolinomLagrange(double A1[], double A2[], double z)
{
	double p = 0, s;
	for (int i = 0; i<num; i++)
	{
		s = 1;
		for (int j = 0; j<num; j++)
		if (j != i)s *= (z - A1[j]) / (A1[i] - A1[j]);
		p += A2[i] * s;
	};
	return p;
};

double AproximLagrange(double X[], double Y[], double x, double &e)
{
	double L[num - 1][num - 1], min;
	for (int i = 0; i<num - 1; i++)
		L[i][0] = (Y[i] * (X[i + 1] - x) - Y[i + 1] * (X[i] - x)) / (X[i + 1] - X[i]);
	for (int k = 1; k<num - 1; k++)
	for (int i = k; i<num - 1; i++)
		L[i][k] = (L[i - 1][k - 1] * (X[i + 1] - x) - L[i][k - 1] * (X[i - 1] - x)) / (X[i + 1] - X[i - 1]);
	for (int i = 0; i<num - 1; i++, cout << endl)
	for (int k = 0; k <= i; k++)
		cout << setw(11) << L[i][k] << " ";
	min = fabs(L[1][1] - L[0][0]);
	for (int i = 1; i<num - 1; i++)
	{
		if (fabs(L[i][i] - L[i - 1][i - 1])<e) return L[i][i];
		if (fabs(L[i][i] - L[i - 1][i - 1])<min)min = fabs(L[i][i] - L[i - 1][i - 1]);
	}
	e = min;
	return L[num - 2][num - 2];
};

int main(void)
{
	double X[num], Y[num], xi, eps;
	int i;
	cout << "Introduceti punctele in care se cerceteaza functia(x):\n";
	for (i = 0; i<num; i++)
		cin >> X[i];
	cout << "\nIntroduceti valorile functiei in aceste puncte(y):\n";
	for (i = 0; i<num; i++)
		cin >> Y[i];
	cout << "\nIntroduceti xi: ";
	cin >> xi;
	cout << "\nIntroduceti eroarea: ";
	cin >> eps;
	cout << "\nPolinomul Lagrange:\n\n\tValoarea functiei f(x) in punctul " << xi << " este "
		<< PolinomLagrange(X, Y, xi) << endl << endl;
	cout << "\nAproximarea Lagrange:\n\n\tValoarea functiei f(x) in punctul " << xi
		<< " calculata cu eroarea " << eps << "\neste "
		<< AproximLagrange(X, Y, xi, eps);
	getch();
};
