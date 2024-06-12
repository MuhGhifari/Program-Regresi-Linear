#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>

using namespace std;

int main() {
  ifstream fileInput;
  fileInput.open("input.csv");

  if(!fileInput) {
    cerr << "input tidak terdeteksi!" << endl;
    exit(1);
  }

  int n;
  double xSum=0, ySum=0, x2=0, xySum=0, a, b;

  string str;
  while(getline(fileInput, str)) {
    string isiBaris;
    vector<double> baris;
    stringstream ss(str);

    while(getline(ss, isiBaris, ',')) {
      baris.push_back(stod(isiBaris));
    }
    
    int xi = baris[0];
    int yi = baris[1];

    xSum = xSum + xi;
    x2 = x2 + (xi * xi);
    ySum = ySum + yi;
    xySum = xySum + (xi * yi);

    n++;
  }
  fileInput.close();

  b = (((n * xySum) - (xSum * ySum)) / ((n * x2) - (xSum * xSum)));
  a = (ySum - (b * xSum)) / n;
  cout << "Persamaan : y = " << a << " + " << b << "x" << endl;
  return 0;
}