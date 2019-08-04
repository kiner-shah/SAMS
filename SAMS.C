#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#define MAXNUMWORDS 100
#define MAXWORDLENGTH 64
int distmenu=10;  // Distance Between Menu Items
int rows=15; //Row Value for Menu Item
int columns=8; //Column Value for Menu Item
int menuno=2; //Total menu items
int level=1;//initial level
int drawing=0,changecolor=4;
typedef char option[20];

option menuitems[]= {
		     "New Game", "Quit"
		    };

int lives = 6,win=0;//variable sanat
void disclaimer();
void draw();
void countdown();
void gameloop(int);
void change();
void winlose();
void credits();
void disp(int x,int y,char *str)
{
   x=(8*(x-1));
   y=(8*(y-1));
   outtextxy(x,y,str);
}
void selection(int x,int y,char *str)
{  //if(stop!=0)
   x=(8*(x-1));
   y=(8*(y-1));
   setcolor(14);  //Selected Item Color
   sound(400);
   delay(100);
   nosound();
   outtextxy(x,y,str);
   setcolor(WHITE); //Unselected Item Color
   sound(500);
   delay(100);
   nosound();

}

char menu()
{  int i,press,choice;
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
   setcolor(WHITE);  //Initial Menu Item Color
   for(i = 1; i < menuno; i++)
   disp(columns+15, (i*distmenu)+rows, menuitems[i]);
   selection(columns+15,rows, menuitems[0]);
   i = press = 0;
   while(!press)
   {
      //Status Bar Code
      setfillstyle(SOLID_FILL,BLUE);
      settextstyle(SMALL_FONT,HORIZ_DIR,5);
      bar(8,412,592,432);
      setcolor(LIGHTCYAN);
      switch(i)
      {
	case 0 : outtextxy(32,414,"Save your Father");
		 break;
	case 1 : outtextxy(32,414,"Chicken out");
		 break;
      }
      //status Bar
      setcolor(WHITE);
      settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
      choice = getch();
      switch (choice)
      {
	 case 00: choice = getch();
	    switch (choice)
	    {
	       case 72: disp(columns+15, (i*distmenu)+rows, menuitems[i]);
			  i--;
			      if (i == -1)
			   i = menuno-1;
			   selection(columns+15,(i*distmenu)+rows,menuitems[i]);
			break;
	       case 80: disp(columns+15, (i*distmenu)+rows, menuitems[i]);
			  i++;
			  if (i == menuno)
			   i = 0;
			   selection(columns+15, (i*distmenu)+rows, menuitems[i]);
			break;
	    }
	    break;
	 case 13: press = 1;
      }
   } setbkcolor(BLACK);
   while (!press);
   return(i+49);

}
void call_menu()
{
   char choice;
   clearviewport();

      choice = menu();
      switch (choice)
      {

	case '1':
		 draw();
		 gameloop(level);
		 getch();
		 break;

	case '2':    //Close the project
		 delay(1000);
		 exit(0);
      }

}
void disclaimer()
{
int i ;
char choice;
outtextxy(250,0,"Disclaimer");
outtextxy(50,10,"All of the content contained on the SAMS is edited, checked,");
outtextxy(50,20,"and verified for accuracy as much as it is possible to do so. ");
outtextxy(50,30,"However, we cannot guarantee either its accuracy or the "      );
outtextxy(50,40,"safety in any way it might contain. SAMS, as well as its"      );
outtextxy(50,50,"owners, affiliates, and contributing sponsers can therefore     ");
outtextxy(50,60,"not be held responsible for any problems or damage that occurs   ");
outtextxy(50,70,"as a result of making use of material contained on SAMS.        ");
outtextxy(250,90,"Copyright");
outtextxy(50,100,"Any and all of the content presented on the SAMS is,  ");
outtextxy(50,110,", subject to a copyright held by developers of SAMS.   ");
outtextxy(50,120," It is permissible to link to content from SAMS    ");
outtextxy(50,130," as long as the original source isclearly stated,   ");
outtextxy(50,140,"but the wholesale reproduction or partial modification of    ");
outtextxy(50,150,"content is not permitted. Exceptions are granted only if     ");
outtextxy(50,160,"you receive prior written consent from DEVELOPERS of SAMS.   ");
outtextxy(250,180,"Complaints                                                     ");
outtextxy(50,190,"Any complaints about SAMS may be sent to our support team:     ");
outtextxy(50,200,"SAMS@gmail.com                                                 ");
outtextxy(50,210,"There is no guarantee of a resolution. Each case will be       ");
outtextxy(50,220,"looked at individually, and the developers will be in          ");
outtextxy(50,230,"contact as well.These terms and conditions are subject to change.  ");
outtextxy(250,250,"Contacts");
outtextxy(50,260,"Should you have any further questions, concerns, or queries");
outtextxy(50,270,"about these Terms and Conditions, or if you encounter   ");
outtextxy(50,280,"difficulties while navigating and using the SAMS, please");
outtextxy(50,290,"contact SAMS@gmail.com                                  ");
outtextxy(90,330,"I have read and agreeed to the terms and conditions.");
setcolor(GREEN);
outtextxy(140,350,"PRESS Y if you agree to above conditons.");
setcolor(RED);
outtextxy(210,370,"PRESS N to exit.");
inputagain:
choice=getch();
if(choice=='y' || choice=='Y')
i=89;
else if(choice=='n' || choice=='N')
i=78;
settextstyle(0,0,0);
switch(i)
{
case 89 : setcolor(0);
	  outtextxy(100,410,"Be careful and read the instruction properly");
	  setcolor(15);
	  outtextxy(100,410,"It's good to see you got courage to play the game.");
	  fillellipse(60,410,10,10);
	  setcolor(0);
	  arc(60,414,180,360,(9/2));
	  line(52,406,69,406);
	  setfillstyle(SOLID_FILL,BLACK);
	  pieslice(56,407,180,360,3);
	  pieslice(65,407,180,360,3);
	  delay(3000);
	  break;
case 78 : setcolor(0);
	  outtextxy(100,410,"Be careful and read the instruction properly");
	  setcolor(15);
	  outtextxy(160,410,"Sorry to see you go.");
	 exit(getch()=='/r');
	  break;
default : setcolor(changecolor);
	  outtextxy(100,410,"Be careful and read the instruction properly");
	  changecolor++;
	  goto inputagain;
}
countdown();
}
/////////////////////end of disclaimer function//////////////////////
void countdown()
{	int i=150 ,randomy,randomx,j,e=0,ycoordinate[100],xcoordinate[100],w=0;
	float octave[7] = { 130.81, 146.83, 164.81, 174.61, 196.0, 220.0, 246.94 };
	clearviewport();
	settextstyle(4,0,0);
	setcolor(9);
	setusercharsize(2,0,2,0);
	outtextxy(70,50,"GAME STARTS ");
	outtextxy(250,135,"IN ");
	outtextxy(400,260,"SEC") ;
	setusercharsize(5,1,5,1);
	settextstyle(10,0,0);
	setcolor(9);
	fillellipse(300,335,95,120);
	outtextxy(240,125,"3");
	delay(1000);
	fillellipse(300,335,95,120);
	outtextxy(240,125,"2");
	delay(1000);
	fillellipse(300,335,95,120);
	outtextxy(240,125,"1");
	delay(1000);
	clearviewport();


	setcolor(14);
	settextstyle(0,0,0);
	setusercharsize(2,1,2,1);
	outtextxy(50,150,"Your FATHER is trapped in a maze and you have responsiblity of");
	delay(1000);
	outtextxy(60,160,"saving him by solving a puzzle, your every wrong move will ");
	delay(1000);
	outtextxy(130,170,"result in flaying of 1 of his body parts.  ");
	delay(1000);
	outtextxy(150,180,"Your FATHER has one MESSAGE for you.....");
	delay(1000);
	outtextxy(170,190,"PRESS SPACE TO READ MESSAGE");
	settextstyle(10,0,0);
	setcolor(RED);
	delay(1000); //for reading story
	setusercharsize(2,1,2,1);
	while( !kbhit() )
	{
	sound( octave[ random(3) ]*4 );
	 delay(100);
	}
       while( !kbhit() )
	{
	sound( octave[ random(3) ]*4 );
	 delay(100);
	}
	nosound();
clearviewport();
settextstyle(0,0,0);
setusercharsize(1,0,1,0);
randomize();
for(i=0;i<60,e<500,w<550;i++)
{
xcoordinate[i]=e;
ycoordinate[i]=w;
e+=90;
w+=10;
}
for(i=0;i<=7;i++)
{
for(j=0;j<60;j++)
{ randomx=random(7);
 randomy=random(60);

  back:
 /* p=random(15);
  if(p==1||p==2||p==4||p==9||p==10||p==11||p==14)
   setcolor(p);
  else
  goto back;*/
  setcolor(4);
outtextxy(xcoordinate[randomx],ycoordinate[randomy],"|SAVEMESON|");
delay(10);

}
}
setcolor(14);
setusercharsize(3,0,3,0);
settextstyle(4,0,0);
outtextxy(30,109,"\"SAVE ME\"");
outtextxy(160,209,"\"SON\"");
delay(1000);
}
///////////////////////////end of countdown function/////////////////////

