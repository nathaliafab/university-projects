int min (int* vetor, int size) {
	int i, menor = vetor[0];
	for (i = 0; i < size; i++) {
		if (menor > vetor[i]) {
			menor = vetor[i];
		}
	}
	return menor;
}