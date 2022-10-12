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
    int laikas = -1;
};

ifstream duom("Duomenys.txt");
ofstream rez("Rezultatai.txt");

int read(begikas begikai[8]);
void fastest(vector<begikas>& greiciausi, begikas begikai[8], int n);
void write(vector<begikas>& greiciausi);
void my_sort(vector<begikas>& B);

int main()
{
    int n;
    vector<begikas> greiciausi;
    duom >> n;

    for (int i = 0; i < n; i++)
    {
        int begiku_skaicius;
        begikas begikai[8];
        begiku_skaicius=read(begikai);
        fastest(greiciausi, begikai, begiku_skaicius);
    }
    write(greiciausi);
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
        duom >> begikai[i].minutes;
        duom >> begikai[i].sekundes;
        begikai[i].laikas = begikai[i].sekundes + begikai[i].minutes * 60;
    }
    return n;
}

void fastest(vector<begikas>& greiciausi, begikas begikai[8], int n)
{
    int x;
    for (int i = 0; i < n/2; i++)
    {
        int praeito_laikas = INT_MAX;
        for(int j=0; j<8; j++)
        {
                if (begikai[j].laikas < praeito_laikas && begikai[j].laikas != -1)
            {
                x = j;
                praeito_laikas = begikai[j].laikas;
            }
        }
        greiciausi.push_back(begikai[x]);
        begikai[x].laikas=-1;
    }
}

void write(vector<begikas>& greiciausi)
{
    //ofstream rez("Rezultatai.txt", ios::app);
    int n=greiciausi.size();
    my_sort(greiciausi);
    for (int i = 0; i < n; i++)
    {
        rez << greiciausi[i].name << ' ' << greiciausi[i].minutes << ' ' << greiciausi[i].sekundes << '\n';
    }
}

void my_sort(vector<begikas>& B)
{
    for(int i=0; i<B.size();i++)
    {
        for(int j=i+1; j<B.size();j++)
        {
            if(B[i].laikas>B[j].laikas)
            {
                swap(B[i],B[j]);
            }
        }
    }
}
