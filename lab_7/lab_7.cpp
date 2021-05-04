#include <iostream>
#include <cmath>
using namespace std;
#define RIGHT_BORDER 100



class CountingCh{
    private:
	double x;
	static int border;
    public:		
		void set_x()
		{
			bool DataIsNotNumber = true;
			while (DataIsNotNumber) {
				cout << "Enter the function argument: ";
				cin >> this->x;

				if (cin.fail()) {
					cout << "Entered is not a number.\n";
					cin.clear();
					std::cin.ignore(32767, '\n');
				} else {
					DataIsNotNumber = false;
				}
			}
		}

		static void set_border()
		{
			bool DataIsNotNumber = true;
			while (DataIsNotNumber) {
				cout << "Enter the calculation boundary\n ";
				const int left_border = 0;
				const int right_border = RIGHT_BORDER;
				cout << "Enter a border less than " << right_border << " greater than " << left_border << endl;
				cin >> border;

				if (cin.fail()) {
					cout << "Entered is not a number.\n";
					cin.clear();
					std::cin.ignore(32767, '\n');
				}
				else {
					if ((border > left_border) && (border < right_border)) {
						DataIsNotNumber = false;
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

		void calculates_ch() {
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
	obj.set_x();
	CountingCh::set_border();
	obj.calculates_ch();
}
