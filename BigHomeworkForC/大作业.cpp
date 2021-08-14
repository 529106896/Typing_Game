#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <graphics.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include"mmsystem.h"

#pragma comment(lib,"Winmm.lib")

#define Height 740						//窗口尺寸
#define Width 640

//砖墙结构体
struct brick_wall
{
	int brick_width = Width / 15;
	int brick_height = 25;
	int brick_count = 5;
};

//每一列砖墙是一个结构体
brick_wall Brick[15];

int velocity = 3;

//字母结构体
struct MyChar
{
	int position_x = 0;
	int position_y = 0;
	int v_y = velocity;
	int counts = 0;
};

//每个字母都是个结构体
MyChar letter_Q;
MyChar letter_W;
MyChar letter_R;
MyChar letter_T;
MyChar letter_Y;
MyChar letter_U;
MyChar letter_I;
MyChar letter_O;
MyChar letter_P;
MyChar letter_E;
MyChar letter_A; 
MyChar letter_S;
MyChar letter_D;
MyChar letter_F;
MyChar letter_G;
MyChar letter_H;
MyChar letter_J;
MyChar letter_K;
MyChar letter_L;
MyChar letter_Z;
MyChar letter_X;
MyChar letter_C;
MyChar letter_V;
MyChar letter_B;
MyChar letter_N;
MyChar letter_M;

//背景图
IMAGE img_bk;
IMAGE img_startmenu_bk;

//键盘图
IMAGE img_keyboard;

IMAGE img_lose1;
IMAGE img_lose2;

IMAGE img_notice1;
IMAGE img_notice2;

//字母的图片
IMAGE Char_Q1, Char_Q2;
IMAGE Char_W1, Char_W2;
IMAGE Char_E1, Char_E2;
IMAGE Char_R1, Char_R2;
IMAGE Char_T1, Char_T2;
IMAGE Char_Y1, Char_Y2;
IMAGE Char_U1, Char_U2;
IMAGE Char_I1, Char_I2;
IMAGE Char_O1, Char_O2;
IMAGE Char_P1, Char_P2;
IMAGE Char_A1, Char_A2;
IMAGE Char_S1, Char_S2;
IMAGE Char_D1, Char_D2;
IMAGE Char_F1, Char_F2;
IMAGE Char_G1, Char_G2;
IMAGE Char_H1, Char_H2;
IMAGE Char_J1, Char_J2;
IMAGE Char_K1, Char_K2;
IMAGE Char_L1, Char_L2;
IMAGE Char_Z1, Char_Z2;
IMAGE Char_X1, Char_X2;
IMAGE Char_C1, Char_C2;
IMAGE Char_V1, Char_V2;
IMAGE Char_B1, Char_B2;
IMAGE Char_N1, Char_N2;
IMAGE Char_M1, Char_M2;

TCHAR letter_A_count[5];
TCHAR letter_B_count[5];
TCHAR letter_C_count[5];
TCHAR letter_D_count[5];
TCHAR letter_E_count[5];
TCHAR letter_F_count[5];
TCHAR letter_G_count[5];
TCHAR letter_H_count[5];
TCHAR letter_I_count[5];
TCHAR letter_J_count[5];
TCHAR letter_K_count[5];
TCHAR letter_L_count[5];
TCHAR letter_M_count[5];
TCHAR letter_N_count[5];
TCHAR letter_O_count[5];
TCHAR letter_P_count[5];
TCHAR letter_Q_count[5];
TCHAR letter_R_count[5];
TCHAR letter_S_count[5];
TCHAR letter_T_count[5];
TCHAR letter_U_count[5];
TCHAR letter_V_count[5];
TCHAR letter_W_count[5];
TCHAR letter_X_count[5];
TCHAR letter_Y_count[5];
TCHAR letter_Z_count[5];


//用来测试的字符串
char choice[1000] = "C language is the best language in the world";
char hello_world[] = "include stdio.h int main printf hello world n return";
char add[] = "include stdio.h int main int a int b scanf a b printf a b n return";
char Alphabet[] = "AAABBBCCCDDDEEEFFFGGGHHHIIIJJJKKKLLLMMMNNNOOOPPPQQQRRRSSSTTTUUUVVVWWWXXXYYYZZZ";
char Default[] = "C language is the best language in the world";

int score_default = 36;
int score_hello_world = 43;
int score_add = 50;
int score_alphabet = 78;

////当前选择练习的程序段
char choose[20] = "Default";

//得分
int score;

//游戏状态，0为开始界面，1为正常游戏，2为结束游戏，3为游戏暂停
int gameStatus = 0;

//评分机制
double evaluate(int score_choose)
{
	int brick_left = 5;
	for (int i = 0; i < 15; i++)
	{
		if(brick_left > Brick[i].brick_count)
			brick_left = Brick[i].brick_count;
	}
	double sum1 = (double)score / (double)score_choose;
	double sum2 = (double)brick_left / 5.00;
	double sum3 = (double)velocity / 15.00;
	double sum = sum1 * 50 + sum2 * 20 + sum3 * 30;
	return sum;
}

