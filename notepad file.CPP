#include<iostream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>
#include<string.h>
#include<iomanip.h>
#include<bios.h>
#include<dos.h>
#include<stdlib.h>
int points=0;
class quizm
{
		char ques[100];
		char opta[25];
		char optb[25];
		char optc[25];
		char optd[25];
		char answer;
		char input;
	public:
	void menudesign()
	{
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t K.V. No: 2, Tambaram,Chennai-73"<<endl;
	for(int i=0;i<80;i++)
	cout<<"*";
	cout<<endl<<endl<<endl;
	cout<<"The C++ QUIZ MASTER"<<endl;
	cout<<endl<<endl<<endl;
	for(i=0;i<80;i++)
		cout<<"*";
	cout<<endl;
	cout<<"\t\t\t\t\t by NITIN VASHISTH & MOHIT DHIMAN";
	cout<<endl<<endl<<endl;cout<<endl<<endl<<endl;
	}
	void getques();
	void display(){
			puts(ques);
			puts(opta);
			puts(optb);
			puts(optc);
			puts(optd);
			cout<<answer;

		}
	void menu(int *choice,int admin);
	void show()
	{
		cout<<endl<<endl<<endl;
		char uans; char b;
		puts(ques);
		cout<<endl<<endl<<endl;
		cout<<"\n\t\t"<<"a."<<opta;
		cout<<"\n\t\t"<<"b."<<optb;
		cout<<"\n\t\t"<<"c."<<optc;
		cout<<"\n\t\t"<<"d."<<optd;
		cout<<endl<<endl<<endl;
		cout<<"your answer:- ";
		cin>>uans;

		if(uans==answer)
		{
			cout<<endl<<"CORRECT !!!";points++;
			getch();
			clrscr();
		}
		else
		{
			cout<<"WRONG!!!!!"<<"\n\n The correct answer is "<<answer<<"\a";
			getch();
			clrscr();
		}
	}
};

void quizm::menu(int *choice,int admin)
{
	textcolor(GREEN);
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t K.V. No: 2, Tambaram,Chennai-73"<<endl;
	for(int i=0;i<80;i++)
	cout<<"*";
	cout<<endl<<endl<<endl;
	cout<<"The C++ QUIZ MASTER"<<endl;
	cout<<endl<<endl<<endl;
	for(i=0;i<80;i++)
		cout<<"*";
	cout<<endl;
	cout<<"\t\t\t\t\t by NITIN VASHISTH & MOHIT DHIMAN";
	cout<<endl<<endl<<endl;cout<<endl<<endl<<endl;
	cout<<"\tPress"<<endl<<endl<<endl;
	cout<<"\t\t 1     To Play";cout<<endl<<endl;
	cout<<"\t\t 2     To Know about us";cout<<endl<<endl;
	cout<<"\t\t 3     To Exit\n\n";
	if(admin == 1)
		cout<<"\t\t 4	Add Question"<<endl;

	cout<<endl<<endl<<endl<<"\t Your choice:-";
	cin>>*choice;
}
void quizm::getques()
{
	fstream f;        quizm Q;
	textcolor(RED);
	f.open("Qbank.dat",ios::app|ios::binary);


	cout<<"enter the question"<<endl;
	gets(ques);
	cout<<"enter the options"<<endl;
	gets(opta);
	gets(optb);
	gets(optc);
	gets(optd);

	cout<<"correct answr"<<endl;
	cin>>answer;
	f.write((char*)&Q,sizeof(Q));
	f.close();

}



