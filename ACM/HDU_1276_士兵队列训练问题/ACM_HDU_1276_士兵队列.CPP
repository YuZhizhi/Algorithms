#include<stdio.h>

void print(int arr[],int Num_Of_Solider){// the primary version of print is void print(int arr[])
	int i=0;
	/********the following is the uncorrect print
	while(i<3){
		if(arr[i]!=0){
		    printf("%d ",arr[i++]);
	}*/
	while(i<Num_Of_Solider){
		if(i<Num_Of_Solider-1)
			printf("%d ",arr[i++]);
		else printf("%d",arr[i++]);
	}
	printf("\n");
}
void solve(){
	int a[5001],b[5001];
	int Num_Of_Solider;
	int N,n;
	int flag=0,k,i,index;
	int temp_num;
	scanf("%d",&N);// the number of groups
	while(N--){
		scanf("%d",&n);//the number of soliders
		// initialize
		i=0;
		while(i<n){
			a[i]=i+1;
			i++;
		}
		Num_Of_Solider=n;

		while(Num_Of_Solider>3){
			for(k=2;k<=3;k++){
				if(Num_Of_Solider<=3)break;
				temp_num=Num_Of_Solider;
				if(k==2){
					i=0;
					Num_Of_Solider=0;
					i=0;
					index=0;
					while(i<temp_num){	
						if(i%2==0){
							b[index++]=a[i];
							Num_Of_Solider++;
						}
						a[i]=0;
						i++;
					}// end while i<n
				}//end if k==2
				else{
					i=0;
					Num_Of_Solider=0;
				    i=0;
					index=0;
					while(i<temp_num){
						if((i+1)%3!=0){
							a[index++]=b[i];
							Num_Of_Solider++;
						}
						b[i]=0;
						i++;
					}//end while i<n
				}//end else
			}// end for
		}//end >3
		if(a[0]!=0){
			print(a,Num_Of_Solider);
		}else{
			print(b,Num_Of_Solider);
		}
	}//end N
}
int main(){
	solve();
	return 0;
}