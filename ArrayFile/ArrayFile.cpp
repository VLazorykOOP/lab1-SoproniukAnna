// ArrayFile.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
#include <cstdlib>

#include <time.h>

using namespace std;

//typedef double* pDouble;

/*
*   ConsoleInputArrayDouble
*/
int ConsoleInputSizeArray(const int sizeMax)
{
    int size = 0;
    do {
        cout << " Input size Array ( 0; " << sizeMax << " ) ";
        cin >> size;
    } while (size <= 0 || size >= sizeMax);
    return size;
}
/*
*   ConsoleInputArrayDouble
*/
int ConsoleInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> A[i];
    }
    return size;
}

/*
*   RndInputArrayDouble
*
*/
int RndInputArray(int size, double A[])
{
    int r1 = 0, r2 = 0;
    srand(size);

    for (int i = 0; i < size; i++) 
    {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
    cout << endl;
    return size;
}

/*int ConsoleInputDynamicArrayNew(int sizeMax, pDouble& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = new double[size];
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}*/

void ConsoleInputDynamicArrayNew(int size, double*& pA)
{
    pA = new double[size];
    for (int i = 0; i < size; i++)
    {
        cout << " Array[ " << i << " ] ";
        cin >> pA[i];
    }
}

int ConsoleInputDynamicArray_calloc(int sizeMax, double*& pA)
{
    int size = ConsoleInputSizeArray(sizeMax);
    pA = (double*)calloc(size, sizeof(double));      // pA = (double*)malloc(size * sizeof(double)); 
    if (pA == nullptr) { return 0; }
    for (int i = 0; i < size; i++) {
        cout << " Array[ " << i << "] "; cin >> pA[i];
    }
    return size;
}

void ConsoleInputVector(int size, vector<double>& A)
{
    //    int size = ConsoleInputSizeArray(sizeMax);
    double d;
    for (int i = 0; i < size; i++)
    {
        cout << " Array[ " << i << "] ";
        cin >> d;
        A.push_back(d);
    }
}

/*void ArrayLocal()
{
    double A[1000], B[500], C[500];
    int n;
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
        switch (ch) {
        case '1': cout << " 1 "; break;
        case '2': cout << " 2 "; break;
            //
        case '5': return;
        }
        cout << " Press any key and enter\n";
        ch = getchar();
    } while (ch != 27);
}*/

/*
* ConsoleWriteArray
*/
void ConsoleWriteArray(int size, double* pA)
{
    for (int i = 0; i < size; i++)
        cout << pA[i] << "\t";
    cout << endl;
}


/*
*  WriteArrayTextFile
*/

void WriteArrayTextFile(int n, double* arr, const char* fileName)
{
    ofstream fout(fileName);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}

/*
*  ReadArrayTextFile
*
*/

void ReadArrayTextFile(int &n, double* &arr, const char* fileName)
{
    ifstream fin(fileName);
    if (fin.fail()) return;
    delete[] arr;
    fin >> n;
    arr = new double[n];
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
}

/*void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) * sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}*/
void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    ofstream fout(fileName, ios_base::binary);
    if (fout.fail()) return;
    fout << n << endl;
    for (int i = 0; i < n; i++)
        fout << arr[i] << "   ";
    fout.close(); //
}

/*void ReadArrayBinFile(int& n, double*& arr, const char* fileName)
{
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return;

    bfin.read((char*)&n, sizeof(int));
    bfin.read((char*)arr, static_cast<std::streamsize>(n) * sizeof(double));
    bfin.close();
}*/
void ReadArrayBinFile(int& n, double*& arr, const char* fileName)
{
    ifstream fin(fileName, ios_base::binary);
    if (fin.fail()) return;
    delete[] arr;
    fin >> n;
    arr = new double[n];
    for (int i = 0; i < n; i++)
        fin >> arr[i];
    fin.close();
}

void ShowMainMenu()
{
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
    cout << "    0. Exit  \n";
}

/*void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 (calloc)\n";
    cout << "    3.  Dynamic array 2  new \n";
    cout << "    4.  Dynamic array : vector \n";
    cout << "    0.  Exit \n";
}*/

void MenuInput()
{
    cout << "     Menu Input   \n";
    cout << "    1.  Console all \n";
    cout << "    2.  Console - size, array - random \n";
    cout << "    3.  File 1.txt \n";
    cout << "    4.  bin    \n";
    cout << "    0.  Exit \n";
}


