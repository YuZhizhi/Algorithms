#include<stdio.h>

#define N 61
void print(int m){
	if(m<10){
		printf("0%d",m);
	}else{
		printf("%d",m);
	}
}
int ischar(char c){
	if((c>='A'&&c<='Z')||(c>='a'&&c<='z'))
		return 1;
	return 0;
}
int isLowcase(char c){
	if(c>='A'&&c<='Z')
		return 0;
	return 1;
}
int isNumber(char c){
	if(c>='0'&&c<='9')
		return 1;
	return 0;
}
int analyse1(char str1[],char str2[]){
	int result=0;
	int i=0;
	for(i=0;str1[i]!='#'&&str2[i]!='#';i++){
		if(str1[i]==str2[i]){
			if(ischar(str1[i])&&!isLowcase(str1[i])){//字母并且是大写
				switch(str1[i]){
				case 'A': result+=100;break;
				case'B':result+=200;break;
				case'C':result+=300;break;
				case 'D':result+=400;break;
				case 'E':result+=500;break;
				case 'F':result+=600;break;
				case'G':result+=700;break;
				}
				break;
			}
		}//end if
	}//end for
	for(i+=1;str1[i]!='#'&&str2[i]!='#';i++){
		if(str1[i]==str2[i]){
			if(isNumber(str1[i])||(ischar(str1[i])&&!isLowcase(str1[i]))){
				//如果是数字或者是大写字母
				if(isNumber(str1[i])){
					result=result+str1[i]-48;
				}else{
					result=result+str1[i]-55;
				}
				break;
			}
		}
	}//end for
	return result;
}
int analyse2(char str3[],char str4[]){
	int result=0;
	int i=0;
	for(i=0;str3[i]!='#'&&str4[i]!='#';i++){
		if(str3[i]==str4[i]){
			if(ischar(str3[i]))
			return i;
		}
	}
	return result;
}
int main(){
	char Day[3];
	int HH;
	int MM;
	int dh=0;//dh=day+hh
	char str1[N],str2[N],str3[N],str4[N];

	int str1_size=0,str2_size=0,str3_size=0,str4_size=0;
	//initialize
	for(int i=0;i<N;i++){
		str1[i]='#';
		str2[i]='#';
		str3[i]='#';
		str4[i]='#';
	}

	scanf("%s",str1);
	scanf("%s",str2);
	scanf("%s",str3);
	scanf("%s",str4);
	
	dh=analyse1(str1,str2);
	MM=analyse2(str3,str4);
	HH=dh%100;
	//printf("%d\n",dh/100);
	switch(dh/100){
	case 1:Day[0]='M';Day[1]='O';Day[2]='N';break;
	case 2:Day[0]='T';Day[1]='U';Day[2]='E';break;
	case 3:Day[0]='W';Day[1]='E';Day[2]='D';break;
	case 4:Day[0]='T';Day[1]='H';Day[2]='U';break;
	case 5:Day[0]='F';Day[1]='R';Day[2]='I';break;
	case 6:Day[0]='S';Day[1]='A';Day[2]='T';break;
	case 7:Day[0]='S';Day[1]='U';Day[2]='N';break;
	}
	printf("%c%c%c ",Day[0],Day[1],Day[2]);
	print(HH);
	printf(":");
	print(MM);
	printf("\n");
	return 0;
}