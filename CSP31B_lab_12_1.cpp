#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
    double values[] = {2.4, 1.3, 2.4, 4.5, 6.7, 4.5, 9.0};
    vector<double> doubleVector(values, values + 7);
    ostream_iterator<double> output(cout, " ");
    cout << "values: ";
    copy(values, values + 7, output);
    cout << "\ndoubleVector: ";
    copy(doubleVector.begin(), doubleVector.end(), output);
    double key;
    cout << "\nEnter a key: ";
    cin >> key;
    cout << "Find: " << key << " in values ";
    // Use find to find position of 4.5
    double *p1 = find(values, values + 8, key); // Find key in values
    if (p1 != values + 8)
        cout << "\nfound at position " << (p1 - values + 1);
    else
        cout << "\nnot found";
    // Use find_if to find position of first element less than 2
    auto itr = find_if(doubleVector.begin(), doubleVector.end(), [](double x)
                       { return (x < 2); });
    if (itr != doubleVector.end())
        cout << "\nPosition of first element less than 2: " << (itr - doubleVector.begin() + 1);
    else
        cout << "\nNo element less than 2 found";
    // Use find_end to find sequence positon {2.4, 4.5}
    vector<double> sequence = {2.4, 4.5};
    auto itr_end = find_end(doubleVector.begin(), doubleVector.end(),
                            sequence.begin(), sequence.end());
    if (itr_end != doubleVector.end())
        cout << "\nPosition of sequence { 2.4, 4.5 }: " << (itr - doubleVector.begin() + 1);
    else
        cout << "\nsequence { 2.4, 4.5 } not found";
    // Use find_first_of to find the position of the first common element
    vector<double> list = {34, 55, 2.4, 4.5};
    auto itr_first_of = find_first_of(doubleVector.begin(), doubleVector.end(), list.begin(), list.end());
    if (itr_first_of != doubleVector.end())
        cout << "\nPosition of first common element: " << (itr_first_of - doubleVector.begin() + 1);
    else

        cout << "\nNo common element found";

    return 0;
}