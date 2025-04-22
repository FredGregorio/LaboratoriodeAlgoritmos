void incrementa(int *num) {
    (*num)++; // incrementa o valor apontado
}

int main() {
    int a = 5;
    incrementa(&a); // passa o endereço de a
    printf("Valor de a: %d\n", a); // agora a vale 6
}

