//Date: June-29-2022
//Name: Oleksandr Shyryayev
//Description: Mass Converter in C++

#include <iostream>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <stdio.h>
#include <math.h>
#include <string>
using namespace std;

void convertPounds();
void convertKilograms();
void printGodbye();

int main(){
    int input;

    cout << "********************************************************" << endl;
    cout << "*             Oleksandr Shyryayev - 2210888            *" << endl;
    cout << "*                    LaSalle Student                   *" << endl;
    cout << "*           Mass Converter (Version: 0.1.5 BETA)       *" << endl;
    cout << "********************************************************" << endl;

    do{
        cout << " ------------------------------------------------------" << endl;
        cout << "|  '1' -- Pounds(lb) to Kilograms(kg).                 |" << endl;
        cout << "|  '2' -- Kilograms(kg) to Pounds(lb).                 |" << endl;
        cout << "|  '0' -- Exit.                                        |" << endl;
        cout << " ------------------------------------------------------" << endl;
        cout << "   Option: ";

        while(!(cin >> input)){
            cin >> input;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError: Invalid input..." << endl;
            cout << " ------------------------------------------------------" << endl;
            cout << "|  '1' -- Pounds(lb) to Kilograms(kg).                 |" << endl;
            cout << "|  '2' -- Kilograms(kg) to Pounds(lb).                 |" << endl;
            cout << "|  '0' -- Exit.                                        |" << endl;
            cout << " ------------------------------------------------------" << endl;
            cout << "   Option: ";
        }

        switch(input){
        case 1:
            system("cls");
            convertPounds();
            break;
        case 2:
            system("cls");
            convertKilograms();
            break;
        case 0:
            system("cls");
            printGodbye();
            break;
        default:
            cout << "\nError: Invalid option..." << endl << endl;
            break;
        }

    }while (input != 0);

    return 0;
}

void convertPounds(){
    int i = 0 ;
    double arr[15], arr2[15], input = 0, output = 0, maxWeight = 0, maxWeight2 = 0,
    minWeight = 2147483647, minWeight2 = 2147483647, avg = 0, avg2 = 0, sum, sum2,
    numOfConv, intPart, intPart2, intPart3, intPart4, fractPart, fractPart2, fractPart3, fractPart4;

    cout << " ------------------------------------------------------" << endl;
    cout << "|  Pounds(lb) to Kilograms(kg) (0: back to Main Menu). |" << endl;
    cout << " ------------------------------------------------------" << endl;

    do{
        cout << " Insert the weight in Pounds(lb): ";

        while(!(cin >> input)){
            cin >> input;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError: Invalid input..." << endl << endl;
            cout << " Insert the weight in Pounds(lb): ";
        }

        output = input / 2.2046;
        arr[i] = input;
        arr2[i] = output;
        sum += arr[i];
        sum2 += arr2[i];
        maxWeight = max(maxWeight, arr[i]);
        maxWeight2 = max(maxWeight2, arr2[i]);
        i++;
        numOfConv = i;

        if(input <= 0){
            if(i > 1){
                sum -= arr[i-1];
                sum2 -= arr2[i-1];
                break;
            }else{
                minWeight = 0;
                minWeight2 = 0;
                numOfConv = i + 1;
                sum = 0;
                sum2 = 0;
                break;
            }
        }

        minWeight = min(minWeight, arr[i-1]);
        minWeight2 = min(minWeight2, arr2[i-1]);
        fractPart = modf(output, &intPart);
        if (((int) (fractPart * 1000)) == 0){
            cout << input << " lb (" << input * 16 << " oz) = " << intPart << " kg" << endl;
        }else{
            cout << input << " lb (" << input * 16 << " oz) = " << intPart << " kg " << (int) (fractPart * 1000) << " g" << endl;
        }

    }while(input > 0 && i < 15);

    avg = sum / (numOfConv - 1);
    avg2 = sum2 / (numOfConv - 1);
    fractPart2 = modf(avg2, &intPart2);
    if (((int) (fractPart2 * 1000)) != 0){
        cout << " ------------------------------------------------------" << endl;
        cout << "Average of weight(s) entered is: " << avg << " lb (" << avg * 16 << " oz) or " << intPart2 << " kg " << (int) (fractPart2 * 1000) << " g" << endl;
    }else{
        cout << " ------------------------------------------------------" << endl;
        cout << "Average of weight(s) entered is: " << avg << " lb (" << avg * 16 << " oz) or " << intPart2 << " kg" << endl;
    }

    fractPart3 = modf(maxWeight2, &intPart3);
    if (((int) (fractPart3 * 1000)) != 0){
        cout << "Maximum of weight(s) entered is: " << maxWeight << " lb (" << maxWeight * 16 << " oz) or " << intPart3 << " kg " << (int) (fractPart3 * 1000) << " g" << endl;
    }else{
        cout << "Maximum of weight(s) entered is: " << maxWeight << " lb (" << maxWeight * 16 << " oz) or " << intPart3 << " kg" << endl;
    }

    fractPart4 = modf(minWeight2, &intPart4);
    if (((int) (fractPart4 * 1000)) != 0){
        cout << "Minimum of weight(s) entered is: " << minWeight << " lb (" << minWeight *16 << " oz) or " << intPart4 << " kg " << (int) (fractPart4 * 1000) << " g" << endl;
        cout << " ------------------------------------------------------" << endl << endl;
    }else{
        cout << "Minimum of weight(s) entered is: " << minWeight << " lb (" << minWeight *16 << " oz) or " << intPart4 << " kg" << endl;
        cout << " ------------------------------------------------------" << endl << endl;
    }
}