//对所有字符进行初始化
void checkString(char String[])
{
	letter_Q.counts = 0;
	letter_W.counts = 0;
	letter_E.counts = 0;
	letter_R.counts = 0;
	letter_T.counts = 0;
	letter_Y.counts = 0;
	letter_U.counts = 0;
	letter_I.counts = 0;
	letter_O.counts = 0;
	letter_P.counts = 0;
	letter_A.counts = 0;
	letter_S.counts = 0;
	letter_D.counts = 0;
	letter_F.counts = 0;
	letter_G.counts = 0;
	letter_H.counts = 0;
	letter_J.counts = 0;
	letter_K.counts = 0;
	letter_L.counts = 0;
	letter_Z.counts = 0;
	letter_X.counts = 0;
	letter_C.counts = 0;
	letter_V.counts = 0;
	letter_B.counts = 0;
	letter_N.counts = 0;
	letter_M.counts = 0;

	for (int i = 0; String[i]; i++)
	{
		if (String[i] == 'Q' || String[i] == 'q')
		{
			letter_Q.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_Q.position_x = rand() % (620 - 10 + 1) + 10;
			letter_Q.counts++;
		}
		if (String[i] == 'W' || String[i] == 'w')
		{
			letter_W.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_W.position_x = rand() % (620 - 20 + 1) + 20;
			letter_W.counts++;
		}
		if (String[i] == 'E' || String[i] == 'e')
		{
			letter_E.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_E.position_x = rand() % (620 - 20 + 1) + 20;
			letter_E.counts++;
		}
		if (String[i] == 'R' || String[i] == 'r')
		{
			letter_R.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_R.position_x = rand() % (620 - 20 + 1) + 20;
			letter_R.counts++;
		}
		if (String[i] == 'T' || String[i] == 't')
		{
			letter_T.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_T.position_x = rand() % (620 - 20 + 1) + 20;
			letter_T.counts++;
		}
		if (String[i] == 'Y' || String[i] == 'y')
		{
			letter_Y.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_Y.position_x = rand() % (620 - 20 + 1) + 20;
			letter_Y.counts++;
		}
		if (String[i] == 'U' || String[i] == 'u')
		{
			letter_U.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_U.position_x = rand() % (620 - 20 + 1) + 20;
			letter_U.counts++;
		}
		if (String[i] == 'I' || String[i] == 'i')
		{
			letter_I.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_I.position_x = rand() % (620 - 20 + 1) + 20;
			letter_I.counts++;
		}
		if (String[i] == 'O' || String[i] == 'o')
		{
			letter_O.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_O.position_x = rand() % (620 - 20 + 1) + 20;
			letter_O.counts++;
		}
		if (String[i] == 'P' || String[i] == 'p')
		{
			letter_P.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_P.position_x = rand() % (620 - 20 + 1) + 20;
			letter_P.counts++;
		}
		if (String[i] == 'A' || String[i] == 'a')
		{
			letter_A.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_A.position_x = rand() % (620 - 20 + 1) + 20;
			letter_A.counts++;
		}
		if (String[i] == 'S' || String[i] == 's')
		{
			letter_S.position_y = rand() % (-200 + 100 + 1) - 100;;
			letter_S.position_x = rand() % (620 - 20 + 1) + 20;
			letter_S.counts++;
		}
		if (String[i] == 'D' || String[i] == 'd')
		{
			letter_D.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_D.position_x = rand() % (620 - 20 + 1) + 20;
			letter_D.counts++;
		}
		if (String[i] == 'F' || String[i] == 'f')
		{
			letter_F.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_F.position_x = rand() % (620 - 20 + 1) + 20;
			letter_F.counts++;
		}
		if (String[i] == 'G' || String[i] == 'g')
		{
			letter_G.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_G.position_x = rand() % (620 - 20 + 1) + 20;
			letter_G.counts++;
		}
		if (String[i] == 'H' || String[i] == 'h')
		{
			letter_H.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_H.position_x = rand() % (620 - 20 + 1) + 20;
			letter_H.counts++;
		}
		if (String[i] == 'J' || String[i] == 'j')
		{
			letter_J.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_J.position_x = rand() % (620 - 20 + 1) + 20;
			letter_J.counts++;
		}
		if (String[i] == 'K' || String[i] == 'k')
		{
			letter_K.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_K.position_x = rand() % (620 - 20 + 1) + 20;
			letter_K.counts++;
		}
		if (String[i] == 'L' || String[i] == 'l')
		{
			letter_L.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_L.position_x = rand() % (620 - 20 + 1) + 20;
			letter_L.counts++;
		}
		if (String[i] == 'Z' || String[i] == 'z')
		{
			letter_Z.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_Z.position_x = rand() % (620 - 20 + 1) + 20;
			letter_Z.counts++;
		}
		if (String[i] == 'X' || String[i] == 'x')
		{
			letter_X.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_X.position_x = rand() % (620 - 20 + 1) + 20;
			letter_X.counts++;
		}
		if (String[i] == 'C' || String[i] == 'c')
		{
			letter_C.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_C.position_x = rand() % (620 - 20 + 1) + 20;
			letter_C.counts++;
		}
		if (String[i] == 'V' || String[i] == 'v')
		{
			letter_V.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_V.position_x = rand() % (620 - 20 + 1) + 20;
			letter_V.counts++;
		}
		if (String[i] == 'B' || String[i] == 'b')
		{
			letter_B.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_B.position_x = rand() % (620 - 20 + 1) + 20;
			letter_B.counts++;
		}
		if (String[i] == 'N' || String[i] == 'n')
		{
			letter_N.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_N.position_x = rand() % (620 - 20 + 1) + 20;
			letter_N.counts++;
		}
		if (String[i] == 'M' || String[i] == 'm')
		{
			letter_M.position_y = rand() % (-20 + 200 +1)-200 ;
			letter_M.position_x = rand() % (620 - 20 + 1) + 20;
			letter_M.counts++;
		}
	}
}

//初始化砖墙
void init_brick_wall()
{
	for (int i = 0; i < 15; i++)
	{
		Brick[i].brick_count = 5;
	}
}

//进行下落速度的更新
void veloctiy_change()
{
	letter_Q.v_y = velocity;
	letter_W.v_y = velocity;
	letter_E.v_y = velocity;
	letter_R.v_y = velocity;
	letter_T.v_y = velocity;
	letter_Y.v_y = velocity;
	letter_U.v_y = velocity;
	letter_I.v_y = velocity;
	letter_O.v_y = velocity;
	letter_P.v_y = velocity;
	letter_A.v_y = velocity;
	letter_S.v_y = velocity;
	letter_D.v_y = velocity;
	letter_F.v_y = velocity;
	letter_G.v_y = velocity;
	letter_H.v_y = velocity;
	letter_J.v_y = velocity;
	letter_K.v_y = velocity;
	letter_L.v_y = velocity;
	letter_Z.v_y = velocity;
	letter_X.v_y = velocity;
	letter_C.v_y = velocity;
	letter_V.v_y = velocity;
	letter_B.v_y = velocity;
	letter_N.v_y = velocity;
	letter_M.v_y = velocity;
}

//开始界面
void startMenu()
{
	loadimage(&img_startmenu_bk, ".\\key\\startmenu_bk.png",800,740);	//开始界面背景图
	putimage(0, 0, &img_startmenu_bk);
	FlushBatchDraw();
	Sleep(2);

	velocity = 3;
	veloctiy_change();
	score = 0;
	checkString(choice);
	init_brick_wall();

	MOUSEMSG msg;
	
	if (MouseHit())
	{
		msg = GetMouseMsg();
		//printf("%d,%d\n", msg.x, msg.y);
		if (msg.x >= 320 && msg.x <= 517 && msg.y >= 551 && msg.y <= 580)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				gameStatus = 1;
				mciSendString("close submusic", NULL, 0, NULL);
				mciSendString("open .\\key\\letter_erase.wav alias submusic", NULL, 0, NULL);
				mciSendString("play submusic", NULL, 0, NULL);
			}
		}
		if (msg.x >= 386 && msg.x <= 455 && msg.y >= 627 && msg.y <= 655)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				gameStatus = 2;
				exit(0);
			}
		}
	}
}

