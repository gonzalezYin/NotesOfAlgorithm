//4-4
#include<stdio.h>
#include<string.h>

int readchar(){
    for(;;){
        int ch=getchar();
        //一直读到非换行符为止
        if(ch!='\n' && ch!='\r')
            return ch;
    }
}
//读取c位二进制字符（即0和1），并转化为十进制整数
int readint(int c){
    int v=0;
    while(c--)
        v=v*2+readchar()-'0';
}

int code[8][1<<8];
//读取编码
int readcodes(){
    //清空数组
    memset(code, 0, sizeof(code));
    //直接调到下一行开始读取。如果输入已经结束，会读到EOF。
    code[1][0]=readchar();
    for(int len=2; len<=7; len++){
        for(int i=0; i<(1<<len)-1; i++){
            int ch=getchar();
            if(ch==EOF) return 0;
            if(ch=='\n' || ch=='\r') return 1;
            code[len][i]=ch;
        }
    }
    return 1;
}

int main(){
    while(readcodes()){
        for(;;){
            int len=readint(3);
            if(len==0) break;
            for(;;){
                int v=readint(len);
                if(v==(1<<len)-1)break;
                putchar(code[len][v]);
            }
        }
        putchar('\n');
    }
    return 0;
}

//4-5
#include<stdio.h>
#include<string.h>
#define maxd 10000

struct Command{
    char c[5];
    int r1, c1, r2, c2;
    int a, x[20];
}cmd[maxd];
int r, c, n;

int simulate(int* r0, int* c0){
    for(int i=0; i<n; i++){
        if(cmd[i].c[0]=='E'){
            if(cmd[i].r1==*r0 && cmd[i].c1==*c0){
                *r0=cmd[i].r2;
                *c0=cmd[i].c2;
            }
            else if(cmd[i].r2==*r0 && cmd[i].c2==*c0){
                *r0=cmd[i].r1;
                *c0=cmd[i].c1;
            }
        }
        else{
            int dr=0, dc=0;
            for(int j=0; j<cmd[i].a; j++){
                int x=cmd[i].x[j];
                if(cmd[i].c[1]=='I'){
                    if(cmd[i].c[1]=='R' && x<=*r0) dr++;
                    if(cmd[i].c[1]=='C' && x<=*c0) dc++;
                }
                else{
                    if(cmd[i].c[1]=='R' && x<=*r0) return 0;
                    if(cmd[i].c[1]=='C' && x<=*c0) return 0;
                    if(cmd[i].c[1]=='R' && x<*r0) dr--;
                    if(cmd[i].c[1]=='C' && x<*r0) dc--;
                }
            }
            *r0+=dr;
            *c0+=dc;
        }
    }
    return 1;
}
int main(){
    int r0, c0, q, kase=0;
    while(scanf("%d%d%d", &r, &c, &n)==3 && r){
        for(int i=0; i<n; i++){
            scanf("%s", cmd[i].c);
            if(cmd[i].c[0]=='E'){
                scanf("%d%d%d%d", &cmd[i].r1, &cmd[i].c1, &cmd[i].r2, &cmd[i].c2);
            }
            else{
                scanf("%d", &cmd[i].a);
                for(int j=0; j<cmd[i].a; j++) scanf("%d", &cmd[i].x[j]);
            }
        }
        if(kase>0) printf("\n");
        printf("Spreadsheet #%d\n", ++kase);

        scanf("%d", &q);
        while(q--){
            scanf("%d%d", &r0, &c0);
            printf("Cell data in (%d%d)", r0, c0);
            if(!simulate(&r0, &c0)) printf("GONE\n");
            else printf("moved to (%d%d)\n", r0, c0);
        }
    }
    return 0;
}

//4-6
#include<stdio.h>
#include<string.h>
void print_menu(){}
//isq=1表示查询，isq=0表示删除。
void DQ(int isq){
    char s[maxl];
    for(;;){
        printf("Please enter SID or name. Enter 0 to finish.\n");
        scanf("%s", s);
        if(strcmp(s, "0")==0) break;
        int r=0;
        for(int i=0; i<n; i++)
            if(!removed[i]){
                if(strcmp(sid[i], s)==0 || strcmp(name[i], s)==0){
                    if(isq) printf();
                    else{
                        removed[i]=l; r++;
                    }
                }
            }
        if(!isq) printf("%d student(s) removed.\n", r);
    }
}
int main(){
    for(;;){
        int choice;
        print_menu();
        scanf("%d", &choice);
        if(choice==0) break;
        if(choice==1) add();
        if(choice==2) DQ(0);
        if(choice==3) DQ(1);
        if(choice==4) printf("Showing the ranklist hurts students' self-esteem. Don't do that.\n");
        if(choice==5) stat();
    }
    return 0;
}