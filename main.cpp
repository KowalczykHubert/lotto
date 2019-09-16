#include <iostream>
#include <cstdlib>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

int zakres;
int liczba_skreslen;
int licznik=0;
int losowane_liczby;
void menu();
void duzy_lotek();
void multilotek();
void skreslanie_i_losowanie_liczb();
void return_1();
void return_2();

int main()
{
    menu();

    return 0;
}

void menu()
{
    for (;;)
    {
        char wybor;
        cout << "WITAJ W KOLEKTURZE LOTTO!!!" << endl
             << "WYBIERZ ZAKLADY, KTORE CHCESZ OBSTAWIC" << endl
             << "----------------------------------------" << endl
             << "1. DUZY LOTEK" << endl
             << "2. MULTILOTEK" << endl
             << "3. ZDRAPKA" << endl
             << "4. ZAKONCZ" << endl;
        cout << endl;
        cout << "Wybierz:";
        wybor = _getch();
        cout << endl;

        switch (wybor)
        {
        case '1':
        {
            duzy_lotek();
        }
        break;
        case '2':
        {
            multilotek();
        }
        break;

        case '3':
        {
            cout << "OPCJA W BUDOWIE!" << endl;
            cout << endl;
            return_1();
        }
        break;

        case '4':
            exit(0);
            break;
        default:
        {
            cout << "Nie ma takiej opcji w menu!" << endl;
            cout << endl;
            return_1();
        }
        }
    }
}

