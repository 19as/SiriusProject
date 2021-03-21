#include "calc.h"
#include "stdexcept"
#include "float.h"

double DoIt(int TypeWork, double OperandA, double OperandB, int& ErrorCode)
{
    // результат вычисления
    double result = std::numeric_limits<double>::quiet_NaN();

    // неподдерживаемый индекс
    if (TypeWork > 3 || TypeWork < 0)
    {
        ErrorCode = 1;
        return result;
    }
    else
    {
        try
        {
            if (TypeWork == 0)
            {
                // сложение
                ErrorCode = 0;
                result = OperandA + OperandB;
            }
            else if (TypeWork == 1)
            {
                // вычитание
                ErrorCode = 0;
                result = OperandA - OperandB;
            }
            else if (TypeWork == 2)
            {
                // деление

                // заведомо ложное условие, т.к. вещественные числа с нулем не сравнимы
                // if ( OperandB == 0.0) { ErrorCode = 2; }

                // попытка сравнения с малым числом, близким к нулю
                if (fabs(OperandB) < DBL_EPSILON)
                {
                    ErrorCode = 2;
                }
                else
                {
                    ErrorCode = 0;
                    result = OperandA / OperandB;
                }
            }
            else if (TypeWork == 3)
            {
                // перемножение
                ErrorCode = 0;
                result = OperandA * OperandB;
            }
        }
        catch (...)
        {
            ErrorCode = 3;
            return result;
        }
    }

    return result;
}
