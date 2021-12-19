#include <iostream>
#include <cmath>
#include <bitset>

using namespace std;

unsigned int set7thBitTo1(unsigned int x);
void printNumberX(unsigned int x);
unsigned int invert3rdBit(unsigned int x);
unsigned int invertBits(unsigned int x);
unsigned int setBitsToZero(unsigned int x);
unsigned int makeExpression(unsigned int x, unsigned int y, unsigned int p, unsigned int n);

const int SYMBOLS_COUNT = 10;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите число x: ";
    unsigned int x;
    cin >> x;

    cout << "\n1)Установить 7 бит переменной х в 1;" << endl;
    printNumberX(x);
    printNumberX(set7thBitTo1(x));

    cout << "\n2)Инвертировать 3-ий бит переменной х;" << endl;
    printNumberX(x);
    printNumberX(invert3rdBit(x));

    cout << "\n3) инвертировать 3-ий, 5-ый и 7-ой биты переменной х;" << endl;
    printNumberX(x);
    printNumberX(invertBits(x));

    cout << "\n4) установить 5 и 3 биты в значения переменной х в 0;" << endl;
    printNumberX(x);
    printNumberX(setBitsToZero(x));

    cout << "\n5) Даны два целых положительных числа Х и Y одной разрядности." <<
        "Написать выражение, которое формирует новое значение Х, где n битов, начиная с позиции р," <<
        "установлены так, как n самых правых битов в Y, а остальные биты не изменились." << endl;
    cout << "Введите числа X и Y одной разряжности: ";
    unsigned int y;
    cin >> x >> y;
    printNumberX(x);
    printNumberX(y);

    cout << "Введите p - с какой позиции начать, n - сколько битов: ";
    unsigned int p, n;
    cin >> p >> n;
    printNumberX(makeExpression(x, y, p, n));
}

unsigned int set7thBitTo1(unsigned int x) {
    unsigned int level = pow(2, 7 - 1);
    return x | level;
}

unsigned int invert3rdBit(unsigned int x) {
    unsigned int level = pow(2, 3 - 1);
    return x ^ level;
}

unsigned int invertBits(unsigned int x) {
    return x ^ ((1 << 3 - 1) | (1 << 5 - 1) | (1 << 7 - 1));
}

unsigned int setBitsToZero(unsigned int x) {
    return x & (~((1 << 3 - 1) | (1 << 5 - 1)));
}

unsigned int makeExpression(unsigned int x, unsigned int y, unsigned int p, unsigned int n) {
    //Getting first and second part of X
    unsigned int xFirstPart = (x >> p);
    unsigned int onesForX = pow(2, p) - 1;
    unsigned int xSecondPart = x & onesForX;
       
    //Getting specific part of y
    unsigned int onesForY = pow(2, n) - 1;
    unsigned int yPart = y & onesForY;

    unsigned int result;
    result = xFirstPart << n;
    result |= yPart;
    result <<= p;
    result |= xSecondPart;

    return result;
}

void printNumberX(unsigned int x) {
    cout << std::bitset<SYMBOLS_COUNT>(x) << " - " << x << endl;
}


