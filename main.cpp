#include <iostream>  // ���������� �����-������
#include <clocale>  // ���������� ����������� �������


using namespace std;


int main()
{
    
    setlocale(LC_ALL, "Russian");  // ����������� �������
    unsigned long int temp;
    cout << "������� �����: "; cin >> temp;
    const int N = temp;
    int count = 1;
    temp = N;
    while (temp /= 10) {  
        count++;  // ���� ���������� ���� � ����� (���������� ��������� �������)
    }

    int *p = new int[count];  // �������� ������������� ������� �� count ���������

    int i = 0;
    temp = N;
    while (temp) {
        p[i++] = temp % 10;  // ���������� �������
        temp /= 10;
    }


    int count_nech = 0, 
    count_ch = 0, 
    s_ch = 0, 
    pr = 1, 
    pr_nech = 1,
    num,
    sumfir = 0,
    sumsec = 0;


    cout << "\n �������� �����:" <<
            "\n 1: ������������;" << 
            "\n 2: ���������� ����;" <<
            "\n 3: ����� ���� � �������� �������;" <<
            "\n 4: ������� ���������� ������ � ��������;" <<
            "\n 5: ����� ���� � ������� �������� �������;" <<
            "\n 6: ������������ ���� � ��������� �������� �������." << 
            "\n 7: ����� ���� ������ � ������ �������� �����" << endl;  /* ���������� ���� */
    cout << "�����: "; cin >> num;


    switch(num)
    {

        case 1: for (int i = 0; i < count; i++) {
                    pr *= p[i];  // ������������ ����
                }   
                    cout << "\n" << pr; 
                break; 

        case 2: cout << "\n" << count; break;  // ����� ���������� ���� � �����
        case 3: for (int i = 0; i < count; i++){  // ����� ������� � �������� �������
                    cout << p[i] << ' ';
                }
                break;  

        case 4: for (int i = 0; i < count; i++) {  // ���� ���������� ������ � ��������
                    if (p[i] % 2 == 0) {
                        count_ch++;
                    }else {
                        count_nech++;
                    }
                }
                cout << "������: " << count_ch << endl;
                cout << "��������: " << count_nech << endl; 
                break;

        case 5: for(int i = count - 2; i >= 0; i-=2) {  // ����� �� ������ ������� ������� 
                    s_ch += p[i];
                }
                cout << s_ch;
                break;

        case 6: for(int i = count - 1; i >= 0; i-=2){  // ������������ �� ��������� ������� �������                     
                    pr_nech *= p[i];                      
                }
                cout << pr_nech;
                break;

        case 7: if (count % 2 == 0) {  // ���� ����� ���� ������ � ������ �������� �����
                    for (int i = count - 1; i >= 0; --i) {
                        if (i < count/2){
                            // cout << p[i] << ' ';
                            sumsec += p[i];
                        } else {
                            // cout << p[i] << ' ';
                            sumfir += p[i];
                            }
                    }
                    cout << "����� ������ �������� ����: " << sumfir << endl;
                    cout << "����� ������ �������� ����: " << sumsec;
                } else {
                    cout << "����� �� ������� �� ��������";
                }   
                break;

    }

    delete[] p;  // ������������� ������ �� ��� �������


    return 0;

}