#include <stdio.h>


void removeAt(int *a, int *size, int index) {
    for (int i = index; i < (*size) - 1; i++) {
        a[i] = a[i + 1];
    }
    (*size)--;
}


void insertAt(int *a, int *size, int value, int index) {
    for (int i = (*size) - 1; i >= index; i--) {
        a[i + 1] = a[i];
    }
    a[index] = value;
    (*size)++;
}


int findFirst(int *a, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (a[i] == target)
            return i;
    }
    return -1;
}


void removeAll(int *a, int *size, int target) {
    int pos;
    while ((pos = findFirst(a, *size, target)) != -1) {
        removeAt(a, size, pos);
    }
}


int getMax(int *a, int size) {
    int max = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}


int getMin(int *a, int size) {
    int min = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int main() {
    int a[100];
    int n;

    printf("Nhap so phan tu: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    int choice;

    do {
        printf("1. Xoa phan tu tai vi tri\n");
        printf("2. Them phan tu tai vi tri k\n");
        printf("3. Xoa tat ca phan tu co gia tri x\n");
        printf("4. Tim gia tri lon nhat\n");
        printf("5. Tim gia tri nho nhat\n");
        printf("6. Tim vi tri cua gia tri x\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1: {
                int index;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &index);

                removeAt(a, &n, index);

                for (int i = 0; i < n; i++)
                    printf("%d ", a[i]);
                printf("\n");

                break;
            }

            case 2: {
                int index, value;
                printf("Nhap vi tri chen: ");
                scanf("%d", &index);
                printf("Nhap gia tri: ");
                scanf("%d", &value);

                insertAt(a, &n, value, index);

                for (int i = 0; i < n; i++)
                    printf("%d ", a[i]);
                printf("\n");

                break;
            }

            case 3: {
                int value;
                printf("Nhap gia tri can xoa: ");
                scanf("%d", &value);

                removeAll(a, &n, value);

                for (int i = 0; i < n; i++)
                    printf("%d ", a[i]);
                printf("\n");

                break;
            }

            case 4:
                printf("Gia tri lon nhat: %d\n", getMax(a, n));
                break;

            case 5:
                printf("Gia tri nho nhat: %d\n", getMin(a, n));
                break;

            case 6: {
                int value;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);

                int pos = findFirst(a, n, value);

                if (pos == -1)
                    printf("Khong tim thay phan tu!\n");
                else
                    printf("Tim thay tai vi tri a[%d]\n", pos);

                break;
            }

            case 0:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (choice != 0);

    return 0;
}
