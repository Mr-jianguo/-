#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
//定义一个顺序表类型
typedef struct seqList
{
	int data[MaxSize];
	int length;
}SeqList;

//初始化,将所有数据元素设置为默认初始值为0，防止脏数据
void InitList(SeqList &L)
{
	for(int i = 0; i<MaxSize; i++)
		L.data[i]=0;
	L.length=0;
}
//创建一个有数据的顺序表
void createList(seqList &L)
{
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=4;
	L.data[3]=5;
	L.data[4]=6;
	L.length=5;
}
//插入数据
bool ListInsert(seqList &L, int i, int e )
{
	//位序不合法
	if(i<1||i>L.length+1)
		return false;
	//当前存空间已满，不能插入
	if(L.length>=MaxSize)
		false;
	//将第i个元素及以后的元素后移
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
//删除数据
bool ListDelete(seqList &L,int i,int &e)
{
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	//将第i个元素以后的元素前移
	for(int j=i;j<L.length;j++)	
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
}
//按位查找
int GetElem(seqList L,int i)
{
	return L.data[i-1];
}
//按值查找
int LocateElem(seqList L,int e)
{
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;
		return 0; //退出循环说明查找失败
}
//打印顺序表
void printList(seqList &L)
{
	for (int i = 0; i<L.length; i++)
		printf("data[%d]=%d\n",i,L.data[i]);
} 
//打印删除数据的顺序表
void printeDeleteList(seqList &L)
{
	int e=-1;
	if(ListDelete(L,4,e))
		printf("已删除第4个元素，删除的元素的值为：%d\n",e);
	else
		printf("位序i不合法，删除失败\n");
}
int main ()
{
	SeqList L;
	InitList(L);
	createList(L);
	printf("顺序表如下：\n");
	//插入前：
	printf("插入前：\n");
	printList(L);
	ListInsert(L,3,3);
	//插入后：
	printf("插入后：\n");
	printList(L);
	//删除元素前：
	printf("删除元素前：\n");
	printList(L);
	//删除元素后：
	printf("删除元素后：\n");
	printeDeleteList(L);
	printList(L);
	//按位查找
	printf("按位查找结果如下：\n");
	printf("查找的第3个元素值为：%d\n",(GetElem(L,3)));
	//按值查找
	printf("按值查找的结果如下：\n");
	printf("查找值为5的位序是：%d\n",(LocateElem(L,5)));
	return 0;
}