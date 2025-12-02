#include <stdio.h>
void Delete(int *arr , int n , int pos) {
	for (int i = pos ; i < n - 1 ; i++) {
		arr[i] = arr[i+1];
	}
}
void Add(int *arr , int n, int value , int k) {
	for ( int i = n - 1 ; i >= k ; i--) {
		arr[i+1]=arr[i];
	}
}
void Lostvalue(int *arr , int n , int m , int *t) {
	for(int i = 0 ; i < n ; i++) {
		if ( arr[i] == m) {
			for ( int j = i ; j < n - 1 ; j++) {
				arr[j] = arr[j+1];
			}
		(*t)++;
		i--;
		}
	}
}
void Findvalue(int *arr , int n , int t) {
	int Found = 0;
	for (int i = 0 ; i < n ; i++) {
		if ( arr[i] == t) {
			printf("Tim thay phan tu o vi tri : a[%d]\n", i);
			Found = 1;
	    }
	    if ( Found == 0) {
	    	printf("Khong tim thay phan tu t");
	    }
		}
	}
int Maxvalue(int *arr , int n) {
	int Max = arr[0];
	for(int i = 0; i < n ; i++) {
		if ( arr[i] >= Max) {
			Max = arr[i];
		}
	}
	return Max;
}
int Minvalue(int *arr , int n) {
	int Min = arr[0];
	for(int i = 0; i < n ; i++) {
		if ( arr[i] <= Min) {
			Min = arr[i];
		}
	}
	return Min;
}
int main() {
	int n;
	scanf("%d", &n);
	
	int arr[n];
	for (int i = 0 ; i < n ; i++) {
	printf("a[%d]= ", i);
	scanf("%d", &arr[i]);
}
    int pos;
    printf("Nhap phan tu mang can xoa: ");
    scanf("%d", &pos);
    
    Delete(arr,n,pos);
    n = n - 1;
    for(int i = 0; i < n ; i++) {
    	printf("%d ", arr[i]);
	}
	printf("\n");
	int value,k;
	printf("Nhap phan tu chuyen den: ");
	scanf("%d", &k);
	printf("Nhap gia tri them vao: ");
	scanf("%d", &value);
	
	Add(arr,n,value,k);
	arr[k] = value;
	n++;
	for(int i = 0; i < n ; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	int m,t=0;
	printf("Nhap gia tri can xoa: ");
	scanf("%d", &m);
	
	
	Lostvalue(arr,n,m,&t);
	for(int i = 0; i < n-t ; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	printf("Gia tri lon nhat trong mang la: %d", Maxvalue(arr,n));
	printf("\n");
	printf("Gia tri be nhat trong mang la: %d", Minvalue(arr,n));
	printf("\n");
	
	int find;
	printf("Nhap so find : ");
	scanf("%d", &find);
	
	Findvalue(arr,n,find);
	
return 0;
}