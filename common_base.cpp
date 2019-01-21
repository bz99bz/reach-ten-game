/*1751151 计1 郭思远*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include<windows.h>
using namespace std;
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l);//输入
void CSH(int(*a)[10], int h, int l);//初始化数组
void shuchu(int(*a)[10], char(*cz)[10], int bz[][10], int h, int l, int k);//输出
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd);//查找
void gotoxy(const int X, const int Y);
void setcolor(const int bg_color, const int fg_color);
void jifen(int num, int k, int goal, int cd);//计分
void hebing(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal);//合并
void down(int a[][10], char cz[][10], int h, int l);//下落
int Max(int a[][10], int h, int l);//寻找最大值
void New(int a[][10], int bz[][10], int h, int l, int cd);//填充新值
int fail(int a[][10], int bz[][10], int h, int l);//失败函数。
int judge(int a[][10], int h, int l, int goal);//判断目标是否到达
void kuang5(int a[][10], int h, int l);//框
void kuang6(int a[][10], int h, int l);//框
void nbsz(int a[][10], int h, int l, int cd);//内部数组
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd);//移动
void getxy(int &x, int &y);//取坐标值
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y, int flag);//变色
void getcolor(int &bg_color, int &fg_color);//取色
void hf_colour(int a[][10], int m, int n);
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl);
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal);//图形合并
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl);//零下落
void tc(int a[][10], int bz[][10], int h, int l);//图形填充
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl);//不连返回
void CD();//菜单
void get_end(char *pe, char *pn, char *pd);//读end;
void CD()
{
	setconsoleborder(80, 30, 0, 0);
	int cd;
	int h, l, czh, czl, i, j, goal, ju, sb;
	int sz[8][10] = { 0 }, bz[8][10] = { 0 };
	char cz[8][10] = { 0 }, xx;
	char pe, pn, pd;
	unsigned int k;
	k = (unsigned int)(time(0));
	srand(k);
	cout << "-----------------------------------------" << endl;
	cout << "1.命令行找出可合成项并标识（非递归）" << endl;
	cout << "2.命令行找出可合成项并标识（递归）" << endl;
	cout << "3.命令行完成一次合成（分步骤显示）" << endl;
	cout << "4.命令行完整版（分步骤显示）" << endl;
	cout << "5.伪图形界面显示初始数组（无分隔线）" << endl;
	cout << "6.伪图形界面显示初始数组（有分隔线）" << endl;
	cout << "7.伪图形界面下用箭头键选择当前色块" << endl;
	cout << "8.伪图形界面完成一次合成（分步骤）" << endl;
	cout << "9.伪图形界面完整版" << endl;
	cout << "0、退出" << endl;
	cout << "--------------------------------------" << endl;
	cd = get_int("请选择[0-9]", 0, 9, 0, 0, 0, 0, 0);
	if (cd != 0)
	{

		system("cls");
		h = get_int("请输入行数", 5, 8, 0, 0, 0, 0, 0);
		l = get_int("请输入列数", 5, 10, 0, 0, 0, 0, 0);
		if (cd == 3 || cd == 4 || cd == 8 || cd == 9)
		{
			goal = get_int("请输入合成目标", 5, 20, 0, 0, 0, h, l);
		}
		CSH(sz, h, l);
		if (cd == 1 || cd == 2 || cd == 3 || cd == 4)
		{
			while (1)
			{
				shuchu(sz, 0, 0, h, l, 0);
				get_int("请以字母+数字形式[例：c2]输入矩阵坐标：", 'a', '9', &czh, &czl, 100, h, l);
				cout << "输入为" << (char)(czh + 'A') << "行" << czl << "列" << endl;
				i = CZ(sz, bz, cz, h, l, czh, czl, cd);
				while (i == 0)
				{
					get_int("请以字母+数字形式[例：c2]输入矩阵坐标：", 'a', '9', &czh, &czl, 100, h, l);
					cout << "输入为" << (char)(czh + 'A') << "行" << czl << "列" << endl;
					i = CZ(sz, bz, cz, h, l, czh, czl, cd);
				}
				cout << endl;
				shuchu(sz, cz, bz, h, l, 1);
				cout << endl;
				shuchu(sz, cz, bz, h, l, 2);
				if (cd == 3 || cd == 4)
				{
					cout << "请确认是否把相邻的相同值合并到" << (char)(czh + 'A') << czl << "中(Y/N/Q)：";
					xx = get_int(0, 'N', 'Y', 0, 0, 100, h, l);
					if (xx == 'y' || xx == 'Y')
					{
						hebing(sz, cz, h, l, czh, czl, goal);
						cout << "按回车键进行数组下落除0操作..." << endl;
						int gsy;
						gsy = _getch();
						down(sz, cz, h, l);
						cout << "按回车键进行新值填充..." << endl;
						gsy = _getch();
						New(sz, bz, h, l, cd);
						cout << "本次合成结束，按回车键继续新一次的合成..." << endl;
						gsy = _getch();
						ju = judge(sz, h, l, goal);
						if (ju)
						{
							setcolor(COLOR_HYELLOW, COLOR_HRED);
							cout << "已经合成到" << goal << endl;
							setcolor(COLOR_BLACK, COLOR_WHITE);
							cout << "按回车键继续向更高目标进发..." << endl;
							gsy = _getch();
							while (1)
							{
								if (gsy == 13)
									break;
							}
							goal++;
						}
						sb = fail(sz, bz, h, l);
						if (sb)
						{
							cout << "失败！！！";
							break;
						}
						for (i = 0; i < h; i++)
							for (j = 0; j < l; j++)
							{
								cz[i][j] = 0;
								bz[i][j] = 0;
							}
					}
					if ((xx == 'n' || xx == 'N') && cd == 4)
					{
						for (i = 0; i < h; i++)
							for (j = 0; j < l; j++)
							{
								cz[i][j] = 0;
								bz[i][j] = 0;
							}
						continue;
					}
					if ((xx == 'n' || xx == 'N') && cd == 3)
						break;
				}
				if (cd == 3 || cd == 1 || cd == 2)
				{
					cout << "本小题结束，请输入End继续...";
					get_end(&pe, &pn, &pd);
					system("cls");
					CD();
				}
			}
		}
		if (cd == 5)
		{
			kuang5(sz, h, l);
			nbsz(sz, h, l, 5);
			cout << "本小题结束，请输入End继续...";
			get_end(&pe, &pn, &pd);
			system("cls");
			CD();
		}
		if (cd == 6 || cd == 7 || cd == 8 || cd == 9)
		{
			kuang6(sz, h, l);
			nbsz(sz, h, l, 6);
			if (cd == 6)
			{
				cout << "本小题结束，请输入End继续...";
				get_end(&pe, &pn, &pd);
				system("cls");
				CD();
			}
		}
		if (cd == 7 || cd == 8)
		{
			move(sz, cz, bz, h, l, goal, cd);
			cout << "本小题结束，请输入End继续...";
			get_end(&pe, &pn, &pd);
			system("cls");
			CD();
		}
		if (cd == 9)
		{

			int gsy = 0;
			while (1)
			{
				sb = fail(sz, bz, h, l);
				if (sb)
				{
					setcolor(COLOR_HYELLOW, COLOR_HRED);
					gotoxy(0, h * 4 + 2);
					cout << "失败！！！" << endl;
					cout << "本小题结束，请输入End继续...";
					get_end(&pe, &pn, &pd);
					system("cls");
					CD();
				}
				move(sz, cz, bz, h, l, goal, 9);
				ju = judge(sz, h, l, goal);
				if (ju)
				{
					setcolor(COLOR_HYELLOW, COLOR_HRED);
					gotoxy(0, h * 4 + 2);
					cout << "已经合成到" << goal;
					setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "按回车键继续向更高目标进发..." << endl;
					while (1)
					{

						gsy = _getch();
						if (gsy == 13)
							break;
					}
					gsy = 0;
					gotoxy(0, h * 4 + 2);
					cout << "箭头键移动并取消当前选择，回车键合成" << endl;
					goal++;
				}
				for (i = 0; i < h; i++)
					for (j = 0; j < l; j++)
					{
						cz[i][j] = 0;
						bz[i][j] = 0;
					}
			}
		}
		setcolor(COLOR_BLACK, COLOR_HWHITE);
	}
}