void  draw()
{
 int i=130,p=0,q=1,r=0,rectsize=360,j;
 char choice;
 if(drawing==0)
 {
 clearviewport();
  setfillstyle(SOLID_FILL,BLACK);
 while(i>0)
  {
	setcolor(p);
	for(j=0;j<7;j++)
	{
     //  fillellipse(290,240,a,300);
	 rectangle(100-rectsize,100-rectsize,400-rectsize,400-rectsize);

	rectsize--;
	}
	i--;
	p=q;
	q=r;
	r=p;
	delay(50);
	}
	settextstyle(7,0,0);
	i=50;
	while(i>0) // loop for printing ellipse on main game screen
	{ setcolor(14);
	fillellipse(290,50,280-i,50-i);
	i--;
     delay(50);
	}
 setusercharsize(2,1,2,1);
 setcolor(14);
 outtextxy(60,5,"SAVE");
 delay(500);
 outtextxy(250,5,"ME");
 delay(500);
 outtextxy(390,5,"SON");
 delay(500);
// line(450,175,390,97);
// line(450,175,300,100); speak lines
 setusercharsize(1,0,1,0);    //for setting type for entering the letter
 settextstyle(0,0,0);
  delay(500);
setcolor(15);
  rectangle(90,160,265,310);
  rectangle(380,390,510,410);//platform
  line(380,390,510,390); //horizontal line
  line(380,390,400,360); //leftslant
  line(400,360,490,360); //small horizontal
  line(490,360,510,390); //right slant
  i=7;
  setfillstyle(SOLID_FILL,WHITE);
  while(i>0)
  {
  setcolor(GREEN);//lighting on platform
  fillellipse(399,400,i,i);
  fillellipse(418,400,i,i);
  fillellipse(436,400,i,i);
  fillellipse(454,400,i,i);
  fillellipse(472,400,i,i);
  fillellipse(491,400,i,i);
  i--;
  }

  for(i=0;i<2;i++)
 {
 setcolor(15);
 circle(450,160,30+i); //head
 line(450+i,190,450+i,290);//dorsal
 line(450+i,190,410+i,250);  //our left, hand
 line(450+i,190,490+i,250); //our right, hand
 line(450+i,290,410+i,380);//our left ,leg
 line(450+i,290,490+i,380);//our right , leg
 line(450,158,446,168);  //rightside slant nose
 line(450,158,454,168);//left side slant nose
 line(446,168,454,168);//horizontal nose
 //setcolor(RED);
 fillellipse(440,150 ,2,2);//our left , eye
 fillellipse(460,150 ,2,2);// our right,eye
 line(440,175,460,175);//mouth
}drawing++;
delay(500);
}
else
{
 clearviewport();
  setfillstyle(SOLID_FILL,BLACK);
 while(i>0)
  {
	setcolor(p);
	for(j=0;j<7;j++)
	{
     //  fillellipse(290,240,a,300);
	 rectangle(100-rectsize,100-rectsize,400-rectsize,400-rectsize);

	rectsize--;
	}
	i--;
	p=q;
	q=r;
	r=p;
  //	delay(50);
	}
	settextstyle(7,0,0);
	i=50;
	while(i>0) // loop for printing ellipse on main game screen
	{ setcolor(14);
	fillellipse(290,50,280-i,50-i);
	i--;
	//delay(50);
	}
 setusercharsize(2,1,2,1);
 setcolor(14);
 outtextxy(60,5,"SAVE");
// delay(500);
 outtextxy(250,5,"ME");
// delay(500);
 outtextxy(390,5,"SON");
// delay(500);
// line(450,175,390,97);
// line(450,175,300,100); speak lines
 setusercharsize(1,0,1,0);    //for setting typr fo enter the letter
 settextstyle(0,0,0);
//  delay(500);
setcolor(15);
  rectangle(90,150,265,310);
  rectangle(380,390,510,410);//platform
  line(380,390,510,390); //horizontal line
  line(380,390,400,360); //leftslant
  line(400,360,490,360); //small horizontal
  line(490,360,510,390); //right slant
  i=7;
  setfillstyle(SOLID_FILL,WHITE);
  while(i>0)
  {
  setcolor(GREEN);//lighting on platform
  fillellipse(399,400,i,i);
  fillellipse(418,400,i,i);
  fillellipse(436,400,i,i);
  fillellipse(454,400,i,i);
  fillellipse(472,400,i,i);
  fillellipse(491,400,i,i);
  i--;
  }

  for(i=0;i<2;i++)
 {
 setcolor(15);
 circle(450,160,30+i); //head
 line(450+i,190,450+i,290);//dorsal
 line(450+i,190,410+i,250);  //our left, hand
 line(450+i,190,490+i,250); //our right, hand
 line(450+i,290,410+i,380);//our left ,leg
 line(450+i,290,490+i,380);//our right , leg
 line(450,158,446,168);  //rightside slant nose
 line(450,158,454,168);//left side slant nose
 line(446,168,454,168);//horizontal nose
 //setcolor(RED);
 fillellipse(440,150 ,2,2);//our left , eye
 fillellipse(460,150 ,2,2);// our right,eye
 line(440,175,460,175);//mouth
}drawing++;
//delay(500);
}
}
//////////////////////end of draw function///////////////////////////////
void gameloop(int level)
{

	char words[MAXNUMWORDS][MAXWORDLENGTH];
	int WordsReadIn = 0;
	char input[64];
	int randomIndex ;
	char buf[10];
	int correct;
	int oldCorrect ;
	int length;
	int quit ;
	int i=80 ,j;
	int reguessed ;
	char guess[16];
	char letterEntered,asd;
	int letterGuessed[16];
	FILE *pToFile = fopen("test.txt","r");
	char choice;
      //	int nolocal=no;
	setusercharsize(1,1,1,1);
	settextstyle(0,0,0);
	srand(time(NULL));
	if(pToFile == NULL)
	{
		printf("Failed To Open File\n");

	}

	while(fgets(input, 63, pToFile))
	{
		sscanf(input, "%s", words[WordsReadIn]);
		WordsReadIn++;
	}
	fclose(pToFile);
	while(level<=3){
		// index for random word
	 randomIndex = rand() % WordsReadIn;
	 correct = 0;
	 oldCorrect = 0;
	length = strlen(words[randomIndex]);
	for(i=0; i<16; i++)
	letterGuessed[i] = 0;
	quit = 0;
	i = 0;
	reguessed = 0;
	lives=6;
	if(level==1){
		outtextxy(140,320,"LEVEL EASY");
		for( i = 0; i < length; i++){
		if(words[randomIndex][i]=='a'||words[randomIndex][i]=='e'||words[randomIndex][i]=='i'||words[randomIndex][i]=='o'||words[randomIndex][i]=='u')
		letterGuessed[i] = 1;}}
		if(level==2){ outtextxy(140,320,"LEVEL MEDIUM");
		for( i = 0; i < length; i++){
		if(words[randomIndex][i]=='a'||words[randomIndex][i]=='e'||words[randomIndex][i]=='i'||words[randomIndex][i]=='o'||words[randomIndex][i]=='u')
		{
			outtextxy(100+(10*i),270,"*");
			outtextxy(100+(10*i),252,"_");
			}}}
		 else if(level>=3){
		 outtextxy(140,320,"LEVEL HARD");}

		for( i = 0; i < length; i++)
		{
			if(letterGuessed[i] == 1)
			correct++;}
	// game loop
	while ( correct < length )
	{



		for( i = 0; i < length; i++)
		{
			if(letterGuessed[i] == 1)
			{
			sprintf(buf, "%c", words[randomIndex][i]);
				outtextxy(100+(10*i),250,buf);
			} else
			{
				outtextxy(100+(10*i),252,"_");
			}

		}

		//printf("\n");

		//printf("Number Correct So Far:%d\n",correct);
		//printf("Enter a letter:");
		 settextstyle(0,0,2);
		outtextxy(80,130,"Enter a letter:");
		settextstyle(0,0,0);
		gotoxy(45,9);
		fgets(guess, 16, stdin);

		if( strncmp(guess, "quit", 4) == 0) {//menu and hidden options
			quit = 1;
			break;
		}

		if( strncmp(guess, "win", 3) == 0) {
			win = 1;
			break;
		}

		if( strncmp(guess, "cheat", 5) == 0) {
		       //	gotoxy(10,50);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nCheater!\n %s\n",words[randomIndex]);
		}

		if( strncmp(guess, "menu", 4) == 0) {
			call_menu();
		}


		letterEntered = guess[0];
		reguessed = 0;

		//printf("letterEntered:%c\n",letterEntered);

		oldCorrect = correct;

		for( i = 0; i < length; i++)
		{
					if(letterGuessed[i] == 1||letterGuessed[i] == 2)
			{
				if(words[randomIndex][i] == letterEntered) {
					reguessed = 1;
					break;
				}
				continue;
			}

			if( letterEntered == words[randomIndex][i] )
			{
				letterGuessed[i] = 1;
				correct++;
			}

		}

		if( oldCorrect == correct && reguessed == 0)
		{
					lives--;
		       //printf("Sorry, wrong guess\n");
			if (lives == 0)
			{
			   change();
			    break;
			}
		} else if( reguessed == 1)
		{

			//printf("Already Guessed!!\n");
		} else
		{
			//printf("Correct guess :)\n");
		}
	change();
	} // while loop

	if( quit == 1 ) {
	   exit(0);
	} else if (lives == 0)
		{  settextstyle(0,0,2);
			      outtextxy(80,350,"\nSorry you lose\n");
	       settextstyle(0,0,0);
	       //	printf("\nSorry you lose, the word was: %s\n",
			sprintf(buf, "%c", words[randomIndex][i]);
				outtextxy(100+(10*i),250,buf);
	       //	words[randomIndex]);
		win=0;
	     //	winlose();
		break;

	} else
	{          settextstyle(0,0,2);
	       outtextxy(100,400,"\nYOU WIN!\n");
		settextstyle(0,0,0);
		for(i=0; i<length; i++)
		{
		sprintf(buf, "%c", words[randomIndex][i]);
				outtextxy(100+(10*i),250,buf);}
		//win=1;
		//nolocal--;
		//if(nolocal==0)
		level++;
		if(level>3)
		break;
		draw();

		gameloop(level);
		break;

		}


    }
	if(level>3){
		win=1;}

}
/////////////////////////end of game loop///////////////////////////////
void change()
{
  int i;
setcolor(RED);
switch(lives)
{
case 0: for(i=0;i<2;i++)
	circle(450,160,30+i); //head
	 i=7;
	 while(i>0)
  {
  setcolor(RED);//lighting on platform
  fillellipse(399,400,i,i);
  i--;
  }

	 break;
case 1: for(i=0;i<2;i++)
	{//delay(1000);
	line(450+i,190,450+i,290);  } //dorsal

	   i=7;while(i>0)
  {
  setcolor(RED);//lighting on platform
 fillellipse(418,400,i,i);
  i--;
  }

	   break;
case 2:   for(i=0;i<2;i++)
	  line(450+i,190,410+i,250);  //our left, hand
	  i=7;
	  while(i>0)
  {
  setcolor(RED);//lighting on platform
  fillellipse(436,400,i,i);
  i--;
  }
break;
case 3:  for(i=0;i<2;i++)
	 line(450+i,190,490+i,250); //our right, hand
	  i=7;
	  while(i>0)
  {
  setcolor(RED);//lighting on platform
  fillellipse(454,400,i,i);
  i--;
  }
 break;
case 4:   for(i=0;i<2;i++)
	  line(450+i,290,410+i,380);//our left ,leg
	  i=7;
	  while(i>0)
  {
  setcolor(RED);//lighting on platform
  fillellipse(472,400,i,i);
  i--;
  }
break;
case 5:   for(i=0;i<2;i++)
	  line(450+i,290,490+i,380);//our right , leg
	  i=7;
	  while(i>0)
  {
  setcolor(RED);//lighting on platform
  fillellipse(491,400,i,i);
  i--;
  }
break;

}
}

