#include<bits/stdc++.h>
#include <stdio.h>
using namespace std;



int main() {
    string temp;
    int sol = 0;
    while (cin >> temp) {
        if (string::npos != temp.find("time=")) {
             sscanf(temp.c_str(), "time=%d", &sol);
             cout << sol << endl;
         }
    }
}