#include<string.h>
#include<stdio.h>
/*  #define N 3
struct student
{
    char name[20];
    int id;
    char address[20];
    float grade;
};
int main()
{
    struct student stu[N];
    int i;
    float sum=0;
    for(i=0;i<N;i++)
    {
        printf("please input the name\n");
        scanf("%s",stu[i].name);
        printf("please input the id\n");
        scanf("%d",&stu[i].id);
        printf("please input the address\n");
        scanf("%s",stu[i].address);
        printf("please input the grade\n");
        scanf("%f",&stu[i].grade);
        sum+=stu[i].grade;
    }
    printf("name\tid\taddress\t\tgrade\n");
    for(i=0;i<N;i++)
    {
        printf("%s\t",stu[i].name);
        printf("%d\t",stu[i].id);
        printf("%s\t\t",stu[i].address);
        printf("%.2f\n",stu[i].grade);
    }
    printf("\nthe average grade is %.2f\n",sum/N);
}
*/
/*  struct stu
{
    int num;
    char name[20];
    char sex;
    float score;
}boy[6]={
        {101,"li ping",'m',45},
        {102,"zhang ping",'m',62.5},
        {103,"he fang",'m',92.5},
        {104,"cheng ling",'f',87},
        {106,"wang ming",'m',58},
        };
int numoffail(struct stu *p[6])
{
    int i,num=0;
    for(i=0;i<5;i++)
        if(p[i]->score<60)
            num++;
    return num;
}
int main()
{
    struct stu *p[6];
    int i;
    for(i=0;i<6;i++)
        p[i]=&boy[i];
    printf("the number of failing is %d\n",numoffail(p));
    struct stu pp,*temp;
    scanf("%d%s %c%f",&pp.num,pp.name,&pp.sex,&pp.score);
    temp=p[4];
    p[4]=&pp;
    p[5]=temp;
    for(i=0;i<6;i++)
        printf("%d\t%12s\t\t%c\t%.2f\n",p[i]->num,p[i]->name,p[i]->sex,p[i]->score);
    printf("-----------------------------------------\n");
    p[3]=p[4];
    p[4]=p[5];
    for(i=0;i<5;i++)
        printf("%d\t%12s\t\t%c\t%.2f\n",p[i]->num,p[i]->name,p[i]->sex,p[i]->score);
}
*/

struct date
{
    int year;
    int month;
    int day;
};
int calculate(struct date *p,struct date *q)
{
    int i,j=0,x,y,sum;
    for(i=p->year+1;i<q->year;i++)
        if((i%4==0&&i%100!=0)||i%400==0)
            j++;
    if(p->month<=2&&p->day<=28)
        {
            x=365-(p->month-1)*31-p->day;
            if((p->year%4==0&&p->year%100!=0)||p->year%400==0)
                x++;
        }
    else if(p->month!=11)
        x=365-(p->month-1)*31-p->day+3+p->month/3;
        if(p->month==3)
                x--;
    else
        x=365-(p->month-1)*31-p->day+3+4;

    if(q->month<=2&&q->day<=28)
        y=(q->month-1)*31+q->day;
    else if((q->month)!=11)
        {
            y=(q->month-1)*31+q->day-3-q->month/3;
            if(((q->year)%4==0&&q->year%100!=0)||q->year%400==0)
                y++;
            if(q->month==3)
                y++;
        }
    else
    {
        y=((q->month)-1)*31+q->day-3-4;
        if((q->year%4==0&&q->year%100!=0)||q->year%400==0)
            y++;
    }
    if(q->year>p->year)
        sum=j*366+(q->year-p->year-j-1)*365+x+y;
    else if(p->month<=2&&q->month>=3)
        if((p->year%4==0&&p->year%100!=0)||p->year%400==0)
            sum=y-366+x;
        else
            sum=y-365+x;
    else
        sum=y-365+x;
    return sum;
}
int main()
{
    struct date a,b;
    int days;
    printf("请输入第一个时间:\n");
    scanf("%d%d%d",&a.year,&a.month,&a.day);
    printf("请输入第二个时间:\n");
    scanf("%d%d%d",&b.year,&b.month,&b.day);
    days=calculate(&a,&b);
    printf("相差的天数是%d\n",days);
}
/*
#define N 2
struct stu
{
    char name[20];
    char school_id[20];
    char origin[20];
    char id[20];
    int age;
    char address[20];
    char sex;
    char phone_num[20];
};
void input(struct stu *p[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("请输入学生信息:\n");
        scanf("%s%s%s%s",p[i]->name,p[i]->school_id,p[i]->origin,p[i]->id);
        scanf("%d%s %c%s",&p[i]->age,p[i]->address,&p[i]->sex,p[i]->phone_num);
    }
}
void print(struct stu *p[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("学生%d信息:\n",i+1);
        printf("%s\t%s\t%s\t%s\t",p[i]->name,p[i]->school_id,p[i]->origin,p[i]->id);
        printf("%d\t%s\t %c\t%s\n",p[i]->age,p[i]->address,p[i]->sex,p[i]->phone_num);
    }
}
struct stu search(struct stu *p[N],char a[20])
{
    int i;
    for(i=0;i<N;i++)
        if(strcmp(p[i]->name,a)==0)
            return *p[i];
}
int main()
{
    struct stu student[N],temp;
    struct stu *p[N];
    char _name[20];
    int i;
    for(i=0;i<N;i++)
        p[i]=&student[i];
    input(p);
    print(p);
    printf("请输入想要查找的学生姓名:\n");
    scanf("%s",_name);
    temp=search(p,_name);
    printf("%s\t%s\t%s\t%s\t",temp.name,temp.school_id,temp.origin,temp.id);
    printf("%d\t%s\t %c\t%s\n",temp.age,temp.address,temp.sex,temp.phone_num);
}
*/
