#include <iostream>
#include<bits/stdc++.h>
using namespace std;

char grid[5][5]; // 5x5  matrix to encryption or decryption
char key[26];
char msg[100];
int mark[130],len,r,c;

void createGrid();
void showGrid();
void encryption();
void decryption();
void initialize();

void initialize()
{
    memset(mark,0,sizeof(mark));
    system("CLS");
}

void menu()
{
    system("CLS");
    int n;
    string op[]={"1. Encryption","2. Decryption","3. Exit"};
    cout<<op[0]<<endl<<op[1]<<endl<<op[2]<<endl<<"Enter choice: ";
    cin>>n;
    if(n==1) encryption();
    else if(n==2) decryption();
    else exit(1);
}

int main()
{
    menu();
    return 0;
}

void createGrid()
{
    cout<<"Key: ";
    cin>>key;
    getchar();
    len=strlen(key);
    mark['J']=1; // ignore J
    r=0,c=0;

    for(int i=0;i<len;i++)
    {
        if(!mark[toupper(key[i])]) // ignore duplicates
        {
            mark[toupper(key[i])]=1;
            grid[r][c++]=toupper(key[i]);
            if(c%5==0)
            {
                c=0;
                r++;
            }
        }
    }

    for(int i='A';i<='Z';i++)
    {
        if(mark[i]==0)
        {
            grid[r][c++]=i;
            mark[i]=1;
            if(c%5==0)
            {
                if(r==4 && c==5) break;
                r++;
                c=0;
            }
        }
    }
}
void showGrid()
{
    cout<<"5x5 Matrix"<<endl;
   for(int i=0;i<5;i++)
   {
       for(int j=0;j<5;j++)
       {
           cout<<grid[i][j]<<" ";
       }
       cout<<endl;
   }
}

void decryption()
{
    initialize();
    createGrid();
    cout<<"Cypher text: ";
    char cypText[150];
    cin>>cypText;
    getchar(); // flush buffer
    int l=strlen(cypText);

    cout<<"Decryption text: ";
    int P,Q,S,f1,f2;
    char x,y;
    int R[l+l+2],C[l+l+2];
    P=0;
    Q=0;
    for(int i=0;i<l/2;i++)
    {
        for(int k=0;k<5;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(cypText[i]==grid[k][m])
                {
                    R[P]=k;
                    P++;
                    R[P]=m;
                    P++;
                    break;
                }
            }
        }
    }
    int index=0;
    for(int i=l/2;i<l;i++)
    {
        for(int k=0;k<5;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(cypText[i]==grid[k][m])
                {
                    C[index++]=k;
                    C[index++]=m;
                    break;
                }
            }
        }
    }
    for(int i=0;i<index;i++)
        cout<<grid[R[i]][C[i]];
    cout<<endl<<endl;
    system("PAUSE");
    menu();
}
void encryption()
{
    initialize();
    createGrid();
    cout<<"Message to cypher: ";
    gets(msg);
    int l=strlen(msg);
    char reqText[150];
    int in=0,j=0;
    for(int i=0;i<l;i++)
    {
        j=i+1;
        if(msg[i]==' ') //ignore all space from string
        {
            i++;
            j++;
        }
        if(msg[j]==' ') j++; //ignore space
        if(toupper(msg[i])=='J') msg[i]='i'; // ignore J
        if(toupper(msg[i])==toupper(msg[j])) // if duplicate add 'X' after the first letter
        {
            reqText[in]=toupper(msg[i]);
            reqText[in+1]='X';
            in++;
        }
        else
        {
            reqText[in]=toupper(msg[i]);
        }
        in++;
    }
    if(in%2!=0)
    {
        reqText[in++]='X'; // if one character left, add 'X' after it
    }
    cout<<"Cypher text: ";
    int P,Q,R,S,f1,f2;
    char x,y;
    int mat[in+in+2];
    P=0;
    Q=in;
    for(int i=0;i<in;i++)
    {
        for(int k=0;k<5;k++)
        {
            for(int m=0;m<5;m++)
            {
                if(reqText[i]==grid[k][m])
                {
                    mat[P++]=k;
                    mat[Q++]=m;
                    break;
                }
            }
        }
    }
    for(int i=0;i<in+in;i+=2)
        cout<<grid[mat[i]][mat[i+1]];
    cout<<endl<<endl;
    system("PAUSE");
    menu();
}
