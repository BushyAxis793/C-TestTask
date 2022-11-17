
#include <fstream>
#include <iostream>
#include <chrono>
#include "Image.h"
#include <memory>




int main()
{
	std::unique_ptr<Image> imageB (new Image());
	std::unique_ptr<Image> imageA(new Image(255,0,0));
	/*

	/* Dodać konstrukctor domyslny który tworzy imgA
	* i generuje obrazek z czarnym tlem i bialymi liniami.+
	* Dodać konstrukctor kopiujący który tworzy obraz z 
	* grafiką jak imgA -
	* Dodać kosntruktor pzeciazony, który generuje sam kolor +
	*
	
	


	

	/* Mierzenie czasu operacji
    auto start = std::chrono::high_resolution_clock::now();
    

    auto stop = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

    std::cout << duration.count() << std::endl;
	*/
	
}


