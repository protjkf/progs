#include <iostream>  // библиотека ввода-вывода
#include <clocale>  // библиотека локализации консоли


using namespace std;


int main()
{
    
    setlocale(LC_ALL, "Russian");  // локализация консоли
    unsigned long int temp;
    cout << "введите число: "; cin >> temp;
    const int N = temp;
    int count = 1;
    temp = N;
    while (temp /= 10) {  
        count++;  // счет количества цифр в числе (количество элементов массива)
    }

    int *p = new int[count];  // создание динамического массива из count элементов

    int i = 0;
    temp = N;
    while (temp) {
        p[i++] = temp % 10;  // наполнение массива
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


    cout << "\n выберите пункт:" <<
            "\n 1: произведение;" << 
            "\n 2: количество цифр;" <<
            "\n 3: вывод цифр в обратном порядке;" <<
            "\n 4: Подсчет количества четных и нечетных;" <<
            "\n 5: сумма цифр с четными номерами позиций;" <<
            "\n 6: произведение цифр с нечетными номерами позиций." << 
            "\n 7: сумма цифр первой и второй половины числа" << endl;  /* консольное меню */
    cout << "пункт: "; cin >> num;


    switch(num)
    {

        case 1: for (int i = 0; i < count; i++) {
                    pr *= p[i];  // произведение цифр
                }   
                    cout << "\n" << pr; 
                break; 

        case 2: cout << "\n" << count; break;  // вывод количетсва цифр в числе
        case 3: for (int i = 0; i < count; i++){  // вывод массива в обратном порядке
                    cout << p[i] << ' ';
                }
                break;  

        case 4: for (int i = 0; i < count; i++) {  // счет количества четных и нечетных
                    if (p[i] % 2 == 0) {
                        count_ch++;
                    }else {
                        count_nech++;
                    }
                }
                cout << "четных: " << count_ch << endl;
                cout << "нечетных: " << count_nech << endl; 
                break;

        case 5: for(int i = count - 2; i >= 0; i-=2) {  // сумма по четным номерам позиции 
                    s_ch += p[i];
                }
                cout << s_ch;
                break;

        case 6: for(int i = count - 1; i >= 0; i-=2){  // произведение по нечентным номерам позицци                     
                    pr_nech *= p[i];                      
                }
                cout << pr_nech;
                break;

        case 7: if (count % 2 == 0) {  // счет суммы цифр первой и второй половины числа
                    for (int i = count - 1; i >= 0; --i) {
                        if (i < count/2){
                            // cout << p[i] << ' ';
                            sumsec += p[i];
                        } else {
                            // cout << p[i] << ' ';
                            sumfir += p[i];
                            }
                    }
                    cout << "сумма первой половины цифр: " << sumfir << endl;
                    cout << "сумма второй половины цифр: " << sumsec;
                } else {
                    cout << "число не делится на половины";
                }   
                break;

    }

    delete[] p;  // высвобождение памяти из под массива


    return 0;

}