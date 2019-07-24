#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


/*cd C:\Users\Kai Thomas\Documents\CSCI 3308/project*/
//g++ -std=c++11 baseConversion.cpp -o base && base

//bin, dec, hex, maybe tri
//dec->bin X
//dec->hex X
//bin->dec X
//bin->hex X
//hex->bin X
//hex->dec X



int binToDec(int n)
{
  int sum =0;
  string x = to_string(n);
  int l = x.size();
  //cout << l << endl;
  int k =0;
  for(int i=l-1; i>=0;i-- )
  {
    //cout << x[i] << endl;
    if(x[i]!='0')
    {
      //cout << x[i] << endl;
      sum += pow(2, k);
    }

    k++;
    //cout << sum << endl;
  }
  return sum;
}

string decToBin(int n)
{
  string x = to_string(n);
  vector<int> R = {0};
  int l = x.size();
  while (n > 0)
  {
    //cout << n%2 << endl;
    R.push_back(n%2);
    n=floor(n/2);
  }
  string bin = "";
  auto k = R.size()-1;
  for (k;k>0;k--)
  {
    //cout << R[k] << endl;
    bin+=to_string(R[k]);
    //cout << bin << endl;
  }
  return bin;
}

string decToHex(int n)
{
  string x = to_string(n);
  int chars[6]= {'A', 'B', 'C', 'D', 'E', 'F'};
  vector<int> R = {0};
  int l = x.size();
  while (n > 0)
  {
    //cout << n%16 << endl;
    R.push_back(n%16);
    n=floor(n/16);
  }
  string hex = "";
  auto k = R.size()-1;
  for (k;k>0;k--)
  {
    //cout << R[k] << endl;
    if (R[k]<=9)
    {
      hex+=to_string(R[k]);
    }
    else
    {
      int j = R[k]-10;
      hex+=chars[j];
    }
    //cout << hex << endl;
  }
  return hex;
}

int hexToDec(string x)
{
  int sum =0;
  char chars[6]= {'A', 'B', 'C', 'D', 'E', 'F'};
  int v = (sizeof(chars)/sizeof(chars[0]));
  //cout << v << endl;
  int l = x.size();
  //cout << l << endl;
  int k =0;
  for(int i=l-1; i>=0;i-- )
  {
    //cout << x[i] << endl;
    if(x[i]!='0')
    {
      //cout << x[i] << endl;
      if (isalpha(x[i]))
      {
        for(int j=0;j < v;j++)
        {
          //cout << "in the seconf for" << endl;
          if (x[i] == chars[j])
          {
            //cout << x[i] << endl;
            //cout << j << endl;
            sum += pow(16, k) * (j+10);
          }

        }
      }

      else
      {
        sum += pow(16, k) * stoi(x.substr(i, 1));
      }

    }

    k++;
  //  cout << sum << endl;
  }
  return sum;

}

string binToHex(string n)
{
 string bins[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001",  "1010", "1011", "1100", "1101", "1110", "1111"};
 char chars[6]= {'A', 'B', 'C', 'D', 'E', 'F'};
 string hex ="";
 int l = n.size()/4;
 //cout << l << endl;
 for (int i =0; l>0;i+=4)
 {
   string k = n.substr(i, 4);
   //cout << k << endl;
   for (int j =0; j<sizeof(bins);j++)
   {
     if (k == bins[j] && j <=9)
     {
       //cout << bins[j] << " | " << j << endl;
      hex+=to_string(j);
      break;
     }
     else if(k == bins[j] && j > 9)
     {
       //cout << bins[j] << " | " << j << endl;
       hex+=chars[j-10];
       //cout << hex << endl;
       break;
     }
   }

   l--;
 }

 //cout << hex << endl;
 return hex;
}


string hexToBin(string n)
{
  int l =n.size();
  string bins[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000", "1001",  "1010", "1011", "1100", "1101", "1110", "1111"};
  char chars[6]= {'A', 'B', 'C', 'D', 'E', 'F'};
  string bin ="";
  int v = (sizeof(chars)/sizeof(chars[0]));
  for (int i=0; i<l;i++)
  {
    if (isalpha(n[i]))
    {
      for(int j=0;j < v;j++)
      {
        //cout << "in the seconf for" << endl;
        if (n[i] == chars[j])
        {
          //cout << x[i] << endl;
          //cout << j << endl;
          bin += bins[j+10];
        }
      }
    }
    else
    {

      bin+=bins[stoi(n.substr(i, 1))];
    }
  }
  //cout << bin << endl;
  return bin;
}



int main()
{
  //need to access users choice somehow and call the right function
  int bDec = binToDec(1010);
  //cout << bDec << endl;
  string dBin = decToBin(32);
  //cout << dBin << endl;
  string dHex = decToHex(139);
  //cout << dHex << endl;
  int hDec = hexToDec("A5");
  //cout << hDec << endl;
  string bHex = binToHex("110101010110");
  //cout << bHex << endl;
  string hBin = hexToBin("A49D");
  cout << hBin << endl;
}
