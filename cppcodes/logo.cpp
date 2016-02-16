#include<iostream>
using namespace std;

int main()
{
    int floor[20][20]={};
    int pen=0,direction=1;
    int command,steps;
    cout << "Command" << "  " << "Meaning" << endl;
    cout << "1" << "        " << "Pen up" << endl;
    cout << "2" << "        " << "Pen down" << endl;
    cout << "3" << "        " << "Turn right" << endl;
    cout << "4" << "        " << "Turn left" <<endl;
    cout << "5,10" << "        " << "Move forwaord 10 places (for example)" << endl;
    cout << "6" << "        " << "Print the 20-by-20 array" << endl;
    cout << "9" << "        " << "End of data" << endl;
    cout << "The turtle starts at (0,0)" << endl;
    cin >> command;
    int x=0,y=0;
    while(command!=9)
    {
        if(command==1)
            pen=0;
        else if(command==2)
            pen=1;
        else if(command==3)
        {
            if(direction==1)
            {
                direction=4;
            }
            else if(direction==2)
            {
                direction=3;
            }
            else if(direction==3)
            {
                direction=1;
            }
            else if(direction==4)
            {
                direction=2;
            }
        }
        else if(command==4)
        {
            if(direction==1)
            {
                direction=3;
            }
            else if(direction==2)
            {
                direction=4;
            }
            else if(direction==3)
            {
                direction=2;
            }
            else if(direction==4)
            {
                direction=1;
            }
        }
        else if(command==5)
        {
            cin >> steps;
            if(pen==1)
            {
                if(direction==1)
                {
                    for(int i=x;i<steps+x;i++)
                        floor[y][i]=1;
                    x=x+steps;
                }
                else if(direction==2)
                {
                    for(int i=x;i>=x-steps;i--)
                        floor[y][i]=1;
                    x=x-steps;
                }
                else if(direction==3)
                {
                    for(int i=y;i>=y-steps;i--)
                        floor[i][x]=1;
                    y=y-steps;
                }
                else if(direction==4)
                {
                    for(int i=y;i<y+steps;i++)
                        floor[i][x]=1;
                    y=y+steps;
                }
            }
            if(pen==0)
            {
                if(direction==1)
                {
                    x=x+steps;
                }
                else if(direction==2)
                {
                    x=x-steps;
                }
                else if(direction==3)
                {
                    y=y-steps;
                }
                else if(direction==4)
                {
                    y=y+steps;
                }
            }
        }
        else if(command==6)
        {
            for(int i=0;i<20;i++)
            {
                for(int j=0;j<20;j++)
                {
                    if(floor[i][j]==1)
                        cout << "*";
                    else
                        cout << " ";
                }
                cout << "\n";
            }
        }
        cout << x << " " << y << " " << "Direction: " << direction << endl;
        cin >> command;
    }
    return 0;
}
