/*
Create an array with these numbers: 2.4, 1.3, 2.4, 4.5, 6.7,
4.5, 9.0
Use the find function to find the position of 4.5 in the array.
Use the find_if function to find the position of the first element that
is less than 2.
Use the find_end function to find the sequence position {2.4, 4.5} in
the array.
Use the find_first_of function to find the position of the first
common element in the array and a list with these values
{34,55,2.4,4.5}
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main() {
    // Initialize the array and vector
    double values[] = {2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0};
    vector<double> doubleVector(values, values + 7);

    // Output the values array and doubleVector
    ostream_iterator<double> output(cout, " ");
    cout << "values: ";
    copy(values, values + 7, output);
    cout << "\ndoubleVector: ";
    copy(doubleVector.begin(), doubleVector.end(), output);

    // Use the find function to find the position of 4.5 in the array.
    auto p1 = find(values, values + 7, 4.5);
    if (p1 != values + 7) {
        cout << "\nFound 4.5 at position " << (p1 - values + 1);
    } else {
        cout << "\nNot found";
    }

    // Find the position of the first element less than 2
    auto itr = find_if(doubleVector.begin(), doubleVector.end(), [](double x) {
        return x < 2;
    });
    if (itr != doubleVector.end()) {
        cout << "\nPosition of first element less than 2: " << (itr - doubleVector.begin() + 1);
    } else {
        cout << "\nNo element less than 2 found";
    }

    // Find the position of the first common element in a list
    vector<double> list = {34, 55, 2.4, 4.5};
    auto itr_first_of = find_first_of(doubleVector.begin(), doubleVector.end(), list.begin(), list.end());
    if (itr_first_of != doubleVector.end()) {
        cout << "\nPosition of first common element: " << (itr_first_of - doubleVector.begin() + 1);
    } else {
        cout << "\nNo common element found";
    }

    return 0;
}