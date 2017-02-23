
     // snake game for the tech expo
#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include<process.h>
#include <dos.h>
/* the names of the text styles supported */
int dice;
char *fname[] = { "DEFAULT font",
		  "TRIPLEX font",
		  "SMALL font",
		  "SANS SERIF font",
		  "GOTHIC font"
		};
char *fname1[] = { "EMPTY_FILL",
		  "SOLID_FILL",
		  "LINE_FILL",
		  "LTSLASH_FILL",
		  "SLASH_FILL",
		  "BKSLASH_FILL",
		  "LTBKSLASH_FILL",
		  "HATCH_FILL",
		  "XHATCH_FILL",
		  "INTERLEAVE_FILL",
		  "WIDE_DOT_FILL",
		  "CLOSE_DOT_FILL",
		  "USER_FILL"
		};

char *lname[] = {
   "SOLID_LINE",
   "DOTTED_LINE",
   "CENTER_LINE",
   "DASHED_LINE",
   "USERBIT_LINE"
   };

   char name1[100] , name2[100];

  int player1=0 , player2=0 , lastposition;
void disp_dice()
{

setfillstyle(SOLID_FILL , 4);
 rectangle(350,130,380,160);
gotoxy(46,11);
 printf("%d" , dice);
 setcolor(11);
line(350,130,365,115);
line(380 ,130,395,115);
line(365,115,395,115);
line(395, 145  ,395,115);
line(380,160,395,145);
}


void ladder()
{

setlinestyle(SOLID_LINE, 1, 200);
setcolor(BLUE);
line(0 , 34 , 10 , 115);
line(25 , 34 , 35 , 115);
line(4 , 55 , 26, 50);
line(5 , 67 , 27, 62);
line(6 , 79 , 28+1, 74);
line(7 , 91 , 29+1, 86);
line(8 , 103 , 32, 98);
}
void ladder2()
{
setcolor(GREEN);
setlinestyle(SOLID_LINE , 1 , 10);
line(105 , 85 , 306 , 327);
line(135 , 80 , 336 , 320);
line(120 , 102 , 140, 83);
line(130 , 115 , 150, 96);
line(140 , 128 , 160, 109);
line(150 , 141 , 170, 122);
line(160 , 154 , 180, 135);
line(170 , 167 , 190, 148);
line(180 , 180 , 200, 161);
line(192 , 193 , 210, 174);
line(204 , 206 , 222, 187);
line(212 , 219 , 230, 200);
line(225 , 232 , 244, 210);
line(236 , 245 , 254, 226);
line(247 , 258 , 265, 239);
line(257 , 271 , 276, 252);
line(267 , 284 , 286, 265);
line(277 , 297 , 300, 278);
line(287 , 310 , 310, 291);
line(297 , 323 , 320, 304);

}
  void ladder3()
  {
	setcolor(YELLOW);
  setlinestyle(SOLID_LINE , 1 , 7);
line(105 , 300 , 146 , 246);
line(130 , 305 , 167 , 253);
line(140 , 252 , 155 , 270);
line(128 , 265 , 143 , 283);
line(116 , 278 , 131 , 296);

}
void snake3()
{
setcolor(7);
setlinestyle(SOLID_LINE , 1 , 7);
arc(5,30,300,0,100);
arc(25,30,305,0,100);
	   line(56,96,84,92);
line(104,30,115,20);
line(124,30,115,20);
line(115,20,113,18);
line(115 ,20,117,18);
setcolor(2);
circle(118,28,1);

}
void snake1()
{
    setcolor(CYAN);
   setlinestyle(SOLID_LINE , 1 , 7);
   arc(80,180,150,180,40);
   arc(80,180,180,253,40);
   arc(51,246,293,70,50);
   arc(98,180,150,180,40);
   arc(98,180,146,248,40);
   arc(77,247,265,55,45);
   arc(70,247,35,76,50);
   line(44,165,58,155);
   line(63,163,58,155);
   line(58,155,61,152);
   line(58,155,67,152);
     setfillstyle(SOLID_FILL,10);
   setcolor(15);
   circle(50,165,1);

}
void snake2()
{
setcolor(13);
arc(118 ,60 ,320,0,170);
arc(132 ,60 ,305,0,170);
line(257,136,229,169);
line(287 , 60 ,295 ,45);
line(302 , 60 ,295, 45);
line(295,45, 290,41);
line(295,45 ,300,41);
setfillstyle(SOLID_FILL ,13);

setcolor(14);
circle(295 , 55 ,1);
}
void numbering()
{
       settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
	      setcolor(WHITE);
     outtextxy(5 , 10 , "100  99  98   97  96  95  94  93  92  91");
     outtextxy(5 , 40 , " 81  82  83   84  85  86  87  88  89  90");
     outtextxy(5 , 75 , " 80  79  78   77  76  75  74  73  72  71");
     outtextxy(5 , 105 ," 61  62  63   64  65  66  67  68  69  70");
     outtextxy(5 , 140 ," 60  59  58   57  56  55  54  53  52  51");
     outtextxy(5 , 175 ," 41  42  43   44  45  46  47  48  49  50");
     outtextxy(5 , 210 ," 40  39  38   37  36  35  34  33  32  31");
     outtextxy(5 , 245 ," 21  22  23   24  25  26  27  28  29  30");
     outtextxy(5 , 280 ," 20  19  18   17  16  15  14  13  12  11");
     outtextxy(5 , 315 ,"  1   2   3    4   5   6   7   8   9  10");
     }
