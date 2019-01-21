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
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y,int flag);//变色
void getcolor(int &bg_color, int &fg_color);//取色
void hf_colour(int a[][10], int m, int n);
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl);
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal);//图形合并
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl);//零下落
void tc(int a[][10], int bz[][10], int h, int l);//图形填充
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl);//不连返回
void CD();//菜单
void get_end(char *pe, char *pn, char *pd);//读end;
int main()//按Q没设置和菜单一起设置！
{
	CD();
}
/*输入*/
int get_int(char *prompt, int min_value, int max_value, int *p1, int *p2, int cs, int h, int l)
{
	int value;
	char value2;
	char  a[4] = { 0 };
	if (min_value == 'a')
	{
		while (1)
		{
			cout << "                                                  " << endl;
			cout << prompt;
			cin >> a;
			if (a[0] >= 'a'&&a[0] <= 'h')
				a[0] = a[0] - 32;
			if (a[0] >= 'A'&&a[0] <= h - 1 + 'A'&&a[1] >= '0'&&a[1] <= l - 1 + '0')
			{
				*p1 = a[0] - 'A';
				*p2 = a[1] - '0';
				break;
			}
			else
				cout << "输入错误，请重新输入.";

		}
		return 0;
	}
	if (min_value == 0)
	{
		while (1)
		{
			cout << prompt << "(" << min_value << "-" << max_value << "):";
			cin >> value;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail(), '\n');
				continue;
			}
			if (value >= min_value&&value <= max_value)
				break;
		}
		return value;
	}
	if (min_value == 5)
	{
		while (1)
		{
			if (max_value == 8)
				gotoxy(0, 0);
			if (max_value == 10)
				gotoxy(0, 1);
			if (max_value == 20)
				gotoxy(0, 2);
			cout << "                                                                                  " << endl;
			if (max_value == 8)
				gotoxy(0, 0);
			if (max_value == 10)
				gotoxy(0, 1);
			if (max_value == 20)
				gotoxy(0, 2);
			cout << prompt << "(" << min_value << "-" << max_value << "):";
			cin >> value;
			if (!cin.good())
			{
				cin.clear();
				cin.ignore(cin.rdbuf()->in_avail(), '\n');
				continue;
			}
			if (value >= min_value&&value <= max_value)
				break;
			else
				cout << "                       输入错误" << endl;
		}
		return value;
	}
	if (min_value == 'N')
		while (1)
		{
			cin >> value2;
			if (value2 == 'y' || value2 == 'Y' || value2 == 'n' || value2 == 'N' || value2 == 'q' || value2 == 'Q')
				break;
		}
	return value2;
}

