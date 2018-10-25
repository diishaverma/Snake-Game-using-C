#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
char board[20][18];
int r,c;
struct food
{
    int x,y;
    char val;
};
struct snake
{
    int x,y;
    char val;
    snake*next;
};
snake*head=NULL;
class linked
{
  public:
      snake*create(int a,int b)
      {
          snake*temp;
          temp = new snake;
          temp->x=a;
          temp->y=b;
          temp->val='#';
          temp->next=NULL;
          return temp;
      }
      void insert()
      {
          snake*t,*temp;
          int a,b,c=0;
          cout<<"enter node";
          cin>>a>>b;
          system("cls");
          temp = create(a,b);
          if(head==NULL)
          {
              temp->val='H';
              head = temp;
          }
          else
          {
              t=head;
              c=0;
              while(t->next!=NULL)
              {
                  t=t->next;
                  c++;
              }
              if(c==2)
              temp->val='T';
              t->next=temp;
              temp->next=NULL;
          }
      }
      void print()
      {
          system("cls");
          int i,j;
              for(i=0;i<20;i++)
            {     for(j=0;j<18;j++)
                   cout<<board[i][j];
        cout<<endl;
            }
      }
      void matrix()
      {
          int i,j;
          snake*t;
          t=head;
          while(t!=NULL)
          {
            i=t->x;
            j=t->y;
            board[i][j]=t->val;
            t=t->next;
          }
      }
      void move(int r, int c)
      {
          snake*t;
          int s,u;
          t=head;
          if(r==t->next->x && c==t->next->y)
            exit(0);
          s=t->x;
          u=t->y;
          t->x=r;
          t->y=c;
          board[r][c]=t->val;
          t=t->next;
          r=s;
          c=u;
          while(t!=NULL)
          {
              s=t->x;
              u=t->y;
              t->x=r;
              t->y=c;
             board[r][c]=t->val;
              r=s;
              c=u;
              t=t->next;
          }
          board[s][c]=' ';
          print();

      }
      void movement()
      {
          char z;
          int i=1;
          snake* t;
          while(i==1)
         {
         // cout<<"l for left,r for right,u for up,b for buttom"<<endl;
          // cin>>z;
         z = getch();
           system("cls");
           t=head;
           r = t->x;
           c = t->y;
           if(z=='l')
           {
               if(c-1>1)
                move(r,c-1);
               else
                move(r,16);
           }
           else if(z=='r')
           {
               if(c+1<16)
                move(r,c+1);
               else
                move(r,1);

           }
           else if(z=='t')
              { if(r-1>1)
                move(r-1,c);
               else
                move(18,c);

              }
              else if(z=='b')
              {
                  if(r+1<18)
                    move(r+1,c);
                  else
                    move(1,c);
              }
         }

      }
};
int main()
{
    linked l;
    int i,j,n;
    for(i=0;i<20;i++)
      board[i][0]='|';
    for(i=0;i<18;i++)
        board[0][i]='---';
        for(i=0;i<18;i++)
            board[19][i]='----';
            for(i=0;i<20;i++)
            board[i][17]='|';


 cout<<"Enter the length of snake"<<endl;
 cin>>n;
 system("cls");
while(n)
{
 l.insert();
 n--;
}
l.matrix();
l.print();
l.movement();
    return 0;
}
