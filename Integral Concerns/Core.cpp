#include <functional>
#include <iostream>
using namespace std;

double integrate(function<double(double)> f, double a, double b, int precision)
{
	//Variable setup
	double area = 0;
	double dx = (b - a) / precision;
	double x;

	for (int i = 0; i < precision; i++)
	{
		x = a + (i * dx);
		area += f(x) * dx;
	}

	return area;
}

int main()
{
	cout << "Testing integrate..." << endl;
	//All Tests will utilize 100 precision, variable name used in code for possible non-100 context if ever tested in future.
	double result;

	cout << "Test 1: Linear Function 1" << endl;
	cout << "Function: f(x) = x" << endl;
	cout << "Range: 0 - 4" << endl;
	result = integrate([](double x) {return x;}, 0.0, 4.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 1 Complete." << endl;

	cout << "\nTest 2: Linear Function 2" << endl;
	cout << "Function: f(x) = (3/2)x" << endl;
	cout << "Range: 1 - 7" << endl;
	result = integrate([](double x) {return (3.0 / 2.0) * x;}, 1.0, 7.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 2 Complete." << endl;

	cout << "\nTest 3: Constant Function 1" << endl;
	cout << "Function: f(x) = 4" << endl;
	cout << "Range: 2 - 3" << endl;
	result = integrate([](double x) {return 4;}, 2.0, 3.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 3 Complete." << endl;

	cout << "\nTest 4: Constant Function 2" << endl;
	cout << "Function: f(x) = 9" << endl;
	cout << "Range: 1 - 5" << endl;
	result = integrate([](double x) {return 9;}, 1.0, 5.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 4 Complete." << endl;

	cout << "\nTest 5: Polynomial Function 1" << endl;
	cout << "Function: f(x) = 2x + 7" << endl;
	cout << "Range: 2 - 4" << endl;
	result = integrate([](double x) {return (2 * x) + 7;}, 2.0, 4.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 5 Complete." << endl;

	cout << "\nTest 6: Polynomial Function 2" << endl;
	cout << "Function: f(x) = 4x - 4" << endl;
	cout << "Range: 1 - 6" << endl;
	result = integrate([](double x) {return (4 * x) - 4;}, 1.0, 6.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 6 Complete." << endl;

	cout << "\nTest 7: Polynomial Function 3" << endl;
	cout << "Function: f(x) = x^2 + 3x - 8" << endl;
	cout << "Range: 0 - 10" << endl;
	result = integrate([](double x) {return (x * x) + (3 * x) - 8;}, 0.0, 10.0, 100);
	cout << "Result: " << result << endl;
	cout << "Test 7 Complete." << endl;

	cout << "\nAll 'integrate' Tests Complete!" << endl;
}