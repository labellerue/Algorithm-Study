#include <stdio.h>

//น้มุ 11726

int counted[1001];

int dtTile(int x){
	if(x==1) return 1;
	if(x==2) return 2;
	if(counted[x] != 0) return counted[x];
	return counted[x] = (dtTile(x-1) + dtTile(x-2)) % 10007;
}

int main(void){
	int number;
	scanf("%d", &number);
	printf("%d", dtTile(number));
	
	return 0;
}