void board()
{
 int i , j , k ;
      delay(100);
      setbkcolor(0);
       setcolor(RED);

    /* loop to create rectangle on board */
   for (i=1; i<=10; i++)
   {
    for(j=1 ; j<=10 ; j++)
   {

      rectangle(34*i , 34*j , 0 , 0);

     }
   for(k=i ; k<=10 ; k++)
    {
   rectangle(34 , 34*k , 0 , 0);

   }
    }
    ladder();
    ladder2();
    ladder3();
    snake1();
    snake2();
    snake3();

}
void welcome()
{
float octave[]={130.81 , 146.83 , 164.81 , 174.61 , 196 , 220 , 246.94} ;
float n;
int i;
for(i=0 ; i<50 ; i++)
{
n=random(4);
sound(octave[n]*4);
snake1();
ladder2();
ladder3();
snake2();
ladder();
delay(40);
nosound();
}
    }
    void play_dice2(int*score)
    {
    dice=random(6)+1;
    gotoxy(35,17);
    printf("\n you got %d point on dice !!!" , dice);
    disp_dice();
    *score=*score+dice;gotoxy(35,18);
    printf("\n you are at position %d" , *score);
    switch(*score)
    {

case 61:*score=81;
break;
case 17: *score=25;
break;
case 10: *score=77;
break;
case 89: *score=54;
break;
case 59: *score=18;
break;
case 1:*score=1; break;
case 2:*score=2; break;
case 3:*score=3; break;
case 4:*score=4; break;
case 5:*score=5; break;
case 6:*score=6; break;
case 7:*score=7; break;
case 8:*score=8; break;
case 9:*score=9; break;
case 11:*score=11; break;
case 12:*score=12; break;
case 13:*score=13; break;
case 14:*score=14; break;
case 15:*score=15; break;
case 16:*score=16; break;
case 18:*score=18; break;
case 19:*score=19; break;
case 20:*score=20; break;
case 21:*score=21; break;
case 22:*score=22; break;
case 23:*score=23; break;
case 24:*score=24; break;
case 25:*score=25; break;
case 26:*score=26; break;
case 27:*score=27; break;
case 28:*score=28; break;
case 29:*score=29; break;
case 30:*score=30; break;
case 31:*score=31; break;
case 32:*score=32; break;
case 33:*score=33; break;
case 34:*score=34; break;
case 35:*score=35; break;
case 41:*score=41; break;
case 36:*score=36; break;
case 37:*score=37; break;
case 38:*score=38; break;
case 39:*score=39; break;
case 40:*score=40; break;
case 42:*score=42; break;
case 43:*score=43; break;
case 44:*score=44; break;
case 45:*score=45; break;
case 46:*score=46; break;
case 47:*score=47; break;
case 48:*score=48; break;
case 49:*score=49; break;
case 50:*score=50; break;
case 51:*score=51; break;
case 52:*score=52; break;
case 53:*score=53; break;
case 54:*score=54; break;
case 55:*score=55; break;
case 56:*score=56; break;
case 57:*score=57; break;
case 58:*score=58; break;
case 60:*score=60; break;
case 62:*score=62; break;
case 63:*score=63; break;
case 64:*score=64; break;
case 65:*score=65; break;
case 66:*score=66; break;
case 67:*score=67; break;
case 68:*score=68; break;
case 69:*score=69; break;
case 70:*score=70; break;
case 71:*score=71; break;
case 72:*score=72; break;
case 73:*score=73; break;
case 74:*score=74; break;
case 75:*score=75; break;
case 76:*score=76; break;
case 77:*score=77; break;
case 78:*score=78; break;
case 79:*score=79; break;
case 80:*score=80; break;
case 81:*score=81; break;
case 82:*score=82; break;
case 83:*score=83; break;
case 84:*score=84; break;
case 85:*score=85; break;
case 86:*score=86; break;
case 87:*score=87; break;
case 88:*score=88; break;
case 90:*score=90; break;
case 91:*score=91; break;
case 92:*score=92; break;
case 93:*score=93; break;
case 94:*score=94; break;
case 95:*score=95; break;
case 96:*score=96; break;
case 97:*score=79; break;
case 98:*score=98; break;
case 99:*score=99; break;
case 100:*score=100;
}}

