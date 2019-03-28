#include <stdio.h>
#include <stdlib.h>
typedef struct student
{
    int ID;
    int number;
    struct student *next;
}stu;
stu *set(int n,stu *head)
{
    int j;
    stu *p=head;
    for(j=0;j<n;j++)
    {
        stu *stup=(stu *)malloc(sizeof(stu));
        printf("please input the ID\n");
        scanf("%d",&stup->ID);
        printf("please input the number\n");
        scanf("%d",&stup->number);
        if(head==NULL)
        {
            head=stup;
            p=stup;
        }
        else
        {
            p->next=stup;
            p=p->next;
        }
    }
    p->next=head;
    return head;
}
stu *deletelink(stu *p)//删除传入节点的下一个
{
    stu *q=p;
    stu *s;
    s=q->next;
    q->next=s->next;
    free(s);
    return q;
}
stu * josephloop(stu *head,int m,int n)
{
    stu *p=head;
    int i=0;
    int newm=m-1;
    int idnumber;
    while(n!=1)
    {
        for(i=0;i<newm-1;i++)
            p=p->next;
        newm=p->next->number;
        idnumber=p->next->ID;
        p=deletelink(p);
        printf("%d->",idnumber);
        n--;
    }
    idnumber=p->ID;
    printf("%d\n",idnumber);
    return p;
}
int main()
{
    int n,m;
    printf("please input the number of student\n");
    scanf("%d",&n);
    printf("please input the  first number\n");
    scanf("%d",&m);
    stu *head=NULL;
    head=set(n,head);
    head=josephloop(head,m,n);
    free(head);
}
