#include <stdio.h>
#include <conio.h>
#include <limits.h>

int bitAnd(int a,int b)
{
int res;

a=~a;
b=~b;
res=a|b;
res=~res;
return res;
}
int bitXor(int a,int b)
{
int na,nb,res;

na=~a;
nb=~b;
a=a&nb;
b=b&na;
na=~a;
nb=~b;
res=na&nb;
res=~res;
return res;
}
int thirdBits(void)
{
int a,i,res;

a=36;
res=36;
a=a<<3;
res=res+a;
a=a<<3;
res=res+a;
a=a<<3;
res=res+a;
a=a<<3;
res=res+a;

return res;
}
int fitsBits(int x,int n)
{
int res;
res=x>>n;
res=!res;
return res;
}
int sign(int x)
{
int s,n,res;
s=x>>31;
n=!x;
n=!n;
res=s|n;
return res;
}
int getByte(int x,int n)
{
 int res;
 n=n<<3;
 x=x>>n;
 res=x&255;
return res;
}
int logicalShift(int x,int n)
{
int a,res;

res=x>>n;
a=7;
a=a<<4;
a=a+0xF;
a=a<<4;
a=a+0xF;
a=a<<4;
a=a+0xF;
a=a<<4;
a=a+0xF;
a=a<<4;
a=a+0xF;
a=a<<4;
a=a+0xF;
a=a<<4;
a=a+0xF;
a=a>>n;
a=a<<1;
a=a+1;
res=res&a;
return res;
}
int addOK(int x,int y)
{
 int xv,yv,pr,a,res;

 a=255;
 a=a<<8;
 a=a+255;
 xv=x&a;
 yv=y&a;
 pr=xv+yv;
 pr=pr>>16;
 x=x>>16;
 y=y>>16;
 x=x&a;
 y=y&a;
 pr=x+y+pr;
 pr=pr>>16;
 res=!pr;

return res;
}
int bang(int a)
{
 int av,res;

 av=a>>16;
 a=a|av;
 av=a>>8;
 a=a|av;
 av=a>>4;
 a=a|av;
 av=a>>2;
 a=a|av;
 av=a>>1;
 a=a|av;
 res=a&1;

return res;
}
int conditional(int x,int y,int z)
{
int xz,res;
x=!x;
x=!x;
x=x<<31;
x=x>>31;
xz=~x;
res=y&x;
xz=z&xz;
res=res+xz;

return res;
}


int main()
{
int r;

r=bitAnd(5,6);
printf("5 and 6 = %d\n", r);
r=bitXor(4,5);
printf("4 xor 5 = %d\n", r);
r=thirdBits();
printf("thirdBits() = %d\n", r);
r=fitsBits(5,3);
printf("fitsBits(,3) = %d\n", r);
r=fitsBits(-4,3);
printf("fitsBits(-4,3) = %d\n", r);
r=sign(130);
printf("sign(130) = %d\n", r);
r=sign(-23);
printf("sign(-23) = %d\n", r);
r=sign(0);
printf("sign(0) = %d\n", r);
r=getByte(0x12345678,1);
printf("GetByte(0x12345678,1) = %x\n", r);
r=logicalShift(0x87654321,4);
printf("logicalShift(0x87654321,4) = %08x\n", r);
r=addOK(0x80000000,0x80000000);
printf("addOk(0x80000000,0x80000000) = %d\n", r);
r=addOK(0x8000000,0x7000000);
printf("addOk(0x80000000,0x70000000) = %d\n", r);
r=bang(3);
printf("bang(3) = %d\n", r);
r=bang(0);
printf("bang(0) = %d\n", r);
r=conditional(2,4,5);
printf("2?4:5 = %d\n", r);


getch();
return 0;
}