/*
* Задано одновимірний масив А розміру 2N.
* Побудувати два масиви В і С розміру N,
* включивши  у масив В елементи масиву А з парними індексами,
* а у С - з непарними.
*****************
*  A - in
*  B, C - out
*/
/*void  TestVariant(int N, double* A, double* B, double* C) {
    for (int i = 0; i < N; i++) {
        B[i] = A[2 * i];
        C[i] = A[2 * i + 1];
    }
}*/
/*
*  Task  Var
*
*
*/
/*void TaskV()
{
    char ch = '5';
    do {
        system("cls");
        MenuTask();
        ch = getchar();
        getchar();
            switch (ch) {
             case '1': cout << " 1 "; break;
             case '2': cout << " 2 "; break;
            //
            case '5': return;
            }
        cout << " Press any key and enter\n";
        ch = getchar();
        } while (ch != 27);

}*/


void Task1(int size, double* A, double* &C)
{
    delete[] C;
    C = new double[size];

    double st2 = 1;
    for (int i = 0; i < size; i++)
    {
        C[i] = A[i] * st2;
        st2 *= 2;
    }
}

void Task2(int size, double* A)
{
    double c, d;

    cout << "Input diapason: " << endl;
    do
    {
        cout << "Input c: ";
        cin >> c;
        cout << "Input d: ";
        cin >> d;
    } while (d < c);

    double max = 0;
    bool f = false;

    double* ptr = A;

    for (int i = 0; i < size; i++, ptr++)
    {
        if ((int)(*ptr) % 2 == 0)
            break;
        if (c <= (*ptr) && (*ptr) <= d)
        {
            if (f)
            {
                if (max < (*ptr))
                    max = (*ptr);
            }
            else
            {
                max = (*ptr);
                f = true;
            }
        }
    }
    if (f)
        cout << "max = " << max << endl;
    else
        cout << "No maximum in diaposon" << endl;

}

void Task3(int size, double* A)
{
    double Sum = 0, Dob = 1;
    bool f = false;

    for (int i = 0; i < size; i++)
    {
        int count = 0;
        for (int j = 0; j < size; j++)
            if (A[i] == A[j])
                count++;
        if (count > 1)
            Sum += A[i];
        else
        {
            Dob *= A[i];
            f = true;
        }
    }

    cout << endl;

    cout << "Final Result" << endl;
    cout << "Sum: " << Sum << endl;
    if (f)
        cout << "Multiply: " << Dob << endl;
    else
        cout << "No elements for multiply(" << endl;
    cout << endl;
}

int main()
{
    const int MAX_SIZE = 560;
    double* A = NULL, *C = NULL;
    int n;
    int select;

    do
    {
        MenuInput();
        cin >> select;
        system("cls");
        switch (select)
        {
        case 1:
        {
            n = ConsoleInputSizeArray(MAX_SIZE);
            ConsoleInputDynamicArrayNew(n, A);

            break;
        }
        case 2:
        {
            n = ConsoleInputSizeArray(MAX_SIZE);
            A = new double[n];
            RndInputArray(n, A);
        }
        break;
        case 3:
            ReadArrayTextFile(n, A, "1.txt");
            ConsoleWriteArray(n, A);
            break;
        case 4:
            ReadArrayBinFile(n, A, "1.bin");
            cout << "n = " << n << endl;
            ConsoleWriteArray(n, A);
            break;

        default:
            cout << "Select options for 1 to 4" << endl;
            cout << "0 - Exit" << endl;
            break;
        }
    } while (select != 0);

    do
    {
        ShowMainMenu();
        cin >> select;
        switch (select)
        {
        case 0:
            break;
        case 1:
            Task1(n, A, C);
            cout << endl;
            cout << "Final Result" << endl;
            ConsoleWriteArray(n, C);
            break;
        case 2:
            Task2(n, A);
            break;
        case 3:
            Task3(n, A);
            break;

        default:
            cout << "Select task for 1 to 3" << endl;
            cout << "0 - Exit" << endl;
            break;
        }
    } while (select != 0);

    delete[] A;
    delete[] C;


    /*
    double A[MAX_SIZE], B[MAX_SIZE],C[MAX_SIZE];
    int n,m;
    n = RndInputArray(MAX_SIZE, A);
    WriteArrayTextFile(n, A, "1.txt");
    m = ReadArrayTextFile(MAX_SIZE, B, "1.txt");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++)
        cout << B[i] << "   ";
    WriteArrayBinFile(n, A, "1.bin");
    m = ReadArrayBinFile(MAX_SIZE, C, "1.bin");
    cout << " \n m= " << m << endl;
    for (int i = 0; i < m; i++)
        cout << C[i] << "   ";
    cout << "\n  Vector \n";
    vector<double> vA;
    ConsoleInputVector(MAX_SIZE, vA);
    for (auto v : vA) {
        cout << v << "   ";
    }
*/
//TaskV();
    return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
