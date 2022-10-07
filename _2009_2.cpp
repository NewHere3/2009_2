#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

struct begikas
{
    string name = "placeholder";
    int minutes = 0;
    int sekundes = 0;
    int laikas = 0;
};

ifstream duom("Duomenys.txt");

int read(begikas begikai[8]);
int fastest(begikas begikai[8], int n);
void write(begikas begikai[8], int n);

int main()
{
    int n;
    duom >> n;
    ofstream rez("Rezultatai.txt");
    for (int i = 0; i < n; i++)
    {
        int begiku_skaicius;
        begikas begikai[8];
        begiku_skaicius=read(begikai);
        cout << "uiaryghohouahgotaeshpitshjpstihj" << '\n';
        write(begikai, begiku_skaicius);
    }
    return 0;
}

int read(begikas begikai[8])
{
    int n = 0;
    duom >> n;
    for (int i = 0; i < n; i++)
    {
        char temp[21];
        duom.ignore();
        duom.get(temp, 21);
        begikai[i].name = temp;
        //cout << begikai[i].name << '\n';
        duom >> begikai[i].minutes;
        duom >> begikai[i].sekundes;
        begikai[i].laikas = begikai[i].sekundes + begikai[i].minutes * 60;
    }
        for (int i = 0; i < n; i++)
    {
        cout << begikai[i].name << ' ';
        cout << begikai[i].minutes << ' ';
        cout << begikai[i].sekundes << ' ';
        cout << begikai[i].laikas << '\n';
    }
    return n;
}

int fastest(begikas begikai[8], int n)
{
    int x = 0;
    int praeito_laikas = begikai[0].laikas;
    for (int i = 0; i < n; i++)
    {
        if (begikai[i].laikas < praeito_laikas && begikai[i].laikas != -1)
        {
            x = i;
        }
    }
    //cout << "begikai[x].laikas" << begikai[x].laikas << '\n';
    begikai[x].laikas = -1;
    return x;
}

void write(begikas begikai[8], int n)
{
    //cout << "rsabgiusabgusibgius" << '\n';
    ofstream rez("Rezultatai.txt", ios::app);
    int n2 = n / 2;
    for (int i = 0; i < n2; i++)
    {
        int x = fastest(begikai, n);
        rez << begikai[x].name << ' ' << begikai[x].minutes << ' ' << begikai[x].sekundes << '\n';
    }
}
