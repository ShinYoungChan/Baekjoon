#include <stdio.h>
#include <iostream>

using namespace std;

char space[501][501];
int counting[4];
int n, m, startN, startM, firstX, firstY;
bool inf = false;
void up(int x, int y, int originalX, int originalY);
void down(int x, int y, int originalX, int originalY);
void left1(int x, int y, int originalX, int originalY);
void right1(int x, int y, int originalX, int originalY);


void up(int x, int y, int originalX, int originalY)
{
	if (x<0 || y<0 || x>n - 1 || y>m - 1)
		return;
	if (space[x][y] == 'C')
		return;
	if (x == startN && y == startM && (x-1)==firstX &&y==firstY) {
		inf = true;
		return;
	}
	counting[0]++;
	if (space[x][y] == '/' && (x + 1) == originalX && y == originalY)
		right1(x, y + 1, x, y);
	if (space[x][y] == '\\' && (x + 1) == originalX && y == originalY)
		left1(x, y - 1, x, y);
	if (space[x][y] == '.')
		up(x - 1, y, x, y);
}

void down(int x, int y, int originalX, int originalY)
{
	if (x<0 || y<0 || x>n - 1 || y>m - 1)
		return;
	if (space[x][y] == 'C')
		return;
	if (x == startN && y == startM && (x+1)==firstX&&y==firstY) {
		inf = true;
		return;
	}
	counting[1]++;
	if (space[x][y] == '/' && (x - 1) == originalX && y == originalY)
		left1(x, y - 1, x, y);
	if (space[x][y] == '\\' && (x - 1) == originalX && y == originalY)
		right1(x, y + 1, x, y);
	if(space[x][y]=='.')
		down(x + 1, y, x, y);
}

void left1(int x, int y, int originalX, int originalY)
{
	if (x<0 || y<0 || x>n - 1 || y>m - 1)
		return;
	if (space[x][y] == 'C')
		return;
	if (x == startN && y == startM &&x==firstX&&(y-1)==firstY) {
		inf = true;
		return;
	}
	counting[2]++;
	
	if (space[x][y] == '/' && x == originalX && (y + 1) == originalY)
		down(x + 1, y, x, y);
	if (space[x][y] == '\\' && x == originalX && (y + 1) == originalY)
		up(x - 1, y, x, y);
	if (space[x][y] == '.')
		left1(x, y - 1, x, y);
}

void right1(int x, int y, int originalX, int originalY)
{
	if (x<0 || y<0 || x>n - 1 || y>m - 1)
		return;
	if (space[x][y] == 'C')
		return;
	if (x == startN && y == startM&&x==firstX&&(y+1)==firstY) {
		inf = true;
		return;
	}
	counting[3]++;
	
	
	if (space[x][y] == '/' && x == originalX && (y - 1) == originalY)
		up(x - 1, y, x, y);
	if (space[x][y] == '\\' && x == originalX && (y - 1) == originalY)
		down(x + 1, y, x, y);
	if (space[x][y] == '.')
		right1(x, y + 1, x, y);
}

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> space[i][j];
		}
	}
	cin >> startN >> startM;
	startN--;
	startM--;
	firstX = startN - 1;
	firstY = startM;
	up(startN - 1, startM, startN, startM);
	int u = counting[0] + counting[1] + counting[2] + counting[3] + 1;
	for (int i = 0; i < 4; i++)
		counting[i] = 0;
	if (inf) {
		printf("U\nVoyager");
		return 0;
	}

	firstX = startN;
	firstY = startM + 1;
	right1(startN, startM + 1, startN, startM);
	int r = counting[0] + counting[1] + counting[2] + counting[3] + 1;
	for (int i = 0; i < 4; i++)
		counting[i] = 0;
	if (inf) {
		printf("R\nVoyager");
		return 0;
	}

	firstX = startN + 1;
	firstY = startM;
	down(startN + 1, startM, startN, startM);
	int d = counting[0] + counting[1] + counting[2] + counting[3] + 1;
	for (int i = 0; i < 4; i++)
		counting[i] = 0;
	if (inf) {
		printf("D\nVoyager");
		return 0;
	}

	firstX = startN;
	firstY = startM - 1;
	left1(startN, startM - 1, startN, startM);
	int l = counting[0] + counting[1] + counting[2] + counting[3] + 1;
	if (inf) {
		printf("L\nVoyager");
		return 0;
	}


	int max = u > d ? u : d;
	max = max > l ? max : l;
	max = max > r ? max : r;
	if (max == u)
		printf("U\n%d\n", u);
	else if (max == r)
		printf("R\n%d\n", r);
	else if (max == d)
		printf("D\n%d\n", d);
	else if (max == l)
		printf("L\n%d\n", l);
	return 0;
}