#include <iostream>
#include <cmath>
using namespace std;
#define RIGHT_BORDER 100



class CountingCh{
    private:
    double x;
	static int border;
    public:

		double scan_double_number()
		{
			while (true) {
				cout << "Enter the function argument: ";
				double x = 0;
				cin >> x;

				if (cin.fail()) {
					cout << "Entered is not a number.\n";
					cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else {
					return x;
				}
			}
		}

		int scan_number_in_range(const int left_border, const int right_border)
		{
			while (true) {
				cout << "Enter the calculation boundary\n ";
				cout << "Enter a border less than " << right_border << " greater than " << left_border << endl;
				int border = 0;
				cin >> border;

				if (cin.fail()) {
					cout << "Entered is not a number.\n";
					cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else {
					if ((border > left_border) && (border < right_border)) {
						return border;
					}
					else {
						if (border <= left_border) {
							cout << "The entered number is less " << left_border << endl;
							cin.clear();
						}
						if (border >= right_border) {
							cout << "The entered number is greater than or equal to " << right_border << endl;
							cin.clear();
						}
					}
				}
			}
		}

		void calculates_ch(int border) {
			double ch = 0;
			for (int index = 0; index <= border; index++) {
				ch = (pow(x, index * 2) / calculates_factorial(index * 2)) + ch;
			}
			cout << "The value of the hyperbolic cosine is " << ch;
		}
		
		int calculates_factorial(const double number) {
			int factorial = 1, index;
			for (index = 1; index <= number; index++) {
				factorial = index * factorial;
			}
			return factorial;
		}
};

int CountingCh::border;

int main()
{
	CountingCh obj;
	obj.scan_double_number();
	obj.calculates_ch(obj.scan_number_in_range(0, RIGHT_BORDER));
}
