//#include<stdlib.h>//#include<stdio.h>//#include<string.h>//#define MAXSIZE 100//typedef int datatype;//typedef struct link_node////{//	datatype a[MAXSIZE];//	char name[20];//	char qqnum[15];//	char phonenum[11];//	struct link_node*next;//}node;//node*init()//{//	return NULL;//}//node *create()//{//	int i, x;//	node*head = NULL;//	node *p = NULL;//	node *q = NULL;////	printf("输入要存储的人数：\n");//	scanf("%d", &x);//	printf("姓名            qq                      电话                      \n");//	for (i = 1; i <= x; i++)//	{//		p = (node*)malloc(sizeof(node));//		scanf("%s", p->name);//		scanf("%s", p->qqnum);//		scanf("%s", p->phonenum);//		if (i == 1)//		{//			head = p;//			q = p;//		}//		else//		{//			q->next = p;//			q = p;//		}//	}//	return head;//}//void display(node *head)//{//	node *p;//	p = head;//	if (!p)//		printf("\n该通讯录是空的！");//	else//	{//		printf("姓名：%s           qq:%s                       电话：%s               \n", p->name, p->qqnum, p->phonenum);//		p = p->next;////	}//}////node *find(node *head, char name[20])//{//	node *q;//	if (!head)//	{//		printf("该通讯录是空的！\n");//		return NULL;//	}//	q = head;//	while (q->next&&q->name != name)//		q = q->next;//	if (q->name == name)//		return q;//	else  NULL;//}////node *insert(node *head)//{//	node *p, *q = head;//	char a[15];//	int n, i;//	printf("请输入要插入的人数：\n");//	scanf("%d", &n);//	printf("姓名            qq                      电话                      \n");//	for (i = 1; i <= n; i++)//	{//		p = (node*)malloc(sizeof(node));//		scanf("%s", p->name);//		scanf("%s", p->qqnum);//		scanf("%s", p->phonenum);//		p->next = head;//		head = p;//	}//	return head;//}//node *dele(node *head)//{//	node *pre = head, *q = head->next;//	char name[15];//	printf("请输入要删除的人：\n");//	scanf("%s", name);//	if (strcmp(q->name, name) == 0)//	{//		head = head->next;//		free(pre);//	}//	else//	{//		while (q)//		{//			if (strcmp(q->name, name) == 0)//			{//				pre->next = q->next;//				free(q);//				break;//			}//			else//			{//				pre = q;//				q = q->next;//			}//		}//	}//	return head;//}//int main()//{//	int i;//	char a[20], b[20], c[20];//	node *list;//	node *p;//	p = init();//	list = create();//	display(list);//	scanf("%d%s%s%s", &i, &a, &b);//	list = insert(list);//	display(list);//	printf("输入删除名字");//	scanf("%s", &a);//	list = dele(list);//	display(list);//	return 0;//}