#include<iostream>
#include<conio.h>

using namespace std;
const int width = 10;
const int length = 10;
int x = rand()%10;
int y = rand()%10;
int xx = x;
int yy = y-1;
int x1= 3;
int y1 =9;
char plr[100];
int point =0;
bool newFile = false;
bool takeScore = true;

char dp[]="Score.txt";





struct playerData {
    char pl[1000];
    int scr;

};



int lineCount() {
    FILE *f = fopen(dp, "r");
    char us[1000];
    int g;
    int count = 0;
    for (; !feof(f);) {
        fscanf(f, "%s %d", us, &g);
        count++;
        if (feof(f)) {
            break;
        }
    }
    return count;
}
void rankScore() {
    int k = lineCount();
    struct playerData *x;
    x = (struct playerData *)malloc((k)* sizeof(struct playerData));
    FILE *a = fopen(dp, "r+");
    for (int i = 0; i<k; i++) {
        fscanf(a, "%s %d", x[i].pl, &x[i].scr);
    }
    fclose(a);
    char z[1000];
    for (int i = 0; i<k; i++) {
        for (int j = i + 1; j < k; j++) {
            if (x[i].scr < x[j].scr) {
                int temp = x[i].scr;
                x[i].scr = x[j].scr;
                x[j].scr = temp;
                strcpy(z, x[i].pl);
                strcpy(x[i].pl, x[j].pl);
                strcpy(x[j].pl, z);
            }
        }
    }
    FILE *n = fopen(dp, "w+");
    for (int i = 0; i < k - 1; i++) {
        fprintf(n, "%s\t", x[i].pl);
        fprintf(n, "%ld\n", x[i].scr);
    }
    free(x);
    fclose(n);
}

void setHigh(char* player, long int scr) {
    int u;
    long int y;
    char c[1000];
    int i;
    FILE *a;
    FILE *g;
    struct playerData plr;
    strcpy(plr.pl, player);
    plr.scr = scr;
    bool newFile = false;
    a = fopen(dp, "r");
    if (a == NULL) {
        a = fopen(dp, "w");
        newFile = true;
        fclose(a);
    }
    else {
        a = fopen(dp, "a");
        fclose(a);
    }
    if (newFile == false && takeScore == true) {
        g = fopen(dp, "a+");
        fprintf(g, " %s %ld \n", plr.pl, plr.scr);
        fclose(g);
    }
    else if (newFile == true && takeScore == true) {
        struct playerData f[10];
        g = fopen(dp, "w+");
        fprintf(g, " %s %ld \n", plr.pl, plr.scr);
        for (i = 0; i < 10; i++) {
            fprintf(g, " %s %ld \n", "Unknown", 0);
        }
        newFile = false;
        fclose(g);
    }
    rankScore();
    takeScore = false;
}


void cls() {

// for windows10 use
    //system("cls");
    printf("\e[1;1H\e[2J");

}

void player(char ch,char* plr, int point) {
    FILE *f;

    if(ch == '1') {
          setHigh(plr,point)  ;
    }
    else if(ch == '2') {
        char lm[2222];
        f = fopen(dp,"r");

        for(;;) {
            fgets(lm,2222,f);
            if( feof(f) ) {
                break ;
            }
            puts(lm);

        }
        cout<<endl<<"PRESS ANY [KEY] TO RETURN";
        char e= _getch();
        if(e) {
            cls();

        }

    }
    fclose(f);

}



