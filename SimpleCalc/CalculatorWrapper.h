#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Swift can see this Objective-C class through the bridging header.
// It can NOT see Calculator.hpp directly — Swift doesn't speak C++.
@interface CalculatorWrapper : NSObject

- (void)clear;
- (void)inputDigit:(NSInteger)digit;
- (void)inputDecimal;
- (void)negate;
- (void)setOperation:(NSString *)op;
- (double)compute;
- (double)displayValue;

@end

NS_ASSUME_NONNULL_END
