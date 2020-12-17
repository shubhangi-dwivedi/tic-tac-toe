#include<iostream>

using namespace std;

char pannel[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char curr_marker;
int curr_player;

void create_pannel();


int main()
{
    game();

    return 0;
}

void create_pannel()
{
    cout<<"------------\n";
    cout<<"| "<<pannel[0][0]<<" | "<<pannel[0][1]<<" | "<<pannel[0][2]<<" | " <<endl;
    cout<<"------------\n";
    cout<<"| "<<pannel[1][0]<<" | "<<pannel[1][1]<<" | "<<pannel[1][2]<<" | "<<endl;
    cout<<"------------\n";
    cout<<"| "<<pannel[2][0]<<" | "<<pannel[2][1]<<" | "<<pannel[2][2]<<" | "<<endl;
    cout<<"------------\n";

}

bool put_marker(int slot)
{
    int col, row=slot/3;

    if(slot%3==0)
    {
        row=row-1;
        col=2;
    }

    else
    {
        col=slot%3 - 1;
    }

    if (pannel[row][col]!='x' && pannel[row][col]!='o')
    {
        pannel[row][col]=curr_marker;
        return true;
    }
    else
    {
        return false;
    }
}

int winner_is()
{
    for(int i=0;i<3;i++)
    {
        //row
        if(pannel[i][0]==pannel[i][1] && pannel[i][1]==pannel[i][2])
        {
            return curr_player;
        }

        //columns
        if(pannel[0][i]==pannel[1][i] && pannel[1][i]==pannel[2][i])
        {
            return curr_player;
        }
    }

    //diagonal 1
    if(pannel[0][0]==pannel[1][1] && pannel[1][1]==pannel[2][2])
    {
        return curr_player;
    }

    //diagonal 2
    if(pannel[0][2]==pannel[1][1] && pannel[1][1]==pannel[2][0])
    {
        return curr_player;
    }

    return 0;
}

void swap_player_and_marker()
{
    if(curr_marker=='x')
    {
        curr_marker='o';
    }
    else
    {
        curr_marker='x';
    }

    if(curr_player==1)
    {
        curr_player=2;
    }
    else
    {
        curr_player=1;
    }

}

void game()
{

    int winner;
    cout<<"Player 1, please choose your marker : ";
    char p1_marker;
    cin>>p1_marker;

    curr_player=1;
    curr_marker=p1_marker;

    create_pannel();

    for(int i=0; i<9; i++)
    {
        cout<<"PLAYER "<<curr_player<<"'s turn.\n Enter your slot : ";
        int slot;
        cin>>slot;

        if(slot<1 || slot>9)
        {
            cout<<"Invalid slot no.! Enter value of slot in the range of 1 to 9";
            i--;
            continue;
        }

        if(!put_marker(slot))
        {
            cout<<"The slot is already occupied! Enter another value of slot";
            i--;
            continue;
        }

        create_pannel();

        winner=winner_is();
        if(winner==1)
        {
            cout<<"Player 1 won! \n******CONGRATS******";
            break;
        }

        if(winner==2)
        {
            cout<<"Player 2 won! \n******CONGRATS******";
            break;
        }

        swap_player_and_marker();
    }

    if(winner==0)
    {
        cout<<"*****IT'S A TIE*****";
    }
}

