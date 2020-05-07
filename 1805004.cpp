# define _CRT_SECURE_NO_WARNINGS
# include "iGraphics.h"
# include <math.h>
# define m acos(-1)
double x = 300.0, y = 300.0, r = 50.0;
double x3[3];
double y3[3];
int dx=2;
int flag1=1;
int flag2=0;
double t;
int r1[]={100,100,480,100};//x coordinates
int r2[]={100,100,100,550};//y coordinates
int r3[]={10,380,10,380};//width
int r4[]={450,10,460,10};//height
double dc, ac;
double degangle=0;
double radangle;

void iDraw() {

    if(flag1==1){
	iClear();

	iSetColor(255, 0, 0);
	iFilledCircle(x, y, r);

    iSetColor(255,255,0);
    iLine(x,y,x3[2],y3[2]);

    iSetColor(255,255,0);
    iFilledPolygon(x3,y3,3);

    iSetColor(0,0,255);
    iFilledRectangle(r1[0],r2[0],r3[0],r4[0]);
    iFilledRectangle(r1[1],r2[1],r3[1],r4[1]);
    iFilledRectangle(r1[2],r2[2],r3[2],r4[2]);
    iFilledRectangle(r1[3],r2[3],r3[3],r4[3]);
}
    if(flag1==0)
    {
    iClear();

    iSetColor(0, 0, 255);
	iFilledCircle(x, y, r);

    iSetColor(255,255,0);
    iLine(x,y,x3[2],y3[2]);

    iSetColor(255,255,0);
    iFilledPolygon(x3,y3,3);


    iSetColor(255,0,0);
    iFilledRectangle(r1[0],r2[0],r3[0],r4[0]);
    iFilledRectangle(r1[1],r2[1],r3[1],r4[1]);
    iFilledRectangle(r1[2],r2[2],r3[2],r4[2]);
    iFilledRectangle(r1[3],r2[3],r3[3],r4[3]);
    }

    iText(30,30,"PRESS p FOR PAUSE, r FOR RESUME, end for terminate",GLUT_BITMAP_9_BY_15);



}
double radianangle(double degangle)
{
    return ((m*degangle)/180);
}


void runningplus()
{
    radangle=radianangle(degangle);
    x=x+dx*cos(radangle);
    y=y+dx*sin(radangle);
    if(x+r>r1[2]||x-r<r1[0]+10)
    {
       degangle=180-degangle;
       t=flag2;
       flag2=flag1;
       flag1=t;
    }
    if(y+r>r2[3]||y-r<r2[1]+10)
    {
       degangle=-degangle;
       t=flag2;
       flag2=flag1;
       flag1=t;
    }

    x3[2]=x+r*cos(radangle);
    y3[2]=y+r*sin(radangle);
    dc=3*r/5;
    ac=2*r/5;
    x3[0]=x+(dc*cos(radangle))-(ac*sin(radangle));//rotation of axis
    y3[0]=y+(dc*sin(radangle))+(ac*cos(radangle));
    x3[1]=x+(dc*cos(radangle))+(ac*sin(radangle));//sign opposition of ac
    y3[1]=y+(dc*sin(radangle))-(ac*cos(radangle));

}

void iMouseMove(int mx, int my) {

}

void iMouse(int button, int state, int mx, int my) {

}

void iKeyboard(unsigned char key)
{

   if(key=='a')
   {
       r1[0]--;
       r1[1]--;
       r1[2]--;
       r1[3]--;
       x--;
       x3[0]--;
       x3[1]--;
       x3[2]--;

   }
   if(key=='d')
   {
       r1[0]++;
       r1[1]++;
       r1[2]++;
       r1[3]++;
        x++;
       x3[0]++;
       x3[1]++;
       x3[2]++;
   }
   if(key=='s')
   {
       r2[0]--;
       r2[1]--;
       r2[2]--;
       r2[3]--;
       y--;
       y3[0]--;
       y3[1]--;
       y3[2]--;
   }
   if(key=='w')
   {
       r2[0]++;
       r2[1]++;
       r2[2]++;
       r2[3]++;
        y++;
       y3[0]++;
       y3[1]++;
       y3[2]++;
   }
   if(key=='p')
   {
       iPauseTimer(0);
   }
   if(key=='r')
   {
       iResumeTimer(0);
   }
}



void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
    if(key == GLUT_KEY_LEFT)
	{
        degangle+=4;
        runningplus();

    }


	if(key == GLUT_KEY_RIGHT)
	{
	    degangle-=4;
        runningplus();
	}


}


int main() {

    iSetTimer(1,runningplus);
	iInitialize(700, 600, "A SIMPLE GAME");
	return 0;
}
