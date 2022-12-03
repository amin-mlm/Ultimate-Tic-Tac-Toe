#include <stdio.h>
#include <systemtopologyapi.h>
void printTable(char ja[10][10]);
void miniTable(char ja[10][10],char c[4][4],int q,int w);

int main()
{
    int q,w,qTemp,wTemp,i,j,h=0;
    char ja[10][10];     // h:  Even ='x' Odd='o'
    char c[4][4];

    for(i=1;i<=9;i++)   // determine 'space' to all first value
    {
        for(j=1;j<=9;j++)
        {
            ja[i][j]=' ';
        }
    }
    for(i=1;i<=3;i++)   // determine 'space' to all first value
    {
        for(j=1;j<=3;j++)
        {
            c[i][j]=' ';
        }
    }
    printf("Here is METAdoZ\nMake  vertical, horizontal or diagonal line to win mini tables.\n");
    printf("You should enter 2 integers witch are (x,y) of blocks of table.\n");
    printf("Rules:\n1.x & y must obey 1<=x,y<=9\n2.Your choice can't be busy blocks.\n3.Winner is who win the Big Table.\n");
    printf("\nAre you ready? Press any key to start\n\n");
    getch();
    printf("It's X turn\n");
    printf("\n");
    printTable(ja);

    while(h<=80)
    {
            scanf("%d %d",&q,&w);
            if(q>9 || q<1 || w>9 || w<1)
            {
                printf("\aWrong number!\nTry again:\n");
                continue;
            }
            if(ja[q][w]=='x' || ja[q][w]=='o')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
        qTemp=q;
        wTemp=w;
        if(q%3==0)  q-=2;
        else if(q%3==2)  q-=1;
        if(w%3==0)  w-=2;
        else if(w%3==2)  w-=1;

            if(q==1 && w==1 && c[1][1]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
             else if(q==1 && w==4 && c[1][2]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
             else if(q==1 && w==7 && c[1][3]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
            else if(q==4 && w==1 && c[2][1]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
             else if(q==4 && w==4 && c[2][2]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
            else if(q==4 && w==7 && c[2][3]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
            else if(q==7 && w==1 && c[3][1]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
             else if(q==7 && w==4 && c[3][2]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }
             else if(q==7 && w==7 && c[3][3]!=' ')
            {
                printf("\aThat block is full!\nChoose another:\n");
                continue;
            }


        if(h%2==0)
        {
            ja[qTemp][wTemp]='x';
        }
        else
        {
            ja[qTemp][wTemp]='o';
        }

        system("cls");
        if(h%2==0) printf("It's O turn\n\n");
        else printf("It's X turn\n\n");

        printTable(ja);
        if(  (ja[q+1][w+1]!=' ') &&  ( (ja[q+1][w]==ja[q+1][w+1] && ja[q+1][w+1]==ja[q+1][w+2])  ||  (ja[q][w+1]==ja[q+1][w+1] && ja[q+1][w+1]==ja[q+2][w+1]) ||
           (ja[q][w]==ja[q+1][w+1] && ja[q+1][w+1]==ja[q+2][w+2])   ||   (ja[q][w+2]==ja[q+1][w+1] && ja[q+1][w+1]==ja[q+2][w]) ) )
        {
            qTemp=q+1;
            wTemp=w+1;
            if(q==4) q=2;
            else if(q==7)  q=3;
            if(w==4) w=2;
            else if(w==7)  w=3;

            c[q][w]=ja[qTemp][wTemp];
            system("cls");
            miniTable(ja,c,q,w);
            printTable(ja);
        }
        else if ( (ja[q][w]!=' ') && ((ja[q][w]==ja[q][w+1] && ja[q][w+1]==ja[q][w+2])  ||  (ja[q][w]==ja[q+1][w] && ja[q+1][w]==ja[q+2][w]))  )
        {
            qTemp=q;
            wTemp=w;
            if(q==4) q=2;
            else if(q==7)  q=3;
            if(w==4) w=2;
            else if(w==7)  w=3;

            c[q][w]=ja[qTemp][wTemp];
            system("cls");
            miniTable(ja,c,q,w);
            printTable(ja);
        }
        else if( (ja[q+2][w+2]!=' ') && ((ja[q+2][w]==ja[q+2][w+1] && ja[q+2][w+1]==ja[q+2][w+2]) ||  (ja[q][w+2]==ja[q+1][w+2] && ja[q+1][w+2]==ja[q+2][w+2])) )
        {
            qTemp=q+2;
            wTemp=w+2;
            if(q==4) q=2;
            else if(q==7)  q=3;
            if(w==4) w=2;
            else if(w==7)  w=3;

            c[q][w]=ja[qTemp][wTemp];
            system("cls");
            miniTable(ja,c,q,w);
            printTable(ja);
        }

         if(  c[1][1]!=' ' && ((c[1][1]==c[1][2] && c[1][2]==c[1][3]) || (c[1][1]==c[2][1] && c[2][1]==c[3][1])) )
         {
             printf("%c WINS!",c[1][1]);
             break;
         }
        else if( c[3][3]!=' ' && ((c[3][3]==c[3][2] && c[3][2]==c[3][1]) || (c[3][3]==c[2][3] && c[2][3]==c[1][3]))  )
        {
            printf("%c WINS!",c[3][3]);
            break;
        }
        else if( c[2][2]!=' ' && ((c[1][1]==c[2][2] && c[2][2]==c[3][3]) || (c[1][3]==c[2][2] &&c[2][2]==c[3][1]) ||
           (c[1][2]==c[2][2] && c[2][2]==c[3][2]) || (c[2][1]==c[2][2] && c[2][2]==c[2][3])) )
        {
            printf("%c WINS!",c[2][2]);
            break;
        }
        else if(h==80)
        {
            printf("DRAW!");
            break;
        }
    h++;
    }
    getch();
    return 0;
}


void printTable(char ja[10][10])     // print table with newest data
{
    int i,j,iTemp,jTemp;
        iTemp=1;
        jTemp=1;
         printf("   1 2 3   4 5 6   7 8 9\n");
    for(i=1;i<=13;i++)
    {
        if(i%4==1)
        {
            printf(" |-----------------------|\n");// 13 dash + 2 |
            continue;
        }
        for(j=1;j<=13;j++)
        {
            if(j%4==1)
            {
                if(j==13)
                {
                    iTemp++;
                    jTemp=1;
                }
                if(j==1)printf("%d",iTemp);
                printf("| ");
                continue;
            }
            printf("%c ",ja[iTemp][jTemp]);
            jTemp++;

        }
        printf("\n");
    }
}
void miniTable(char ja[10][10],char c[4][4],int q,int w)    // determine X/O for each bigger blocks
{
    int i,j;
    if(q==1)
    {
        if(w==1)
        {
            if(c[1][1]=='x')
            {ja[1][1]=ja[2][2]=ja[3][3]=ja[1][3]=ja[3][1]='|';}
            else
            {ja[1][2]=ja[2][1]=ja[2][3]=ja[3][2]='-';}
                for(i=1;i<=3;i++)
                {
                    for(j=1;j<=3;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
        else if(w==2)
        {
            if(c[1][2]=='x')
            {ja[1][4]=ja[2][5]=ja[3][6]=ja[1][6]=ja[3][4]='|';}
            else
            {ja[1][5]=ja[2][4]=ja[2][6]=ja[3][5]='-';}
            for(i=1;i<=3;i++)
                {
                    for(j=4;j<=6;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
        else
        {
            if(c[1][3]=='x')
            {ja[1][7]=ja[2][8]=ja[3][9]=ja[1][9]=ja[3][7]='|';}
            else
            {ja[1][8]=ja[2][7]=ja[2][9]=ja[3][8]='-';}
            for(i=1;i<=3;i++)
                {
                    for(j=7;j<=9;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
    }
    else if(q==2)
    {
        if(w==1)
        {
            if(c[2][1]=='x')
            {ja[4][1]=ja[5][2]=ja[6][3]=ja[4][3]=ja[6][1]='|';}
            else
            {ja[4][2]=ja[5][1]=ja[5][3]=ja[6][2]='-';}
            for(i=4;i<=6;i++)
                {
                    for(j=1;j<=3;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
        else if(w==2)
        {
            if(c[2][2]=='x')
            {ja[4][4]=ja[5][5]=ja[6][6]=ja[4][6]=ja[6][4]='|';}
            else
            {ja[4][5]=ja[5][4]=ja[5][6]=ja[6][5]='-';}
            for(i=4;i<=6;i++)
                {
                    for(j=4;j<=6;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
        else
        {
            if(c[2][3]=='x')
            {ja[4][7]=ja[5][8]=ja[6][9]=ja[4][9]=ja[6][7]='|';}
            else
            {ja[4][8]=ja[5][7]=ja[5][9]=ja[6][8]='-';}
            for(i=4;i<=6;i++)
                {
                    for(j=7;j<=9;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
    }
    else
    {
        if(w==1)
        {
            if(c[3][1]=='x')
            {ja[7][1]=ja[8][2]=ja[9][3]=ja[7][3]=ja[9][1]='|';}
            else
            {ja[7][2]=ja[8][1]=ja[8][3]=ja[9][2]='-';}
            for(i=7;i<=9;i++)
                {
                    for(j=1;j<=3;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
        else if(w==2)
        {
            if(c[3][2]=='x')
            {ja[7][4]=ja[8][5]=ja[9][6]=ja[7][6]=ja[9][4]='|';}
            else
            {ja[7][5]=ja[8][4]=ja[8][6]=ja[9][5]='-';}
            for(i=7;i<=9;i++)
                {
                    for(j=4;j<=6;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
        else
        {
            if(c[3][3]=='x')
            {ja[7][7]=ja[8][8]=ja[9][9]=ja[7][9]=ja[9][7]='|';}
            else
            {ja[7][8]=ja[8][7]=ja[8][9]=ja[9][8]='-';}
            for(i=7;i<=9;i++)
                {
                    for(j=7;j<=9;j++)
                    {
                        if(ja[i][j]!='-' && ja[i][j]!='|') ja[i][j]=' ';
                    }
                }
        }
    }
}