//暂停界面
void pauseMenu()
{
	cleardevice();
	settextcolor(WHITE);
	settextstyle(40, 0, _T("微软雅黑"));
	outtextxy(Width * 0.5, Height * 0.2, _T("1 Resume"));
	outtextxy(Width * 0.5, Height * 0.3, _T("2 Restart"));
	outtextxy(Width * 0.5, Height * 0.4, _T("3 Exit"));

	settextstyle(30, 0, _T("黑体"));
	outtextxy(Width * 0.3, Height * 0.6 + 10, _T("Drop Speed:"));
	TCHAR m[20];
	_stprintf(m, _T("%d"), velocity);
	outtextxy(Width * 0.3 + 275, Height * 0.6 + 10, m);
	settextstyle(50, 0, _T("黑体"));
	outtextxy(Width * 0.3 + 220, Height * 0.6, _T("+"));
	outtextxy(Width * 0.3 + 350, Height * 0.6, _T("-"));

	TCHAR a[20];
	_stprintf(a, _T("%s"), choose);
	settextstyle(30, 0, _T("黑体"));
	outtextxy(Width * 0.2, Height * 0.7, _T("Current Program:"));
	outtextxy(Width * 0.6, Height * 0.7, a);

	outtextxy(Width * 0.6, Height * 0.75, _T("A.Alphabet"));
	outtextxy(Width * 0.6, Height * 0.8, _T("B.Hello World"));
	outtextxy(Width * 0.6, Height * 0.85, _T("C.Add two Integer"));
	outtextxy(Width * 0.6, Height * 0.9, _T("D.Default"));

	MOUSEMSG msg;

	if (MouseHit())
	{
		msg = GetMouseMsg();
		if (msg.x >= 350 && msg.x <= 465 && msg.y <= 180 && msg.y >= 155)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				gameStatus = 1;
				mciSendString("close restartmusic", NULL, 0, NULL);
				mciSendString("open .\\key\\Restart.mp3 alias restartmusic", NULL, 0, NULL);
				mciSendString("play restartmusic", NULL, 0, NULL);
			}
		}
		if (msg.x >= 350 && msg.x <= 452 && msg.y <= 255 && msg.y >= 230)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				score = 0;
				checkString(choice);
				init_brick_wall();
				gameStatus = 1;
				mciSendString("close resumemusic", NULL, 0, NULL);
				mciSendString("open .\\key\\Exit.mp3 alias resumemusic", NULL, 0, NULL);
				mciSendString("play resumemusic", NULL, 0, NULL);
			}
		}
		if (msg.x >= 350 && msg.x <= 400 && msg.y <= 330 && msg.y >= 304)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				gameStatus = 2;
				exit(0); 
			}
		}
		if (msg.x >= 413 && msg.x <= 437 && msg.y <= 480 && msg.y >= 459)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				velocity += 1;
				if (velocity > 15)
				{
					velocity = 15;
				}
				veloctiy_change();
			}
		}
		if (msg.x >= 542 && msg.x <= 566 && msg.y <= 475 && msg.y >= 464)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{

				velocity -= 1;
				if (velocity < 1)
				{
					velocity = 1;
				}
				veloctiy_change();
			}
		}
		if (msg.x >= 382 && msg.x <= 532 && msg.y <= 582 && msg.y >= 561)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				score = 0;
				memset(choice, '\0', sizeof(choice));
				strcpy(choose, "Alphabet");
				strcpy(choice, Alphabet);
				checkString(choice);
				init_brick_wall();
			}
		}
		if (msg.x >= 382 && msg.x <= 578 && msg.y <= 618 && msg.y >= 598)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				score = 0;
				memset(choice, '\0', sizeof(choice));
				strcpy(choose, "Hello World");
				strcpy(choice, hello_world);
				checkString(choice);
				init_brick_wall();
			}
		}
		if (msg.x >= 382 && msg.x <= 637 && msg.y <= 655 && msg.y >= 633)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				score = 0;
				memset(choice, '\0', sizeof(choice));
				strcpy(choose, "Add two Integer");
				strcpy(choice, add);
				checkString(choice);
				init_brick_wall();
			}
		}
		if (msg.x >= 382 && msg.x <= 520 && msg.y <= 690 && msg.y >= 670)
		{
			if (msg.uMsg == WM_LBUTTONDOWN)
			{
				score = 0;
				memset(choice, '\0', sizeof(choice));
				strcpy(choose, "Default");
				strcpy(choice, Default);
				checkString(choice);
				init_brick_wall();
			}
		}
	}
	FlushBatchDraw();
}

//加载所有图片
void loadallimage()
{
	loadimage(&img_keyboard, ".\\key\\key_board.jpg", 587, 200);		//键盘图
	loadimage(&img_bk, ".\\key\\bk.jpg", 640, 740);				//背景图

	loadimage(&img_lose1, ".\\key\\lose.png");
	loadimage(&img_lose2, ".\\key\\lose2.png");

	loadimage(&img_notice1, ".\\key\\notice1.png",36,30);
	loadimage(&img_notice2, ".\\key\\notice2.png",36,30);

	loadimage(&Char_Q1, ".\\key\\letter\\Q1.png");				//Q
	loadimage(&Char_Q2, ".\\key\\letter\\Q2.png");
	loadimage(&Char_W1, ".\\key\\letter\\W1.png");				//W
	loadimage(&Char_W2, ".\\key\\letter\\W2.png");
	loadimage(&Char_E1, ".\\key\\letter\\E1.png");				//E
	loadimage(&Char_E2, ".\\key\\letter\\E2.png");
	loadimage(&Char_R1, ".\\key\\letter\\R1.png");				//R
	loadimage(&Char_R2, ".\\key\\letter\\R2.png");
	loadimage(&Char_T1, ".\\key\\letter\\T1.png");				//T
	loadimage(&Char_T2, ".\\key\\letter\\T2.png");
	loadimage(&Char_Y1, ".\\key\\letter\\Y1.png");				//Y
	loadimage(&Char_Y2, ".\\key\\letter\\Y2.png");
	loadimage(&Char_U1, ".\\key\\letter\\U1.png");				//U
	loadimage(&Char_U2, ".\\key\\letter\\U2.png");
	loadimage(&Char_I1, ".\\key\\letter\\I1.png");				//I
	loadimage(&Char_I2, ".\\key\\letter\\I2.png");
	loadimage(&Char_O1, ".\\key\\letter\\O1.png");				//O
	loadimage(&Char_O2, ".\\key\\letter\\O2.png");
	loadimage(&Char_P1, ".\\key\\letter\\P1.png");				//P
	loadimage(&Char_P2, ".\\key\\letter\\P2.png");
	loadimage(&Char_A1, ".\\key\\letter\\A1.png");				//A
	loadimage(&Char_A2, ".\\key\\letter\\A2.png");
	loadimage(&Char_S1, ".\\key\\letter\\S1.png");				//S
	loadimage(&Char_S2, ".\\key\\letter\\S2.png");
	loadimage(&Char_D1, ".\\key\\letter\\D1.png");				//D
	loadimage(&Char_D2, ".\\key\\letter\\D2.png");
	loadimage(&Char_F1, ".\\key\\letter\\F1.png");				//F
	loadimage(&Char_F2, ".\\key\\letter\\F2.png");
	loadimage(&Char_G1, ".\\key\\letter\\G1.png");				//G
	loadimage(&Char_G2, ".\\key\\letter\\G2.png");
	loadimage(&Char_H1, ".\\key\\letter\\H1.png");				//H
	loadimage(&Char_H2, ".\\key\\letter\\H2.png");
	loadimage(&Char_J1, ".\\key\\letter\\J1.png");				//J
	loadimage(&Char_J2, ".\\key\\letter\\J2.png");
	loadimage(&Char_K1, ".\\key\\letter\\K1.png");				//K
	loadimage(&Char_K2, ".\\key\\letter\\K2.png");
	loadimage(&Char_L1, ".\\key\\letter\\L1.png");				//L
	loadimage(&Char_L2, ".\\key\\letter\\L2.png");
	loadimage(&Char_Z1, ".\\key\\letter\\Z1.png");				//Z
	loadimage(&Char_Z2, ".\\key\\letter\\Z2.png");
	loadimage(&Char_X1, ".\\key\\letter\\X1.png");				//X
	loadimage(&Char_X2, ".\\key\\letter\\X2.png");
	loadimage(&Char_C1, ".\\key\\letter\\C1.png");				//C
	loadimage(&Char_C2, ".\\key\\letter\\C2.png");
	loadimage(&Char_V1, ".\\key\\letter\\V1.png");				//V
	loadimage(&Char_V2, ".\\key\\letter\\V2.png");
	loadimage(&Char_B1, ".\\key\\letter\\B1.png");				//B
	loadimage(&Char_B2, ".\\key\\letter\\B2.png");
	loadimage(&Char_N1, ".\\key\\letter\\N1.png");				//N
	loadimage(&Char_N2, ".\\key\\letter\\N2.png");
	loadimage(&Char_M1, ".\\key\\letter\\M1.png");				//M
	loadimage(&Char_M2, ".\\key\\letter\\M2.png");
}

