#include <stdio.h>

void normalize_array(int *arr, int size) {
    if (size <= 1) return;
    
    // Trouver min et max
    long long min = arr[0];
    long long max = arr[0];
    
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }
    
    // Éviter division par zéro
    if (max == min) {
        for (int i = 0; i < size; i++) {
            arr[i] = size / 2;
        }
        return;
    }
    
    // Utiliser des doubles pour une meilleure précision
    double scale = (double)(size - 1) / (max - min);
    
    // Normaliser chaque élément
    for (int i = 0; i < size; i++) {
        arr[i] = (int)((arr[i] - min) * scale + 0.5); // +0.5 pour un arrondi correct
    }
}

int main() {
    int arr[] = {229, 188, 253, 97, 273, 50, 126, 429, 58, 243, 233, 264, 408, 207, 185, 3, 96, 
                 212, 220, 369, 499, 152, 407, 386, 27, 249, 115, 120, 236, 460, 216, 334, 475, 
                 401, 470, 437, 174, 332, 345, 330, 347, 287, 24, 218, 82, 436, 8, 237, 309, 488, 
                 435, 102, 338, 440, 500, 310, 184, 11, 205, 151, 167, 327, 40, 314, 286, 464, 430, 
                 308, 60, 84, 468, 248, 271, 458, 250, 274, 189, 234, 110, 394, 387, 448, 363, 2, 
                 391, 105, 270, 5, 361, 247, 480, 85, 266, 168, 417, 7, 256, 145, 302, 329, 404, 
                 351, 128, 431, 22, 23, 463, 301, 367, 88, 466, 172, 349, 454, 379, 335, 46, 267, 
                 55, 486, 157, 316, 364, 37, 467, 455, 420, 284, 108, 392, 175, 80, 158, 210, 311, 
                 292, 355, 374, 300, 280, 177, 131, 331, 439, 77, 425, 397, 48, 326, 231, 403, 413, 
                 166, 245, 257, 483, 371, 91, 230, 215, 324, 100, 135, 12, 336, 222, 223, 446, 450, 
                 353, 493, 155, 303, 484, 263, 438, 198, 317, 29, 238, 368, 385, 119, 53, 149, 191, 
                 409, 224, 133, 182, 9, 142, 33, 255, 315, 357, 260, 130, 288, 365, 137, 305, 36, 
                 496, 390, 432, 393, 54, 451, 10, 71, 171, 320, 38, 406, 491, 214, 106, -359, 59, 
                 225123, 79809076, -6789567};
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    printf("Avant normalisation (10 premiers éléments) :\n");
    for (int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("...\n\n");
    
    normalize_array(arr, size);
    
    printf("Après normalisation (tous les éléments) :\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");
    
    return 0;
}