void skreslanie_i_losowanie_liczb()
{
   int *skreslenia;
   skreslenia = new int [liczba_skreslen];
   int *liczba;
   liczba = new int [losowane_liczby];
    for (int i = 0; i<liczba_skreslen; i++) //\JAK DAJE i<=5 to ostatnia wylosowana liczba wskakuje na miejsce pierwszej skreslonej
    {
        cout << "Skresl " << i + 1 <<". "<<"liczbe: ";
        cin >> skreslenia[i];
        if (cin.good())
        {
            if (skreslenia[i] < 1 || skreslenia[i]>zakres)
            {
                cout << "Podales liczba spoza zakresu!" << endl;
                i--;
            }
            else
                for (int j = i - 1; j > -1; j--)
                {
                    if (skreslenia[i] == skreslenia[j])
                    {
                        cout << "Podales juz taka liczbe!" << endl;
                        i--;
                    }
                }
        }
        else
        {
            Sleep(1000);
            cout << "Wpisales niepoprawny znak!" << std::endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            i--;
        }
    }
    cout << endl;
    cout << "ZA CHWILE NASTAPI ZWOLNIENIE BLOKADY!" << endl;
    cout << endl;
    Sleep(3000);
    cout << "ROZPOCZYNAMY LOSOWANIE "<<losowane_liczby<<" LICZB: " << endl;
    cout << endl;
    srand(time(NULL));
    for (int j = 0; j <= losowane_liczby-1; j++)
    {
        liczba[j] = rand() % zakres + 1;
        //Sleep(1000);
        for (int a = j - 1; a >= -1; a--)
        {
            if (liczba[a] == liczba[j])
            {
                //cout<<"wylosowano juz taka liczbe!"<<endl;
                j--;
            }
        }
    }
    Sleep(1000);
    cout << endl;
    cout << "OTO TWOJE SKRESLONE LICZBY: ";
    for (int i = 0; i <= liczba_skreslen-1; i++)
    {
        cout << skreslenia[i] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "OTO WYLOSOWANE LICZBY:     ";
    for (int j = 0; j <= losowane_liczby-1; j++)
    {
        Sleep(1000);
        cout << liczba[j] << " ";
    }
    cout << endl;
    cout << endl;
    cout << "UWAGA! TRWA SPRAWDZANIE WYNIKOW!" << endl;
    cout << endl;
    Sleep(1000);
    //int licznik = 0;

    for (int i = 0; i <= liczba_skreslen-1; i++)
    {
        for (int j = 0; j <= losowane_liczby-1; j++)
        {
            if (skreslenia[i] == liczba[j])
                licznik++;
            //cout<<skreslenia[i]<<"-"<<liczba[j]<<endl; //porownanie
            // cout<<"licznik= "<<licznik<<endl; SPRAWDZAM PORÓWNANIA LICZB
        }
    }
delete [] skreslenia;
delete [] liczba;
}

void duzy_lotek()
{
    cout << "______________________________" << endl;
    cout << "SKRESL 6 LICZB Z ZAKRESU 1..49" << endl;
    cout << "______________________________" << endl;
    losowane_liczby=6;
    liczba_skreslen=6;
    zakres=49;
    //int licznik;
    skreslanie_i_losowanie_liczb();

    if (licznik == 1)
    {
        cout << "Udalo Ci sie trafic tylko " << licznik << " liczbe :)" << endl;
        cout << endl;
        return_2();
    }
    else if (licznik == 2)
    {
        cout << "Udalo Ci sie trafic dwojke:)" << endl;
        cout << endl;
        return_2();
    }
    else if ((licznik > 2) && (licznik<6))
    {
        cout << "BRAWO! Udalo Ci sie trafic " << licznik << " liczby! WYGRYWASZ HAJS :)" << endl;
        cout << endl;
        return_2();
    }
    else if (licznik>5)
    {
        cout << "BRAWO! TRAFILES SZOSTKE!!!!! " << endl << "WYGRYWASZ W CHUJ HAJSU!!!" << endl;
        cout << endl;
        return_2();
    }
    else
    {
        cout << "Niestety nie udalo Ci sie trafic zadnej liczby :(" << endl;
        cout << endl;
        return_2();
    }
}
void return_1()
{
    Sleep(2000);
    cout << "Nacisnij ENTER, aby wybrac ponownie." << endl;
    getchar();
    system("cls");
}
void return_2()
{
    Sleep(2000);
    cout << "Nacisnij ENTER, aby powrocic do menu" << endl;
    getchar();
    getchar();
    system("cls");
}
void multilotek()
{
    zakres=80;
    losowane_liczby =20;
    cout << "WITAJ W GRZE MULTI MULTI. WYTYPUJ MAX 10 LICZB." << endl;
    cout << "______________________________" << endl;
    for (int i=1; i<=1; i++)
    {
        cout << "PODAJ ILE LICZB CHCESZ SKRESLIC: " << endl;
        cin>>liczba_skreslen;
        if (cin.good())
        {
            if (liczba_skreslen < 1 || liczba_skreslen>10)
            {
                cout << "Podaj poprawna skreslen. Mozesz skreslic maksymalnie 10 liczb!" << endl;
                i--;
            }
        }
        else
        {
            Sleep(1000);
            cout << "Wpisales niepoprawny znak!" << std::endl;
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            i--;
        }
    }
    cout << "SKRESL "<<liczba_skreslen<<" LICZB Z ZAKRESU 1..80" << endl;
    cout << "______________________________" << endl;

    skreslanie_i_losowanie_liczb();

    if ((licznik == 1)&&(liczba_skreslen==1))
    {
        cout << "Udalo Ci sie trafic " << licznik << " liczbe :)" << endl;
        cout <<"Wygrywasz 4 zl!"<<endl;
        cout << endl;
        return_2();
    }
    else if ((licznik == 2)&&(liczba_skreslen==2||liczba_skreslen==3||liczba_skreslen==4))
    {
        cout << "Udalo Ci sie trafic dwojke:)" << endl;
        if (liczba_skreslen==2)
        {
            cout<<"Wygrywasz 16zl!"<<endl;
        }
        else if (liczba_skreslen==3)
        {
            cout<<"Wygrywasz 2zl"<<endl;
        }
        else if (liczba_skreslen==4)
        {
            cout<<"Wygrywasz 2zl"<<endl;
        }
        cout << endl;
        return_2();
    }
    else if ((licznik > 2) && (licznik<6))
    {
        cout << "BRAWO! Udalo Ci sie trafic " << licznik << " liczby! WYGRYWASZ HAJS :)" << endl;
        cout << endl;
        return_2();
    }
    else if (licznik>5)
    {
        cout << "BRAWO! TRAFILES SZOSTKE!!!!! " << endl << "WYGRYWASZ W CHUJ HAJSU!!!" << endl;
        cout << endl;
        return_2();
    }
    else
    {
        cout << "Niestety nie udalo Ci sie nic wygrac :(" << endl;
        cout << endl;
        return_2();
    }
}
