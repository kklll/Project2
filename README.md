# Project2
# 数据结构部分代码
希望各位大哥能够支持一下，对你们有用的话点个star。
--- 
## project2目录下的文件说明：
- bighomework，以前写的c语言大作业。  


[bighomework](https://github.com/kklll/Project2/blob/master/Project2/bighomework.c)  

- bdayi.c 	数据结构顺序串


[dayi.c](https://github.com/kklll/Project2/blob/master/Project2/dayi.c) 
- drawing_test.c  图的创建与遍历

[drawing_test.c](https://github.com/kklll/Project2/blob/master/Project2/drawing_test.c) 
- head_node.c   单链表

[head_node.c](https://github.com/kklll/Project2/blob/master/Project2/head_node.c) 
- test.c    数据结构第一上机实验

[test.c](https://github.com/kklll/Project2/blob/master/Project2/test.c) 
- tree.c 	数据结构后二叉树创建与遍历

[tree.c](https://github.com/kklll/Project2/blob/master/Project2/tree.c) 
- work.c	数据结构递归与非递归求叶子节点个数。

[work.c](https://github.com/kklll/Project2/blob/master/Project2/work.c) 

## 新的数据结构代码移步到project2文件下的c文件夹
### prim算法
+ prim算法的核在于
``` c
/*
	编译环境dev-c++，GCC 4.9.2 内容为：
	数据结构图的最小生成树的算法（Prim算法）
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct edgedata {
	int beg, end;	//开始边的下标与结束边的下标 
	int length;	//两边的长度 
}edge;
typedef struct mgraph {		//此函数用来创建图的邻接矩阵 
	int n, e;		//记录点与边的个数信息
	int edges[30][30];		//邻接矩阵
	char vexs[30];		//顶点的信息（也就是顶点名称）
}mgraph;
void creat(mgraph *g, char *s, int c)		//邻接矩阵的创建 
{
	int i, j, k, w;
	FILE *rf;
	rf = fopen(s, "r");
	if (rf)
	{
		fscanf(rf, "%d %d\n", &g->n, &g->e);
		for (i = 0; i < g->n; i++)
		{
			fscanf(rf, "%c\n", &g->vexs[i]);
		}
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (j == i)
					g->edges[i][i] = 0;
				else
					g->edges[i][j] = 999;
			}
		}
		for (k = 0; k < g->e; k++)
		{
			fscanf(rf, "%d %d %d\n", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
				g->edges[j][i] = w;
		}
		fclose(rf);
	}
	else
	{
		printf("打开文件失败无法创建!");
		exit(0);
	}
}
void prim(mgraph g, edge tree[29])
{
	edge x;
	int d, min, s, v,k,j;
	for (v = 1; v <= g.n - 1; v++) 
	{
		tree[v - 1].beg = 0; 
		tree[v - 1].end = v;
		tree[v - 1].length = g.edges[0][v]; 
	}
	for (k = 0; k <= g.n - 3; k++) 
	{
		min = tree[k].length;  
		s = k; 
		for (j = k + 1; j <= g.n - 2; j++)
		{
			if (tree[j].length < min)
			{
				min = tree[j].length;
				s = j; 
			}
		}
		v = tree[s].end;
		x = tree[s];
		tree[s] = tree[k];
		tree[k] = x;
		for (j = k + 1; j <= g.n - 2; j++)
		{
			d = g.edges[v][tree[j].end];  
			if (d < tree[j].length)  
			{
				tree[j].length = d; 
				tree[j].beg = v; 
			}
		}
	}
	printf("最小生成树为：\n");
	for (j = 0; j <= g.n - 2; j++)
	{
		printf("\n%c--->%c-----%d\n", g.vexs[tree[j].beg], g.vexs[tree[j].end], tree[j].length);
	}
	printf("根节点为：%c\n", g.vexs[0]);
}
int main()
{
	mgraph g;
	edge tree[30];
	char filename[100] = { "Data.txt" };
	creat(&g, filename, 0);
	prim(g, tree);
	return 0;
}
```
### 卡鲁斯卡尔算法
```c
/*
    编译环境dev-c++，GCC 4.9.2 内容为：
	数据结构图的最小生成树的算法（卡鲁斯卡尔算法）
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct mgraph{		//此函数用来创建图的邻接矩阵 
	int n,e;		//记录点与边的个数信息
	int edges[30][30];		//邻接矩阵
	char verx[30];		//顶点的信息（也就是顶点名称）
}mgraph;
typedef struct edgedata
{
	int beg,end;
	int len;
}edge;
void QuickSort(edge edges[],int left,int right)
{			//快速排序 
	edge x;
	int i,j,flag=1;
	if(left<right)
	{
		i=left;
		j=right;
		x=edges[i];
		while(i<j)
		{
			while(i<j&&x.len<edges[j].len)
				j--;
			if(i<j)
				edges[i++]=edges[j];
			while(i<j&&x.len>edges[i].len)
				i++;
			if(i<j)
				edges[j--]=edges[i];
		}
		edges[i]=x;
		QuickSort(edges,left,i-1);		//递归实现方法 
		QuickSort(edges,i+1,right);		
	}
}
void getedge(mgraph g,edge edges[])
{		//获取可到达边,使用edges数组储存每条边信息 
	int i,j,k=0;
	for(i=0;i<g.n;i++)
		for(j=0;j<i;j++)
			if(g.edges[i][j]!=0&&g.edges[i][j]<999)
			{
				edges[k].beg=i;
				edges[k].end=j;
				edges[k++].len=g.edges[i][j];
			}	
}
void kruskal(mgraph g)
{
	int i,j,k=0,lt;//lt变量用于储存中间变量
	int cnvx[30];
	edge edges[900];
	edge tree[30];
	getedge(g,edges);
	QuickSort(edges,0,g.e-1);
	for(i=0;i<g.n;i++)
		cnvx[i]=i;
	for(i=0;i<g.n-1;i++)
	{
		while(cnvx[edges[k].beg]==cnvx[edges[k].end])
			k++;
		tree[i]=edges[k];
		lt=cnvx[edges[k].end];
		for(j=0;j<g.n;j++)
			if(cnvx[j]==lt)
			cnvx[j]=cnvx[edges[k].beg];
		k++;
	}
	printf("最小生成树为:\n");
	for(j=0;j<g.n-1;j++)
	{
		printf("%c------>%c\n",g.verx[tree[j].end],g.verx[tree[j].beg]);
	}
}
void creat(mgraph *g,char *s,int c)		//邻接矩阵的创建 
{
	int i,j,k,w;
	FILE *rf;
	rf= fopen(s,"r");
	if(rf)
	{
		fscanf(rf,"%d %d\n",&g->n,&g->e);
		for(i=0;i<g->n;i++)
		{
			fscanf(rf,"%c\n",&g->verx[i]);
		}
		for(i=0;i<g->n;i++)
		{
			for(j=0;j<g->n;j++)
			{
				if(j==i)
				g->edges[i][i]=0;
				else
				g->edges[i][j]=999;
			}
		}
		for(k=0;k<g->e;k++)
		{
			fscanf(rf,"%d %d %d\n",&i,&j,&w);
			g->edges[i][j]=w;
			if(c==0)
			g->edges[j][i]=w;
		}
		fclose(rf);
	}
	else
	{
		printf("打开文件失败无法创建!");
		exit(0);
	}
 } 
 int main()
 {
 	mgraph g;
 	char filename[30]={"Data.txt"};
 	creat(&g,filename,0);
 	kruskal(g);
 }
```
### 单源最大路径
```c
/*
	编译环境dev-c++，GCC 4.9.2 内容为：
	数据结构最短路径的生成
*/
#include<stdio.h>
#include<stdlib.h>
#include"creat.h"		//引入邻接矩阵的创建函数 
#define m 30
typedef enum {
	false, true
}bool;	//将1替换为true，将0替换为false 
typedef int dist[m];	//距离向量 
typedef int path[m];	//路径向量 
void dj(mgraph g, int v0, path p, dist d)
{
	bool final[m];		//标记是否求出最短路径 
	int i, j, k, v, min, x;
	//以上为栈结构内的变量
	for (v = 0; v < g.n; v++)	//执行初始化 
	{
		final[v] = false;
		d[v] = g.edges[v0][v];
		if (d[v] < 999 && d[v] != 0)
			p[v] = v0;
		else
			p[v] = -1;
	}

	final[v0] = true;
	d[v0] = 0;
	for (i = 1; i < g.n; i++)
	{
		min = 999;	//此时无最小长度，相当于初始化。 
		for (k = 0; k < g.n; ++k)
			if (!final[k] && d[k] < min)
			{
				v = k;	//v来记录当前节点。 
				min = d[k];
			}
			printf("\n%c--->%c---%d\n " ,g.vexs[v0],g.vexs[v],min);
			if (min == 999)
				return;
			final[v] = true;	//表示其已经求出最短路径。 
		for (k = 0; k < g.n; ++k)
		{
			if (!final[k] && (min + g.edges[v][k] < d[k]))
			{
				d[k] = min + g.edges[v][k];
				p[k] = v;
			}
		}
	}
}
void print(mgraph g, path p, dist d)
{
	int st[m], i, pre, top = -1;
	//以上为栈结构内的变量
	for (i = 0; i < g.n; i++)
	{
		st[++top] = i;
		printf("\n距离为%3d,路径为:\n", d[i]);
		pre = p[i];
		while (pre != -1)
		{
			st[++top] = pre;
			pre = p[pre];
		}
		while (top > 0)
			printf("%2d", st[top--]);
	}
}
int main()
{
	mgraph g;
	path p;
	dist d;
	int v0;
	creat(&g, "s-data.txt", 1);
	printf("请输入原点序号：\n");
	scanf("%d", &v0);
	dj(g, v0, p, d);
	print(g, p, d);

}
```