void CSH(int(*a)[10], int h, int l)
{
	int i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			*(*(a + i) + j) = rand() % 3 + 1;
		}
	cout << endl;

}
void shuchu(int(*a)[10], char(*cz)[10], int bz[][10], int h, int l, int k)//0:当前数组，1：查找数组，2：颜色，3：零，4：填充
{

	if (k == 0)
	{
		cout << "当前数组：" << endl;
	}
	if (k == 2)
	{
		cout << "当前数组(不同色标识)：" << endl;
	}
	if (k == 1)
	{
		cout << "查找结果数组：" << endl;
	}
	if (k == 3)
	{
		cout << "除0后的数组(不同色标识)" << endl;
	}
	if (k == 4)
	{
		cout << "新值填充后的数组(不同色标识)：" << endl;
	}
	int i, j;
	cout << "  |";
	for (j = 0; j < l; j++)
		cout << "  " << j;
	cout << endl;
	cout << "--+";
	for (j = 1; j <= l; j++)
		cout << "---";
	cout << "-" << endl;
	if (k == 0)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
				cout << "  " << *(*(a + i) + j);
			cout << endl;
		}
	}
	if (k == 1)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
				cout << "  " << *(*(cz + i) + j);
			cout << endl;
		}
	}
	if (k == 2)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*')
				{
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cout << "  " << a[i][j];
					setcolor(COLOR_BLACK, COLOR_WHITE);
				}
				else
					cout << "  " << a[i][j];
			}
			cout << endl;
		}
	}
	if (k == 3)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
			{
				if (a[i][j] == 0)
				{
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cout << "  " << a[i][j];
					setcolor(COLOR_BLACK, COLOR_WHITE);
				}
				else
					cout << "  " << a[i][j];
			}
			cout << endl;
		}
	}
	if (k == 4)
	{
		for (i = 0; i < h; i++)
		{
			cout << (char)('A' + i) << " |";
			for (j = 0; j < l; j++)
			{
				if (bz[i][j] == 1)
				{
					setcolor(COLOR_BLACK, COLOR_HYELLOW);
					cout << "  " << a[i][j];
					setcolor(COLOR_BLACK, COLOR_WHITE);
				}
				else
					cout << "  " << a[i][j];
			}
			cout << endl;
		}
	}
	cout << endl;

}
int CZ(int(*a)[10], int(*bz)[10], char(*cz)[10], int h, int l, int czh, int czl, int cd)//查找函数
{
	int i, j, mb;
	mb = a[czh][czl];
	if ((*(*(a + czh - 1) + czl)) != mb&& *(*(a + czh + 1) + czl) != mb && (*(*(a + czh) + czl - 1) != mb) && (*(*(a + czh) + czl + 1) != mb))
	{
		if (cd != 8)
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
		if (cd == 8)
		{
			setcolor(COLOR_BLACK, COLOR_WHITE);
			gotoxy(0, h * 4 + 2);
			cout << "周围无相同值，箭头键移动，回车键选择" << endl;
		}
		return 0;
	}
	else
	{
		bz[czh][czl] = 1;
		cz[czh][czl] = '*';
		if (a[czh - 1][czl] == mb && (czh - 1) >= 0)
			cz[czh - 1][czl] = '*';
		if (a[czh + 1][czl] == mb && (czh + 1) < h)
			cz[czh + 1][czl] = '*';
		if (a[czh][czl + 1] == mb && (czl + 1) < l)
			cz[czh][czl + 1] = '*';
		if (a[czh][czl - 1] == mb && (czl - 1) >= 0)
			cz[czh][czl - 1] = '*';
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*'&&bz[i][j] == 0)
				{
					bz[i][j] = 1;
					if (a[i - 1][j] == mb && (i - 1) >= 0)
						cz[i - 1][j] = '*';
					if (a[i + 1][j] == mb && (i + 1) < h)
						cz[i + 1][j] = '*';
					if (a[i][j + 1] == mb && (j + 1) < l)
						cz[i][j + 1] = '*';
					if (a[i][j - 1] == mb && (j - 1) >= 0)
						cz[i][j - 1] = '*';
					i = 0;
					j = 0;
					continue;
				}
			}

		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] != '*')
					cz[i][j] = '0';
			}
		return 1;
	}
}
void hebing(int a[][10], char cz[][10], int h, int l, int czh, int czl, int goal)
{

	int i, j, k, num = 0;
	k = a[czh][czl];
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (cz[i][j] == '*')
			{
				a[i][j] = 0;
				num++;
			}
		}
	a[czh][czl] = k + 1;
	shuchu(a, cz, 0, h, l, 2);
	jifen(num, k, goal, 0);
}

void jifen(int num, int k, int goal, int cd)
{
	static int sum = 0;
	int bc;
	bc = k*num * 3;
	sum = sum + bc;
	if (cd == 8)
		gotoxy(0, 0);
	cout << "本次得分：" << bc << " " << "总得分：" << sum << " " << "合成目标：" << goal << endl;
	cout << endl;
}
void down(int a[][10], char cz[][10], int h, int l)
{
	int i, j, step = h - 1;

	for (j = 0; j < l; j++)
	{
		step = h - 1;
		for (i = h - 1; i >= 0; i--)
			if (a[i][j] != 0)
			{
				a[step][j] = a[i][j];
				step--;
			}
		while (step >= 0)
		{
			a[step][j] = 0;
			step--;
		}
	}
	shuchu(a, cz, 0, h, l, 3);
}
int Max(int a[][10], int h, int l)
{
	int i, j, k;
	k = a[0][0];
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			if (a[i][j] > k)
			{
				k = a[i][j];
			}
	return k;
}

