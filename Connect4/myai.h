#ifndef MYAI_H
#define MYAI_H
#include "Judge.h"
#include "Point.h"
#include <vector>

int selection();
int expansion(int);
int simulation(int pos,int** para_board);
void backPropagation(int pos,int delta);
void hyf_getPoint(const int para_M, const int para_N, const int* top, int** board, 
	const int lastX, const int lastY, const int para_noX, const int para_noY,int& ans_x,int& ans_y);
void copy_board(int**,int**);

struct node;
/*
int simple_search()//�������㣬���ر�ʤ������޾ͷ���-1��ͬʱ���������ߵ���
{
	for(int i = 0;i < 20;++i) cannot[i] = 0;
	int** local_board = new int*[M];
	for(int i = 0;i < M;++i)
		local_board[i] = new int[N];
	copy_board(root_board,local_board);
	//���Ƶõ�board
	int* local_top = new int[N];
	for(int i = 0;i < N;++i)
		local_top[i] = root_top[i];
	//���Ƶõ�top
	int* type = new int[2100];
	for(int i = 0;i < 2100;++i)
		type[i] = 0;//0-uninit 1-��ʤ 2-�ذ� 3-δ֪
	//��ʤ���ذܱ��
	node* simtree = new node[2100];
	//���ڵ�Ϊ1��
	int index = 2;
	for(int i = 0;i < N;++i)
	{
		if(local_top[i] <= 0)
		{
			cannot[i] = 1;
			continue;
		}
		int index_i = index;//��¼�õ������
		simtree[index].col = i;//�к�
		simtree[index].parent = 1;//���ڵ�Ϊ1��
		type[index] = 1;//��ʼ״̬��Ϊ��ʤ�ڵ�
		local_board[local_top[i] - 1][i] = 2;//��i������
		if(machineWin(local_top[i] - 1,i,M,N,local_board))
		{
			return i;//����ߵ������Ѿ�ʤ����ֱ�ӷ��أ�����ȷ��
		}
		local_board[local_top[i] - 1][i] = 0;//�ָ�
		index++;
		choose(local_board,local_top,i,2);//����board��top
		for(int j = 0;j < N;++j)
		{
			if(local_top[j] <= 0) continue;
			int index_j = index;//��¼�õ������
			simtree[index].col = j;//�к�Ϊj
			simtree[index].parent = index_i;//����Ϊ֮ǰ��¼������
			type[index] = 0;//��ʼ״̬Ϊ��ʤ��
			local_board[local_top[j] - 1][j] = 1;//�޸�board��������
			if(userWin(local_top[j] - 1,j,M,N,local_board))//�Է��Ƿ���Ի�ʤ�����ʤ
			{
				cannot[simtree[simtree[index].parent].col] = 1;
				//type[simtree[index].parent] = 2;//�����ĸ��׽ڵ�ذܣ�������
				
				//index++;
				//local_board[local_top[j] - 1][j] = 0;//�ָ�����
				//break;//������������
				
			}
			//�Է���ʱ����ʤ
			local_board[local_top[j] - 1][j] = 0;
			choose(local_board,local_top,j,1);
			//�ָ����̺�ͳһ�޸�board��top
			index++;
			for(int k = 0;k < N;++k)
			{
				if(local_top[k] <= 0) continue;
				simtree[index].col = k;//��¼�к�Ϊk
				simtree[index].parent = index_j;//����Ϊ֮ǰ��¼������
				local_board[local_top[k] - 1][k] = 2;//�޸�board��������
				if(machineWin(local_top[k] - 1,k,M,N,local_board))//����һ�ʤ��
				{
					type[simtree[index].parent] = 1;//˵���丸�׽ڵ������˵�Ǳ�ʤ
					
					//index++;
					//local_board[local_top[k] - 1][k] = 0;//�ָ�����
					//break;//������������
				}
				index++;
				local_board[local_top[k] - 1][k] = 0;//�ָ�����
			}
			backchoose(local_board,local_top,j);//�ָ�����
			if(type[index_j] == 0) type[simtree[index_j].parent] = 0;
			//����õ���ȻΪ0��˵�������Ǳ�ʤ�㣬��ô������Ҳ����ʤ
			//���������е�type[index_j]Ϊ1��˵�����۶Է���ô���Ҷ�����ʤ����ô����Ҳ��ʤ
		}
		backchoose(local_board,local_top,i);//�ָ�����
		if(type[index_i] == 1) return simtree[index_i].col;
	}
	//_cprintf("index:%d\n",index);
	//system("pause");
	for(int i = 2;i < 2000;++i)
	{
		if(simtree[i].parent != 1) continue;
		//_cprintf("%d\n",i);
		//_cprintf("%d\n",type[i]);
		if(type[i] == 1) return simtree[i].col;
		if(type[i] == 2) cannot[simtree[i].col] = 1;
	}
	
	for(int i = 0;i < M;++i)
		delete local_board[i];
	delete[] local_board;
	delete[] local_top;
	return -1;
}
*/
#endif