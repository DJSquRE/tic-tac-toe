#include<iostream>
using namespace std;
class tictactoe{
      public:
     //FUNCTION FOR WIN AND DRAW
     int windraw(char arr[5][5]){
          int count=0;
          //HORIZONTALWIN
          for(int i=0;i<5;i=i+2){
               int j=0;
               if((arr[i][j]==arr[i][j+2])&&(arr[i][j+2]==arr[i][j+4])){
                    if(arr[i][j]=='X') {return 0;}
                    else{ return 1;}
                    }

          }
          //VERTICAL WIN
          for(int j=0;j<5;j=j+2){
               int i=0;
               if((arr[i][j]==arr[i+2][j])&&(arr[i+2][j]==arr[i+4][j])){
                    if(arr[i][j]=='X') {return 0;}
                    else{ return 1;}
                    }
          }
           //DIAGNOL WIN
          if((arr[0][0]==arr[2][2])&&(arr[2][2]==arr[4][4])){
               if(arr[2][2]=='X'){return 0;}
               else {return 1;}
                    
                    
                 }
          else if((arr[0][4]==arr[2][2])&&(arr[2][2]==arr[4][0])){
               if(arr[2][2]=='X'){return 0;}
               else {return 1;}
                 }
         
         //CODE FOR DRAW
          for(int i=0;i<5;i=i+2){
               for(int j=0;j<5;j=j+2){
                    if((arr[i][j]!='X')&&(arr[i][j]!='O')){
                         count++;
                    }
                    if(count==0){
                         return 2;
                    }
                    else{
                         return 3;
                    }
               }
          }
         
     }

     //Checking the position for PLAYER-1
     void checkX(char arr[5][5],char x){
          int flag=0;
               for(int i=0;i<5;i+=2){
                    for(int j=0;j<5;j+=2){
                         if((x!='X')&&(x!='O')){
                              if(arr[i][j]==x){
                              arr[i][j]='X';
                              flag=1;
                              break;
                                   }}
                         else {flag=0; break;}
                         
               }
               if (flag == 1) {
                break;
            }
               }
               
          if(flag==0){
               cout<<"Enter valid position:";
               cin>>x;
               checkX(arr,x);
          }
     
     }

     //Checking the position for PLAYER-2
     void checkO(char arr[5][5],char x){
          int flag=0;
               for(int i=0;i<5;i+=2){
                    for(int j=0;j<5;j+=2){
                         if((x!='X')&&(x!='O')){
                              if(arr[i][j]==x){
                              arr[i][j]='O';
                              flag=1;
                              break;
                                   }}
                         else {flag=0; break;}
                         
               }
               if (flag == 1) {
                break;
            }
               }
          if(flag==0){
               cout<<"Enter valid position:";
               cin>>x;
               checkO(arr,x);
          }
     }

     //Displaying the tic-tac-toe board
     void board(char arr[5][5]){
          cout<<"-------TICTACTOE-------\n"<<endl;
          for(int i=0;i<5;i++){
               cout<<"      ";
               for(int j=0;j<5;j++){
                    cout<<" "<<arr[i][j];
               }
               cout<<"\n";
               
          }
     }
          //Function for INPUT by PLAYERS
          void input(char arr[5][5]){
               int checker;
               board(arr);
               char x;
               cout<<"PLAYER-1 WILL 'X' AND PLAYER-2 WILL 'O'"<<endl;
               for(int i=0;i<9;i++){
                    if(i%2==0){
                         //Input for PLAYER-1
                         cout<<"PLAYER-1"<<endl;
                         cout<<"Enter position:";
                         cin>>x;
                         checkX(arr,x);
                         system("cls"); 
                         board(arr);
                    }
                    else{
                         //Input for PLAYER-2
                         cout<<"PLAYER-2"<<endl;
                         cout<<"Enter position:";
                         cin>>x;
                         checkO(arr,x);
                         system("cls");
                         board(arr);
                    }
               //Checking RESULT of GAME
               checker=windraw(arr);
               if(checker==0){
                    cout<<"\n!!!PLAYER-1 WON!!!";
                    break;
                    }
               else if(checker==1){
                    cout<<"\n!!!PLAYER-2 WON!!!";
                    break;
               }       
                       
          }
          if(checker==2){
                    cout<<"\n|____GAME DRAW____|";

               } 
          
          
     }
};

int main(){
     //MAIN PROGRAM
     char ttt[5][5]={{'1','|','2','|','3'},
                     {'-','-','-','-','-'},
                     {'4','|','5','|','6'},
                     {'-','-','-','-','-'},
                     {'7','|','8','|','9'}
                     };
     
     tictactoe obj;//created object of class 

     obj.input(ttt);//calling function for input from players
     
    return 0;
}
