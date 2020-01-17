#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
   ifstream stream;

   vector<double> arr;

   stream.open("./inp3.txt", ifstream::in);
   if (!stream.is_open()) {
       perror("Cannot open file!");
   }
   string buffer;
   while (getline(stream, buffer)) {
       arr.push_back(atof(buffer.c_str()));
   }

   double mean = std::accumulate(arr.begin(), arr.end(), 0) / arr.size();

   double diff_sum = 0;
   
   // sum(x - x^)**2
   for_each(arr.begin(), arr.end(), [mean, diff_sum](double &value) mutable {
       diff_sum += (value - mean) * (value - mean);
   });

   double std_deviation = sqrt(diff_sum / arr.size());

   cout << "Standard deviation = " << std_deviation << endl;

   stream.close();
}