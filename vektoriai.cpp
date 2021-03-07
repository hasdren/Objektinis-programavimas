#include"vektoriai.h"

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