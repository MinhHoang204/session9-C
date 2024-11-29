#include <stdio.h>

// Ham hien thi menu
void displayMenu() {
    printf("\nMENU\n");
    printf("1. Nhap kich co va gia tri cac phan tu cua mang\n");
    printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
    printf("3. In gia tri cac phan tu la le va tinh tong\n");
    printf("4. In ra cac phan tu nam tren duong bien va tinh tich\n");
    printf("5. In ra cac phan tu nam tren duong cheo chinh\n");
    printf("6. In ra cac phan tu nam tren duong cheo phu\n");
    printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
    printf("8. Thoat\n");
    printf("Lua chon cua ban: ");
}

int main() {
    int arr[100][100], rows = 0, cols = 0, choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Nhap kich co va gia tri cac phan tu cua mang
                printf("Nhap so dong: ");
                scanf("%d", &rows);
                printf("Nhap so cot: ");
                scanf("%d", &cols);

                if (rows <= 0 || cols <= 0 || rows > 100 || cols > 100) {
                    printf("Kich thuoc khong hop le.\n");
                } else {
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            printf("Nhap gia tri phan tu arr[%d][%d]: ", i, j);
                            scanf("%d", &arr[i][j]);
                        }
                    }
                    printf("Da nhap mang thanh cong.\n");
                }
                break;
            }
            case 2: {
                // In gia tri cac phan tu cua mang theo ma tran
                if (rows == 0 || cols == 0) {
                    printf("Mang chua co du lieu.\n");
                } else {
                    printf("Ma tran:\n");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            printf("%d ", arr[i][j]);
                        }
                        printf("\n");
                    }
                }
                break;
            }
            case 3: {
                // In gia tri cac phan tu la le va tinh tong
                if (rows == 0 || cols == 0) {
                    printf("Mang chua co du lieu.\n");
                } else {
                    int sum = 0;
                    printf("Cac phan tu le: ");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            if (arr[i][j] % 2 != 0) {
                                printf("%d ", arr[i][j]);
                                sum += arr[i][j];
                            }
                        }
                    }
                    printf("\nTong cac phan tu le: %d\n", sum);
                }
                break;
            }
            case 4: {
                // In ra cac phan tu nam tren duong bien va tinh tich
                if (rows == 0 || cols == 0) {
                    printf("Mang chua co du lieu.\n");
                } else {
                    long long product = 1;
                    printf("Cac phan tu tren duong bien: ");
                    for (int i = 0; i < rows; i++) {
                        for (int j = 0; j < cols; j++) {
                            if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
                                printf("%d ", arr[i][j]);
                                product *= arr[i][j];
                            }
                        }
                    }
                    printf("\nTich cac phan tu tren duong bien: %lld\n", product);
                }
                break;
            }
            case 5: {
                // In ra cac phan tu nam tren duong cheo chinh
                if (rows == 0 || cols == 0 || rows != cols) {
                    printf("Mang khong phai ma tran vuong hoac chua co du lieu.\n");
                } else {
                    printf("Cac phan tu tren duong cheo chinh: ");
                    for (int i = 0; i < rows; i++) {
                        printf("%d ", arr[i][i]);
                    }
                    printf("\n");
                }
                break;
            }
            case 6: {
                // In ra cac phan tu nam tren duong cheo phu
                if (rows == 0 || cols == 0 || rows != cols) {
                    printf("Mang khong phai ma tran vuong hoac chua co du lieu.\n");
                } else {
                    printf("Cac phan tu tren duong cheo phu: ");
                    for (int i = 0; i < rows; i++) {
                        printf("%d ", arr[i][cols - i - 1]);
                    }
                    printf("\n");
                }
                break;
            }
            case 7: {
                // In ra dong co tong gia tri cac phan tu la lon nhat
                if (rows == 0 || cols == 0) {
                    printf("Mang chua co du lieu.\n");
                } else {
                    int maxSum = 0, maxRow = 0;
                    for (int i = 0; i < rows; i++) {
                        int rowSum = 0;
                        for (int j = 0; j < cols; j++) {
                            rowSum += arr[i][j];
                        }
                        if (i == 0 || rowSum > maxSum) {
                            maxSum = rowSum;
                            maxRow = i;
                        }
                    }
                    printf("Dong co tong lon nhat: %d (Tong: %d)\n", maxRow, maxSum);
                }
                break;
            }
            case 8: {
                printf("Thoat chuong trinh.\n");
                break;
            }
            default: {
                printf("Lua chon khong hop le. Vui long chon lai.\n");
            }
        }
    } while (choice != 8);

    return 0;
}

