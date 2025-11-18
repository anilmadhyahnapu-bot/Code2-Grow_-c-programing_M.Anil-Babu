#include <stdio.h>
int id[MAX], qty[MAX], price[MAX], count=0;
int rack[R][C] = { {10,5,15}, {20,8,12}, {5,25,10} };
int search(int x) {
for(int i=0; i<count; i++) if(id[i]==x) return i;
return -1;
}
void add() {
int x,q,p;
if(count==MAX){ printf("Full");
return; }
printf("ID: "); scanf("%d",&x);
if(search(x)!=-1){ printf("Duplicate");
return; }
printf("Qty: "); scanf("%d",&q);
printf("Price: "); scanf("%d",&p);
if(q<=0 || p<=0){ printf("Invalid");
return; }
id[count]=x; qty[count]=q; price[count]=p; count++;
printf("Added");
}
void search_disp() {
int x,i;
printf("Search ID: "); scanf("%d",&x);
i = search(x);
if(i==-1){ printf("Not Found");
return; }
printf("ID:%d Qty:%d Price:%d", id[i], qty[i], price[i]);
}
void update() {
int x,c,a,i;
printf("Update ID: "); scanf("%d",&x);
i=search(x);
if(i==-1){ printf("Not Found");
return; }
printf("1.Increase 2.Decrease: ");
scanf("%d",&c);
printf("Amount: ");
scanf("%d",&a);
if(a<=0){
printf("Invalid");
return; }
if(c==1) qty[i]+=a;
else if(c==2) {
if(qty[i]-a<0){
printf("Negative Qty");
return; }
qty[i]-=a;
}
else {
printf("Invalid choice");
return; }
printf("Updated Qty: %d", qty[i]);
}
void rack_report() {
int max=rack[0][0], min=rack[0][0], rmax=0,cmax=0,rmin=0,cmin=0, sum=0;
for(int i=0; i<R; i++)
for(int j=0; j<C; j++) {
sum+=rack[i][j];
if(rack[i][j]>max){ max=rack[i][j]; rmax=i; cmax=j; }
if(rack[i][j]<min){ min=rack[i][j]; rmin=i; cmin=j; }
}
printf("Max: %d at (%d,%d) Min: %d at (%d,%d)Total: %d", max,rmax,cmax,min,rmin,cmin,sum);
}
void stock_value() {
if(count==0){ printf("No products");
return; }
int maxv=qty[0]*price[0], minv=maxv, imax=0, imin=0, total=0;
for(int i=0; i<count; i++){
int val = qty[i]*price[i];
total += val;
printf("ID:%d Value:%d", id[i], val);
if(val>maxv){ maxv=val; imax=i; }
if(val<minv){ minv=val; imin=i; }
}
printf("Highest ID:%d Value:%dLowest ID:%d Value:%d Total:%d", id[imax], maxv, id[imin], minv, total);
}
void display() {
if(count==0){ printf("No products"); return; }
printf("ID Qty Price Value");
for(int i=0; i<count; i++)
printf("%d %d %d %d", id[i], qty[i], price[i], qty[i]*price[i]);
}
int main() {
int ch;
while(1){
printf("1.Add 2.Search 3.Update 4.Rack 5.StockValue 6.Display 0.Exit Choice: ");
scanf("%d", &ch);
switch(ch) {
case 1:add(); break;
case 2:search_disp(); break;
case 3:update(); break;
case 4:rack_report(); break;
case 5:stock_value(); break;
case 6:display(); break;
case 0:return 0;
default: printf("Invalid");
}}}
