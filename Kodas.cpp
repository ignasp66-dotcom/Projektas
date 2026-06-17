#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct Filmas
{
    int id;
    string pavadinimas;
    string zanras;
    int metai;
    int trukme;
    double ivertinimas;
};

vector<Filmas> filmai;

void nuskaitytiIsFailo()
{
    ifstream failas("filmai.txt");

    if (!failas)
    {
        cout << "Nepavyko atidaryti failo filmai.txt\n";
        return;
    }

    filmai.clear();

    string eilute;

    while (getline(failas, eilute))
    {
        stringstream ss(eilute);

        Filmas f;

        string idStr, metaiStr, trukmeStr, ivertinimasStr;

        getline(ss, idStr, ';');
        getline(ss, f.pavadinimas, ';');
        getline(ss, f.zanras, ';');
        getline(ss, metaiStr, ';');
        getline(ss, trukmeStr, ';');
        getline(ss, ivertinimasStr, ';');

        f.id = stoi(idStr);
        f.metai = stoi(metaiStr);
        f.trukme = stoi(trukmeStr);
        f.ivertinimas = stod(ivertinimasStr);

        filmai.push_back(f);
    }

    failas.close();
}

void issaugotiIFaila()
{
    ofstream failas("filmai.txt");

    for (const auto& f : filmai)
    {
        failas << f.id << ";"
               << f.pavadinimas << ";"
               << f.zanras << ";"
               << f.metai << ";"
               << f.trukme << ";"
               << f.ivertinimas << endl;
    }

    failas.close();

    cout << "\nDuomenys issaugoti sekmingai!\n";
}

void rodytiFilmus()
{
    if (filmai.empty())
    {
        cout << "\nFilmu sarasas tuscias.\n";
        return;
    }

    cout << "\n===== FILMU SARASAS =====\n";

    for (const auto& f : filmai)
    {
        cout << "\nID: " << f.id
             << "\nPavadinimas: " << f.pavadinimas
             << "\nZanras: " << f.zanras
             << "\nMetai: " << f.metai
             << "\nTrukme: " << f.trukme << " min."
             << "\nIvertinimas: " << f.ivertinimas
             << "\n--------------------------\n";
    }
}

void pridetiFilma()
{
    Filmas f;

    cout << "\nIveskite filmo ID: ";
    cin >> f.id;

    cin.ignore();

    cout << "Pavadinimas: ";
    getline(cin, f.pavadinimas);

    cout << "Zanras: ";
    getline(cin, f.zanras);

    cout << "Metai: ";
    cin >> f.metai;

    cout << "Trukme (min): ";
    cin >> f.trukme;

    cout << "Ivertinimas: ";
    cin >> f.ivertinimas;

    filmai.push_back(f);

    cout << "\nFilmas sekmingai pridetas!\n";
}

void redaguotiFilma()
{
    int id;

    cout << "\nIveskite filmo ID: ";
    cin >> id;

    cin.ignore();

    bool rasta = false;

    for (auto& f : filmai)
    {
        if (f.id == id)
        {
            rasta = true;

            cout << "Naujas pavadinimas: ";
            getline(cin, f.pavadinimas);

            cout << "Naujas zanras: ";
            getline(cin, f.zanras);

            cout << "Nauji metai: ";
            cin >> f.metai;

            cout << "Nauja trukme: ";
            cin >> f.trukme;

            cout << "Naujas ivertinimas: ";
            cin >> f.ivertinimas;

            cout << "\nFilmas atnaujintas!\n";
            break;
        }
    }

    if (!rasta)
    {
        cout << "\nFilmas nerastas!\n";
    }
}

void pasalintiFilma()
{
    int id;

    cout << "\nIveskite salinamo filmo ID: ";
    cin >> id;

    bool rasta = false;

    for (size_t i = 0; i < filmai.size(); i++)
    {
        if (filmai[i].id == id)
        {
            filmai.erase(filmai.begin() + i);
            rasta = true;

            cout << "\nFilmas pasalintas!\n";
            break;
        }
    }

    if (!rasta)
    {
        cout << "\nFilmas nerastas!\n";
    }
}

