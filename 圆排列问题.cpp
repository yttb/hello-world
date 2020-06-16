#include "stdio.h"
#include "math.h"
#define MAX 10

int n;  //Բ�ĸ���
float min = 10000;  //��ǰԲ���е���С����
int r[MAX];  //����Բ�İ뾶
int bestr[MAX];   //����������Բ�İ뾶
float x[MAX];  //����Բ��Բ��

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

//���㵱ǰԲ���еĳ���
void compute()
{
    int i;
    float low = 0;  //Բλ��ԭ���Ҳ�
    float heigh = 0;
    for(i=1; i<=n; i++)
    {
        if(x[i]-r[i]<low)  //Ѱ������ߵ����꣬��Բλ��ԭ�����ʱ�Ż����
            low = x[i]-r[i];
        if(x[i]+r[i]>heigh)  //Ѱ�����ұߵ�����
            heigh = x[i]+r[i];
    }
    if(heigh-low<min)  //�����ǰԲ���еĳ���С��֮ǰ������ֵ
         min =  heigh - low;  //����
}

//���㵱ǰ��ѡ��Բ��Բ��
float center(int i)
{
    int j;
    float temp = 0.0;
    float valuex;
    for(j=1; j<i; j++)
    {
        valuex = x[j] + 2.0*sqrt(r[j]*r[i]);  //Ѱ�ҵ�ǰ�������ұߵ�Բ��
        if(valuex>temp)
            temp = valuex;
    }
    return temp;
}

void backtrack(int i)
{
    if(i>n)  //��������һ��Բ
    {
        compute();  //���㵱ǰԲ���е���С����
        int  j;
        for(j=1; j<=n; j++)  
            bestr[j] = r[j];
    }
    else
    {  
        int j;
        for(j=i; j<=n; j++)  //ѡ��Ҫ���е�Բ
        {
            swap(r[i], r[j]); //ѡ���j��Բ
            float centerx = center(i);  //����Բ��
            if(centerx+r[i]<min)  //�½�Լ������ǰԲ�ĳ���<����ֵ�����ܲ�������ֵ
            {
                x[i] = centerx;  //��¼Բ��
                backtrack(i+1);  //������һ��
            }
            swap(r[i], r[j]);  //������һ��
        }
    }
}

void circle(int n1, int r1[])
{
    n = n1;
    int i;
    for(i=1; i<=n; i++)
        r[i] = r1[i];
    backtrack(1);
}

int main()
{
    int n1 = 3;
    int r1[]={0, 1, 1, 2};
    circle(n1, r1);
    printf("Բ�ĸ���Ϊ��%d\n", n);
    printf("�뾶�ֱ�Ϊ��\n");
    int i;
    for(i=1; i<=n; i++)
        printf("%d ", r1[i]);
    printf("\n");
    printf("���������£�Բ�İ뾶Ϊ��\n");
    for(i=1; i<=n; i++)
        printf("%d ", bestr[i]);
    printf("\n");
    printf("��С����Ϊ��%.3f\n", min);
    return 0;
}