void convertKilograms(){
    int i = 0 ;
    double arr[15], arr2[15], input = 0, output = 0, maxWeight = 0, maxWeight2 = 0,
    minWeight = 2147483647, minWeight2 = 2147483647, avg = 0, avg2 = 0, sum, sum2,
    numOfConv, intPart, intPart2, intPart3, intPart4, fractPart, fractPart2, fractPart3, fractPart4;

    cout << " ------------------------------------------------------" << endl;
    cout << "|  Kilograms(kg) to Pounds(lb) (0: back to Main Menu). |" << endl;
    cout << " ------------------------------------------------------" << endl;

    do{
        cout << " Insert the weight in Kilograms(lb): ";

        while(!(cin >> input)){
            cin >> input;
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "\nError: Invalid input..." << endl << endl;
            cout << " Insert the weight in Kilograms(lb): ";
        }

        output = input / 0.45359237;
        arr[i] = input;
        arr2[i] = output;
        sum += arr[i];
        sum2 += arr2[i];
        maxWeight = max(maxWeight, arr[i]);
        maxWeight2 = max(maxWeight2, arr2[i]);
        i++;
        numOfConv = i;

        if(input <= 0){
            if(i > 1){
                sum -= arr[i-1];
                sum2 -= arr2[i-1];
                break;
            }else{
                minWeight = 0;
                numOfConv = i + 1;
                sum = 0;
                sum2 = 0;
                break;
            }
        }

        minWeight = min(minWeight, arr[i-1]);
        minWeight2 = min(minWeight2, arr2[i-1]);
        fractPart = modf(input, &intPart);
        if (((int) (fractPart * 1000)) != 0){
            cout << intPart << " kg " << (int) (fractPart * 1000) << " g = " << output << " lb (" << output * 16 << " oz)" << endl;
        }else{
            cout << intPart << " kg = " << output << " lb (" << output * 16 << " oz)" << endl;
        }

    }while(input > 0 && i < 15);

    avg = sum / (numOfConv - 1);
    avg2 = sum2 / (numOfConv - 1);
    fractPart2 = modf(avg, &intPart2);
    if (((int) (fractPart2 * 1000)) != 0){
        cout << " ------------------------------------------------------" << endl;
        cout << "Average of weight(s) entered is: " << intPart2 << " kg " << (int) (fractPart2 * 1000) << " g or " << avg2 << " lb (" << avg2 * 16 << " oz)"<< endl;
    }else{
        cout << " ------------------------------------------------------" << endl;
        cout << "Average of weight(s) entered is: " << intPart2 << " kg or " << avg2 << " lb (" << avg2 * 16 << " oz)"<< endl;
    }

    fractPart3 = modf(maxWeight, &intPart3);
    if (((int) (fractPart3 * 1000)) != 0){
        cout << "Maximum of weight(s) entered is: " << intPart3 << " kg " << (int) (fractPart3 * 1000) << " g or " << maxWeight2 << " lb (" << maxWeight2 * 16 << " oz)"<< endl;
    }else{
        cout << "Maximum of weight(s) entered is: " << intPart3 << " kg or " << maxWeight2 << " lb (" << maxWeight2 * 16 << " oz)"<< endl;
    }

    fractPart4 = modf(minWeight, &intPart4);
    if (((int) (fractPart4 * 1000)) != 0){
        cout << "Minimum of weight(s) entered is: " << intPart4 << " kg " << (int) (fractPart4 * 1000) << " g or " << minWeight2 << " lb (" << minWeight2 * 16 << " oz)"<< endl;
        cout << " ------------------------------------------------------" << endl;
    }else{
        cout << "Minimum of weight(s) entered is: " << intPart4 << " kg or " << minWeight2 << " lb (" << minWeight2 * 16 << " oz)"<< endl;
        cout << " ------------------------------------------------------" << endl << endl;
    }
}

void printGodbye(){
    // R1 is taken as 1, since it is only multiplied with terms,
    // we can neglect it in this program.

    // A, B
    float A = 0, B = 0;

    //phi, theta
    float i, j;

    //K1
    int k;

    //z-buffer
    float z[1760];
    char b[1760];
    std::cout << "\x1b[2J";
    while (true){
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.07){
            for (i = 0; i < 6.28; i += 0.02){
                // We will calculate the position and luminance of each point.
                float c = sin(i); // sin(phi)
                float d = cos(j); // cos(theta)
                float e = sin(A); // sin(A)
                float f = sin(j); // sin(theta)
                float g = cos(A); // cos(A)
                float h = d + 2;  // (R2 + R1cos(theta)) //R2 is taken as 2 here
                float D = 1 / (c * h * e + f * g + 5); // 1/(z + K2) //K2 is taken as 5
                float l = cos(i); // cos(phi)
                float m = cos(B); // cos(B)
                float n = sin(B); // sin(B)

                float t = c * h * g - f * e;

                // Calculating x (x' since we are multiplting by D) (K1 is 1)
                int x = 40 + 30 * D * (l * h * m - t * n);

                // Calculating y (y' specifically since we are multiplying by D)
                int y = 12 + 15 * D * (l * h * n + t * m);

                // Varible to store rendered ASCII character in the buffer.
                // We are using a 1D array.
                int o = x + 80 * y;

                // Luminance
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
                {
                    // String D in z-buffer
                    z[o] = D;

                    // Choosing ASCII character based on Luminance and storing it in buffer
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        std::cout << "\x1b[H";
        for (k = 0; k < 1761; k++){
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        //Sleep(10);
        static HANDLE h = NULL;
        if(!h)
            h = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD c = { 0, 1 };
            SetConsoleCursorPosition(h,c);

        cout << "Have a DONUT! Exiting program..." << endl;
    }
}
