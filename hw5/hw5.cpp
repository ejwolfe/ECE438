#include <cmath>
#include <iostream>

using namespace std;

int main(){
    int a, b, c, d, result;
    while(a != -1){
        cin >> a;
        cin >> b;
        cin >> c;
        cin >> d;

        result = abs(a - b) + abs(c - d);
        cout << result << endl;
    }
    return 0;
}
