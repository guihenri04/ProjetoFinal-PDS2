#include <iostream>

using namespace std;

int main(){
  float celsius;
  cout << "Enter temperature in Celsius\n"; // inputting the temperature
  cin >> celsius;

  float f = (9 * celsius) / 5; // calculating the first part of the formula
  f += 32; // calculating the remaining part
  
  cout << "Temperature in Fahrenheit: " << f; // printing the calculated temperature
  return 0;
}