//显示还剩余字母的个数
void letters_left_count()
{
	setcolor(WHITE);
	settextstyle(25, 0, _T("微软雅黑"));
	outtextxy(Width + 5, Height * 0.20, "剩余字母:");
	outtextxy(Width + 5, Height * 0.24, "A");
	_stprintf_s(letter_A_count, _T("%d"), letter_A.counts);
	outtextxy(Width + 25, Height * 0.24, letter_A_count);

	outtextxy(Width + 5, Height * 0.28, "B");
	_stprintf_s(letter_B_count, _T("%d"), letter_B.counts);
	outtextxy(Width + 25, Height * 0.28, letter_B_count);

	outtextxy(Width + 5, Height * 0.32, "C");
	_stprintf_s(letter_C_count, _T("%d"), letter_C.counts);
	outtextxy(Width + 25, Height * 0.32, letter_C_count);

	outtextxy(Width + 5, Height * 0.36, "D");
	_stprintf_s(letter_D_count, _T("%d"), letter_D.counts);
	outtextxy(Width + 25, Height * 0.36, letter_D_count);

	outtextxy(Width + 5, Height * 0.40, "E");
	_stprintf_s(letter_E_count, _T("%d"), letter_E.counts);
	outtextxy(Width + 25, Height * 0.40, letter_E_count);

	outtextxy(Width + 5, Height * 0.44, "F");
	_stprintf_s(letter_F_count, _T("%d"), letter_F.counts);
	outtextxy(Width + 25, Height * 0.44, letter_F_count);

	outtextxy(Width + 5, Height * 0.48, "G");
	_stprintf_s(letter_G_count, _T("%d"), letter_G.counts);
	outtextxy(Width + 25, Height * 0.48, letter_G_count);

	outtextxy(Width + 5, Height * 0.52, "H");
	_stprintf_s(letter_H_count, _T("%d"), letter_H.counts);
	outtextxy(Width + 25, Height * 0.52, letter_H_count);

	outtextxy(Width + 5, Height * 0.56, "I");
	_stprintf_s(letter_I_count, _T("%d"), letter_I.counts);
	outtextxy(Width + 25, Height * 0.56, letter_I_count);

	outtextxy(Width + 5, Height * 0.60, "J");
	_stprintf_s(letter_J_count, _T("%d"), letter_J.counts);
	outtextxy(Width + 25, Height * 0.60, letter_J_count);

	outtextxy(Width + 5, Height * 0.64, "K");
	_stprintf_s(letter_K_count, _T("%d"), letter_K.counts);
	outtextxy(Width + 25, Height * 0.64, letter_K_count);

	outtextxy(Width + 5, Height * 0.68, "L");
	_stprintf_s(letter_L_count, _T("%d"), letter_L.counts);
	outtextxy(Width + 25, Height * 0.68, letter_L_count);

	outtextxy(Width + 5, Height * 0.72, "M");
	_stprintf_s(letter_M_count, _T("%d"), letter_M.counts);
	outtextxy(Width + 25, Height * 0.72, letter_M_count);

	outtextxy(Width + 55, Height * 0.24, "N");
	_stprintf_s(letter_N_count, _T("%d"), letter_N.counts);
	outtextxy(Width + 75, Height * 0.24, letter_N_count);

	outtextxy(Width + 55, Height * 0.28, "O");
	_stprintf_s(letter_O_count, _T("%d"), letter_O.counts);
	outtextxy(Width + 75, Height * 0.28, letter_O_count);

	outtextxy(Width + 55, Height * 0.32, "P");
	_stprintf_s(letter_P_count, _T("%d"), letter_P.counts);
	outtextxy(Width + 75, Height * 0.32, letter_P_count);

	outtextxy(Width + 55, Height * 0.36, "Q");
	_stprintf_s(letter_Q_count, _T("%d"), letter_Q.counts);
	outtextxy(Width + 75, Height * 0.36, letter_Q_count);

	outtextxy(Width + 55, Height * 0.40, "R");
	_stprintf_s(letter_R_count, _T("%d"), letter_R.counts);
	outtextxy(Width + 75, Height * 0.40, letter_R_count);

	outtextxy(Width + 55, Height * 0.44, "S");
	_stprintf_s(letter_S_count, _T("%d"), letter_S.counts);
	outtextxy(Width + 75, Height * 0.44, letter_S_count);

	outtextxy(Width + 55, Height * 0.48, "T");
	_stprintf_s(letter_T_count, _T("%d"), letter_T.counts);
	outtextxy(Width + 75, Height * 0.48, letter_T_count);

	outtextxy(Width + 55, Height * 0.52, "U");
	_stprintf_s(letter_U_count, _T("%d"), letter_U.counts);
	outtextxy(Width + 75, Height * 0.52, letter_U_count);

	outtextxy(Width + 55, Height * 0.56, "V");
	_stprintf_s(letter_V_count, _T("%d"), letter_V.counts);
	outtextxy(Width + 75, Height * 0.56, letter_V_count);

	outtextxy(Width + 55, Height * 0.60, "W");
	_stprintf_s(letter_W_count, _T("%d"), letter_W.counts);
	outtextxy(Width + 75, Height * 0.60, letter_W_count);

	outtextxy(Width + 55, Height * 0.64, "X");
	_stprintf_s(letter_X_count, _T("%d"), letter_X.counts);
	outtextxy(Width + 75, Height * 0.64, letter_X_count);

	outtextxy(Width + 55, Height * 0.68, "Y");
	_stprintf_s(letter_Y_count, _T("%d"), letter_Y.counts);
	outtextxy(Width + 75, Height * 0.68, letter_Y_count);

	outtextxy(Width + 55, Height * 0.72, "Z");
	_stprintf_s(letter_Z_count, _T("%d"), letter_Z.counts);
	outtextxy(Width + 75, Height * 0.72, letter_Z_count);
}

