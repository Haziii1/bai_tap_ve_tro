#include <stdio.h>
void DeleteElement(int *arr , int n , int pos) {
	for (int i = pos ; i < n - 1 ; i++) {
		arr[i] = arr[i+1];
	}
}
void AddValue(int *arr , int n, int value , int k) {
	for ( int i = n - 1 ; i >= k ; i--) {
		arr[i+1]=arr[i];
	}
}
void LostValue(int *arr , int n , int m , int *t) {
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
void FindElement(int *arr , int n , int f) {
	int Found = 0;
	for (int i = 0 ; i < n ; i++) {
		if ( arr[i] == f) {
			printf("Tim thay phan tu o vi tri : a[%d]\n", i);
			Found = 1;
	    }
	    if ( Found == 0) {
	    	printf("Khong tim thay phan tu t");
	    }
		}
	}
int MaxValue(int *arr , int n) {
	int Max = arr[0];
	for(int i = 0; i < n ; i++) {
		if ( arr[i] >= Max) {
			Max = arr[i];
		}
	}
	return Max;
}
int MinValue(int *arr , int n) {
	int Min = arr[0];
	for(int i = 0; i < n ; i++) {
		if ( arr[i] <= Min) {
			Min = arr[i];
		}
	}
	return Min;
}
int main() {
	int arr[100];
	int n;
	
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	
	for(int i = 0 ; i < n ; i++) {
		printf("a[%d] = ", i);
		scanf("%d", &arr[i]);
	}
	
	int choice;
	do {
		printf("1. Nhap phan tu can xoa\n");
        printf("2. Them phan tu vi tri k trong mang\n");
        printf("3. Xoa gia tri t khoi mang\n");
        printf("4. Tim gia tri lon nhat trong mang\n");
        printf("5. Tim gia tri nho nhat trong mang\n");
        printf("6. Tim gia tri phan tu o vi tri f\n");

		scanf("%d", &choice);
		
		switch(choice) {
			case 1: {
				int pos;
				printf("Nhap phan tu can xoa : ");
				scanf("%d", &pos);
				
				DeleteElement(arr,n,pos);
				n = n - 1;
				
				for (int i = 0; i < n ; i++) {
					printf("%d ", arr[i]);
				}
				printf("\n");
				break;
			}
			case 2: {
				int value,k;
	            printf("Nhap phan tu chuyen den: ");
	            scanf("%d", &k);
	            printf("Nhap gia tri them vao: ");
	            scanf("%d", &value);
	
  	            AddValue(arr,n,value,k);
	            arr[k] = value;
	            
	            n++;
	            for(int i = 0; i < n ; i++) {
		            printf("%d ", arr[i]);
	            }
	            printf("\n");
				break;
			}
			case 3: {
				int m,t=0;
	            printf("Nhap gia tri can xoa: ");
 	            scanf("%d", &m);
	
	
	            LostValue(arr,n,m,&t);
	            for(int i = 0; i < n-t ; i++) {
		            printf("%d ", arr[i]);
            	}
            	printf("\n");
				break;
			}
			case 4: {
				printf("Gia tri lon nhat trong mang la: %d", MaxValue(arr,n));
				printf("\n");
				break;
			}
			case 5: {
				printf("Gia tri be nhat trong mang la: %d", MinValue(arr,n));
				printf("\n");
				break;
			}
			case 6: {
				int find;
				
	            printf("Nhap so find : ");
	            scanf("%d", &find);
	            
	            FindElement(arr,n,find);
	            printf("\n");
				break;
			}
		}
	} while(choice != 0);
	
return 0;
}
