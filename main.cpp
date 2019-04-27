#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bt
{
    char l;   
    int weight;    
    int lchild,rchild,parent;
}htnode;
typedef char **huffmancode;

void huffmancoding(htnode *ht, int n ,int *_weight,char *letter,char *test)
{
    int m=2*n-1;
    int i=0;
    for(i=1;i<=n;i++)  
    {
        ht[i].weight=_weight[i-1];
        ht[i].l=letter[i-1];
        ht[i].parent=0;
        ht[i].lchild=0;
        ht[i].rchild=0;
    }
    
    for(i=n+1;i<=m;i++)     
    {
        ht[i].weight=0;
        ht[i].l='0';
        ht[i].parent=0;
        ht[i].lchild=0;
        ht[i].rchild=0;
    }
    
    for(i=n+1;i<=m;i++)      
    {
        int s1_weight=999, s2_weight=999;
        int s1=-1, s2=-1;

        //select(ht,i-1,&s1,&s2);
        for(int d=1;d<=i-1;d++)    
        {
            if(ht[d].weight<s1_weight && ht[d].parent==0)
            {
                s1 = d;
                s1_weight = ht[d].weight; 
            }
        }
        for(int d=1;d<=i-1;d++)
        {
            if(ht[d].weight<s2_weight && d!=s1 && ht[d].parent==0)
            {
                s2 = d;
                s2_weight = ht[d].weight;
            }
        }
        
        ht[s1].parent=i;
        ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;
    }
    printf("end of building tree\n");

    huffmancode code=(huffmancode)malloc((n+1)*sizeof(char *));   
    char _code[n];   
    _code[n-1]='\0';

    for(i=1;i<=n;i++)   
    {
        int start=n-1;
        int c;
        int f;
        for(c=i,f=ht[i].parent;f;c=f,f=ht[f].parent)
        {
            if(ht[f].lchild==c)
            {
                --start;
                _code[start]='0';
            }
            else
            {
                --start;
                _code[start]='1';
            }
        }
        
        code[i] = (char *)malloc((n-start)*sizeof(char));
        printf("i = %d, _code+start: %s\n", i, _code+start);
        strcpy(code[i],&_code[start]);   
        printf("code[i]: %s\n", code[i]);
    }
    
    for(i=1;i<=n;i++)
    {
        printf("--%s",code[i]);
    }
    printf("end of char encoding\n");
    
    printf("\nresult:");
    for(int k=0; k<strlen(test); ++k)      
    {
        for(int i=0;i<27;i++)
        {
            if(letter[i]==test[k])    
            {
                printf("%c -> %s\n", test[k], code[i+1]);   
            }
        }
    }
    
    free(code);
}

int main()
{
    int n=27;
    int m=2*n-1;
    htnode *hfmTree=(htnode *)malloc((m+1)*sizeof(htnode));
    char l[27];
    int i=0;
    for(i=1,l[0]=' ';i<27;l[i]='a'+i-1,i++);
    int _weight[30]={186,64,13,22,32,103,21,15,47,57,1,5,32,20,57,63,15,1,48,51,80,23,8,18,1,16,1};//Ȩ������
    char test[50]={"this program is my favorite"};
    huffmancoding(hfmTree,n,_weight,l,test);
    free(hfmTree);
    
}