void play_dice(int *score)
{
dice=random(6)+1;
gotoxy(35,14);
printf("\n you got %d point on dice!!" , dice );
disp_dice();
*score=*score+dice;
gotoxy(35,15);
printf("\n you are at position %d" , *score);

switch(*score)
{
case 61:*score=81;
break;
case 17: *score=25;
break;
case 10: *score=77;
break;
case 89: *score=54;
break;
case 59: *score=18;
break;
case 1:*score=1; break;
case 2:*score=2; break;
case 3:*score=3; break;
case 4:*score=4; break;
case 5:*score=5; break;
case 6:*score=6; break;
case 7:*score=7; break;
case 8:*score=8; break;
case 9:*score=9; break;
case 11:*score=11; break;
case 12:*score=12; break;
case 13:*score=13; break;
case 14:*score=14; break;
case 15:*score=15; break;
case 16:*score=16; break;
case 18:*score=18; break;
case 19:*score=19; break;
case 20:*score=20; break;
case 21:*score=21; break;
case 22:*score=22; break;
case 23:*score=23; break;
case 24:*score=24; break;
case 25:*score=25; break;
case 26:*score=26; break;
case 27:*score=27; break;
case 28:*score=28; break;
case 29:*score=29; break;
case 30:*score=30; break;
case 31:*score=31; break;
case 32:*score=32; break;
case 33:*score=33; break;
case 34:*score=34; break;
case 35:*score=35; break;
case 41:*score=41; break;
case 36:*score=36; break;
case 37:*score=37; break;
case 38:*score=38; break;
case 39:*score=39; break;
case 40:*score=40; break;
case 42:*score=42; break;
case 43:*score=43; break;
case 44:*score=44; break;
case 45:*score=45; break;
case 46:*score=46; break;
case 47:*score=47; break;
case 48:*score=48; break;
case 49:*score=49; break;
case 50:*score=50; break;
case 51:*score=51; break;
case 52:*score=52; break;
case 53:*score=53; break;
case 54:*score=54; break;
case 55:*score=55; break;
case 56:*score=56; break;
case 57:*score=57; break;
case 58:*score=58; break;
case 60:*score=60; break;
case 62:*score=62; break;
case 63:*score=63; break;
case 64:*score=64; break;
case 65:*score=65; break;
case 66:*score=66; break;
case 67:*score=67; break;
case 68:*score=68; break;
case 69:*score=69; break;
case 70:*score=70; break;
case 71:*score=71; break;
case 72:*score=72; break;
case 73:*score=73; break;
case 74:*score=74; break;
case 75:*score=75; break;
case 76:*score=76; break;
case 77:*score=77; break;
case 78:*score=78; break;
case 79:*score=79; break;
case 80:*score=80; break;
case 81:*score=81; break;
case 82:*score=82; break;
case 83:*score=83; break;
case 84:*score=84; break;
case 85:*score=85; break;
case 86:*score=86; break;
case 87:*score=87; break;
case 88:*score=88; break;
case 90:*score=90; break;
case 91:*score=91; break;
case 92:*score=92; break;
case 93:*score=93; break;
case 94:*score=94; break;
case 95:*score=95; break;
case 96:*score=96; break;
case 97:*score=79; break;
case 98:*score=98; break;
case 99:*score=99; break;
case 100:*score=100;
}}

