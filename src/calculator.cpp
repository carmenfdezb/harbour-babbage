#include "calculator.hpp"
#include "math_parser.hpp"
#include <limits>
#include <cmath>

calculator::calculator(QObject *parent) : QObject(parent) {
    V.insert("pi", std::atan(1.)*4);
}

QString calculator::calculate(QString formula) {
    double res=std::numeric_limits<double>::quiet_NaN();
    try {
        res=P.value(formula, V);
    }
    catch (...) {
    }
    return formula+" = "+QString::number(res);
}
