#include "calc.h"
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int loop = true;
    while (loop)
    {
        std::cout << "Enter 0 to exit program\n";
        std::cout << "Enter calculate expresssion:\n";

        std::string expr;
        std::cin >> expr;


        if (std::stoi(expr) == 0 && expr.size() == 1)
            break;
        else
        {
            std::vector <std::string> opers = { "/", "*", "+", "-" };

            for (auto& oper : opers)
            {
                if (auto pos = expr.find(oper); pos != std::string::npos)
                {
                    int oper_index = 0;
                    // определение соответствия операции его индекса
                    if (oper == "+")
                        oper_index = 0;
                    else if (oper == "-")
                        oper_index = 1;
                    else if (oper == "/")
                        oper_index = 2;
                    else if (oper == "*")
                        oper_index = 3;

                    auto a = expr.substr(0, pos);
                    auto b = expr.substr(pos + 1, expr.size());

                    if (a.empty() || b.empty())
                        break;

                    int err = -1;
                    auto result = DoIt(oper_index, 
                        a.find(".") == std::string::npos ? std::stoi(a) : std::stod(a),
                        b.find(".") == std::string::npos ? std::stoi(b) : std::stod(b), 
                        err);

                    if (err == -1)
                        std::cout << "something wrong" << std::endl;
                    else
                        std::cout << result << std::endl;

                    break;
                }
            }
        }
    }
    return 0;
}
