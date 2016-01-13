//
//  PHONELST.cpp
//  codeforces
//
//  Created by Vladimir Charchabal Escalona
#include<stdio.h>
#include<string.h>
int test,n;
bool yes;
struct trie
{
    int pa,fin;
    trie *a[10];
};
char cad[15];
void calc()
{
    trie t;
    trie *L = &t;
    L->pa = 0;
    L->fin = 0;
    for(int i=0;i<=9;++i)
        L->a[i] = NULL;
    for(int i=0;i<n;++i)
    {
        trie *L = &t;
        scanf("%s",cad);
        for(int j=0;j<strlen(cad);++j)
        {
            if(L->a[cad[j]-'0']==NULL)
            {
                L->a[cad[j]-'0'] =  new trie();
                L->a[cad[j]-'0']->pa = 0;
                L->a[cad[j]-'0']->fin = 0;
            }
            L->a[cad[j]-'0']->pa++;
            if(L->a[cad[j]-'0']->fin>0) yes = false;
            L = L->a[cad[j]-'0'];
        }
        if(L->pa > 1) yes = false;
        L->fin++;
        
    }
}
int main()
{
    scanf("%d",&test);
    while(test--)
    {
        yes = true;
        scanf("%d",&n);
        calc();
        if(yes) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

