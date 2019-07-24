#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


/*cd C:\Users\Kai Thomas\Documents\CSCI 3308/project*/
//g++ -std=c++11 masses.cpp -o mass && mass

//standard shit
////metric <-> imperial
////pounds <-> grams
////grams <-> ounces
////kilograms <-> grams
////ounces <-> kilograms
////ounces <-> pounds
////kilograms <-> pounds

//weight on another planet XXXX
//first get the mass: divide weight /(9.8 m/s^2)
//then just multiply by m/s^2 of other planet
////Earth: 9.8 m/s^2
////Jupiter: 24.79 m/s^2
////Mars: 3.711 m/s^2
////Venus: 8.87 m/s^2
////Neptune: 11.15 m/s^2
////Mercury: 3.7 m/s^2
////Saturn: 10.44 m/s^2
////Uranus: 8.69 m/s^2

float poundsToGrams(float pounds)
{
  float grams = pounds*453.592;
  return grams;
}

float gramsToPounds(float grams)
{
  double pounds = grams/453.592;
  return pounds;
}

float gramsToOunces(float grams)
{
  float ounces = grams/28.3495;
  return ounces;
}

float ouncesToGrams(float ounces)
{
  float grams = ounces*28.3495;
  return grams;
}

float kilogramsToGrams(float kilograms)
{
  float grams = kilograms*1000;
  return grams;
}

float gramsToKilograms(float grams)
{
  float kilograms = grams/1000;
  return kilograms;
}

float ouncesToKilograms(float ounces)
{
  float kilograms = ounces/35.274;
  return kilograms;
}

float kilogramsToOunces(float kilograms)
{
  float ounces = kilograms*35.274;
  return ounces;
}

float ouncesToPounds(float ounces)
{
  float pounds = ounces/16;
  return pounds;
}

float poundsToOunces(float pounds)
{
  float ounces = pounds*16;
  return ounces;
}

float kilogramsToPounds(float kilograms)
{
  float pounds = kilograms*2.205;
  return pounds;
}

float poundsToKilograms(float pounds)
{
  float kilograms = pounds/2.205;
  return kilograms;
}

void planets(float weight) //weight has to be in lbs for this feat!!
{
  ////Earth: 9.8 m/s^2
  ////Jupiter: 24.79 m/s^2
  ////Mars: 3.711 m/s^2
  ////Venus: 8.87 m/s^2
  ////Neptune: 11.15 m/s^2
  ////Mercury: 3.7 m/s^2
  ////Saturn: 10.44 m/s^2
  ////Uranus: 8.69 m/s^2
  string planets[] = {"Mercury", "Venus", "Earth", "Mars", "Jupiter", "Saturn", "Uranus", "Neptune"};
  float forces[] = {3.7, 8.87, 9.8, 3.711,  24.79, 10.44, 8.69, 11.15};
  int n = sizeof(forces)/sizeof(forces[0]);
  float mass = weight/9.8;
  for (int i =0;i <n;i++)
  {
    float w = mass*forces[i];
    cout << planets[i] << ": " << w << " lbs" << endl;
  }



}



int main()
{
  planets(69);
  //cout << poundsToGrams(100) << endl;
  //cout <<gramsToPounds(45) << endl;
  //cout << gramsToOunces(45) << endl;
  //cout << ouncesToGrams(7) << endl;
  cout << kilogramsToGrams(7) << endl;
  //cout << gramsToKilograms(45) << endl;
  //cout << ouncesToKilograms(7) << endl;
  cout << kilogramsToOunces(7) << endl;
  //cout << ouncesToPounds(7) << endl;
  //cout << poundsToOunces(100) << endl;
  cout << kilogramsToPounds(7) << endl;
  //cout << poundsToKilograms(100) << endl;


}
