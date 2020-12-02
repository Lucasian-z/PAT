#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int comp(int date1[3], int date2[3])
{
	if (date1[0] < date2[0])
		return 1;
	else if (date1[0] > date2[0])
		return 0;
	else
	{
		if (date1[1] < date2[1])
			return 1;
		else if (date1[1] > date2[1])
			return 0;
		else
		{
			if (date1[2] < date2[2])
				return 1;
			else if (date1[2] > date2[2])
				return 0;
		}
	}
	return 1;
}

int isCorrect(int date[3])
{
	if (date[0] < 1814 || date[0] > 2014)
		return 0;
	else if (date[0] == 1814)
	{
		if (date[1] < 9 || (date[1] == 9 && date[2] <6))
			return 0;
	}
	else if (date[0] == 2014)
	{
		if (date[1] > 9 || (date[1] == 9 && date[2] > 6))
			return 0;
	}
	return 1;
}

int main()
{
	int N = 0, i = 0, cnt = 0;
	int ret = scanf("%d", &N);
	if (ret != 1)
		return 0;
	char** names;
	names = (char**)calloc(N, sizeof(char*));
	for (i = 0; i < N; ++i)
		names[i] = (char*)calloc(7, sizeof(char));
	char c;
	int maxi = 0, mini = 0;
	int most_old[3] = { 2014,9,7 }, most_young[3] = { 1814,9,5 };
	c = getchar();
	for (i = 0; i < N; ++i)
	{
		int time[3] = { 0 };
		int j = 0;
		
		while ((c = getchar())!=' ')
		{
			names[i][j++] = c;
		}
		names[i][j] = '\0';
		for (j = 0; j < 3; ++j)
		{
			while ((c = getchar()) != '/' && c != '\n')
			{
				time[j] = time[j] * 10 + (c - '0');
			}
		}
		if (isCorrect(time))
			++cnt;
		else continue;
		if (comp(time, most_old) == 1)
		{
			//printf("comp:test\n");
			for (j = 0; j < 3; ++j)
				most_old[j] = time[j];
			maxi = i;
			//printf("maxi = %d\n", maxi);
		}
		if(comp(most_young, time) == 1)
		{
			
			mini = i;
			for (j = 0; j < 3; ++j)
				most_young[j] = time[j];
			//printf("%d %d %d\n", most_young[0], most_young[1], most_young[2]);
		}
	}
	if (cnt == 0)
		printf("0");
    else
	    printf("%d %s %s", cnt, names[maxi], names[mini]);
	return 0;
}