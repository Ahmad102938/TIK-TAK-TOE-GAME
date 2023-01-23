#include<iostream>

using namespace std;

char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char current_marker;
int current_player;
int row;
int column;
void boardstructure() {     
// making TTT board structure;

      cout<<"    |    |    \n";
      cout<<" "<<space[0][0]<<"  |  "<<space[0][1]<<" |  "<<space[0][2]<<"    \n";
      cout<<"____|____|____\n";
      cout<<"    |    |    \n";
      cout<<" "<<space[1][0]<<"  |  "<<space[1][1]<<" |  "<<space[1][2]<<"    \n";
      cout<<"____|____|____\n";
      cout<<"    |    |    \n";
      cout<<" "<<space[2][0]<<"  |  "<<space[2][1]<<" |  "<<space[2][2]<<"    \n";
      cout<<"    |    |    \n";
}

 bool positionidentifier(int digit) {
   

  
    if(digit ==1) {

        row=0;
        column=0;
    }
     if(digit ==2) {

        row=0;
        column=1;
    }
     if(digit ==3) {

        row=0;
        column=2;
    }
     if(digit ==4) {

        row=1;
        column=0;
    }
     if(digit ==5) {

        row=1;
        column=1;
    }
     if(digit ==6) {

        row=1;
        column=2;
    }
     if(digit ==7) {

        row=2;
        column=0;
    }
     if(digit ==8) {

        row=2;
        column=1;
    }
     if(digit ==9) {

        row=2;
        column=2;
     }

    if(space[row][column]!='X' && space[row][column]!='O') 
    {
    space[row][column] = current_marker;
    return true;
    
    } 
   else return false;
}

int winner()
{
    for(int i=0; i<3; i++)
    {
        
        if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]) return current_player;

        if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][2]==space[2][0]) return current_player;
    }
    return 0;
}

void swap_player_and_marker()
{
  if(current_marker=='X') current_marker='O';
  else current_marker='X';

  if(current_player==1) current_player= 2;
  else current_player=1;
}

void game()
{
    cout<<"PLAYER 1 CHOOSE YOUR MARKER\n";
    char marker_p1;
    cin>>marker_p1;

    current_player= 1;
    current_marker= marker_p1;

    boardstructure();

    int player_won;

    for(int i =0; i<9; i++)
    {
        cout<<"it's player"<<current_player<<"'s turn enter your digit :";
         int digit;
         cin>>digit;

        if(digit<1 || digit>9)
        {
            cout<<"THIS IS INVALID POSITION, ENTER ANOHER POSITION";
            i--;
            continue;
        }

        if( !positionidentifier(digit)) 
        {
            cout<<"THIS POSITION IS FILLED, TRY ANOTHER POSITION\n";
            i--;
            continue;
        }

         boardstructure();

         player_won = winner();

         if(player_won==1){cout<<"player one won the game"; break;}
         if(player_won==2){cout<<"player two won the game"; break;}


         swap_player_and_marker();

        
    }
    if(player_won==0) cout<<"that was a tie game";
}

int main() {

    game();

}