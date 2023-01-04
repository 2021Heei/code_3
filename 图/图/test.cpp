#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_NUM 20

typedef int Status;
typedef int QElemType;
typedef char VexType;

typedef  struct EdgeNode {
	int adjvex;            //�����λ�� 
	struct EdgeNode* next;//��һ�������λ�� 
}EdgeNode, * EdgeLink;//�����ڽӱ� 

typedef struct Vex {
	VexType data;      //��������� 
	EdgeNode* firstEdge;//ָ���һ���ڽӵ��ָ�� 
}VexNode, AdjList[MAX_NUM];//������������ 

typedef struct {
	AdjList adjlist;
	int vexNum, edgeNum;//����ͱߵ���Ŀ 
}ALGraph; //ͼ���ڽӱ�洢�ṹ

//����
typedef struct Node {
	QElemType data;
	struct Node* next;

}QNode, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

int visited[MAX_NUM];//��¼����״̬

//��ʼ������
Status InitQueue(LinkQueue* Q);
//�ж��Ƿ�Ϊ��
Status IsEmpty(LinkQueue Q);
//���
Status EnQueue(LinkQueue* Q, QElemType e);
//����(����ͷ���)
Status DeQueue(LinkQueue* Q, QElemType* e);
//����ͼ���ڽӱ��ʾ��(����ͼ)
Status CreateGraph(ALGraph* G);
//���
void DFS(ALGraph G, int i);
//��� 
Status BFS(ALGraph G);

int main()
{
	ALGraph G;
	CreateGraph(&G);
	printf("������ȱ���:");
	DFS(G, 0);
	printf("\n");
	printf("������ȱ���:");
	BFS(G);
	printf("\n");
}


//��ʼ������
Status InitQueue(LinkQueue* Q)
{
	Q->front = Q->rear = (QNode*)malloc(sizeof(QNode));
	if (Q->front)
	{
		Q->front->next = NULL;
		return true;
	}
}
//�ж��Ƿ�Ϊ��
Status IsEmpty(LinkQueue Q)
{
	if (Q.front->next == NULL)
	{
		return true;
	}
	else
		return false;
}
//���
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
//����(����ͷ���)
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
//����ͼ���ڽӱ��ʾ��(����ͼ)
Status CreateGraph(ALGraph* G)
{

	int i, k;
	EdgeLink e;
	printf("�����붥�����ͱ���\n");
	scanf("%d %d", &G->vexNum, &G->edgeNum);

	getchar();
	printf("����������������:\n");
	for (i = 0; i < G->vexNum; i++)//��ʼ���������� 
	{
		scanf("%c", &G->adjlist[i].data);

		if (G->adjlist[i].data == '\n')
		{
			i--;
			continue;
		}
		G->adjlist[i].firstEdge = NULL;
	}

	printf("�����붥�㣨vi,vj)�߶�������\n");
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
//��� 
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