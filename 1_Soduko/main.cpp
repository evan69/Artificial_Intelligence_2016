//���ݷ��������
#include <iostream>//������� 
#include <fstream>//�������
using namespace std;
char p[20][20];//���ַ���ʽ������ 
bool check_row(int x,int y)
//�����һ���Ѿ��������û���ظ� 
{
	for(int i = 0;i < 9;i++)
	{
		if(i != y && p[x][i] == p[x][y])
		{
			return false;
		}
	}
	return true;
}

bool check_col(int x,int y)
//�����һ���Ѿ��������û���ظ� 
{
	for(int i = 0;i < 9;i++)
	{
		if(i != x && p[i][y] == p[x][y])
		{
			return false;
		}
	}
	return true;
}

bool check_sqr(int x,int y)
//���ͬһ������������û���ظ����� 
{
	int r = x / 3;
	int s = y / 3;
	for(int i = 3*r;i < 3*(r+1);i++)
	{
		for(int j = 3*s;j < 3*(s+1);j++)
		{
			if(i != x && j != y && p[i][j] == p[x][y])
			{
				return false;
			}
		}
	}
	return true;
}

bool check(int x,int y)
//���ĳһ��λ���Ƿ���� 
{
	if(check_row(x,y) && check_col(x,y) && check_sqr(x,y))
	{
		return true;
	}
	return false;
}

bool f(int x,int y)
{
//	cout << x << " " << y <<endl;
	if(y == 9)
	{
		return f(x+1,0);//������⣬ת��һ�� 
	}
	if(x == 9) return true;//�Ѿ�������� 
	if(p[x][y] != '0')
	{
		return f(x,y+1);
		//����0�ĵ����账�� 
	}
	for(int i = 0;i < 9;i++)
	{
		p[x][y] = char('1' + i); 
		if(check(x,y))
		//ȡ��һ����Ӧ�õĹ��� 
		//����������p��һ����״̬
		{
			bool tmp = f(x,y+1);
			//�ݹ���� 
			if(tmp) return true;
		}
	}
	p[x][y] = '0';
	return false;
	//ʧ�� ������� �Ļ�p������x��y����ֵ 
}

int main(int argc,char** argv)
{
	ifstream fin;
	fin.open(argv[1]);
	ofstream fout;
	fout.open(argv[2]);
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			fin >> p[i][j];
		}
	}
	fin.close();
	f(0,0);//�ӵ�һ���㿪ʼ 
	for(int i = 0;i < 9;i++)
	{
		for(int j = 0;j < 9;j++)
		{
			fout << p[i][j];
		}
		fout << '\n';
	}
	fout.close();
	return 0;
}


