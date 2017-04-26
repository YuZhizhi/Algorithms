#include<stdio.h>

int main(){
	int  N;
	unsigned long  result[100];
	int i;
	//initialize
	result[0]=0;
	result[1]=1;
	result[2]=2;
	while(scanf("%d",&N)!=EOF){
		switch(N){
			case 0:break;
			case 1:break;
			case 2:break;
			default:for( i=3;i<=N;i++){
						result[i]=result[i-1]+result[i-2];
					}//end for
					break;
		}
		printf("%ld\n",result[N]);
		for(i=3;i<=N;i++){
			result[i]=-1;
		}
	}
	return 0;
}