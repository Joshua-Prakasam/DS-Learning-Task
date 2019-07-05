/* Calculating Simple expression */
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;
// 48 for '0'
int main()
{
    
    stack<int> num;
    string expression;
    
    cout<<"Enter simple expression without operator precedence and parenthesis(also no spaces):"<<endl;
    getline(cin, expression);
    
    for(int i = 0; expression[i] != 0; i++)
    {
        if(num.size() == 0 && (expression[i]>=48 && expression[i]<=57))
        {
            num.push(expression[i] - 48);
        }
        else{
            if(expression[i] == '+' || expression[i] == '-' || expression[i] == '/' ||
                expression[i] == '*' || expression[i] == '%')
            {
                int j = i+1;
                char symbol = expression[i];
                if(expression[j] != 0)
                {
                    while( (expression[j] >= 48 && expression[j] <= 57) && (expression[j] != '+' ||
                            expression[j] != '-' || expression[j] != '/' || expression[j] != '*' ||
                            expression[j] != '%') && expression[j] != 0)
                    {
                        if(j == i+1)
                        {
                            num.push(expression[j] - 48);
                        }
                        else
                        {
                            num.top() = num.top() * 10 + (expression[j] - 48);
                        }
                        j++;
                    }
                    i = j-1;
                    if( num.size() > 1 ){
                        int num1, num2, res;
                        num2 = num.top();
                        num.pop();
                        num1 = num.top();
                        num.pop();
                        switch(symbol){
                            case '+': res = num1 + num2; break;
                            case '-': res = num1 - num2; break;
                            case '/': res = num1 / num2; break;
                            case '*': res = num1 * num2; break;
                            case '%': res = num1 % num2; break;
                        }
                    num.push(res);
                    }
                }
                else
                {
                    cout<<"Invalid Expression";
                    return 0;
                }
            }
            else if( expression[i] >= 48 && expression[i] <= 57){
                num.top() = num.top() * 10 + (expression[i]-48);
            }
        }
    }
    
    cout<<num.top();
    
    return 0;
}
