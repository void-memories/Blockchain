#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H
#include <vector>
#include <map>
#include <string>
#include "dehash.h"

class Exceptions{
    int errorNo;
    string errorMessage;

    public:
    void Exception(int no);
};
#endif