void gscore(int p1,int p2)
{   setcolor(GREEN);
settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 2);
outtextxy(375,10, " GAME STATUS!!");
setcolor(10);
settextstyle(SMALL_FONT , HORIZ_DIR , 4);
moveto(350,40);
setcolor(4);
outtext("PLAYER 1");
setcolor(8);
outtextxy(390,40,"   is at position \n");
gotoxy(45,5);
setcolor(14);
printf("%d" ,p1);
moveto(350,70);
setcolor(4);
outtext("PLAYER 2");
setcolor(8);
outtextxy(390,70,"   is at position \n");
gotoxy(45,7);
setcolor(14);
printf("%d" ,p2);
}
	      void win1()
	      {        clrscr();
	      setbkcolor(12);
	      settextstyle(GOTHIC_FONT , HORIZ_DIR , 10);
	      sound(500);
	      setcolor(0);
	      gotoxy(15,30);
	      printf("%s WINS !!!! " , name1);
	      delay(200);
	      nosound();
	      }
	       void win2()
	      {      clrscr();
	      setbkcolor(4);
	      settextstyle(GOTHIC_FONT , HORIZ_DIR , 10);
	      sound(500);
	      setcolor(0);
	      gotoxy(15,30);
	      printf("%s WINS !!!! " , name2);
	      delay(200);
	      nosound();
	      }
int main(void)
{

   int gdriver = EGA, gmode = EGAHI, errorcode;
   int i , j , k ,bkcol  , midx , midy;
   int size=6;
   int style;
     randomize();
  initgraph(&gdriver, &gmode, "");
 errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1);
     }
     // for starting of screen
	       setbkcolor(0);
	      settextstyle(GOTHIC_FONT , HORIZ_DIR , size);
	       outtextxy(30 , 0 , "SNAKES");
	       outtextxy(230 , 60 , "AND");
	       outtextxy(350 , 120 , "LADDER !!");
	      welcome();
    cleardevice();
  setbkcolor(14);
     // for player entry
     setcolor(4);
     settextstyle(GOTHIC_FONT , HORIZ_DIR , 6);
  outtextxy(200 , 50 , "WELCOME");
     settextstyle(SANS_SERIF_FONT , HORIZ_DIR , 2);
  outtextxy(135 , 195 , "PLAYER 1 :");
   gotoxy(45 , 15);
   scanf("%s" ,name1);
    settextstyle(SANS_SERIF_FONT , HORIZ_DIR , 2);
  outtextxy(135 , 245 , "PLAYER 2 :");
   gotoxy(45 , 19);
   scanf("%s" ,name2);
   clrscr();
   cleardevice();
      //game screen
     board();
     numbering();
  disp_dice();

       while(player1<=100&&player2<=100)
{

board();
numbering();
disp_dice();
gscore(player1 , player2);
setcolor(YELLOW);
gotoxy(50 ,13);
printf("%s" , name1);
printf(" - NOW YOUR TURN");
getch();
sound(100);
delay(50);
nosound();
lastposition=player1;
play_dice(&player1);  //call
gscore(player1,player2);
if(player1==54||player1==18||player1==79)
{
 gotoxy(45,14);
printf("\n  YOU ARE AT POSITION%d\n" , player1);
}
else if(player1==81||player1==25||player1==77)
{
	 gotoxy(45,14);
printf(" YOU ARE AT POSITION %d" , player1);
}
else if(player1>=100)
{         gotoxy(40,35);
delay(400);
	 printf("\n PLAYER %s WINS " , name1);
	 win1();
	 delay(3000);
	 exit(1);
	 }
gotoxy(50,15);
printf("%s" ,name2);
printf(" - NOW YOUR TURN ");
getch();
sound(90);
delay(50);
nosound();
lastposition=player2;
play_dice2(&player2);
gscore(player1,player2);
if(player2==54||player2==18||player2==79)
{
      gotoxy(50,16);
//printf("oops!!! a snake find !!!");
printf(" YOU ARE AT POSITION %d" , player2);
}
else if(player2==81||player2==25||player2==77)
 {   gotoxy(45,16);
//printf("GREAT!! YOU GOT LADDER");
printf("YOU ARE AT POSITION %d" , player2);
}
	else if(player2>=100)
	 {   gotoxy(40,35);
		  delay(400);
	 printf("\n PLAYER %s WINS" , name2);
	 win2();
	 delay(2500);
	 exit(0);
	 }
	 delay(850);
	 clrscr();
      cleardevice();
	}
      getch();
      closegraph();
   return 0;
   }











