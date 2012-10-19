/* Example Generator */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double rand01 () {
  return (rand()%1000)/1000.0;
}

int main (int argc, char **argv) {
  if (argc < 2) {
    cout << "Argument is needed" << endl;
    return 1;
  }

  int size = atoi(argv[1]);
  double *sum = new double[size];

  cout << size << ' ' << size << endl;
  for (int i = 0; i < size; i++) {
    sum[i] = size - 1;
    for (int j = 0; j < size; j++) {
      double r = rand01();
      sum[i] += r;
      if (i == j)
        cout << setiosflags(ios_base::fixed) << setw(7) 
             << setprecision(3) << size - 1 + r << ' ';
      else {
        cout << setiosflags(ios_base::fixed) << setw(7) 
             << setprecision(3) << r << ' ';
      }
    }
    cout << endl;
  }
  cout << size << ' ' << 1 << endl;
  for (int i = 0; i < size; i++)
    cout << setiosflags(ios_base::fixed) << setw(7)
         << setprecision(3) << sum[i] << endl;

  delete []sum;

}
