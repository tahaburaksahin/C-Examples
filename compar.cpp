#include <iostream>
#include <cmath>      // sqrt
#include <vector>
#include <algorithm>  // sort, copy
#include <iterator>
using namespace std;

struct Comp {
   enum Methods {
       by_sum_of_digits,
       by_num_of_divisors,
       by_value_asc,
       by_value_desc
   };

   Comp(Methods method): method(method) { }

   bool operator()(int n1, int n2);

   class NoComparator { };

private:
   Methods method;

   static int sum_of_digits(int n);
   static int numb_divs(int n);
};

bool Comp::operator()(int n1, int n2) {
   switch (method) {
       case by_sum_of_digits:
           return sum_of_digits(n1) < sum_of_digits(n2);
       case by_num_of_divisors:
           return numb_divs(n1) < numb_divs(n2);
       case by_value_asc:
           return n1 < n2;
       case by_value_desc:
           return n2 < n1;
       default:
           throw NoComparator();
                        // should never happen
   }
}

int Comp::sum_of_digits(int n) {
   // sum of digits of an integral number
   // (all taken with plus sign)
   n = n >= 0 ? n : -n;
   int s = 0;
   while (n) { s += n%10; n /= 10; }
   return s;
}

int Comp::numb_divs(int n) {
   // number of positive divisors of an integral
   // number (including 1 and the number itself)
   n = n > 0 ? n : -n;
   if ( n < 3 ) return n;
   int sr = (int) sqrt(n+0.5);
   int cnt = sr*sr == n ? 1 : 2;
   for (int i = 2; i <= sr; ++i) if (n%i == 0) cnt += 2;
   return cnt;
}

int main() {
   int tab[] = {7, 4, 8, 12, 13, 119, 16, 6};
   vector<int> v(tab,tab+sizeof(tab)/sizeof(int));
   v.push_back(64);

    // sorting with different methods and displaying results

   cout <<   "Sorting by sum of digits\n";
   sort(v.begin(),v.end(),Comp(Comp::by_sum_of_digits));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

   cout << "\nSorting by number of divisors\n";
   sort(v.begin(),v.end(),Comp(Comp::by_num_of_divisors));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));


   cout << "\nSorting by value in asc. order\n";
   sort(v.begin(),v.end(),Comp(Comp::by_value_asc));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

   cout << "\nSorting by value in desc. order\n";
   sort(v.begin(),v.end(),Comp(Comp::by_value_desc));
   copy(v.begin(),v.end(),ostream_iterator<int>(cout," "));

   cout << endl;
}
