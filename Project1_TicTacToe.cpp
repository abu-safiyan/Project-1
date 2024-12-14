#include<iostream>
using namespace std;
void draw_table(char a[][3]) {
    for(int i=0; i<3; i++) {
        cout<<"-------------\n| ";
        for(int j=0; j<3; j++) {
            cout<<a[i][j]<<" | ";
        }
        cout<<endl;
    }
    cout<<"-------------"<<endl;
}
void choose(int &row, int &col) {
    do{   
        cout<<"Enter row number (1-3): ";
        cin>>row;
        if(row<1 || row>3) {
            cout<<"Invalid choice, select 1 to 3...\n";
        }
    }while(row<1 || row>3);
    do{   
        cout<<"Enter column number (1-3): ";
        cin>>col;
        if(col<1 || col>3) {
            cout<<"Invalid choice, select 1 to 3...\n";
        }
    }while(col<1 || col>3);
}
void check(char a[][3], char c, int &w) {
    for(int i=0; i<3; i++) {
        if(a[i][0]==c && a[i][1]==c && a[i][2]==c) {
            w=1;
            return;
        }
        if(a[0][i]==c && a[1][i]==c && a[2][i]==c) {
            w=1;
            return;
        }
    }
    if(a[0][0]==c && a[1][1]==c && a[2][2]==c) {
        w=1;
        return;
    }
    if(a[0][2]==c && a[1][1]==c && a[2][0]==c) {
        w=1;
        return;
    }
}
int main() {
    cout<<"Tic Tac Toe"<<endl;
    char arr[3][3]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int a, b, win=0;
    char ch='O';
    draw_table(arr);
    for(int i=1; i<10; i++) {
        choose(a, b);
        while(true) {
            if(arr[a-1][b-1]==' ') {
                arr[a-1][b-1]=ch;
                break;
            }
            else {
                cout<<"Invalid choice, select empty box.\n";
                choose(a, b);
            }
        }
        draw_table(arr);
        check(arr, ch, win);
        if(win==1) {
            cout<<"Congratulations, Player '"<<ch<<"' has won.";
            break;
        }
        if(ch=='O') {
            ch='X';
        }
        else {
            ch='O';
        }
    }
    if(win==0) {
        cout<<"The match has tied.\n";
    }

    return 0;
}