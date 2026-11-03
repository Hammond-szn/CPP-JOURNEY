// .mm extension = Objective-C++. This file is the only place
// Objective-C and C++ are allowed to mix.
#import "CalculatorWrapper.h"
#include "Calculator.hpp"

@implementation CalculatorWrapper {
    Calculator _engine; // the actual C++ object lives here
}

- (void)clear {
    _engine.clear();
}

- (void)inputDigit:(NSInteger)digit {
    _engine.inputDigit((int)digit);
}

- (void)inputDecimal {
    _engine.inputDecimal();
}

- (void)negate {
    _engine.negate();
}

- (void)setOperation:(NSString *)op {
    if (op.length == 0) return;
    char c = [op UTF8String][0];
    _engine.setOperation(c);
}

- (double)compute {
    return _engine.compute();
}

- (double)displayValue {
    return _engine.displayValue();
}

@end
