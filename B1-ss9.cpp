#include <stdio.h>

int main() {
    // Khai bao mang voi kich thuoc toi da
    int arr[100];
    int currentLength = 0; // Ðo dai hien tai cua mang

    // Nhap so phan tu ban dau
    int numElements;
    printf("Nhap so phan tu ban dau (toi da 100): ");
    scanf("%d", &numElements);

    if (numElements > 100 || numElements < 0) {
        printf("So phan tu khong hop le. Thoat chuong trinh.\n");
        return 1;
    }

    // Nhap cac phan tu vao mang
    printf("Nhap %d phan tu:\n", numElements);
    for (int i = 0; i < numElements; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    // Cap nhat do dai hien tai
    currentLength = numElements;

    // Yeu cau nhap gia tri va vi tri can them
    int addValue, addIndex;
    printf("Nhap gia tri can them: ");
    scanf("%d", &addValue);
    printf("Nhap vi tri can them (tu 0 den 99): ");
    scanf("%d", &addIndex);

    if (addIndex < 0 || addIndex >= 100) {
        printf("Vi tri khong hop le. Thoat chuong trinh.\n");
        return 1;
    }

    // Kiem tra va thuc hien them phan tu
    if (addIndex >= currentLength) {
        // Neu vi tri them lon hon hoac bang currentLength
        arr[addIndex] = addValue;
        currentLength = addIndex + 1; // Cap nhat do dai hien tai
    } else {
        // Neu vi tri them nho hon currentLength
        for (int i = currentLength; i > addIndex; i--) {
            arr[i] = arr[i - 1]; // Doi cac phan tu sang phai
        }
        arr[addIndex] = addValue; // Gan gia tri moi vao vi tri can them
        currentLength++; // Tang do dai hien tai
    }

    // In mang sau khi them
    printf("Mang sau khi them:\n");
    for (int i = 0; i < currentLength; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

