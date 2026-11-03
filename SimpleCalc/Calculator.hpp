#pragma once

// Pure C++ calculator engine — no Apple/Swift dependencies at all.
// This is the "brain." The rest of the project just puts a face on it.
class Calculator {
public:
    Calculator();

    void clear();
    void inputDigit(int digit);
    void inputDecimal();
    void negate();

    // op should be one of '+', '-', '*', '/'
    void setOperation(char op);

    // Evaluates any pending operation and returns the result.
    // Also called when the user presses "="
    double compute();

    double displayValue() const;

private:
    double currentValue;
    double storedValue;
    char pendingOp;
    bool startNewNumber;
    double decimalPlace; // 0 = not entering decimals yet
};
