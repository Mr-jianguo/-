#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
//����һ��˳�������
typedef struct seqList
{
	int data[MaxSize];
	int length;
}SeqList;

//��ʼ��,����������Ԫ������ΪĬ�ϳ�ʼֵΪ0����ֹ������
void InitList(SeqList &L)
{
	for(int i = 0; i<MaxSize; i++)
		L.data[i]=0;
	L.length=0;
}
//����һ�������ݵ�˳���
void createList(seqList &L)
{
	L.data[0]=1;
	L.data[1]=2;
	L.data[2]=4;
	L.data[3]=5;
	L.data[4]=6;
	L.length=5;
}
//��������
bool ListInsert(seqList &L, int i, int e )
{
	//λ�򲻺Ϸ�
	if(i<1||i>L.length+1)
		return false;
	//��ǰ��ռ����������ܲ���
	if(L.length>=MaxSize)
		false;
	//����i��Ԫ�ؼ��Ժ��Ԫ�غ���
	for(int j=L.length;j>=i;j--)
		L.data[j]=L.data[j-1];
	L.data[i-1]=e;
	L.length++;
	return true;
}
//ɾ������
bool ListDelete(seqList &L,int i,int &e)
{
	if(i<1||i>L.length)
		return false;
	e=L.data[i-1];
	//����i��Ԫ���Ժ��Ԫ��ǰ��
	for(int j=i;j<L.length;j++)	
		L.data[j-1]=L.data[j];
	L.length--;
	return true;
}
//��λ����
int GetElem(seqList L,int i)
{
	return L.data[i-1];
}
//��ֵ����
int LocateElem(seqList L,int e)
{
	for(int i=0;i<L.length;i++)
		if(L.data[i]==e)
			return i+1;
		return 0; //�˳�ѭ��˵������ʧ��
}
//��ӡ˳���
void printList(seqList &L)
{
	for (int i = 0; i<L.length; i++)
		printf("data[%d]=%d\n",i,L.data[i]);
} 
//��ӡɾ�����ݵ�˳���
void printeDeleteList(seqList &L)
{
	int e=-1;
	if(ListDelete(L,4,e))
		printf("��ɾ����4��Ԫ�أ�ɾ����Ԫ�ص�ֵΪ��%d\n",e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��\n");
}
int main ()
{
	SeqList L;
	InitList(L);
	createList(L);
	printf("˳������£�\n");
	//����ǰ��
	printf("����ǰ��\n");
	printList(L);
	ListInsert(L,3,3);
	//�����
	printf("�����\n");
	printList(L);
	//ɾ��Ԫ��ǰ��
	printf("ɾ��Ԫ��ǰ��\n");
	printList(L);
	//ɾ��Ԫ�غ�
	printf("ɾ��Ԫ�غ�\n");
	printeDeleteList(L);
	printList(L);
	//��λ����
	printf("��λ���ҽ�����£�\n");
	printf("���ҵĵ�3��Ԫ��ֵΪ��%d\n",(GetElem(L,3)));
	//��ֵ����
	printf("��ֵ���ҵĽ�����£�\n");
	printf("����ֵΪ5��λ���ǣ�%d\n",(LocateElem(L,5)));
	return 0;
}