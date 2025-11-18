#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;

void merge(double* gpa, string* last, string* first, int beg, int mid, int end){
    int n1 = mid - beg + 1;
    int n2 = end - mid;
    double* Lg = new double[n1 + 1];
    double* Rg = new double[n2 + 1];
    string* Ll = new string[n1 + 1];
    string* Rl = new string[n2 + 1];
    string* Lf = new string[n1 + 1];
    string* Rf = new string[n2 + 1];
    for (int i = 0; i < n1; i++){
        Lg[i] = gpa[beg + i];
        Ll[i] = last[beg + i];
        Lf[i] = first[beg + i];
    }
    for (int i = 0; i < n2; i++){
        Rg[i] = gpa[mid + 1 + i];
        Rl[i] = last[mid + 1 + i];
        Rf[i] = first[mid + 1 + i];
    }
    Lg[n1] = 1e9;
    Rg[n2] = 1e9;
    int i = 0, j = 0;
    for (int k = beg; k <= end; k++){
        bool takeLeft = false;
        if (Lg[i] < Rg[j]) takeLeft = true;
        else if (fabs(Lg[i] - Rg[j]) < 1e-9) {
            if (Ll[i] < Rl[j]) takeLeft = true;
            else if (Ll[i] == Rl[j] && Lf[i] < Rf[j]) takeLeft = true;
        }
        if (takeLeft){
            gpa[k] = Lg[i];
            last[k] = Ll[i];
            first[k] = Lf[i];
            i++;
        } else {
            gpa[k] = Rg[j];
            last[k] = Rl[j];
            first[k] = Rf[j];
            j++;
        }
    }
    delete[] Lg; delete[] Rg;
    delete[] Ll; delete[] Rl;
    delete[] Lf; delete[] Rf;
}

void mergeSort(double* gpa, string* last, string* first, int beg, int end){
    if (beg < end){
        int mid = (beg + end) / 2;
        mergeSort(gpa, last, first, beg, mid);
        mergeSort(gpa, last, first, mid + 1, end);
        merge(gpa, last, first, beg, mid, end);
    }
}

double toGPA(string grade){
    if (grade == "A+") return 4.00;
    if (grade == "A")  return 3.75;
    if (grade == "B+") return 3.50;
    if (grade == "B")  return 3.00;
    if (grade == "C+") return 2.50;
    if (grade == "C")  return 2.00;
    if (grade == "D+") return 1.50;
    if (grade == "D")  return 1.00;
    return 0.00;
}

int main(){
    int n;
    if (!(cin >> n)) return 0;
    string* last = new string[n];
    string* first = new string[n];
    double* gpa = new double[n];

    for (int i = 0; i < n; i++){
        cin >> last[i] >> first[i];
        int m;
        cin >> m;
        double sum = 0, cred = 0;
        for (int j = 0; j < m; j++){
            string grade; int c;
            cin >> grade >> c;
            sum += toGPA(grade) * c;
            cred += c;
        }
        gpa[i] = sum / cred;
    }

    if (n > 0) mergeSort(gpa, last, first, 0, n - 1);

    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < n; i++)
        cout << last[i] << " " << first[i] << " " << gpa[i] << endl;

}