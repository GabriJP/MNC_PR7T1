#include <cstdio>
#include "cuda_runtime.h"

extern void printDeviceProperties(cudaDeviceProp devProp);

int main(int argc, char *argv[]) {

	//Contar el n�mero de dispositivos
	int devCount;
	printf("Buscando dispositivos CUDA...\n");
	cudaGetDeviceCount(&devCount);
	printf("Hay %d dispositivos CUDA\n", devCount);

	//Imprimir caracter�sticas de los dispositivos
	for (int i = 0; i < devCount; i++)
	{
		printf("\nDispositivo CUDA #%d\n", i);
		cudaDeviceProp devProp;
		cudaGetDeviceProperties(&devProp, i);
		printDeviceProperties(devProp);
	}

	std::getchar();
	return 0;
}