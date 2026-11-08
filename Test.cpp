// #include "file_open/file_open.h"
#include "changeoutputcolor/changeoutputcolor.h"
#include "random_randint/random_randint.h"
#include <iostream>
#include <stdexcept>
#include <conio.h>
using namespace std;

void changeOutputColor_TEST() {
    int flag=false;
    {
        string colorname;
        cin>>colorname;
        try {
            changeOutputColor(colorname);
            cout<<"TEST"<<endl;
            changeOutputColor(7);
        } catch (const exception& e) {
            changeOutputColor(7);
            cout<<"Error: "<<e.what()<<endl;
            flag=true;
        };
        colorname = nullptr;
    };
    if (flag) cout<<"Test failed."<<endl; else cout<<"Test passed."<<endl;
};

int main() {
    string select_index;
    cout<<"Select to test:"<<endl;
    cin>>select_index;
    if (select_index=="changeOutputColor") {
        changeOutputColor_TEST();
    } else {
        cout<<"Error: No such test."<<endl;
    };
    return 0;
};
