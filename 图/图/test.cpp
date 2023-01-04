#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_NUM 20

typedef int Status;
typedef int QElemType;
typedef char VexType;

typedef  struct EdgeNode {
	int adjvex;            //顶点的位置 
	struct EdgeNode* next;//下一个顶点的位置 
}EdgeNode, * EdgeLink;//建立邻接表 

typedef struct Vex {
	VexType data;      //顶点的数据 
	EdgeNode* firstEdge;//指向第一条邻接点的指针 
}VexNode, AdjList[MAX_NUM];//建立顶点数组 

typedef struct {
	AdjList adjlist;
	int vexNum, edgeNum;//顶点和边的数目 
}ALGraph; //图的邻接表存储结构

//队列
typedef struct Node {
	QElemType data;
	struct Node* next;

}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int visited[MAX_NUM];//记录遍历状态

//初始化队列
Status InitQueue(LinkQueue* Q);
//判断是否为空
Status IsEmpty(LinkQueue Q);
//入队
Status EnQueue(LinkQueue* Q, QElemType e);
//出队(带有头结点)
Status DeQueue(LinkQueue* Q, QElemType* e);
//创建图（邻接表表示）(无向图)
Status CreateGraph(ALGraph* G);
//深度
void DFS(ALGraph G, int i);
//广度 
Status BFS(ALGraph G);

int main()
{
	ALGraph G;
	CreateGraph(&G);
	printf("深度优先遍历:");
	DFS(G, 0);
	printf("\n");
	printf("广度优先遍历:");
	BFS(G);
	printf("\n");
}


//初始化队列
Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if (Q->front)
	{
		Q->front->next = NULL;
		return true;
	}
}
//判断是否为空
Status IsEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL)
	{
		return true;
	}
	else
		return false;
}
//入队
Status EnQueue(LinkQueue* Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (p)
	{
		p->data = e;
		p->next = NULL;
		Q->rear->next = p;
		Q->rear = p;
		return true;
	}
	else
		return false;

}
//出队(带有头结点)
Status DeQueue(LinkQueue* Q, QElemType* e)
{
	QueuePtr q;
	if (Q->front == Q->rear)return false;
	q = Q->front->next;
	*e = q->data;
	Q->front->next = q->next;
	if (Q->rear = q)
	{
		Q->rear = Q->front;
	}
	free(q);
	return true;
}
//创建图（邻接表表示）(无向图)
Status CreateGraph(ALGraph* G)
{

	int i, k;
	EdgeLink e;
	printf("请输入顶点数和边数\n");
	scanf("%d %d", &G->vexNum, &G->edgeNum);

	getchar();
	printf("请输入各顶点的数据:\n");
	for (i = 0; i < G->vexNum; i++)//初始化顶点数组 
	{
		scanf("%c", &G->adjlist[i].data);

		if (G->adjlist[i].data == '\n')
		{
			i--;
			continue;
		}
		G->adjlist[i].firstEdge = NULL;
	}

	printf("请输入顶点（vi,vj)边定点的序号\n");
	for (k = 0; k < G->edgeNum; k++)
	{
		int a, b;
		scanf("%d %d", &a, &b);

		e = (EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex = b;
		e->next = G->adjlist[a].firstEdge;
		G->adjlist[a].firstEdge = e;
		e = (EdgeLink)malloc(sizeof(EdgeNode));
		e->adjvex = a;
		e->next = G->adjlist[b].firstEdge;
		G->adjlist[b].firstEdge = e;

	}
	return true;
}
void DFS(ALGraph G, int i)
{
	EdgeLink e;
	visited[i] = true;
	printf("%c", G.adjlist[i].data);
	e = G.adjlist[i].firstEdge;
	while (e)
	{
		if (!visited[e->adjvex])
		{
			DFS(G, e->adjvex);
		}
		e = e->next;
	}
}
//广度 
Status BFS(ALGraph G)
{
	int i;
	EdgeLink p;
	LinkQueue Q;
	InitQueue(&Q);
	for (i = 0; i < MAX_NUM; i++)
	{
		visited[i] = false;
	}
	for (i = 0; i < G.vexNum; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			printf("%c", G.adjlist[i].data);
			EnQueue(&Q, i);
			while (!IsEmpty(Q))
			{
				DeQueue(&Q, &i);
				p = G.adjlist[i].firstEdge;
				while (p)
				{
					if (!visited[p->adjvex])
					{
						visited[p->adjvex] = true;
						printf("%c", G.adjlist[p->adjvex].data);
						EnQueue(&Q, p->adjvex);

					}
					p = p->next;
				}
			}
		}
	}
	return true;
}tu