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
int RndInputArray(int sizeMax, double A[])
{
    int size = ConsoleInputSizeArray(sizeMax);
    int r1=0, r2=0;
    srand(size);

    for (int i = 0; i < size; i++) {
        r1 = rand();
        r2 = rand();
        A[i] = 100.0 * r1;
        A[i] = A[i] / (1.0 + r2);
        cout << A[i] << "   ";
    }
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

void ConsoleInputDynamicArrayNew(int size, double* &pA)
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

void ConsoleInputVector(int size, vector<double> &A)
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

void WriteArrayTextFile(int n, double *arr, const char *fileName )
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

int ReadArrayTextFile(int n, double* arr, const char* fileName)
{
    int size;
    ifstream fin(fileName);
    if (fin.fail()) return 0;
    fin >> size;
    if (size <= 0) return 0;
    if (size > n) size = n;   
    for (int i = 0; i < n; i++)
       fin>> arr[i];
    fin.close();
    return size;
    
}

void WriteArrayBinFile(int n, double* arr, const char* fileName)
{
    //ios_base
    ofstream bfout(fileName, ios_base::binary);
    if (bfout.fail()) return;
    bfout.write((const char*)&n, sizeof(int));
    std::streamsize  cn = static_cast<std::streamsize>(n) *sizeof(double);
    bfout.write((const char*)arr, cn);
    bfout.close();
}

int ReadArrayBinFile(int n, double* arr, const char* fileName)
{
    int size=0;
    ifstream bfin(fileName, ios_base::binary);
    if (bfin.fail()) return 0;
    bfin.read((char*)&size, sizeof(int));
    if (size <= 0) return 0;
    if (size > n) size = n;
    bfin.read((char*)arr, static_cast<std::streamsize>(size) * sizeof(double));
    bfin.close();
    // ssdhs
    return size;
}

/*int Random(int size, double*& arr)
{
    srand(time(NULL));

    for (int i = 0; i < size; i++) 
    {
        arr[i] = (rand() % size) + 1;
        cout << arr[i];
        cout << " ";
    }
    return 1;
}*/

void ShowMainMenu()
{
    cout << "    1.  Task 1  \n";
    cout << "    2.  Task 2  \n";
    cout << "    3.  Task 3  \n";
    cout << "    0. Exit  \n";
}

void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Local array  \n";
    cout << "    2.  Dynamic array 1 (calloc)\n";
    cout << "    3.  Dynamic array 2  new \n"; 
    cout << "    4.  Dynamic array : vector \n";
    cout << "    0.  Exit \n";
}

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



void Task1()
{
    cout << "			Ex_1			" << endl;
    double* A;
    int tmp;
    do
    {
        MenuInput();
        cin >> tmp;
        switch (tmp)
        {
        case 1:
        {
            int n = ConsoleInputSizeArray(1000);
            ConsoleInputDynamicArrayNew(n, A);
            double* C = new double[n];

            cout << endl;

            double st2 = 1;
            for (int i = 0; i < n; i++)
            {
                C[i] = A[i] * st2;
                st2 *= 2;
            }

            //	for (int i = 0; i < N; i++)
               //     C[i] = pow(2, i) * A[i];

            cout << endl;
            cout << "Final Result" << endl;
            ConsoleWriteArray(n, C);

            cout << endl;

            delete[] A;
            delete[] C;
            break;
        }
        case 2:
        {
            int n = ConsoleInputSizeArray(1000);
        }
            break;
        case 3:
            break;
        case 4:
            break;

        default:
            cout << "Select options for 1 to 4" << endl;
            cout << "0 - Exit" << endl;
            break;
        }
    } while (tmp != 0);
    
}

void Task2()
{
    cout << "			Ex_2			" << endl;

    int tmp;
    do
    {
        MenuInput();
        cin >> tmp;
        switch (tmp)
        {
        case 1:
        {
            double c, d;

            int n = ConsoleInputSizeArray(1000);

            cout << "Input array A" << endl;
            double* A = new double[n];
            ConsoleInputDynamicArrayNew(n, A);

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

            for (int i = 0; i < n; i++, ptr++)
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
            delete[] A;

            cout << endl;

            /*	for (int i = 0; i < N; i++)
                {
                    if ((int)A[i] % 2 == 0)
                        break;
                    if (c <= A[i] && A[i] <= d)
                    {
                        if (f)
                        {
                            if (max < A[i])
                                max = A[i];
                        }
                        else
                        {
                            max = A[i];
                            f = true;
                        }
                    }
                }
            */
            break;
        }
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

        default:
            cout << "Select task for 1 to 4" << endl;
            cout << "0 - Exit" << endl;
            break;
        }
    } while (tmp != 0);

    
}

void Task3()
{
    cout << "			Ex_3			" << endl;

    int tmp;
    do
    {
        MenuInput();
        cin >> tmp;
        switch (tmp)
        {
        case 1:
        {
            double Sum = 0, Dob = 1;
            bool f = false;
            int n = ConsoleInputSizeArray(500);

            cout << "Input array A" << endl;
            double* A = new double[n];
            ConsoleInputDynamicArrayNew(n, A);

            for (int i = 0; i < n; i++)
            {
                int count = 0;
                for (int j = 0; j < n; j++)
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

            delete[] A;
            break;
        }
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;

        default:
            cout << "Select task for 1 to 4" << endl;
            cout << "0 - Exit" << endl;
            break;
        }
    } while (tmp != 0);

    
}

int main()
{ 
    const int MAX_SIZE = 560;
    int task;
    do
    {
        ShowMainMenu();
        cin >> task;
        switch (task)
        {
        case 1:
            Task1();
            break;
        case 2:
            Task2();
            break;
        case 3:
            Task3();
            break;

        default:
            cout << "Select task for 1 to 3" << endl;
            cout << "0 - Exit" << endl;
            break;
        }
    } while (task != 0);

    
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
    return 1;

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
