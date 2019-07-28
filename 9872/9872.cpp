#include <queue>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    vector<priority_queue<string>> a;
    vector<string> que;
    //priority_queue<priority_queue<string>> que;

    for (int i = 0; i < N; i++)
    {
        priority_queue<string> tmp;
        for (int j = 0; j < 3; j++)
        {
            string b;
            cin >> b;
            tmp.push(b);
        }
        string c;
        for (int j = 0; j < 3; j++)
        {
            c += (tmp.top() + "&");
            tmp.pop();
        }
        que.push_back(c);
        //a.push_back(tmp);
        //que.push(tmp);
    }
    sort(que.begin(), que.end());
    int answer = 0;
    /* for (int i = 0; i < que.size(); i++)
        cout << que[i] << endl;*/
    if (que[0] == que[que.size() - 1])
        cout << que.size();
    else
    {
        for (int i = 0; i < que.size(); i++)
        {
            int num = 1;
            for (int j = i + 1; j < que.size(); j++)
            {
                //cout << i << " "<< j << " " << num << endl;
                if (que[i] == que[j])
                    num++;
                else
                {
                    i = j - 1;
                    if (answer < num)
                        answer = num;
                    break;
                }
            }
            //cout << i << " " << num << endl;
        }
        cout << answer;
        /* if(answer == 1) cout << 1;
    else cout << answer+1;*/

        //sort(a.begin(), a.end());

        /* 
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < 3; j++)
        {

             cout << a[i].top() << " ";
            a[i].pop();
        }
        cout << endl;
    }*/
    }

    return 0;
}