void New(int a[][10], int bz[][10], int h, int l, int cd)
{
	int i, j, N, k;
	N = Max(a, h, l);
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			bz[i][j] = 0;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			if (a[i][j] == 0)
			{
				if (N == 3)
				{
					a[i][j] = rand() % N + 1;
					bz[i][j] = 1;
				}
				if (N == 4)
				{
					k = rand() % 100;
					if (k < 90)
						a[i][j] = rand() % (N - 1) + 1;
					if (k >= 90)
						a[i][j] = 4;
					bz[i][j] = 1;
				}
				if (N == 5)
				{
					k = rand() % 100;
					if (k < 75)
						a[i][j] = rand() % (N - 2) + 1;
					if (k >= 75 && k < 90)
						a[i][j] = 4;
					if (k >= 90)
						a[i][j] = 5;
					bz[i][j] = 1;
				}
				if (N == 6)
				{
					k = rand() % 100;
					if (k < 80)
						a[i][j] = rand() % (N - 2) + 1;
					if (k >= 80 && k < 95)
						a[i][j] = 5;
					if (k >= 95)
						a[i][j] = 6;
					bz[i][j] = 1;
				}
				if (N > 6)
				{
					k = rand() % 100;
					if (k < 80)
						a[i][j] = rand() % (N - 3) + 1;
					if (k >= 80 && k < 90)
						a[i][j] = N - 2;
					if (k >= 90 && k < 95)
						a[i][j] = N - 1;
					if (k >= 95)
						a[i][j] = N;
					bz[i][j] = 1;
				}
			}
	if (cd == 3 || cd == 4)
		shuchu(a, 0, bz, h, l, 4);
}
void get_end(char *pe, char *pn, char *pd)
{
	int m, n, i;
	getxy(m, n);
	gotoxy(m, n);
	char a[10] = { 0 };
	while (1)
	{
		cin >> a;
		if (a[0] >= 'a'&&a[0] <= 'z'&&a[1] >= 'a'&&a[1] <= 'z'&&a[2] >= 'a'&&a[2] <= 'z')
		{
			a[0] = a[0] - 32;
			a[1] = a[1] - 32;
			a[2] = a[2] - 32;
		}
		if (a[0] == 'E'&&a[1] == 'N'&&a[2] == 'D')
		{
			*pe = a[0];
			*pn = a[1];
			*pd = a[2];
			break;
		}
		else
		{
			gotoxy(m, n + 1);
			cout << "输入错误";
		}
		for (i = 0; i < 10; i++)
			a[i] = 0;
	}
}
int fail(int a[][10], int bz[][10], int h, int l)
{
	int i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			bz[i][j] = 0;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if ((i - 1) >= 0 && (i + 1) < h && (j - 1) >= 0 && (j + 1) < l)//中间
				if (a[i - 1][j] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						if (a[i][j - 1] != a[i][j])
							if (a[i][j + 1] != a[i][j])
								bz[i][j] = 1;
			if (j == 0 && i != 0 && i != h - 1)//四边
				if (a[i - 1][j] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						if (a[i][j + 1] != a[i][j])
							bz[i][j] = 1;
			if (i == 0 && j != 0 && j != l - 1)
				if (a[i + 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						if (a[i][j + 1] != a[i][j])
							bz[i][j] = 1;
			if (j == l - 1 && i != 0 && i != h - 1)
				if (a[i - 1][j] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						if (a[i][j - 1] != a[i][j])
							bz[i][j] = 1;
			if (i == h - 1 && j != 0 && j != l - 1)
				if (a[i - 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						if (a[i][j + 1] != a[i][j])
							bz[i][j] = 1;
			if (i == 0 && j == 0)//四角
				if (a[i][j + 1] != a[i][j])
					if (a[i + 1][j] != a[i][j])
						bz[i][j] = 1;
			if (i == 0 && j == l - 1)
				if (a[i + 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						bz[i][j] = 1;
			if (i == h - 1 && j == 0)
				if (a[i][j + 1] != a[i][j])
					if (a[i - 1][j] != a[i][j])
						bz[i][j] = 1;
			if (i == h - 1 && j == l - 1)
				if (a[i - 1][j] != a[i][j])
					if (a[i][j - 1] != a[i][j])
						bz[i][j] = 1;
		}
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (bz[i][j] != 1)
				return 0;
		}
	return 1;
}
int judge(int a[][10], int h, int l, int goal)
{
	int i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			if (a[i][j] == goal)
				return 1;
	return 0;
}
void kuang5(int a[][10], int h, int l)
{
	setconsoleborder(35 + 6 * (l - 5), 22 + 3 * (h - 5), 0, 0);
	cout << "屏幕当前设置为" << 22 + 3 * (h - 5) << "行" << 35 + 6 * (l - 5) << "列" << endl;
	int i, j, k;
	setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "╔";
	for (j = 0; j < l; j++)
	{
		cout << "═══";
		Sleep(100);
	}
	cout << "╗" << endl;
	for (i = 0; i < h; i++)
	{
		for (k = 0; k < 3; k++)
		{
			cout << "║";
			for (j = 0; j < l; j++)
				cout << "      ";
			cout << "║" << endl;
			Sleep(100);
		}
	}
	cout << "╚";
	for (j = 0; j < l; j++)
	{
		cout << "═══";
		Sleep(100);
	}
	cout << "╝" << endl;

	setcolor(COLOR_BLACK, COLOR_WHITE);
}
void kuang6(int a[][10], int h, int l)//有分割的框
{
	setconsoleborder(43 + 8 * (l - 5), 26 + 4 * (h - 5), 0, 0);
	cout << "屏幕当前设置为" << 26 + 4 * (h - 5) << "行" << 43 + 8 * (l - 5) << "列" << endl;
	int i, j, k;
	setcolor(COLOR_HWHITE, COLOR_BLACK);
	cout << "╔";
	for (j = 0; j < l - 1; j++)
		cout << "═══╤";
	cout << "═══";
	cout << "╗" << endl;
	Sleep(100);
	for (i = 0; i < h - 1; i++)
	{
		for (k = 0; k < 3; k++)
		{
			cout << "║";
			for (j = 0; j < l - 1; j++)
				cout << "      │";
			cout << "      ║" << endl;
			Sleep(100);
		}
		cout << "╟";
		for (j = 0; j < l - 1; j++)
			cout << "───┼";
		cout << "───╢" << endl;
	}
	for (k = 0; k < 3; k++)
	{
		cout << "║";
		for (j = 0; j < l - 1; j++)
			cout << "      │";
		cout << "      ║" << endl;
		Sleep(100);
	}
	cout << "╚";
	for (j = 0; j < l - 1; j++)
	{
		cout << "═══╧";
		Sleep(100);
	}
	cout << "═══";
	cout << "╝" << endl;

}
void nbsz(int a[][10], int h, int l, int cd)//内部数组
{
	const int BASE_X = 2, BASE_Y = 2;
	int n = 0, m = 0;
	gotoxy(BASE_X, BASE_Y);
	int i, j;
	for (i = 0; i < h; i++)
	{

		for (j = 0; j < l; j++)
		{

			if (a[i][j] == 1)
			{
				setcolor(1, COLOR_BLACK);
				cout << "╔═╗";
				if (cd == 5)
					gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
				if (cd == 6)
					gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
				cout << "║ " << a[i][j] << "║";
				if (cd == 5)
					gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
				if (cd == 6)
					gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
				cout << "╚═╝";

			}
			if (a[i][j] == 2)
			{
				setcolor(2, COLOR_BLACK);
				cout << "╔═╗";
				if (cd == 5)
					gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
				if (cd == 6)
					gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
				cout << "║ " << a[i][j] << "║";
				if (cd == 5)
					gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
				if (cd == 6)
					gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
				cout << "╚═╝";
			}
			if (a[i][j] == 3)
			{
				setcolor(3, COLOR_BLACK);
				cout << "╔═╗";
				if (cd == 5)
					gotoxy(BASE_X + n * 6, BASE_Y + 1 + m * 3);
				if (cd == 6)
					gotoxy(BASE_X + n * 8, BASE_Y + 1 + m * 4);
				cout << "║ " << a[i][j] << "║";
				if (cd == 5)
					gotoxy(BASE_X + n * 6, BASE_Y + 2 + m * 3);
				if (cd == 6)
					gotoxy(BASE_X + n * 8, BASE_Y + 2 + m * 4);
				cout << "╚═╝";
			}
			if (cd != 8)
				Sleep(100);
			n++;
			if (cd == 5)
				gotoxy(BASE_X + 6 * n, BASE_Y + m * 3);
			if (cd == 6)
				gotoxy(BASE_X + 8 * n, BASE_Y + m * 4);
		}
		n = 0;
		m++;
		if (cd == 5)
			gotoxy(BASE_X + n * 6, BASE_Y + m * 3);
		if (cd == 6)
			gotoxy(BASE_X + n * 8, BASE_Y + m * 4);
	}
	if (cd == 5)
		gotoxy(BASE_X + n * 6, BASE_Y + m * 3 + 3);
	if (cd == 6)
		gotoxy(BASE_X + n * 6, BASE_Y + m * 3 + 6);
	setcolor(COLOR_BLACK, COLOR_WHITE);
}
void move(int sz[][10], char cz[][10], int bz[][10], int h, int l, int goal, int cd)
{
	gotoxy(0, h * 4 + 2);
	if (cd == 7)
		cout << "箭头键移动，回车键选择并结束" << endl;
	if (cd == 8)
		cout << "箭头键移动，回车键选择" << endl;
	int t = 0, s = 0, i = 2, j = 2, w=0, kg = 1;
	const int BASE_X = 2, BASE_Y = 2;
	int x = BASE_X, y = BASE_Y, n = 0, m = 0;
	int hh, ll;
	gotoxy(BASE_X, BASE_Y);
	int a, b;
	int ret, maction;
	int X = 0, Y = 0;
	int flag = 0,feifa=1,bl=1,get_x=0,get_y=0,qr=0,ju;
	enable_mouse();
	setcursor(CURSOR_INVISIBLE);

	while (1)
	{
		if (bl)
		{
				hf_colour(sz, t, s);
				colour(sz, h, l, &t, &s, i, j, flag);
		}
		ret = read_keyboard_and_mouse(X, Y, maction, a, b);
		if (ret == CCT_KEYBOARD_EVENT)
		{
			feifa = 1;
			for (hh = 0; hh < h; hh++)
				for (ll = 0; ll < l; ll++)
				{
					bz[hh][ll] = 0;
					cz[hh][ll] = 0;
				}
			if (a == 13)
			{
				if (cd == 7)
					break;
				w = lian(sz, cz, bz, h, l, i, j);
				a = 0;
				a = _getch();
				if (a == 13 && w == 1)
					break;
				if (a == 224)
				{
					b = _getch();
					bulian(sz, cz, bz, h, l, i, j);
					a = 0;
					continue;
				}
			}
			else
			{
				if (a == 224 && b == 72)
				{
					if (y >= BASE_Y + 4 && y <= BASE_Y + (h - 1) * 4)
					{
						n--;
						x = BASE_X + 8 * m;
						y = BASE_Y + 4 * n;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
					if (y == BASE_Y)
					{
						n = h - 1;
						x = BASE_X + 8 * m;
						y = BASE_Y + (h - 1) * 4;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
				}
				else if (a == 224 && b == 75)
				{
					if (x >= BASE_X + 8 && x <= BASE_X + (l - 1) * 8)
					{
						m--;
						x = BASE_X + 8 * m;
						y = BASE_Y + 4 * n;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
					if (x == BASE_X)
					{
						m = l - 1;
						x = BASE_X + (l - 1) * 8;
						y = BASE_Y + 4 * n;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
				}
				else if (a == 224 && b == 77)
				{
					if (x >= BASE_X && x <= BASE_X + (l - 2) * 8)
					{
						m++;
						x = BASE_X + 8 * m;
						y = BASE_Y + 4 * n;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
					if (x == BASE_X + (l - 1) * 8)
					{
						m = 0;
						x = BASE_X;
						y = BASE_Y + 4 * n;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}

				}
				else if (a == 224 && b == 80)
				{
					if (y >= BASE_Y&&y <= BASE_Y + (h - 2) * 4)
					{
						n++;
						x = BASE_X + 8 * m;
						y = BASE_Y + 4 * n;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
					if (y == BASE_Y + (h - 1) * 4)
					{
						n = 0;
						x = BASE_X + 8 * m;
						y = BASE_Y;
						gotoxy(x, y);
						getxy(i, j);
						continue;
					}
				}
			}
		}
		else if (ret == CCT_MOUSE_EVENT)
		{
			ju = judge(sz, h, l, goal);
			if (ju)
			{
				gotoxy(0, h * 4 + 2);
				setcolor(COLOR_HYELLOW, COLOR_HRED);
				cout << "已经合成到" << goal << endl;
				setcolor(COLOR_BLACK, COLOR_WHITE);
				cout << "按回车键继续向更高目标进发..." << endl;
				while (1)
				{
					ret = read_keyboard_and_mouse(X, Y, maction, a, b);
					if (a == 13|| maction== MOUSE_LEFT_BUTTON_CLICK)
						break;
				}
				goal++;
			}
			flag = 1;
			switch (maction) 
			{
				case MOUSE_ONLY_MOVED:
					if (!bl && (X <= (i-2)/8*8+2|| X >= (i - 2) / 8 * 8 + 8) ||(Y<=(j- 2) / 4 * 4+1||Y>= (j - 2) / 4 * 4 + 5))
					{
						bulian(sz, cz, bz, h, l, i, j);
						bl = 1;
						qr = 0;
						w = 0;
					}
					setcolor(COLOR_BLACK,COLOR_WHITE);
					gotoxy(0, h * 4 + 2);
					cout << "                                                   ";
					gotoxy(0, h * 4 + 2);
					if ((((Y - 2) / 4) <= h - 1) && (((X - 2) / 8) <= l - 1) && Y > 0)
					{
						cout << "[当前鼠标]" << (char)('A' + (Y - 2) / 4) << "行" << (X - 2) / 8 << "列" << endl;
						if (bl)
						{
							i = X;
							j = Y;
						}
						feifa = 1;
					}
					else
					{
						cout << "[当前鼠标]位置非法";
						feifa = 0;
					}
					break;
				case MOUSE_LEFT_BUTTON_CLICK:
				{
					if (qr&&w)
					{
						for (hh = 0; hh < h; hh++)
							for (ll = 0; ll < l; ll++)
								bz[hh][ll] = 0;
						i = (X - 2) / 8 * 8 + 2;
						j = (Y - 2) / 4 * 4 + 2;
						tx_hb(sz, cz, bz, h, l, i, j, goal);
						tx_down(sz, bz, cz, h, l, i, j);
						tc(sz, bz, h, l);
						qr = 0;
						w = 0;
					}
					else
					{
						i = (X - 2) / 8 * 8 + 2;
						j = (Y - 2) / 4 * 4 + 2;
						w = lian(sz, cz, bz, h, l, i, j);
						bl = 0;
						qr = 1;
						setcolor(COLOR_BLACK, COLOR_WHITE);
						gotoxy(0, h * 4 + 2);
						cout << "箭头键/鼠标移动取消当前选择，回车键、单击左键确认";
					}
					break;
				}
			}
			get_x = i, get_y = j;
		}
	}
	if (cd == 8 || cd == 9)
	{
		for (hh = 0; hh < h; hh++)
			for (ll = 0; ll < l; ll++)
				bz[hh][ll] = 0;
		tx_hb(sz, cz, bz, h, l, i, j, goal);
		int gsy;
		if (cd == 8)
		{
			while (1)
			{
				gsy = _getch();
				if (gsy == 13)
					break;
			}
		}
		tx_down(sz, bz, cz, h, l, i, j);
		gsy = 0;
		if (cd == 8)
			while (1)
			{
				gsy = _getch();
				if (gsy == 13)
					break;
			}
		tc(sz, bz, h, l);
	}
	gotoxy(0, h * 4 + 3);
	setcolor(COLOR_BLACK, COLOR_WHITE);
}
void colour(int a[][10], int h, int l, int *p1, int *p2, int x, int y,int flag)
{
	if (flag)
	{
		*p1 = (x - 2) / 8 * 8 + 2;
		*p2 = (y - 2) / 4 * 4 + 2;
		setcolor(COLOR_HYELLOW, COLOR_BLUE);
		gotoxy((x-2)/8*8+2, (y - 2) / 4 * 4 + 2);
		cout << "╔═╗";
		gotoxy((x - 2) / 8 * 8 + 2, (y-2) / 4*4 + 3);
		cout << "║ " << a[(y - 2) / 4][(x - 2) / 8] << "║";
		gotoxy((x - 2) / 8 * 8 + 2, (y - 2) / 4 * 4 + 4);
		cout << "╚═╝";
		gotoxy(0, h * 4 + 3);
	}
	else
	{
		*p1 = x;
		*p2 = y;
		setcolor(COLOR_HYELLOW, COLOR_BLUE);
		gotoxy(x, y);
		cout << "╔═╗";
		gotoxy(x, y + 1);
		cout << "║ " << a[(y - 2) / 4][(x - 2) / 8] << "║";
		gotoxy(x, y + 2);
		cout << "╚═╝";
		gotoxy(0, h * 4 + 3);
	}
}
void hf_colour(int a[][10], int m, int n)
{
	if (m != 0)
	{
		int c = a[(n - 2) / 4][(m - 2) / 8];
		setcolor(c, COLOR_BLACK);
		gotoxy(m, n);
		cout << "╔═╗";
		gotoxy(m, n + 1);
		cout << "║ " << a[(n - 2) / 4][(m - 2) / 8] << "║";
		gotoxy(m, n + 2);
		cout << "╚═╝";
	}
}
int lian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl)//czh,czl是当前光标位置。
{
	int k, i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			cz[i][j] = 0;
			bz[i][j] = 0;
		}
	k = CZ(a, bz, cz, h, l, (czl - 2) / 4, (czh - 2) / 8, 8);
	if (k == 0)
		return 0;
	if (k)
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*')
				{
					if ((i == (czl - 2) / 4) && (j == (czh - 2) / 8))
						setcolor(COLOR_HYELLOW, COLOR_HRED);
					else
						setcolor(COLOR_HYELLOW, COLOR_BLACK);
					gotoxy(8 * j + 2, 4 * i + 2);
					cout << "╔═╗";
					gotoxy(8 * j + 2, 4 * i + 2 + 1);
					cout << "║ " << a[i][j] << "║";
					gotoxy(8 * j + 2, 4 * i + 2 + 2);
					cout << "╚═╝";
				}
			}
		setcolor(COLOR_BLACK, COLOR_WHITE);
		gotoxy(0, h * 4 + 2);
		cout << "箭头键移动并取消当前选择，回车键合成                  " << endl;
	}
	return 1;
}
void bulian(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl)
{
	int k, i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			cz[i][j] = 0;
			bz[i][j] = 0;
		}
	k = CZ(a, bz, cz, h, l, (czl - 2) / 4, (czh - 2) / 8, 8);
	if (k)
	{
		for (i = 0; i < h; i++)
			for (j = 0; j < l; j++)
			{
				if (cz[i][j] == '*')
				{
					setcolor(a[i][j], COLOR_BLACK);
					gotoxy(8 * j + 2, 4 * i + 2);
					cout << "╔═╗";
					gotoxy(8 * j + 2, 4 * i + 2 + 1);
					cout << "║ " << a[i][j] << "║";
					gotoxy(8 * j + 2, 4 * i + 2 + 2);
					cout << "╚═╝";
				}
			}
	}
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			cz[i][j] = 0;
			bz[i][j] = 0;
		}
}
void tx_hb(int a[][10], char cz[][10], int bz[][10], int h, int l, int czh, int czl, int goal)
{
	int i, j, k, num = 0;
	k = a[(czl - 2) / 4][(czh - 2) / 8];
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
		{
			if (cz[i][j] == '*')
			{
				setcolor(COLOR_HWHITE, COLOR_HWHITE);
				gotoxy(8 * j + 2, 4 * i + 2);
				cout << "╔═╗";
				gotoxy(8 * j + 2, 4 * i + 2 + 1);
				cout << "║ " << a[i][j] << "║";
				gotoxy(8 * j + 2, 4 * i + 2 + 2);
				cout << "╚═╝";
				num++;
				bz[i][j] = 1;
			}
		}
	a[(czl - 2) / 4][(czh - 2) / 8] = k + 1;
	setcolor(k + 1, COLOR_BLACK);
	gotoxy(czh, czl);
	cout << "╔═╗";
	gotoxy(czh, czl + 1);
	cout << "║ " << a[(czl - 2) / 4][(czh - 2) / 8] << "║";
	gotoxy(czh, czl + 2);
	cout << "╚═╝";
	bz[(czl - 2) / 4][(czh - 2) / 8] = 0;
	setcolor(COLOR_BLACK, COLOR_WHITE);
	jifen(num, k, goal, 8);
	gotoxy(0, h * 4 + 2);
	cout << "合成完成，回车键下落0                         " << endl;
}
void tx_down(int a[][10], int bz[][10], char cz[][10], int h, int l, int czh, int czl)
{
	int i, j, kg = 0, m, n;
	for (j = 0; j < l; j++)
	{
		for (i = h - 1; i >= 0; i--)
		{
			if (bz[i][j] == 1 && kg == 0)
			{
				kg = 1;
				m = i;
				n = j;
			}
			if (kg == 1)
			{
				if (bz[i][j] == 0)
				{
					setcolor(COLOR_HWHITE, COLOR_HWHITE);
					gotoxy(8 * j + 2, 4 * i + 2);
					cout << "╔═╗";
					gotoxy(8 * j + 2, 4 * i + 2 + 1);
					cout << "║  ║";
					gotoxy(8 * j + 2, 4 * i + 2 + 2);
					cout << "╚═╝";
					setcolor(a[i][j], COLOR_BLACK);
					gotoxy(8 * n + 2, 4 * m + 2);
					cout << "╔═╗";
					gotoxy(8 * n + 2, 4 * m + 2 + 1);
					cout << "║ " << a[i][j] << "║";
					gotoxy(8 * n + 2, 4 * m + 2 + 2);
					cout << "╚═╝";
					bz[m][n] = 0;
					bz[i][j] = 1;
					a[m][n] = a[i][j];
					a[i][j] = 0;
					kg = 0;
					i = h - 1;
					Sleep(500);
					continue;
				}
			}
		}
		kg = 0;
	}
}
void tc(int a[][10], int bz[][10], int h, int l)
{
	int i, j;
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			if (bz[i][j] == 1)
				a[i][j] = 0;
	New(a, bz, h, l, 8);
	for (i = 0; i < h; i++)
		for (j = 0; j < l; j++)
			if (bz[i][j] == 1)
			{
				setcolor(a[i][j], COLOR_BLACK);
				gotoxy(8 * j + 2, 4 * i + 2);
				cout << "╔═╗";
				gotoxy(8 * j + 2, 4 * i + 2 + 1);
				cout << "║ " << a[i][j] << "║";
				gotoxy(8 * j + 2, 4 * i + 2 + 2);
				cout << "╚═╝";
			}
}