#include <iostream>
using namespace std;

int main(){

    bool male = false;
    if (male) {
        cout << "This is a boy." << endl;
    } else {
        cout << "This is a girl." << endl;
    }

    bool is_playing = true;
    cout << "Playing = " << is_playing << endl;
    cout << "Playing invert = " << !is_playing << endl;

    cout << "1 and True = " << (1 && true) << endl;
    cout << "True and True = " << (true && true) << endl;
    cout << "True and False = " << (true && false) << endl;
    cout << "True or True = " << (true || true) << endl;
    cout << "True or False = " << (true || false) << endl;

    return 0;
}