//显示函数
void show()
{
	while (gameStatus == 3)
	{
		pauseMenu();
	}

	//显示背景图
	putimage(0, 0, &img_bk);

	//显示键盘图
	putimage(26, 540, &img_keyboard);

	setfillcolor(BLACK);
	solidrectangle(Width, 0, Width + 160, Height);

	//显示玩家分数
	setcolor(WHITE);
	settextstyle(25, 0, _T("微软雅黑"));
	setbkmode(TRANSPARENT);
	TCHAR a[] = _T("正确输入:");
	outtextxy(Width+5, Height * 0.02, a);
	TCHAR defen[20];
	_stprintf_s(defen, _T("%d"), score);
	outtextxy(Width+10, Height * 0.06, defen);

	//显示当前练习的程序
	setcolor(WHITE);
	TCHAR t[] = _T("目前程序:");
	outtextxy(Width+5, Height * 0.10, t);
	outtextxy(Width+10, Height * 0.14, choose);

	letters_left_count();

	//显示底
	setfillcolor(YELLOW);
	solidrectangle(5, 360, 635, 380);

	//画砖墙
	setlinecolor(BLACK);
	setfillcolor(YELLOW);
	settextcolor(RED);
	TCHAR count[20];
	for (int i = 0; i < 15; i++)
	{
		_stprintf(count, _T("%d"), Brick[i].brick_count);
		outtextxy(20 + i * Brick[i].brick_width, 520, count);
		for (int j = 0; j < Brick[i].brick_count; j++)
			fillrectangle(5 + i * Brick[i].brick_width, 515 - j * Brick[i].brick_height, (i + 1) * Brick[i].brick_width, 520 - (j + 1) * Brick[i].brick_height);
	}
	
	if (letter_Q.counts)
	{
		putimage(letter_Q.position_x, letter_Q.position_y, &Char_Q1, SRCINVERT);
		putimage(letter_Q.position_x, letter_Q.position_y, &Char_Q2, NOTSRCERASE);
		if (letter_Q.position_x <= 640 && letter_Q.position_y >= 0)	//Q
		{
			putimage(90, 601, &img_notice1, SRCINVERT);
			putimage(90, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_W.counts)
	{
		putimage(letter_W.position_x, letter_W.position_y, &Char_W1, SRCINVERT);
		putimage(letter_W.position_x, letter_W.position_y, &Char_W2, NOTSRCERASE);
		if (letter_W.position_x <= 640 && letter_W.position_y >= 0)	//W
		{
			putimage(130, 601, &img_notice1, SRCINVERT);
			putimage(130, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_E.counts)
	{
		putimage(letter_E.position_x, letter_E.position_y, &Char_E1, SRCINVERT);
		putimage(letter_E.position_x, letter_E.position_y, &Char_E2, NOTSRCERASE);
		if (letter_E.position_x <= 640 && letter_E.position_y >= 0)	//E
		{
			putimage(170, 601, &img_notice1, SRCINVERT);
			putimage(170, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_R.counts)
	{
		putimage(letter_R.position_x, letter_R.position_y, &Char_R1, SRCINVERT);
		putimage(letter_R.position_x, letter_R.position_y, &Char_R2, NOTSRCERASE);
		if (letter_R.position_x <= 640 && letter_R.position_y >= 0)	//R
		{
			putimage(211, 601, &img_notice1, SRCINVERT);
			putimage(211, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_T.counts)
	{
		putimage(letter_T.position_x, letter_T.position_y, &Char_T1, SRCINVERT);
		putimage(letter_T.position_x, letter_T.position_y, &Char_T2, NOTSRCERASE);
		if (letter_T.position_x <= 640 && letter_T.position_y >= 0)	//T
		{
			putimage(252, 601, &img_notice1, SRCINVERT);
			putimage(252, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_Y.counts)
	{
		putimage(letter_Y.position_x, letter_Y.position_y, &Char_Y1, SRCINVERT);
		putimage(letter_Y.position_x, letter_Y.position_y, &Char_Y2, NOTSRCERASE);
		if (letter_Y.position_x <= 640 && letter_Y.position_y >= 0)	//Y
		{
			putimage(292, 601, &img_notice1, SRCINVERT);
			putimage(292, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_U.counts)
	{
		putimage(letter_U.position_x, letter_U.position_y, &Char_U1, SRCINVERT);
		putimage(letter_U.position_x, letter_U.position_y, &Char_U2, NOTSRCERASE);
		if (letter_U.position_x <= 640 && letter_U.position_y >= 0)	//U
		{
			putimage(332, 601, &img_notice1, SRCINVERT);
			putimage(332, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_I.counts)
	{
		putimage(letter_I.position_x, letter_I.position_y, &Char_I1, SRCINVERT);
		putimage(letter_I.position_x, letter_I.position_y, &Char_I2, NOTSRCERASE);
		if (letter_I.position_x <= 640 && letter_I.position_y >= 0)	//I
		{
			putimage(372, 601, &img_notice1, SRCINVERT);
			putimage(372, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_O.counts)
	{
		putimage(letter_O.position_x, letter_O.position_y, &Char_O1, SRCINVERT);
		putimage(letter_O.position_x, letter_O.position_y, &Char_O2, NOTSRCERASE);
		if (letter_O.position_x <= 640 && letter_O.position_y >= 0)	//O
		{
			putimage(412, 601, &img_notice1, SRCINVERT);
			putimage(412, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_P.counts)
	{
		putimage(letter_P.position_x, letter_P.position_y, &Char_P1, SRCINVERT);
		putimage(letter_P.position_x, letter_P.position_y, &Char_P2, NOTSRCERASE);
		if (letter_P.position_x <= 640 && letter_P.position_y >= 0)	//P
		{
			putimage(452, 601, &img_notice1, SRCINVERT);
			putimage(452, 601, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_A.counts)
	{
		putimage(letter_A.position_x, letter_A.position_y, &Char_A1, SRCINVERT);
		putimage(letter_A.position_x, letter_A.position_y, &Char_A2, NOTSRCERASE);
		if (letter_A.position_x <= 640 && letter_A.position_y >= 0)	//A
		{
			putimage(100, 636, &img_notice1, SRCINVERT);
			putimage(100, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_S.counts)
	{
		putimage(letter_S.position_x, letter_S.position_y, &Char_S1, SRCINVERT);
		putimage(letter_S.position_x, letter_S.position_y, &Char_S2, NOTSRCERASE);
		if (letter_S.position_x <= 640 && letter_S.position_y >= 0)	//S
		{
			putimage(140, 636, &img_notice1, SRCINVERT);
			putimage(140, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_D.counts)
	{
		putimage(letter_D.position_x, letter_D.position_y, &Char_D1, SRCINVERT);
		putimage(letter_D.position_x, letter_D.position_y, &Char_D2, NOTSRCERASE);
		if (letter_D.position_x <= 640 && letter_D.position_y >= 0)	//D
		{
			putimage(180, 636, &img_notice1, SRCINVERT);
			putimage(180, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_F.counts)
	{
		putimage(letter_F.position_x, letter_F.position_y, &Char_F1, SRCINVERT);
		putimage(letter_F.position_x, letter_F.position_y, &Char_F2, NOTSRCERASE);
		if (letter_F.position_x <= 640 && letter_F.position_y >= 0)	//F
		{
			putimage(220, 636, &img_notice1, SRCINVERT);
			putimage(220, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_G.counts)
	{
		putimage(letter_G.position_x, letter_G.position_y, &Char_G1, SRCINVERT);
		putimage(letter_G.position_x, letter_G.position_y, &Char_G2, NOTSRCERASE);
		if (letter_G.position_x <= 640 && letter_G.position_y >= 0)	//G
		{
			putimage(261, 636, &img_notice1, SRCINVERT);
			putimage(261, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_H.counts)
	{
		putimage(letter_H.position_x, letter_H.position_y, &Char_H1, SRCINVERT);
		putimage(letter_H.position_x, letter_H.position_y, &Char_H2, NOTSRCERASE);
		if (letter_H.position_x <= 640 && letter_H.position_y >= 0)	//H
		{
			putimage(301, 636, &img_notice1, SRCINVERT);
			putimage(301, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_J.counts)
	{
		putimage(letter_J.position_x, letter_J.position_y, &Char_J1, SRCINVERT);
		putimage(letter_J.position_x, letter_J.position_y, &Char_J2, NOTSRCERASE);
		if (letter_J.position_x <= 640 && letter_J.position_y >= 0)	//J
		{
			putimage(342, 636, &img_notice1, SRCINVERT);
			putimage(342, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_K.counts)
	{
		putimage(letter_K.position_x, letter_K.position_y, &Char_K1, SRCINVERT);
		putimage(letter_K.position_x, letter_K.position_y, &Char_K2, NOTSRCERASE);
		if (letter_K.position_x <= 640 && letter_K.position_y >= 0)	//K
		{
			putimage(382, 636, &img_notice1, SRCINVERT);
			putimage(382, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_L.counts)
	{
		putimage(letter_L.position_x, letter_L.position_y, &Char_L1, SRCINVERT);
		putimage(letter_L.position_x, letter_L.position_y, &Char_L2, NOTSRCERASE);
		if (letter_L.position_x <= 640 && letter_L.position_y >= 0)	//L
		{
			putimage(422, 636, &img_notice1, SRCINVERT);
			putimage(422, 636, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_Z.counts)
	{
		putimage(letter_Z.position_x, letter_Z.position_y, &Char_Z1, SRCINVERT);
		putimage(letter_Z.position_x, letter_Z.position_y, &Char_Z2, NOTSRCERASE);
		if (letter_Z.position_x <= 640 && letter_Z.position_y >= 0)	//Z
		{
			putimage(119, 670, &img_notice1, SRCINVERT);
			putimage(119, 670, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_X.counts)
	{
		putimage(letter_X.position_x, letter_X.position_y, &Char_X1, SRCINVERT);
		putimage(letter_X.position_x, letter_X.position_y, &Char_X2, NOTSRCERASE);
		if (letter_X.position_x <= 640 && letter_X.position_y >= 0)	//X
		{
			putimage(159, 670, &img_notice1, SRCINVERT);
			putimage(159, 670, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_C.counts)
	{
		putimage(letter_C.position_x, letter_C.position_y, &Char_C1, SRCINVERT);
		putimage(letter_C.position_x, letter_C.position_y, &Char_C2, NOTSRCERASE);
		if (letter_C.position_x <= 640 && letter_C.position_y >= 0)	//C
		{
			putimage(200, 670, &img_notice1, SRCINVERT);
			putimage(200, 670, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_V.counts)
	{
		putimage(letter_V.position_x, letter_V.position_y, &Char_V1, SRCINVERT);
		putimage(letter_V.position_x, letter_V.position_y, &Char_V2, NOTSRCERASE);
		if (letter_V.position_x <= 640 && letter_V.position_y >= 0)	//V
		{
			putimage(240, 670, &img_notice1, SRCINVERT);
			putimage(240, 670, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_B.counts)
	{
		putimage(letter_B.position_x, letter_B.position_y, &Char_B1, SRCINVERT);
		putimage(letter_B.position_x, letter_B.position_y, &Char_B2, NOTSRCERASE);
		if (letter_B.position_x <= 640 && letter_B.position_y >= 0)	//B
		{
			putimage(280, 670, &img_notice1, SRCINVERT);
			putimage(280, 670, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_N.counts)
	{
		putimage(letter_N.position_x, letter_N.position_y, &Char_N1, SRCINVERT);
		putimage(letter_N.position_x, letter_N.position_y, &Char_N2, NOTSRCERASE);
		if (letter_N.position_x <= 640 && letter_N.position_y >= 0)	//N
		{
			putimage(321, 670, &img_notice1, SRCINVERT);
			putimage(321, 670, &img_notice2, NOTSRCERASE);
		}
	}
	if (letter_M.counts)
	{
		putimage(letter_M.position_x, letter_M.position_y, &Char_M1, SRCINVERT);
		putimage(letter_M.position_x, letter_M.position_y, &Char_M2, NOTSRCERASE);
		if (letter_M.position_x <= 640 && letter_M.position_y >= 0)	//M
		{
			putimage(361, 670, &img_notice1, SRCINVERT);
			putimage(361, 670, &img_notice2, NOTSRCERASE);
		}
	}

	FlushBatchDraw();
	Sleep(50);
}

//判断游戏是否胜利
int victory()
{
	if (strcmp(choose, "Default") == 0)
	{
		if (score == score_default)
		{
			return 1;
		}
	}

	else if (strcmp(choose, "Alphabet") == 0)
	{
		if (score == score_alphabet)
		{
			return 1;
		}
	}

	else if (strcmp(choose, "Hello World") == 0)
	{
		if (score == score_hello_world)
		{
			return 1;
		}
	}

	else if (strcmp(choose, "Add two Integer") == 0)
	{
		if (score == score_add)
		{
			return 1;
		}
	}
	return 0;
}

//判断游戏是否失败
int gameover()
{
	for (int i = 0; i < 15; i++)
	{
		if (Brick[i].brick_count <= 0)
		{	
			putimage(i * Brick[i].brick_width, 480, &img_lose1, SRCINVERT);
			putimage(i * Brick[i].brick_width, 480, &img_lose2, NOTSRCERASE);
			return 0;
		}
	}
	return 1;
}

//与用户输入无关的更新
void updateWithoutInput()
{

	if (letter_Q.counts)
	{
		letter_Q.position_y += letter_Q.v_y;

		if (letter_Q.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_Q.position_x = rand() % (620 - 20 + 1) + 20;
			letter_Q.position_y = rand() % (-200 + 100 +1) -100;
		}

		if (letter_Q.position_x >= Width)
			letter_Q.position_x = rand() % (620 - 20 + 1) + 20;
	}

	if (letter_W.counts)
	{
		letter_W.position_y += letter_W.v_y;

		if (letter_W.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_W.position_x = rand() % (620 - 20 + 1) + 20;
			letter_W.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_W.position_x >= Width)
		{
			letter_W.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_E.counts)
	{
		letter_E.position_y += letter_E.v_y;

		if (letter_E.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_E.position_x = rand() % (620 - 20 + 1) + 20;
			letter_E.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_E.position_x >= Width)
		{
			letter_E.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_R.counts)
	{
		letter_R.position_y += letter_R.v_y;

		if (letter_R.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_R.position_x = rand() % (620 - 20 + 1) + 20;
			letter_R.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_R.position_x >= Width)
		{
			letter_R.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_T.counts)
	{
		letter_T.position_y += letter_T.v_y;

		if (letter_T.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_T.position_x = rand() % (620 - 20 + 1) + 20;
			letter_T.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_T.position_x >= Width)
		{
			letter_T.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_Y.counts)
	{
		letter_Y.position_y += letter_Y.v_y;

		if (letter_Y.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_Y.position_x = rand() % (620 - 20 + 1) + 20;
			letter_Y.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_Y.position_x >= Width)
		{
			letter_Y.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_U.counts)
	{
		letter_U.position_y += letter_U.v_y;

		if (letter_U.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_U.position_x = rand() % (620 - 20 + 1) + 20;
			letter_U.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_U.position_x >= Width)
		{
			letter_U.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_I.counts)
	{
		letter_I.position_y += letter_I.v_y;

		if (letter_I.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_I.position_x = rand() % (620 - 20 + 1) + 20;
			letter_I.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_I.position_x >= Width)
		{
			letter_I.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_O.counts)
	{
		letter_O.position_y += letter_O.v_y;

		if (letter_O.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_O.position_x = rand() % (620 - 20 + 1) + 20;
			letter_O.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_O.position_x >= Width)
		{
			letter_O.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_P.counts)
	{
		letter_P.position_y += letter_P.v_y;

		if (letter_P.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_P.position_x = rand() % (620 - 20 + 1) + 20;
			letter_P.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_P.position_x >= Width)
		{
			letter_P.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_A.counts)
	{
		letter_A.position_y += letter_A.v_y;

		if (letter_A.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_A.position_x = rand() % (620 - 20 + 1) + 20;
			letter_A.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_A.position_x >= Width)
		{
			letter_A.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_S.counts)
	{
		letter_S.position_y += letter_S.v_y;

		if (letter_S.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_S.position_x = rand() % (620 - 20 + 1) + 20;
			letter_S.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_S.position_x >= Width)
		{
			letter_S.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_D.counts)
	{
		letter_D.position_y += letter_D.v_y;

		if (letter_D.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_D.position_x = rand() % (620 - 20 + 1) + 20;
			letter_D.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_D.position_x >= Width)
		{
			letter_D.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_F.counts)
	{
		letter_F.position_y += letter_F.v_y;

		if (letter_F.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_F.position_x = rand() % (620 - 20 + 1) + 20;
			letter_F.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_F.position_x >= Width)
		{
			letter_F.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_G.counts)
	{
		letter_G.position_y += letter_G.v_y;

		if (letter_G.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_G.position_x = rand() % (620 - 20 + 1) + 20;
			letter_G.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_G.position_x >= Width)
		{
			letter_G.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_H.counts)
	{
		letter_H.position_y += letter_H.v_y;

		if (letter_H.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_H.position_x = rand() % (620 - 20 + 1) + 20;
			letter_H.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_H.position_x >= Width)
		{
			letter_H.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_J.counts)
	{
		letter_J.position_y += letter_J.v_y;

		if (letter_J.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_J.position_x = rand() % (620 - 20 + 1) + 20;
			letter_J.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_J.position_x >= Width)
		{
			letter_J.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_K.counts)
	{
		letter_K.position_y += letter_K.v_y;

		if (letter_K.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_K.position_x = rand() % (620 - 20 + 1) + 20;
			letter_K.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_K.position_x >= Width)
		{
			letter_K.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_L.counts)
	{
		letter_L.position_y += letter_L.v_y;

		if (letter_L.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_L.position_x = rand() % (620 - 20 + 1) + 20;
			letter_L.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_L.position_x >= Width)
		{
			letter_L.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_Z.counts)
	{
		letter_Z.position_y += letter_Z.v_y;

		if (letter_Z.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_Z.position_x = rand() % (620 - 20 + 1) + 20;
			letter_Z.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_Z.position_x >= Width)
		{
			letter_Z.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_X.counts)
	{
		letter_X.position_y += letter_X.v_y;

		if (letter_X.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_X.position_x = rand() % (620 - 20 + 1) + 20;
			letter_X.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_X.position_x >= Width)
		{
			letter_X.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_C.counts)
	{
		letter_C.position_y += letter_C.v_y;

		if (letter_C.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_C.position_x = rand() % (620 - 20 + 1) + 20;
			letter_C.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_C.position_x >= Width)
		{
			letter_C.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_V.counts)
	{
		letter_V.position_y += letter_V.v_y;

		if (letter_V.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_V.position_x = rand() % (620 - 20 + 1) + 20;
			letter_V.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_V.position_x >= Width)
		{
			letter_V.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_B.counts)
	{
		letter_B.position_y += letter_B.v_y;

		if (letter_B.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_B.position_x = rand() % (620 - 20 + 1) + 20;
			letter_B.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_B.position_x >= Width)
		{
			letter_B.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_N.counts)
	{
		letter_N.position_y += letter_N.v_y;

		if (letter_N.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_N.position_x = rand() % (620 - 20 + 1) + 20;
			letter_N.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_N.position_x >= Width)
		{
			letter_N.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	if (letter_M.counts)
	{
		letter_M.position_y += letter_M.v_y;

		if (letter_M.position_y > 340)
		{
			Brick[rand() % (15)].brick_count--;
			letter_M.position_x = rand() % (620 - 20 + 1) + 20;
			letter_M.position_y = rand() % (-20 + 200 +1)-200 ;
		}

		if (letter_M.position_x >= Width)
		{
			letter_M.position_x = rand() % (620 - 20 + 1) + 20;
		}
	}

	FlushBatchDraw();

	//判断游戏是否胜利
	if (victory() == 1)
	{
		mciSendString("close winmusic", NULL, 0, NULL);
		mciSendString("open .\\key\\victory.mp3 alias winmusic", NULL, 0, NULL);
		mciSendString("play winmusic", NULL, 0, NULL);
		settextcolor(RED);
		setbkmode(TRANSPARENT);
		settextstyle(40, 0, _T("Segoe Print"));
		outtextxy(Width / 2 - 75, Height / 3 - 15, _T("Victory!"));

		TCHAR zongping[20];

		if (strcmp(choose, "Default") == 0)
		{
			_stprintf_s(zongping, _T("%.2lf"), evaluate(score_default));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, zongping);
		}

		else if (strcmp(choose, "Alphabet") == 0)
		{
			_stprintf_s(zongping, _T("%.2lf"), evaluate(score_alphabet));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, zongping);
		}

		else if (strcmp(choose, "Hello World") == 0)
		{
			_stprintf_s(zongping, _T("%.2lf"), evaluate(score_hello_world));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, zongping);
		}

		else if (strcmp(choose, "Add two Integer") == 0)
		{
			_stprintf_s(zongping, _T("%.2lf"), evaluate(score_add));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, zongping);
		}

		outtextxy(Width / 5 + 20, Height / 3 + 45, _T("Back to start menu in 5 seconds"));
		FlushBatchDraw();
		Sleep(5000);
		gameStatus = 0;
	}

	//判断游戏是否结束
	if (gameover() == 0)
	{
		mciSendString("close losemusic", NULL, 0, NULL);
		mciSendString("open .\\key\\lose.mp3 alias losemusic", NULL, 0, NULL);
		mciSendString("play losemusic", NULL, 0, NULL);
		settextcolor(RED);
		setbkmode(TRANSPARENT);
		settextstyle(40, 0, _T("Segoe Print"));
		outtextxy(Width / 2 - 75, Height / 3 - 15, _T("You Lose!"));
		TCHAR pingce[20];

		if (strcmp(choose, "Default") == 0)
		{
			_stprintf_s(pingce, _T("%.2lf"), evaluate(score_default));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, pingce);
		}

		else if (strcmp(choose, "Alphabet") == 0)
		{
			_stprintf_s(pingce, _T("%.2lf"), evaluate(score_alphabet));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, pingce);
		}

		else if (strcmp(choose, "Hello World") == 0)
		{
			_stprintf_s(pingce, _T("%.2lf"), evaluate(score_hello_world));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, pingce);
		}

		else if (strcmp(choose, "Add two Integer") == 0)
		{
			_stprintf_s(pingce, _T("%.2lf"), evaluate(score_add));
			outtextxy(Width / 5 + 10, Height / 3 + 15, _T("Your score is:"));
			outtextxy(Width / 5 + 200, Height / 3 + 15, pingce);
		}

		outtextxy(Width / 5 + 20, Height / 3 + 45, _T("Back to start menu in 5 seconds"));

		FlushBatchDraw();
		Sleep(5000);
		gameStatus = 0;
	}
}

//与用户输入有关的更新
void updateWithInput()
{
	if(_kbhit())
	{
		if ((GetAsyncKeyState(0x1B) & 0x8000))//ESC暂停界面
			gameStatus = 3;

		if ((GetAsyncKeyState(0x51) & 0x8000))
		{
			if (letter_Q.counts && letter_Q.position_x <= 640 && letter_Q.position_y >= 0)
			{
				score++;
				letter_Q.counts--;
				letter_Q.position_x = rand() % (620 - 20 + 1) + 20;
				letter_Q.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x57) & 0x8000))	//W
		{
			if (letter_W.counts && letter_W.position_x <= 640 && letter_W.position_y >= 0)
			{

				score++;
				letter_W.counts--;
				letter_W.position_x = rand() % (620 - 20 + 1) + 20;
				letter_W.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x45) & 0x8000))	//E
		{
			if (letter_E.counts && letter_E.position_x <= 640 && letter_E.position_y >= 0)
			{

				score++;
				letter_E.counts--;
				letter_E.position_x = rand() % (620 - 20 + 1) + 20;
				letter_E.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x52) & 0x8000))	//R
		{
			if (letter_R.counts && letter_R.position_x <= 640 && letter_R.position_y >= 0)
			{

				score++;
				letter_R.counts--;
				letter_R.position_x = rand() % (620 - 20 + 1) + 20;
				letter_R.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x54) & 0x8000))	//T
		{
			if (letter_T.counts && letter_T.position_x <= 640 && letter_T.position_y >= 0)
			{

				score++;
				letter_T.counts--;
				letter_T.position_x = rand() % (620 - 20 + 1) + 20;
				letter_T.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x59) & 0x8000))	//Y
		{
			if (letter_Y.counts && letter_Y.position_x <= 640 && letter_Y.position_y >= 0)
			{

				score++;
				letter_Y.counts--;
				letter_Y.position_x = rand() % (620 - 20 + 1) + 20;
				letter_Y.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x55) & 0x8000))	//U
		{
			if (letter_U.counts && letter_U.position_x <= 640 && letter_U.position_y >= 0)
			{

				score++;
				letter_U.counts--;
				letter_U.position_x = rand() % (620 - 20 + 1) + 20;
				letter_U.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x49) & 0x8000))	//I
		{
			if (letter_I.counts && letter_I.position_x <= 640 && letter_I.position_y >= 0)
			{

				score++;
				letter_I.counts--;
				letter_I.position_x = rand() % (620 - 20 + 1) + 20;
				letter_I.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x4F) & 0x8000))	//O
		{
			if (letter_O.counts && letter_O.position_x <= 640 && letter_O.position_y >= 0)
			{

				score++;
				letter_O.counts--;
				letter_O.position_x = rand() % (620 - 20 + 1) + 20;
				letter_O.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x50) & 0x8000))	//P
		{
			if (letter_P.counts && letter_P.position_x <= 640 && letter_P.position_y >= 0)
			{

				score++;
				letter_P.counts--;
				letter_P.position_x = rand() % (620 - 20 + 1) + 20;
				letter_P.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x41) & 0x8000))	//A
		{
			if (letter_A.counts && letter_A.position_x <= 640 && letter_A.position_y >= 0)
			{

				score++;
				letter_A.counts--;
				letter_A.position_x = rand() % (620 - 20 + 1) + 20;
				letter_A.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x53) & 0x8000))	//S
		{
			if (letter_S.counts && letter_S.position_x <= 640 && letter_S.position_y >= 0)
			{

				score++;
				letter_S.counts--;
				letter_S.position_x = rand() % (620 - 20 + 1) + 20;
				letter_S.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x44) & 0x8000))	//D
		{
			if (letter_D.counts && letter_D.position_x <= 640 && letter_D.position_y >= 0)
			{

				score++;
				letter_D.counts--;
				letter_D.position_x = rand() % (620 - 20 + 1) + 20;
				letter_D.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x46) & 0x8000))	//F
		{
			if (letter_F.counts && letter_F.position_x <= 640 && letter_F.position_y >= 0)
			{

				score++;
				letter_F.counts--;
				letter_F.position_x = rand() % (620 - 20 + 1) + 20;
				letter_F.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x47) & 0x8000))	//G
		{
			if (letter_G.counts && letter_G.position_x <= 640 && letter_G.position_y >= 0)
			{

				score++;
				letter_G.counts--;
				letter_G.position_x = rand() % (620 - 20 + 1) + 20;
				letter_G.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x48) & 0x8000))	//H
		{
			if (letter_H.counts && letter_H.position_x <= 640 && letter_H.position_y >= 0)
			{

				score++;
				letter_H.counts--;
				letter_H.position_x = rand() % (620 - 20 + 1) + 20;
				letter_H.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x4A) & 0x8000))	//J
		{
			if (letter_J.counts && letter_J.position_x <= 640 && letter_J.position_y >= 0)
			{

				score++;
				letter_J.counts--;
				letter_J.position_x = rand() % (620 - 20 + 1) + 20;
				letter_J.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x4B) & 0x8000))	//K
		{
			if (letter_K.counts && letter_K.position_x <= 640 && letter_K.position_y >= 0)
			{

				score++;
				letter_K.counts--;
				letter_K.position_x = rand() % (620 - 20 + 1) + 20;
				letter_K.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x4C) & 0x8000))	//L
		{
			if (letter_L.counts && letter_L.position_x <= 640 && letter_L.position_y >= 0)
			{

				score++;
				letter_L.counts--;
				letter_L.position_x = rand() % (620 - 20 + 1) + 20;
				letter_L.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x5A) & 0x8000))	//Z
		{
			if (letter_Z.counts && letter_Z.position_x <= 640 && letter_Z.position_y >= 0)
			{

				score++;
				letter_Z.counts--;
				letter_Z.position_x = rand() % (620 - 20 + 1) + 20;
				letter_Z.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x58) & 0x8000))	//X
		{
			if (letter_X.counts && letter_X.position_x <= 640 && letter_X.position_y >= 0)
			{

				score++;
				letter_X.counts--;
				letter_X.position_x = rand() % (620 - 20 + 1) + 20;
				letter_X.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x43) & 0x8000))	//C
		{
			if (letter_C.counts && letter_C.position_x <= 640 && letter_C.position_y >= 0)
			{

				score++;
				letter_C.counts--;
				letter_C.position_x = rand() % (620 - 20 + 1) + 20;
				letter_C.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x56) & 0x8000))	//V
		{
			if (letter_V.counts)
			{

				score++;
				letter_V.counts--;
				letter_V.position_x = rand() % (620 - 20 + 1) + 20;
				letter_V.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x42) & 0x8000))	//B
		{
			if (letter_B.counts && letter_B.position_x <= 640 && letter_B.position_y >= 0)
			{

				score++;
				letter_B.counts--;
				letter_B.position_x = rand() % (620 - 20 + 1) + 20;
				letter_B.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x4E) & 0x8000))	//N
		{
			if (letter_N.counts && letter_N.position_x <= 640 && letter_N.position_y >= 0)
			{

				score++;
				letter_N.counts--;
				letter_N.position_x = rand() % (620 - 20 + 1) + 20;
				letter_N.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}
		if ((GetAsyncKeyState(0x4D) & 0x8000))	//M
		{
			if (letter_M.counts && letter_M.position_x <= 640 && letter_M.position_y >= 0)
			{

				score++;
				letter_M.counts--;
				letter_M.position_x = rand() % (620 - 20 + 1) + 20;
				letter_M.position_y = rand() % (-20 + 200 +1)-200 ;
			}
		}

	}
	FlushBatchDraw();
}

//主函数
int main()
{
	srand((unsigned)time(NULL));
	score = 0;
	checkString(choice);
	init_brick_wall();
	loadallimage();
	initgraph(Width + 160, Height);
	BeginBatchDraw();
	while (1)
	{
		while (gameStatus == 0)
		{
			startMenu();
		}
		show();
		updateWithoutInput();
		updateWithInput();
	}
	return 0;
}