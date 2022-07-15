using System;
using System.Collections.Generic;

namespace Task_2
{
    class Program
    {
        static int Main(string[] args)
        {
            Console.OutputEncoding = System.Text.Encoding.Unicode;
            Console.InputEncoding = System.Text.Encoding.Unicode;
            Stack<double> stack = new Stack<double>();
            double temp = 0, check;
            string expression;
            Console.Write("Введіть вираз (використовуючи зворотну польську запис): "); expression = Console.ReadLine();
            for (int i = 0; i < expression.Length; i++)
            {
                if (operators(expression[i]))
                {
                    double b = stack.Pop();
                    double a = stack.Pop();
                    switch (expression[i])
                    {
                        case '+':
                            stack.Push(a + b);
                            break;
                        case '-':
                            stack.Push(a - b);
                            break;
                        case '*':
                            stack.Push(a * b);
                            break;
                        case '/':
                            stack.Push(a / b);
                            break;
                        case '^':
                            stack.Push(Math.Pow(a, b));
                            break;
                    }
                    if (i != expression.Length - 1)
                        i++;
                }
                else if (expression[i] == 's')
                {
                    sqrt(expression, i);
                    double a = stack.Pop();
                    stack.Push(Math.Sqrt(a));
                    if (i != expression.Length - 1)
                        i += 3;
                }
                else
                {
                    string value = null;
                    while (!space(expression[i]) && (!operators(expression[i]) || !sqrt(expression, i)) && (expression[i] != '(' || expression[i] != ')'))
                    {
                        value += expression[i];
                        i++;
                        if (i == expression.Length) break;
                    }
                    if (double.TryParse(value, out check) == true)
                        stack.Push(double.Parse(value));
                }
            }
            Console.WriteLine($"Результат: {stack.Peek()}");
            return 0;
        }
        public static bool operators(char a)
        {
            string oprs = "+-*/^";
            for (int i = 0; i < oprs.Length; i++)
                if (a == oprs[i])
                    return true;
            return false;
        }
        public static bool sqrt(string arr, int a)
        {
            if (arr[a + 1] == 'q' && arr[a + 2] == 'r' && arr[a + 3] == 't')
                return true;
            return false;
        }
        public static bool space(char a)
        {
            if (a == ' ')
                return true;
            return false;
        }
    }
}
