#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct poros
{
    string vardai;
    int TEC[100];
    int ART[100];
};

void nuskaitymas();
void skaiciavimai();
void spausdinimas();

poros P[100];

int n, k;

int main()
{
    nuskaitymas();
    for(int i=0; i<n; i++)
    {
        cout << P[i].vardai << endl;
        for(int j=0; j<k; j++) cout << P[i].ART[j] << " ";
        cout << endl;
    }
    return 0;
}

void nuskaitymas()
{
    char eil[20];
    ifstream fd("U2.txt");
    fd >> n >> k;
    fd.ignore();
    for(int i=0; i<n; i++)
    {
        fd.get(eil, 20);
        P[i].vardai = eil;
        fd.ignore();
        for(int j=0; j<k; j++)
        {
            fd >> P[i].TEC[j];
        }
        fd.ignore();
        for(int j=0; j<k; j++)
        {
            fd >> P[i].ART[j];
        }
        fd.ignore();
    }
    fd.close();


}

void Rikiavimas()
{
    int temp;
    for (int i=0 ; i<n-1 ; i++)
        for (int j=i+1 ; j < n ; j++)
            for(int z=0; z<k; z++)
            {
                if (P[i].TEC[z] > P[j].TEC[z])
                {
                    temp = P[i].TEC[z];
                    P[i].TEC[z] = P[j].TEC[z];
                    P[j].TEC[z] = temp;
                }
            }
}
