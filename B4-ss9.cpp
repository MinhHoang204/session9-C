#include <stdio.h>

// Khai bao cac hang so
#define MAX_SIZE 100

// Ham hien thi menu
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap vao mang\n");
    printf("2. Hien thi mang\n");
    printf("3. Them phan tu\n");
    printf("4. Sua phan tu\n");
    printf("5. Xoa phan tu\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}

// Ham hien thi mang
void displayArray(int arr[], int length) {
    if (length == 0) {
        printf("Mang rong.\n");
        return;
    }
    printf("Mang hien tai: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ham them phan tu
void addElement(int arr[], int *length) {
    if (*length >= MAX_SIZE) {
        printf("Mang da day. Khong the them phan tu moi.\n");
        return;
    }

    int value, position;
    printf("Nhap gia tri can them: ");
    scanf("%d", &value);
    printf("Nhap vi tri can them (tu 0 den %d): ", *length);
    scanf("%d", &position);

    if (position < 0 || position > *length) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = *length; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;
    (*length)++;
    printf("Da them phan tu thanh cong.\n");
}

// Ham sua phan tu
void updateElement(int arr[], int length) {
    int position, newValue;
    printf("Nhap vi tri can sua (tu 0 den %d): ", length - 1);
    scanf("%d", &position);

    if (position < 0 || position >= length) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);
    arr[position] = newValue;
    printf("Da sua phan tu thanh cong.\n");
}

// Ham xoa phan tu
void deleteElement(int arr[], int *length) {
    if (*length == 0) {
        printf("Mang rong. Khong the xoa phan tu.\n");
        return;
    }

    int position;
    printf("Nhap vi tri can xoa (tu 0 den %d): ", *length - 1);
    scanf("%d", &position);

    if (position < 0 || position >= *length) {
        printf("Vi tri khong hop le.\n");
        return;
    }

    for (int i = position; i < *length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    (*length)--;
    printf("Da xoa phan tu thanh cong.\n");
}

// Ham chinh
int main() {
    int arr[MAX_SIZE];
    int length = 0; // So phan tu hien tai cua mang
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nhap mang
                printf("Nhap so phan tu muon nhap (toi da %d): ", MAX_SIZE);
                scanf("%d", &length);
                if (length < 0 || length > MAX_SIZE) {
                    printf("So phan tu khong hop le.\n");
                    length = 0;
                } else {
                    for (int i = 0; i < length; i++) {
                        printf("Nhap phan tu thu %d: ", i);
                        scanf("%d", &arr[i]);
                    }
                    printf("Da nhap mang thanh cong.\n");
                }
                break;

            case 2: // Hien thi mang
                displayArray(arr, length);
                break;

            case 3: // Them phan tu
                addElement(arr, &length);
                break;

            case 4: // Sua phan tu
                updateElement(arr, length);
                break;

            case 5: // Xoa phan tu
                deleteElement(arr, &length);
                break;

            case 6: // Thoat
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 6);

    return 0;
}

