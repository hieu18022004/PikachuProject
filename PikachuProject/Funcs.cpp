#include <iostream>
#include <iomanip>
#include <random>
#include <windows.h>
using namespace std;


int randomInt()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(65, 90);
    return distr(gen);
}