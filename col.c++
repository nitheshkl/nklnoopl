// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2015
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream
#include <sstream>  // istringstream
#include <string>   // getline, string
#include <utility>  // make_pair, pair

#include "Collatz.h"

using namespace std;

// ------------
// collatz_read
// ------------

pair<int, int> collatz_read (const string& s) {
    istringstream sin(s);
    int i;
    int j;
    sin >> i >> j;
    return make_pair(i, j);}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    // <your code>
    if(i == j){
       int c = 1;
        while (i>1){
            if ((i % 2) == 0)
                i = (i / 2);
            else
                i = (3 * i) + 1;
            ++c;
	}
        return c;
    }
    else{
    int range = j-i+1;
    int k =i;
    int max = 0;
    //assert (range > 0);
    while (range > 0){
        int c = 1;
        while (k>1){
            if ((k % 2) == 0)
                k = (k / 2);
            else
                k = (3 * k) + 1;
            ++c;
	}
        if (c > max)
            max=c;
        --range;
        k = ++i; 
    } 
    return (max);}}

// -------------
// collatz_print
// -------------

void collatz_print (ostream& w, int i, int j, int v) {
    w << i << " " << j << " " << v << endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (istream& r, ostream& w) {
    string s;
    while (getline(r, s)) {
        const pair<int, int> p = collatz_read(s);
        const int            i = p.first;
        const int            j = p.second;
        const int            v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}



int main () {
    using namespace std;
    collatz_solve(cin, cout);
    return 0;}