void main()
{
	int caseinp,b,noq,ua,pwd,admin;
	char ex,cont; char *pswd;
	quizm q;
	textcolor(YELLOW);
start:
	clrscr();
	cout<<endl<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t\t K.V. No: 2, Tambaram,Chennai-73"<<endl;
	for(int i=0;i<80;i++)
	cout<<"*";
	cout<<endl<<endl<<endl;
	cout<<"Welcome to Play the C++ QUIZ MASTER"<<endl;
	cout<<endl<<endl<<endl;
	for(i=0;i<80;i++)
		cout<<"*";
	cout<<endl;
	cout<<"\t\t\t\t\t by NITIN VASHISTH & MOHIT DHIMAN";
	cout<<endl<<endl<<endl;cout<<endl<<endl<<endl;
	cout<<"\t\t\t\t Do you want to LOGIN as \n\n";
	cout<<"\n\t\t1  Admin \n\n\t\t2  GUEST";
	ua = getch();
	if(ua=='1')
	{
	       pswd = getpass("\n\n\t\tEnter the password:");
	       if(strcmp(pswd,"vashisth") == 0)
			admin = 1;
	       else
	       {
			cout<<"\n\n\t\tInvalid Password!!";
			getch();
			goto start;
	       }
	}
	else
		admin = 0;
	clrscr();
	q.menu(&caseinp,admin);
	while(1)
	{
	switch(caseinp)
	{
		 case 1 :
			clrscr();
			q.menudesign();
			cout<<"\n\t How many questions would you like to play? max(20)"<<endl;
			cin>>noq;
			clrscr();
			fstream f;
			f.open("QBANK.dat",ios::binary|ios::in|ios::out);
			quizm q;

			/*while(!f.eof())
			{
				f.read((char *)&q,sizeof(q));
				q.display();
				getch();
				clrscr();
			} */
			for(int k=0;k<noq;k++)

			{       q.menudesign();
				if(k==0)
				cout<<endl<<endl<<"\t\t\t\let us start the game now:\n\n\n";
				f.read((char *)&q,sizeof(q));
				// f.read((char*)&Q,sizeof(Q));
				 cout<<"\t\t\tQuestion NO:"<<k+1<<"\n\n";
				 q.show();
			 }
			 cout<<endl<<endl<<endl;
			 clrscr();
			 q.menudesign();
			 if(points==noq)
				  cout<<"\t\tExcellent \n\n You scored full mounty\t"<<points;
			 if(noq-points==1)
				 cout<<"\t\tGood \n\n You are one short of scoring full";
			 if(noq-points>=2)
				 cout<<"\t\tYou scored \n\n\t\t"<<points<<"  out of "<<noq;
			 getch();
			 clrscr();

			 q.menu(&caseinp,admin);
			 break;
		 case 2 :
				textcolor(CYAN);
			clrscr();
			cout<<endl<<endl<<endl;
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t K.V. No: 2, Tambaram,Chennai-73";cout<<endl;
			for(int i=0;i<80;i++)
			cout<<"*"; cout<<endl<<endl<<endl;
			cout<<"The C++ QUIZ MASTER"<<endl;
			cout<<endl<<endl<<endl;
			for(i=0;i<80;i++)
				cout<<"*";
			cout<<endl;
			cout<<endl<<endl;
			cout<<"\t This a creation for School Cbse project(computer science) year 2003-10"<<endl;cout<<endl<<endl;
			cout<<"The members of the project are :";
			cout<<endl<<endl;
			cout<<"NITIN VASHISTH XII Science"<<endl;
			cout<<endl<<endl;
			cout<<"MOHIT DHIMAN XII Sceince"<<endl<<endl;
			cout<<endl<<endl;
			cout<<"SUBJECT TEACHER : \t A.K PANDEY";
			getch();
			clrscr();
			q.menu(&caseinp,admin);
			break;
		case 3 :
			clrscr();
			q.menudesign();
			cout<<"\n\n\n\n\t\t\tAre you sure ?\n  Press y/n";
			ex=getch();
			if(ex=='y')
			{
				clrscr();
				exit(3);
			}
			else
			{
				clrscr();
				q.menu(&caseinp,admin);
			}
		case 4  :
			clrscr();
			q.menudesign();
			q.getques();
			cout<<"Do you want to add another question:";
			pwd = getchar();
			if(pwd == 'y' || pwd == 'Y')
			{
				clrscr();
				caseinp = 4;
			       }
			else
			{       clrscr();
				q.menu(&caseinp,admin);
			}
			break;

		default :
			cout<<" wrong input ";
	  }
	}
}