void game() {

    for(;;) {

        cls();
        cout<<"POINT >> "<<point<<endl;
        for(int i= 0; i<=length; i++) {


            cout<<endl;
            //  cout << "#";
            for(int j=0; j<=width; j++) {


                /*
                if(i==1||i==5){
                    cout<<"#";
                }*/
                if(i==0||j==0||i==width||j==length) {
                    cout<<"/";
                }

                else if(i==x && j==y) {
                    cout<<"0";
                }
                else if(i==xx && j==yy) {
                    cout<<"o";
                }
                else if(i==x1 && j==y1) {
                    cout<<"*";
                }
                else
                    cout<<" ";
            }

        }
        char p;

        cout<<endl<<"press [a/s/d/w] to move 'o0'(snake)"<<endl<<"press [t] to die"<<endl;
        p = _getch();
        if(p=='w') {
            if(xx < x) {
                continue;
            }
            else {
                x--;
                if(y>yy) {
                    yy++;
                }
                else if(y<yy) {
                    yy--;
                }
                else {
                    xx--;

                }
                cls();
            }
        }
        else if(p == 'd') {
            if(yy>y) {
                continue;

            }
            else {
                y++;
                if(x < xx) {
                    xx--;
                }
                else if(x > xx) {
                    xx++;
                }
                else {
                    yy++;
                }
                cls();
            }
        }
        else if(p == 's') {
            if(xx > x) {
                continue;
            }
            else {
                x++;
                if(y>yy) {
                    yy++;
                }
                else if(y<yy) {
                    yy--;
                }

                else {
                    xx++;

                }
                cls();
            }
        }
        else if(p == 'a') {

            if(yy<y) {

                continue;
                /*y = yy;
                yy = y +1;*/
            }
            else {
                y--;
                if(xx < x) {

                    xx++;


                }
                else if(xx > x) {

                    xx--;


                }
                else {
                    yy--;
                }
                cls();
            }
        }

        for(int i= 0; i<=length; i++) {
            /* if(p=='t'){

                 cls();
                   cout<<"YOU DIED ON PURPOSE";
                 break;
             }
             */
            cout<<endl;
            //  cout << "#";
            for(int j=0; j<=width; j++) {


                /*
                if(i==1||i==5){
                    cout<<"#";
                }*/
                if(i==0||j==0||i==width||j==length) {
                    cout<<"/";
                }

                else if(i==x && j==y) {
                    cout<<"0";
                }
                else if(i==x1 && j==y1) {
                    cout<<"*";
                }
                else if(i==xx && j==yy) {
                    cout<<"o";
                }
                else
                    cout<<" ";
            }

        }
        if(y == y1 && x == x1) {
            //cout<<endl<<endl<<"point = "<<++point;
            point++;

            x1 = rand()%8+1;
            y1 = rand()%8+1;


        }
        else if(p=='t') {

            cls();
            cout<<"YOU DIED ON PURPOSE"<<endl;
            cout<<endl<<endl<<"GAME OVER"<<endl<<"YOUR POINT == "<<point<<endl;

            break;
        }
        else if(x == 0 || y == 0||x == width || y == width) {
            cls();
            cout<<"GAME OVER"<<endl<<"YOUR POINT == "<<point<<endl;
            break;
        }
        //cls();
    }
    cout<<"BETTER LUCK NEXT TIME";
    player('1',&plr[0],point);

}


int main()
{
    for(;;) {
        char a;
        cout << "             SNAKE XENZIA\n";
        for(int i=1; i<=38; i++) {
            cout<<"~";
        }
        for(int i= 0; i <3 ; i++) {
            cout<<endl;
        }
        cout<<"               [1]PLAY";
        cout<<endl<<"               [2]HIGH SCORES";
        cout<<endl<<"               [3]INSTRUCTION";
        cout<<endl<<"               [0]EXIT";
        for(int i= 0; i <3 ; i++) {
            cout<<endl;
        }
        cout<<"PRESS [KEY]"<<endl;
        a = _getch();
        if(a == '1') {
            cls();
            cout<<"ENTER PLAYER NAME";

            cout<<endl;
            gets(plr);
            cls();
            game();
            break;
        }
        else if(a == '0') {
            cls();
            break;
        }
        else if(a == '3') {
            cls();
            cout<<"Just play the game.";
            cout<<endl<<"PRESS ANY [KEY] TO RETURN";
            char e= _getch();
            if(e) {
                cls();

            }

        }
        else if(a == '2') {
            cls();
            player('2',&plr[0],point);

        }
        else {
            cls();

            continue;

        }
    }

    return 0;//created by  muhaiminulkabir32@gmail.com
}
