#include "Calculator.hpp"
#include <iostream>

Calculator::Calculator() {
    currentValue = 0;
    storedValue = 0;
    pendingOp = 0;
    startNewNumber = true;
    decimalPlace = 0;
}

void Calculator::inputDigit(int digit) {
    if (startNewNumber) {
        currentValue = 0;
        decimalPlace = 0;
        startNewNumber = false;
    }

    if (decimalPlace > 0) {
        currentValue += digit / decimalPlace;
        decimalPlace *= 10;
    } else {
        currentValue = currentValue * 10 + digit;
    }
}

void Calculator::inputDecimal() {
    if (startNewNumber) {
        currentValue = 0;
        startNewNumber = false;
    }
    if (decimalPlace == 0) {
        decimalPlace = 10;
    }
}

void Calculator::negate() {
    currentValue = -currentValue;
}

void Calculator::setOperation(char op) {
    // If there's already a pending op, chain the computation (e.g. 2 + 3 + 4)
    if (pendingOp != 0 && !startNewNumber) {
        compute();
    } else {
        storedValue = currentValue;
    }
    pendingOp = op;
    startNewNumber = true;
}

double Calculator::compute() {
    switch (pendingOp) {
        case '+': currentValue = storedValue + currentValue; break;
        case '-': currentValue = storedValue - currentValue; break;
        case '*': currentValue = storedValue * currentValue; break;
        case '/':
            if (currentValue != 0) {
                currentValue = storedValue / currentValue;
            }
            break;
        default: break; // no pending operation, "=" on a fresh number
    }
    storedValue = currentValue;
    pendingOp = 0;
    startNewNumber = true;
    return currentValue;
}

double Calculator::displayValue() const {
    return currentValue;
}
