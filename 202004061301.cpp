/*
���ٻ� 202004061301 ����2003��
��С���˷�������������� 




*/
#include <iostream>
#include <stdio.h>
#include<math.h>
#define v 0.00001   /*������ɽ���� */
int main()
{
    using namespace std;
    int i,j,k,m;
    int col;
    int number;
    int sum_x = 0;
    int sum_y = 0;
    int  x[100];         /*��������*/
    int  y[100];
    double theta1;       /* һ�����ϵ��*/
    double theta0;       /* ��ϵ�� */
    double e;            /*���ϵ��*/
    double old_theta1;
    double old_theta0;
    printf("please input sample's number :"); /*���������ĸ���*/
    cin>>number;
    printf("sample's number is %d\n\n",number);
    printf("please input sample'x :");       /*����������x*/
    for(k=0;k<number;k++)
    {
        cin>>x[k];
    }
    printf("\n");
    printf("please input sample'y :");      /*���������y*/
    for(m=0;m<number;m++)
    {
        cin>>y[m];
    }
    printf("\n");
    k=0;
    m=0;
    printf("x[]= ");                /*���������*/ 
    for(k=0;k<number;k++)
    {
        printf("%3d",x[k]);
    }
    printf("\n\n");
    printf("y[] = ");
    for(m=0;m<number;m++)
    {
       printf("%3d",y[m]);
    }
    col = number;
    printf("\n\n");
    printf("the training sample is : %d \n",col);
    for(i=0;i<col-1;i++)
    {
        sum_x = sum_x + x[i];
        sum_y = sum_y + y[i];
    }
    theta1 = (double)sum_y/sum_x;/*������ɽ�ĳ�ʼ��*/
    theta0 = y[0]-theta1*x[0];
    while(1)                     /*ţ�ٿ�ʼ��ɽ��ֱ���ҵ����Ž��˳�ѭ��*/
    {
       double temp1 = 0;
       double temp0 = 0;
       for(j=0;j<col-1;j++)/*������ʧ�����ֱ�Գ�ϵ����һ����ϵ���ĵ���*/
       {
          temp1 = temp1 + (y[j]-(theta0 + theta1*x[j]))*x[j];
          temp0 = temp0 + (y[j]-(theta0 + theta1*x[j]))*1;
       }
	   temp1 = temp1 / col;
       temp0 = temp0 / col;
       old_theta1 = theta1;/*��ǰһ����ϵ����һ����ϵ���洢�Ժ����Ƚ�*/
       old_theta0 = theta0;

       theta1 = theta1 - v*temp1;/*����ÿ�������ĳ�ϵ����һ����ϵ��*/
       theta0 = theta0 - v*temp0;
       e = (pow((old_theta1-theta1),2) + pow((old_theta0 - theta0),2));
        if(e<0.000003);/*�����½��ٶȵ�һ����ֵ*/ 
        {
            printf("the objective function is : \n");
            printf("f(x)= %f + %f*x",theta0,theta1);
            break;/*����ѭ��*/
        }
    }
}
