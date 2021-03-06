#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
using namespace std;
random_device rd;
mt19937 mt(rd());
uniform_int_distribution<int> dist(0, 10);

struct studentas
{
    int n;          //namu darbu kiekis
    vector<int> nd; //namu darbu rezultatu masyvas
    string vardas;
    string pavarde;
    double average;
    double mediana;
};

void VP(int i, string &vardas, string &pavarde)
{
    cout << i + 1 << "-ojo studento vardas: ";
    cin >> vardas;
    vardas[0] = toupper(vardas[0]);
    cout << i + 1 << "-ojo studento pavarde: ";
    cin >> pavarde;
    pavarde[0] = toupper(pavarde[0]);
}
void Random(int i, vector<int> &nd)
{
    nd.push_back(dist(mt));
    cout << i + 1 << "-am studentui"
         << "Pridetas :" << nd.back() << endl;
}

void IvestisSk(int c, vector<int> &nd)
{
    string laik;
    cout << c + 1 << " studento " << nd.size() + 1 << " namu darbo ivertinimas [0-10]: ";
    cin >> laik;
    while (laik != "10" && (laik.length() != 1 || (laik.length() == 1 && (laik[0] - '0' < 0 || laik[0] - '0' > 10))))
    {
        cout << "Neteisinga ivestis!" << endl
             << c + 1 << " studento " << nd.size() + 1 << " namu darbo ivertinimas [0-10]: ";
        cin >> laik;
    }
    nd.push_back(laik[0] - '0');
}

double Average(vector<int> &nd, double &average)
{
    double sum = 0;
    for (int i = 0; i < nd.size(); i++)
    {
        sum = sum + nd[i];
    }
    sum = sum / nd.size();
    average=sum;
}
void Median(vector<int> &nd, double &median)
{
    double sum;
    sort(nd.begin(), nd.end());
    if (nd.size() % 2 != 0)
    {
        sum = nd[nd.size() / 2];
    }
    else
    {
        sum = (nd[nd.size() / 2] + nd[(nd.size() / 2) - 1]) / 2.0;
    }
    median = sum;
}
void printmed(string &vardas,string &pavarde,double &mediana){
cout << left << setw(10) << vardas << setw(16) << pavarde << setw(12)<< fixed <<setprecision(2) << mediana << endl;
}
void printave(string &vardas,string &pavarde,double &average){
    cout << left << setw(10) << vardas << setw(16) << pavarde << setw(12)<<fixed<<setprecision(2) << average << endl;
}

int main()
{
    vector<studentas> s;
    cout << "iveskite studentu skaiciu?(>0)";
    int students, showaverage, manual, knowhomework;
    char p;

    while (true)
    {
        cin >> students;
        if (students <= 0)
        {
            cout << "Error , retry input";
            cin.clear();
        }
        else
        {
            break;
        }
    }
    s.resize(students);
    cout << "Ar norite, kad namu darbai butu ivedami?(y/n)";
    while (true)
    {
        cin >> p;
        if (p == 'Y' || p == 'y')
        {
            manual = 1;
            cin.clear();
            break;
        }
        else if (p == 'N' || p == 'n')
        {
            manual = 0;
            cin.clear();
            break;
        }
        else
        {
            cout << "Bloga ivestis";
            cin.clear();
        }
    }
    cout << "Ar zinote namu darbu kieki?(y/n)";
    while (true)
    {
        cin >> p;
        if (p == 'Y' || p == 'y')
        {
            knowhomework = 1;
            cin.clear();
            break;
        }
        else if (p == 'N' || p == 'n')
        {
            knowhomework = 0;
            cin.clear();
            break;
        }
        else
        {
            cout << "Bloga ivestis";
            cin.clear();
        }
    }
    cout << "Ar norite matyti vidurki?(y/n)";
    while (true)
    {
        cin >> p;
        if (p == 'Y' || p == 'y')
        {
            showaverage = 1;
            cin.clear();
            break;
        }
        else if (p == 'N' || p == 'n')
        {
            showaverage = 0;
            cin.clear();
            break;
        }
        else
        {
            cout << "Wrong entry, try again";
            cin.clear();
        }
    }

    for (int i = 0; i < students; i++)
    {
        VP(i, s[i].vardas, s[i].pavarde);
    }

    if (knowhomework == 0 && manual == 0)
    {
        manual = 1;
    }

    if (knowhomework == 1 && manual == 1)
    {
        for (int i = 0; i < students; i++)
        {   cout<<i+1<<"-ojo studento pazymiu kiekis: ";
            cin >> s[i].n;
        }

        for (int i = 0; i < students; i++)
        {
            for (int j = 0; j<s[i].n; j++)
            {
                IvestisSk(i, s[i].nd);
            }
        }
    }
    else if (manual == 0 && knowhomework == 1)
    {
        for (int i = 0; i < students; i++)
        {   cout<<i+1<<"-ojo studento pazymiu kiekis: ";
            cin >> s[i].n;
        }
        for (int i = 0; i < students; i++)
        {
            for (int j = 0; j<s[i].n; j++)
            {
                Random(i, s[i].nd);
            }
        }
    }
    else if (manual==1 && knowhomework==0)
    {
        for (int i = 0; i < students; i++)
        {
            while (true)
            {
                cout << "Ar norite testi" << i + 1 << "-ojo studento vedima?(y/n)";
                cin >> p;
                    if (p == 'Y' || p == 'y')
                        {
                            IvestisSk(i, s[i].nd);
                            cin.clear();
                        }
                    else if (p == 'N' || p == 'n')
                        {
                    cin.clear();
                    break;
                        }
                    else
                    {
                    cout << "Bloga ivestis";
                    cin.clear();
                    }
            }
        }
    }
    if (showaverage==1){
        cout << left << setw(10) << "Vardas" << setw(16) << "Pavarde" << setw(12) << "Galutinis(vid)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (int i=0;i<students;i++){
        Average(s[i].nd,s[i].average);
        printave(s[i].vardas,s[i].pavarde,s[i].average);
    }
    }
    else {
        cout << left << setw(10) << "Vardas" << setw(16) << "Pavarde" << setw(12) << "Galutinis(med)" << endl;
    cout << "-----------------------------------------------------------" << endl;
    for (int i=0;i<students;i++){
        Median(s[i].nd,s[i].mediana);
        printmed(s[i].vardas,s[i].pavarde,s[i].mediana);
    }
    }
    

}