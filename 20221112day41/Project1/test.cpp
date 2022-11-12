
////NowCoder最近爱上了五子棋，现在给你一个棋局，请你帮忙判断其中有没有五子连珠（超过五颗也算）。
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//    string board[20];
//    while (cin >> board[0])
//    {
//        for (int i = 1;i < 20;i++)
//        {
//            cin >> board[i];
//        }
//        int set = 0;
//        for (int i = 0;i < 20;i++)
//        {
//            for (int j = 0;j < 20;j++)
//            {
//                if (board[i][j] == '*' || board[i][j] == '+')
//                {
//                    //横向
//                    if (i <= 15 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j])
//                    {
//                        set = 1;
//                        break;
//                    }
//                    //右下
//                    else if (i <= 15 && j <= 15 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4])
//                    {
//                        set = 1;
//                        break;
//                    }
//                    //纵向
//                    else if (j <= 15 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4])
//                    {
//                        set = 1;
//                        break;
//                    }
//                    //左下
//                    else if (i >= 4 && j <= 15 && board[i][j] == board[i - 1][j + 1] && board[i][j] == board[i - 2][j + 2] && board[i][j] == board[i - 3][j + 3] && board[i][j] == board[i - 4][j + 4])
//                    {
//                        set = 1;
//                        break;
//                    }
//                }
//            }
//            if (set == 1)
//            {
//                cout << "Yes" << endl;
//                break;
//            }
//        }
//        if (set == 0)
//        {
//            cout << "No" << endl;
//        }
//    }
//    return 0;
//}


//Emacs号称神的编辑器，它自带了一个计算器。与其他计算器不同，它是基于后缀表达式的，即运算符在操作数的后面。例如“2 3 +”等价于中缀表达式的“2 + 3”。
//请你实现一个后缀表达式的计算器。
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<string> Emacs(n);
        for (int i = 0;i < n;i++)
        {
            cin >> Emacs[i];
        }
        vector<int> Heap(n, 0);
        int head = 0;
        for (int i = 0;i < n;i++)
        {
            if (Emacs[i][0] >= '0' && Emacs[i][0] <= '9')
            {
                for (int j = 0;j < Emacs[i].length();j++)
                {
                    Heap[head] = Heap[head] * 10 + (Emacs[i][j] - '0');
                }
                head++;
            }
            else if (Emacs[i][0] == '+')
            {
                Heap[head - 2] = Heap[head - 2] + Heap[head - 1];
                head--;
                Heap[head] = 0;
            }
            else if (Emacs[i][0] == '-')
            {
                Heap[head - 2] = Heap[head - 2] - Heap[head - 1];
                head--;
                Heap[head] = 0;
            }
            else if (Emacs[i][0] == '*')
            {
                Heap[head - 2] = Heap[head - 2] * Heap[head - 1];
                head--;
                Heap[head] = 0;
            }
            else if (Emacs[i][0] == '/')
            {
                Heap[head - 2] = Heap[head - 2] / Heap[head - 1];
                head--;
                Heap[head] = 0;
            }
        }
        cout << Heap[0] << endl;
    }
}