void winlose()
{
int i,j,bk=0,mk=0,ak=0;
clearviewport();
switch(win)
{
case 0 : for(j=0;j<1;j++)
for(i=0;i<2;i++)
{setcolor(RED);
circle(490-j,100,30+i); //head
line(490-i-j,130,490-i-j,230);//dorsal
line(490-i-j,130,450-i-j,190);  //our left, hand
line(490-i-j,130,530-i-j,190); //our right, hand
line(490-i-j,230,450-i-j,320);//our left ,leg
line(490-i-j,230,530-i-j,320);//our right , leg
line(490-i-j,98,486-i-j,108);  //rightside slant nose
line(490-i-j,98,494-i-j,108);//left side slant nose
line(486-i-j,108,494-i-j,108);//horizontal nose
fillellipse(480-j,90,2,2);//our left , eye
fillellipse(500-j,90,2,2);// our right,eye
line(480-j,115,500-j,115);  //mouth
///////////////////////////////////////////////////
setcolor(WHITE);
circle(50+j,180,20+i); //head
line(50-i+j,200,50-i+j,260);//dorsal
line(50-i+j,200,27-i+j,230);  //our left, hand
line(50-i+j,200,73-i+j,230); //our right, hand
line(50-i+j,260,24-i+j,300);//our left ,leg
line(50-i+j,260,76-i+j,300);//our right , leg
fillellipse(40+j,175,1,1);//our left , eye
fillellipse(60+j,175,1,1);// our right,eye
}
outtextxy(80,150,"SORRY DAD I FAILED TO SAVE YOU FROM FLAYING");
delay(500);
outtextxy(80,170,"NOW MOM GONNA HIT ME WID BROOM ):");
delay(1000);
outtextxy(80,190,"I SHOULD GO HOME NOW");
delay(2000);
cleardevice();
for(j=0;j<=600;j++)           //going home
{
cleardevice();
for(i=0;i<1;i++)
{setcolor(WHITE);
circle(50+j,180,20+i); //head
line(50-i+j,200,50-i+j,260);//dorsal
line(50-i+j,200,27-i+j+bk,230);  //our left, hand
line(50-i+j,200,73-i+j-bk,230); //our right, hand
line(50-i+j,260,24-i+j+bk,300);//our left ,leg
line(50-i+j,260,76-i+j-bk,300);//our right , leg
fillellipse(40+j,175,1,1);//our left , eye
fillellipse(60+j,175,1,1);// our right,eye
if(bk!=46)
    bk++;
  else      //for boy's transition
    bk=0;
delay(12) ;
}
if(j==0)
{
line(420,100,520,100);
line(420,130,520,130);
line(420,100,420,130);
line(520,90,540,115);
line(520,100,520,90);       //board for towards home
line(520,130,520,140);
line(520,140,540,115);
rectangle(470,130,490,270);
outtextxy(425,110,"TOWARDS HOME");
delay(2000);
}

}
break;
case 1:
for(j=0;j<1;j++)
for(i=0;i<2;i++)
{setcolor(WHITE);
circle(490-j,100,30+i); //head
line(490-i-j,130,490-i-j,230);//dorsal
line(490-i-j,130,450-i-j,190);  //our left, hand
line(490-i-j,130,530-i-j,190); //our right, hand
line(490-i-j,230,450-i-j,320);//our left ,leg
line(490-i-j,230,530-i-j,320);//our right , leg
line(490-i-j,98,486-i-j,108);  //rightside slant nose
line(490-i-j,98,494-i-j,108);//left side slant nose
line(486-i-j,108,494-i-j,108);//horizontal nose
fillellipse(480-j,90,2,2);//our left , eye
fillellipse(500-j,90,2,2);// our right,eye
line(480-j,115,500-j,115);  //mouth
///////////////////////////////////////////////////   for son
circle(50+j,180,20+i); //head
line(50-i+j,200,50-i+j,260);//dorsal
line(50-i+j,200,27-i+j,230);  //our left, hand
line(50-i+j,200,73-i+j,230); //our right, hand
line(50-i+j,260,24-i+j,300);//our left ,leg
line(50-i+j,260,76-i+j,300);//our right , leg
fillellipse(40+j,175,1,1);//our left , eye
fillellipse(60+j,175,1,1);// our right,eye
}
outtextxy(200,100,"THANK YOU , FOR SAVING ME SON");
delay(500);
outtextxy(200,120,"LETS GO HOME");
delay(1000);
outtextxy(100,180,"SURE DAD , HERE WE GO");
delay(2000);
setcolor(0);
outtextxy(200,100,"THANK YOU , FOR SAVING ME SON");
outtextxy(200,120,"LETS GO HOME");
outtextxy(100,180,"SURE DAD , HERE WE GO");
for(j=0;j<=175;j++)
{
 cleardevice();
for(i=0;i<2;i++)
{setcolor(WHITE);
circle(490-j,100,30+i); //head
line(490-i-j,130,490-i-j,230);//dorsal
line(490-i-j,130,450-i-j+mk,190);  //our left, hand
line(490-i-j,130,530-i-j-mk,190); //our right, hand
line(490-i-j,230,450-i-j+mk,320);//our left ,leg
line(490-i-j,230,530-i-j-mk,320);//our right , leg
line(490-i-j,98,486-i-j,108);  //rightside slant nose
line(490-i-j,98,494-i-j,108);//left side slant nose
line(486-i-j,108,494-i-j,108);//horizontal nose
fillellipse(480-j,90,2,2);//our left , eye
fillellipse(500-j,90,2,2);// our right,eye
line(480-j,115,500-j,115);  //mouth
if(mk!=80)
    mk++;
  else               //for father's transition
    mk=0;
//  for son
circle(50+j,180,20+i); //head
line(50-i+j,200,50-i+j,260);//dorsal
line(50-i+j,200,27-i+j+ak,230);  //our left, hand
line(50-i+j,200,73-i+j-ak,230); //our right, hand
line(50-i+j,260,24-i+j+ak,300);//our left ,leg
line(50-i+j,260,76-i+j-ak,300);//our right , leg
fillellipse(40+j,175,1,1);//our left , eye
fillellipse(60+j,175,1,1);// our right,eye
if(ak!=46)
    ak++;
  else              //for boy's transition
    ak=0;
delay(10) ;
}
}
line(420,100,520,100);
line(420,130,520,130);
line(420,100,420,130);   //board for towards home
line(520,90,540,115);
line(520,100,520,90);
line(520,130,520,140);
line(520,140,540,115);
rectangle(470,130,490,270);
outtextxy(425,110,"TOWARDS HOME ");
delay(2000);
mk=ak=0;
for(j=0;j<=450;j++)           //going home
{
 cleardevice();
for(i=0;i<2;i++)
{setcolor(WHITE);
circle(315+j,100,30+i); //head
line(315-i+j,130,315-i+j,230);//dorsal
line(315-i+j,130,275-i+j+mk,190);  //our left, hand
line(315-i+j,130,355-i+j-mk,190); //our right, hand
line(315-i+j,230,275-i+j+mk,320);//our left ,leg
line(315-i+j,230,355-i+j-mk,320);//our right , leg
line(315-i+j,98,311-i+j,108);  //rightside slant nose
line(315-i+j,98,319-i+j,108);//left side slant nose
line(311-i+j,108,319-i+j,108);//horizontal nose
fillellipse(305+j,90,2,2);//our left , eye
fillellipse(325+j,90,2,2);// our right,eye
line(305+j,115,325+j,115);  //mouth
if(mk!=80)
    mk++;
  else
    mk=0;
//   for son
circle(225+j,180,20+i); //head
line(225-i+j,200,225-i+j,260);//dorsal
line(225-i+j,200,202-i+j+ak,230);  //our left, hand
line(225-i+j,200,248-i+j-ak,230); //our right, hand
line(225-i+j,260,199-i+j+ak,300);//our left ,leg
line(225-i+j,260,251-i+j-ak,300);//our right , leg
fillellipse(215+j,175,1,1);//our left , eye
fillellipse(235+j,175,1,1);// our right,eye
if(ak!=46)
    ak++;
  else
    ak=0;
delay(10) ;
}
}
}
}
///////////////////////end of winlose function///////////////////////
void credits()
{
int i=0,j,p,x,y,k,counter=0;
for(i=450;i>0;i-=2)
{
cleardevice();
settextstyle(0,0,0);
setcolor(15);
outtextxy(250,i,"CREDITS");

outtextxy(250,i+20,"AURO77");

delay(37);
}

clearviewport();
delay(700);
clearviewport();
j=-100;
for(i=500;i>=300;i--)
{
setbkcolor(0);
setusercharsize(3,0,3,0);
settextstyle(4,0,0);
fillellipse(300,150,250,100);
setcolor(0);
outtextxy(j,80,"THE");
outtextxy(i,80,"END");
if(j<100)
j++;
delay(5);
}
settextstyle(0,0,0);
setcolor(15);
outtextxy(150,310,"YOUR INTEREST IN OUR GAME IS APPREICATED");
outtextxy(90,320,"WE THANK YOU  FROM BOTTOM OF OUR HEART FOR CHOOSING US");

}
//////////////////end of credits function///////////////////////////
int main()
{
       int gd=DETECT, gm;
       clrscr();
       initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
       disclaimer();
call_menu();
winlose();
credits();
getch();
closegraph();
return 0;
}
////////////////////end of main function//////////////////////
