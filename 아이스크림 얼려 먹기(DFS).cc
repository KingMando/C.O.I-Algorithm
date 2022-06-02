#include <stdio.h>
int n, m;
int Ice_Cream[100][100] = {};
int DFS(int x, int y) // DFS 수행 함수
{
	if (x < 0 || x >= n || y < 0 || y >= m) // 맵을 초과하는 경우 false 반환
		return false;
	if (Ice_Cream[x][y] == 0) // Ice Cream이 존재할 경우
	{
		Ice_Cream[x][y] = 1; // 방문 처리
		DFS(x-1,y); // 상,하,좌,우 탐색
		DFS(x+1,y);
		DFS(x,y-1);
		DFS(x,y+1);
		return true;
	}
	else
	{
		return false;
	}
}
int main()
{
	int result = 0;
	scanf_s("%d %d", &n, &m);

	for (int i = 0; i < n; i++) // 2차원 배열에 Ice Cream 데이터 저장하기
		for (int j = 0; j<m; j++)
			scanf_s("%d", &Ice_Cream[i][j]);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <m; j++)
		{
			if (DFS(i, j) == true) // DFS 수행하기
				result = result + 1;
		}
	}
	printf("%d", result);
	return 0;
}