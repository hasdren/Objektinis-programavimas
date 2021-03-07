#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <iomanip>
#include <fstream>
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
    int egzaminas;
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
        sum = nd[nd.size() / 2.0];
    }
    else
    {
        sum = (nd[nd.size() / 2.0] + nd[(nd.size() / 2.0) - 1]) / 2.0;
    }
    median = sum;
}
void printmed(string &vardas,string &pavarde,double &mediana){
cout << left << setw(10) << vardas << setw(16) << pavarde << setw(12)<< fixed <<setprecision(2) << mediana << endl;
}
void printave(string &vardas,string &pavarde,double &average){
    cout << left << setw(10) << vardas << setw(16) << pavarde << setw(12)<<fixed<<setprecision(2) << average << endl;
}
int studentEntry(){
    int students;
    cout << "iveskite studentu skaiciu?(>0)";
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
        return students;
    }
}
int ManualEntry(){
    int manual;
    cout << "Ar norite, kad namu darbai butu ivedami?(y/n)";
    while (true)
    {
        char p;
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
    return manual;
    
}
int HomeworkKnown(){
    cout << "Ar zinote namu darbu kieki?(y/n)";
    int knowhomework;
    while (true)
    {   char p;
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
    return knowhomework;

}
int SA(){
    int showaverage;
    cout << "Ar norite matyti vidurki?(y/n)";
    while (true)
    {   char p;
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
    return showaverage;

}
int Choosefile()
{
    int sk;
    cout << "pasirinkite faila";
    while (!(cin >> sk) || (sk < 0 || sk > 3))
    {
        cout << "Neteisinga ivestis!" << endl;
        cin.clear();
        cin.ignore(128, '\n');
    }
    return sk;
}
int File(){
    cout<<"Ar norite nuskaityti is failo?";
    int readfile;
    while (true)
    {   char p;
        cin >> p;
        if (p == 'Y' || p == 'y')
        {
            readfile = 1;
            cin.clear();
            break;
        }
        else if (p == 'N' || p == 'n')
        {
            readfile = 0;
            cin.clear();
            break;
        }
        else
        {
            cout << "Wrong entry, try again";
            cin.clear();
        }
    }
    return readfile;

}


int main()
{
    vector<studentas> s;
    int students, showaverage, manual, knowhomework,readfile,choise,findouthomework=-1,studentfile=1,grade;
    string failas,test;
    char p;
    readfile=File();
    if (readfile==1){
    choise = Choosefile();
    if (choise == 1)
    {
        failas="Studentai10000.txt";
        
    }
    else if (choise == 2)
    {
        failas="Studentai100000.txt";
        
    }
    else
    {
        failas="Studentai1000000.txt";
        
    }
    ifstream in(failas);
        in >> test;
        in >> test;
        while (test != "Egz.")
        {
            in >> test;
            findouthomework++;
        }
    cout<<"Would you like the average to be shown?";
    showaverage=SA();
    if (showaverage==1){
        while (!in.eof())
    {
        s.resize(studentfile);
        in >> s[studentfile - 1].vardas;
        in >> s[studentfile - 1].pavarde;
        for (int m = 0; m < findouthomework; m++)
        {
            in >> grade;
            s[studentfile - 1].nd.push_back(grade);
        }
        in >> s[studentfile - 1].egzaminas;
        studentfile++;
    }
    for (int i=0;i<studentfile-1;i++){
        Average(s[i].nd,s[i].average);
    }

    ofstream out("lmao.txt");
    out<<fixed<<left<<setw(20)<<"Vardas";
    out<<fixed<<left<<setw(20)<<"Pavarde";
    out<<fixed<<left<<setw(20)<<"Galutinis(vid.)"<<endl;
    out<< "-----------------------------------------------------------" << endl;

    for (int b=0;b<studentfile-1;b++){
        out<<fixed<<left<<setw(20)<<s[b].vardas;
        out<<fixed<<left<<setw(20)<<s[b].pavarde;
        out<<fixed<<setprecision(2)<<setw(10)<<s[b].average<<" "<<endl;


    }
        

    }
    else{
         while (!in.eof())
    {
        s.resize(studentfile);
        in >> s[studentfile - 1].vardas;
        in >> s[studentfile - 1].pavarde;
        for (int m = 0; m < findouthomework; m++)
        {
            in >> grade;
            s[studentfile - 1].nd.push_back(grade);
        }
        in >> s[studentfile - 1].egzaminas;
        studentfile++;
    }
    for(int i=0;i<studentfile-1;i++){
        Median(s[i].nd,s[i].mediana);
    }
    ofstream out("lmao.txt");
    out<<fixed<<left<<setw(20)<<"Vardas";
    out<<fixed<<left<<setw(20)<<"Pavarde";
    out<<fixed<<left<<setw(20)<<"Galutinis(med.)"<<endl;
    out<< "-----------------------------------------------------------" << endl;

    for (int b=0;b<studentfile-1;b++){
        out<<fixed<<left<<setw(20)<<s[b].vardas;
        out<<fixed<<left<<setw(20)<<s[b].pavarde;
        out<<fixed<<setprecision(2)<<setw(10)<<s[b].mediana<<" "<<endl;


    }



    }
    

        
    }
    else{
    students=studentEntry();
    s.resize(students);
    manual=ManualEntry();
    knowhomework=HomeworkKnown();
    showaverage=SA();
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
   

}