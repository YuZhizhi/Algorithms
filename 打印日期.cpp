#include<stdio.h>

int is_Leap_Year(int year){
	//是不是闰年
	int result=0;
	if((year%100==0&&year%400==0)||(year%100!=0&&year%4==0)){
		result=1;
	}
	return result;
}
int main(){
	int m,n;
	int days_of_month[13];//记录每个月最后一天的天数
	int month=1,day=0;
	
	while(scanf("%d %d",&m,&n)!=EOF){
		//先初始化为不是闰年
	days_of_month[0]=0;
	days_of_month[1]=31;
	days_of_month[2]=31+28;
	days_of_month[3]=31+28+31;
	days_of_month[4]=31+28+31+30;
	days_of_month[5]=31+28+31+30+31;
	days_of_month[6]=31+28+31+30+31+30;
	days_of_month[7]=31+28+31+30+31+30+31;
	days_of_month[8]=31+28+31+30+31+30+31+31;
	days_of_month[9]=31+28+31+30+31+30+31+31+30;
	days_of_month[10]=31+28+31+30+31+30+31+31+30+31;
	days_of_month[11]=31+28+31+30+31+30+31+31+30+31+30;
	days_of_month[12]=31+28+31+30+31+30+31+31+30+31+30+31;

		if(is_Leap_Year(m)){
			for(int i=2;i<=12;i++){
				days_of_month[i]+=1;
			}
		}
		while(days_of_month[month]<n){
			month++;
		}
		//month--;
		
		day=n-days_of_month[month-1];
		//printf("%d %d %d\n",month,n,day);
		if(month<10){
			if(day<10){
				printf("%d-0%d-0%d\n",m,month,day);
			}else{
				printf("%d-0%d-%d\n",m,month,day);				
			}
		}else{
			if(day<10){
				printf("%d-%d-0%d\n",m,month,day);
			}else{
				printf("%d-%d-%d\n",m,month,day);				
			}			
		}
		month=1;
		day=0;
	}
	return 0;
}