void ieskotiPagalZanra()
{
    cin.ignore();

    string paieska;

    cout << "\nIveskite viena arba kelis zanrus (atskirti kableliu): ";
    getline(cin, paieska);

    vector<string> zanrai;

    string temp;
    stringstream ss(paieska);

    while (getline(ss, temp, ','))
    {
        zanrai.push_back(temp);
    }

    bool rasta = false;

    cout << "\nRasti filmai:\n";

    for (const auto& f : filmai)
    {
        for (const auto& z : zanrai)
        {
            if (f.zanras.find(z) != string::npos)
            {
                cout << "\n" << f.pavadinimas
                     << " | " << f.zanras
                     << " | " << f.metai
                     << " | " << f.ivertinimas;

                rasta = true;
                break;
            }
        }
    }

    if (!rasta)
    {
        cout << "\nNieko nerasta.";
    }

    cout << endl;
}

void ieskotiPagalPavadinima()
{
    cin.ignore();

    string pavadinimas;

    cout << "\nIveskite filmo pavadinima arba jo dali: ";
    getline(cin, pavadinimas);

    bool rasta = false;

    for (const auto& f : filmai)
    {
        if (f.pavadinimas.find(pavadinimas) != string::npos)
        {
            cout << "\nID: " << f.id
                 << "\nPavadinimas: " << f.pavadinimas
                 << "\nZanras: " << f.zanras
                 << "\nMetai: " << f.metai
                 << "\nTrukme: " << f.trukme
                 << "\nIvertinimas: " << f.ivertinimas
                 << "\n--------------------------\n";

            rasta = true;
        }
    }

    if (!rasta)
    {
        cout << "\nFilmas nerastas.\n";
    }
}

void rikiuotiFilmus()
{
    int pasirinkimas;

    cout << "\n===== RIKIAVIMAS =====\n";
    cout << "1. Pagal ivertinima (nuo didziausio)\n";
    cout << "2. Pagal metus (nuo naujausio)\n";
    cout << "3. Pagal trukme (nuo ilgiausio)\n";
    cout << "Pasirinkimas: ";

    cin >> pasirinkimas;

    switch (pasirinkimas)
    {
        case 1:
            sort(filmai.begin(), filmai.end(),
            [](const Filmas& a, const Filmas& b)
            {
                return a.ivertinimas > b.ivertinimas;
            });
            break;

        case 2:
            sort(filmai.begin(), filmai.end(),
            [](const Filmas& a, const Filmas& b)
            {
                return a.metai > b.metai;
            });
            break;

        case 3:
            sort(filmai.begin(), filmai.end(),
            [](const Filmas& a, const Filmas& b)
            {
                return a.trukme > b.trukme;
            });
            break;

        default:
            cout << "\nNeteisingas pasirinkimas!\n";
            return;
    }

    cout << "\nFilmai surikiuoti sekmingai!\n";
}

void meniu()
{
    int pasirinkimas;

    do
    {
        cout << "\n========== FILMU KATALOGAS ==========\n";
        cout << "1. Rodyti visus filmus\n";
        cout << "2. Prideti filma\n";
        cout << "3. Redaguoti filma\n";
        cout << "4. Pasalinti filma\n";
        cout << "5. Paieska pagal zanra\n";
        cout << "6. Paieska pagal pavadinima\n";
        cout << "7. Rikiuoti filmus\n";
        cout << "8. Issaugoti duomenis\n";
        cout << "0. Baigti programa\n";

        cout << "\nPasirinkite veiksma: ";
        cin >> pasirinkimas;

        switch (pasirinkimas)
        {
            case 1:
                rodytiFilmus();
                break;

            case 2:
                pridetiFilma();
                break;

            case 3:
                redaguotiFilma();
                break;

            case 4:
                pasalintiFilma();
                break;

            case 5:
                ieskotiPagalZanra();
                break;

            case 6:
                ieskotiPagalPavadinima();
                break;

            case 7:
                rikiuotiFilmus();
                break;

            case 8:
                issaugotiIFaila();
                break;

            case 0:
                issaugotiIFaila();
                cout << "\nPrograma baigta.\n";
                break;

            default:
                cout << "\nNeteisingas pasirinkimas!\n";
        }

    } while (pasirinkimas != 0);
}

int main()
{
    nuskaitytiIsFailo();
    meniu();

    return 0;
}