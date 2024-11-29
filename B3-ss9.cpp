#include <stdio.h>

int main() {
    // Khai bao mang va cac bien can thiet
    int arr[100];
    int currentLength = 0; // So phan tu hien tai trong mang

    // Nhap so phan tu ban dau
    int numElements;
    printf("Nhap so phan tu ban dau (toi da 100): ");
    scanf("%d", &numElements);

    // Kiem tra so phan tu hop le
    if (numElements < 0 || numElements > 100) {
        printf("So phan tu khong hop le. Thoat chuong trinh.\n");
        return 1;
    }

    // Nhap cac phan tu vao mang
    printf("Nhap %d phan tu:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }
    currentLength = numElements;

    // Yeu cau nguoi dung nhap vi tri can xoa
    int deleteIndex;
    printf("Nhap vi tri can xoa (tu 0 den %d): ", currentLength - 1);
    scanf("%d", &deleteIndex);

    // Kiem tra vi tri xoa hop le
    if (deleteIndex < 0 || deleteIndex >= currentLength) {
        printf("Vi tri xoa khong hop le. Thoat chuong trinh.\n");
        return 1;
    }

    // Thuc hien xoa phan tu
    for (int i = deleteIndex; i < currentLength - 1; i++) {
        arr[i] = arr[i + 1]; // Doi cac phan tu phia sau len truoc
    }
    currentLength--; // Giam do dai hien tai

    // In mang sau khi xoa
    printf("Mang sau khi xoa:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

