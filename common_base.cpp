/*1751151 ��1 ��˼Զ*/
#include<iostream>
#include<time.h>
#include <cstdio>
#include <conio.h>
#include "cmd_console_tools.h"
#include<windows.h>
using namespace std;
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l);//����
void CSH(int(*a)[10], int h, int l);//��ʼ������
void shuchu(int(*a)[10], char(*cz)[10], int bz[][10], int h, int l, int k);//���
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd);//����
void gotoxy(const int X, const int Y);
void setcolor(const int bg_color, const int fg_color);
void jifen(int num, int k, int goal, int cd);//�Ʒ�
void hebing(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal);//�ϲ�
void down(int a[][10], char cz[][10], int h, int l);//����
int Max(int a[][10], int h, int l);//Ѱ�����ֵ
void New(int a[][10], int bz[][10], int h, int l, int cd);//�����ֵ
int fail(int a[][10], int bz[][10], int h, int l);//ʧ�ܺ�����
int judge(int a[][10], int h, int l, int goal);//�ж�Ŀ���Ƿ񵽴�
void kuang5(int a[][10], int h, int l);//��
void kuang6(int a[][10], int h, int l);//��
void nbsz(int a[][10], int h, int l, int cd);//�ڲ�����
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd);//�ƶ�
void getxy(int &x, int &y);//ȡ����ֵ
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y, int flag);//��ɫ
void getcolor(int &bg_color, int &fg_color);//ȡɫ
void hf_colour(int a[][10], int m, int n);
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl);
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal);//ͼ�κϲ�
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl);//������
void tc(int a[][10], int bz[][10], int h, int l);//ͼ�����
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl);//��������
void CD();//�˵�
void get_end(char *pe, char *pn, char *pd);//��end;
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
	cout << "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl;
	cout << "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl;
	cout << "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl;
	cout << "4.�����������棨�ֲ�����ʾ��" << endl;
	cout << "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl;
	cout << "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl;
	cout << "7.αͼ�ν������ü�ͷ��ѡ��ǰɫ��" << endl;
	cout << "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl;
	cout << "9.αͼ�ν���������" << endl;
	cout << "0���˳�" << endl;
	cout << "--------------------------------------" << endl;
	cd = get_int("��ѡ��[0-9]", 0, 9, 0, 0, 0, 0, 0);
	if (cd != 0)
	{

		system("cls");
		h = get_int("����������", 5, 8, 0, 0, 0, 0, 0);
		l = get_int("����������", 5, 10, 0, 0, 0, 0, 0);
		if (cd == 3 || cd == 4 || cd == 8 || cd == 9)
		{
			goal = get_int("������ϳ�Ŀ��", 5, 20, 0, 0, 0, h, l);
		}
		CSH(sz, h, l);
		if (cd == 1 || cd == 2 || cd == 3 || cd == 4)
		{
			while (1)
			{
				shuchu(sz, 0, 0, h, l, 0);
				get_int("������ĸ+������ʽ[����c2]����������꣺", 'a', '9', &czh, &czl, 100, h, l);
				cout << "����Ϊ" << (char)(czh + 'A') << "��" << czl << "��" << endl;
				i = CZ(sz, bz, cz, h, l, czh, czl, cd);
				while (i == 0)
				{
					get_int("������ĸ+������ʽ[����c2]����������꣺", 'a', '9', &czh, &czl, 100, h, l);
					cout << "����Ϊ" << (char)(czh + 'A') << "��" << czl << "��" << endl;
					i = CZ(sz, bz, cz, h, l, czh, czl, cd);
				}
				cout << endl;
				shuchu(sz, cz, bz, h, l, 1);
				cout << endl;
				shuchu(sz, cz, bz, h, l, 2);
				if (cd == 3 || cd == 4)
				{
					cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << (char)(czh + 'A') << czl << "��(Y/N/Q)��";
					xx = get_int(0, 'N', 'Y', 0, 0, 100, h, l);
					if (xx == 'y' || xx == 'Y')
					{
						hebing(sz, cz, h, l, czh, czl, goal);
						cout << "���س����������������0����..." << endl;
						int gsy;
						gsy = _getch();
						down(sz, cz, h, l);
						cout << "���س���������ֵ���..." << endl;
						gsy = _getch();
						New(sz, bz, h, l, cd);
						cout << "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
						gsy = _getch();
						ju = judge(sz, h, l, goal);
						if (ju)
						{
							setcolor(COLOR_HYELLOW, COLOR_HRED);
							cout << "�Ѿ��ϳɵ�" << goal << endl;
							setcolor(COLOR_BLACK, COLOR_WHITE);
							cout << "���س������������Ŀ�����..." << endl;
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
							cout << "ʧ�ܣ�����";
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
					cout << "��С�������������End����...";
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
			cout << "��С�������������End����...";
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
				cout << "��С�������������End����...";
				get_end(&pe, &pn, &pd);
				system("cls");
				CD();
			}
		}
		if (cd == 7 || cd == 8)
		{
			move(sz, cz, bz, h, l, goal, cd);
			cout << "��С�������������End����...";
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
					cout << "ʧ�ܣ�����" << endl;
					cout << "��С�������������End����...";
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
					cout << "�Ѿ��ϳɵ�" << goal;
					setcolor(COLOR_BLACK, COLOR_WHITE);
					cout << "���س������������Ŀ�����..." << endl;
					while (1)
					{

						gsy = _getch();
						if (gsy == 13)
							break;
					}
					gsy = 0;
					gotoxy(0, h * 4 + 2);
					cout << "��ͷ���ƶ���ȡ����ǰѡ�񣬻س����ϳ�" << endl;
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