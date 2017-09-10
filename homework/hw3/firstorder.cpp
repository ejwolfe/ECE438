#include <math.h>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {

  double x, y;

  while (x != -1){

    cout << "Please enter two numbers or enter -1 to stop" << endl;
    cout << "Number 1: ";
    cin >> x;
    cout << "Number 2: ";
    cin >> y;

    double result1 = ((x - y)/3.0) + y;
    double result2 = (((x - y)/3.0)*2.0) + y;
    cout << "Result 1 = " << result1 << endl << "Result 2 = " << result2 << endl;;
  }

  return 0;
}
