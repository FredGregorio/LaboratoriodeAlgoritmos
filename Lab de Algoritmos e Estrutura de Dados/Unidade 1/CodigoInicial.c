int x = 10;
int *ptr = &x; // &x pega o endereço de memória de x

printf("Valor de x: %d\n", x);
printf("Endereço de x: %p\n", &x);
printf("Conteúdo de ptr (endereço): %p\n", ptr);
printf("Valor apontado por ptr: %d\n", *ptr); // *ptr acessa o valor no endereço

