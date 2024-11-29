#include <stdio.h>

int main() {
    // Khai bao mang bat ki va gan gia tri
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10; // So phan tu cua mang

    // In mang ban dau
    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Yeu cau nguoi dung nhap vi tri can sua va gia tri moi
    int pos, newValue;
    printf("Nhap vi tri can sua (tu 0 den %d): ", n - 1);
    scanf("%d", &pos);

    // Kiem tra tinh hop le cua vi tri
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le. Thoat chuong trinh.\n");
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &newValue);

    // Sua gia tri toi vi tri da nhap
    arr[pos] = newValue;

    // In mang sau khi sua
    printf("Mang sau khi sua:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

