#ifndef Q3_H
#define Q3_H

int getCalcOperator();
double getOperand();
double calculate(const double firstOperand, const int calcOperator, const double secondOperand);
bool validateOperator(int calcOperator); //figures outif user input was valid

#endif
