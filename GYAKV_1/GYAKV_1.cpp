#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct	ugynok
{
	string varos;
	int tav;
};
int beolvas(char *t, ugynok* tmb);
int ossztav(ugynok *tmb, int db);
string legtavolabb(ugynok *tmb, int db);
int kozeliekszama (ugynok *tmb, int db);
void rendezvekiir(ugynok *tmb, int db);

int main()
{
	char megnyit[]  = "vartav.txt";
	ugynok A[20];
	int varosdb = beolvas(megnyit, A);
	cout << "A meglatogatott varosok szama : " << varosdb << endl;
	cout << "A januarban megtett osszes tavolsag : " << ossztav(A, varosdb) << endl;
	cout << "A legtavolabbi varos neve: " << legtavolabb(A, varosdb) << endl;
	cout << "80 km nel kozelebbi varosok szama : " << kozeliekszama(A, varosdb) << endl;
	rendezvekiir(A, varosdb);
	return 0;
}

int beolvas(char* t, ugynok *tmb)
{
	ifstream be(t);
	if (be.fail())
	{
		cout << "\nHiba, a fajl nem talalhato!" << endl;
		exit(1);
	}
	int i, j, db = 0;
	for (i = 0; i < 20 && !be.eof(); i++)
		{
			be >> tmb[i].varos;
			be >> tmb[i].tav;
			db++;
			cout << tmb[i].varos << " " << tmb[i].tav << endl;
		}
	be.close();
	return 	db;
}

int ossztav (ugynok* tmb, int db )
{
	int	ossz = 0;
	for	(int i = 0; i < db; i++)
		ossz = ossz + tmb[i].tav;
	return 2 * ossz;
}

string legtavolabb (ugynok* tmb, int db )
{
	int	max = 0;
	for(int i = 1; i < db; i++)
	{
			if(tmb[i].tav > tmb[max].tav )
			{
					max	= i;
			}
	}
	return	tmb[max].varos;
}

int kozeliekszama (ugynok* tmb, int db )
{
	int	tav = 0;
	for(int i = 0; i < db; i++) 
		if (tmb[i].tav < 80) tav++;
		return tav;
}
void rendezvekiir (ugynok* tmb, int db )
{
	ugynok seged;
	ofstream ki("rendezetttavolsag.txt");
	if (ki.fail())
	{
		cerr << "Hiba!" << endl;
		system("pause");
		exit(1);
	}	
	for (int i = 0; i < db - 1; i++)
		{
		for (int j = i + 1; j < db; j++)
				{
					if (tmb[i].tav > tmb[j].tav )
					{
							seged = tmb[i];
							tmb[i] = tmb[j];
							tmb[j] = seged;
					}
		}
	}
	for(int i = 0; i < db; i++)
	{
			cout << tmb[i].varos << " " << tmb[i].tav << endl;
			ki << tmb[i].varos << " " << tmb[i].tav << endl;
	}
	ki.close();
}

	
		
		
