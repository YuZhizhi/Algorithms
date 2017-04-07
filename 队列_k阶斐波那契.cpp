#include<stdio.h>

int Caculate_n(int max,int k,int f[]){
	int n=0;
	int CmpTemp;
	int i=1;
	while(1){
		if(n<k-1){
			CmpTemp=-1;
		}else if(n==k-1){
			CmpTemp=0;
		}else{
			CmpTemp=1;
		}
		switch(CmpTemp){
		case -1:f[n]=0;
				break;
		case 0: f[n]=1;
				break;
		case 1: for(i=1;i<=k;i++){
					f[n]+=f[n-i];
				}
				break;
		}// end switch
		if(f[n]>max){
			break;
		}
		n++;
	}// end while 
	return n-1;
}
int main(){
	int max,k;
	int n=0,i=0;
	int f[1001];
	while(i<1001){
		f[i++]=0;
	}
	scanf("%d %d",&k,&max);
	n=Caculate_n(max,k,f);
	printf("%d\n%d\n",n,f[n]);
	return 0;
}