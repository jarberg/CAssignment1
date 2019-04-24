#include <stdio.h>
#include <math.h>

//#define M_PI acos(-1.0)

float tester[6]={0};
int firstInput=10;

float triangle();
float FloatScan();
void evenSteven();
void goldBach();
int primeCheck();

int main(){
	//setbuf(stdout, NULL);
	//evenSteven();
	//printf("%d",primeCheck(4));
	goldBach(100);
	//triangle();
}

void evenSteven(){
	int i=1;
	int check =0;
	while(i){
		i = (int) FloatScan();
		if(check==0){
			if(i>0){
				firstInput = i;
				check++;
			}
		}
		if(i){
			tester[0] += i%2;
			tester[1] += i*(i%2);
			tester[2]  = ((tester[2]+(i%2*i)))/(1+((i)%2));

			tester[3] += (i+1)%2;
			tester[4] += (i+1)%2*i;
			tester[5]  = ((tester[5]+((i+1)%2*i)))/(1+((i+1)%2));
		}
	}

	printf("odd count = %d, odd sum = %d, oddAverage = %.2f",(int)tester[0],(int)tester[1],tester[2]);
	printf("\n");
	printf("even count = %d, even sum = %d, evenAverage = %.2f",(int)tester[3],(int)tester[4],tester[5]);
	printf("\n");
}

int primeCheck(int n){
	int i;
	int primecheck=0;
	if (n == 1 || n==0){
		return primecheck;
	}
	for(i = 2; i <= n/2; ++i){
		if(n%i == 0){
			primecheck = 1;
			break;
		}
	}
	if (primecheck == 0)
		return 1;
	else
		return 0;
}

void goldBach(int n){
	int temp = n;
	int count1=0;
	int count2=0;

	while(temp>-1){
		int bool = 0;
		for( count1 = 0; count1+count2 < temp ; count1++ ){
			if(bool!=1) {
				if (primeCheck(count1)) {
					for (count2 = 0; (count1 + count2) <= temp; count2++) {
						if (primeCheck(count2)) {
							if(count1+count2 == temp){
								bool=1;
								break;
							}
						}
					}
				}
			}
			else{
				break;
			}
			count2 =0;
		}
		if(bool==0){
			printf("%d",temp);
			printf("\n");
		}
		temp--;
	}
}

float triangle(){
	printf("insert side variable a: ");
	float A = FloatScan();
	printf("insert side variable b: ");
	float B = FloatScan();
	printf("insert side variable c: ");
	float C = FloatScan();

	float angleA = acos((pow(B,2)+pow(C,2)-pow(A,2))/(2*B*C))*180.0/M_PI;
	float angleB = acos((pow(A,2)+pow(C,2)-pow(B,2))/(2*A*C))*180.0/M_PI;
	float angleC = acos((pow(A,2)+pow(B,2)-pow(C,2))/(2*B*A))*180.0/M_PI;



	if( A!=0 && B != 0 & C!=0 && angleA != 0 || angleB != 0 || angleC!= 0){
		if((abs((A*A+B*B)/(C*C)-1) <= 0.01 || abs((A*A+C*C)/(B*B)-1) <= 0.01 || abs((C*C+B*B)/(A*A)-1) <= 0.01)){
			printf("Trekanten er retvinklet");
		}
		else{
			printf("Trekanten er vilkårlig");
		}
		if(A==B){
			printf("\n");
			if(A==C){
				printf("Trekanten er ligesidet");
			}
			else{
				printf("Trekanten er ligebenet");
			}
		}
		printf("\n");
		if(angleA>90 || angleB > 90 || angleC>90){
			printf("Trekanten er stump");
		}
		else if(angleA<90 && angleB < 90 && angleC<90) {
			printf("Trekanten er spids");
		}
	}
	else{
		printf("Noget er galt!");
	}
	printf("\n");
}

float FloatScan(){
	float float1;
	scanf("%f", &float1);
	return float1;
}



/*
 	int temp = n;
	int count1;
	int count2;

	while(temp>1){
		int bool = 0;
		for( count1 = 0; count1 < temp ; count1++ ){
			if(bool==1){
				break;
			}
			if(primeCheck(count1)==1){
				for( count2 = 0; (count1+count2) <= temp ; count2++ ){
					if(primeCheck(count2)==1){
						if((count1+count2)==temp){
							bool = 1;
							break;
						}
						else{
							bool =0;
						}
						if((count1+count2+1)>=temp){
							break;
						}
					}
				}
			}
		}
		if(bool==3){
			printf("%d \n",temp);
		}
		temp--;
	}
 */
