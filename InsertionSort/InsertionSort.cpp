#include <SFML\Graphics.hpp>
using namespace sf;


void disp(RenderWindow& window, int* arr, int n, int index, int key, bool sorted)
{
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == Event::Closed)
		{
			window.close();
			exit(0);
		}
	}
	window.clear();
	for (int i = 0; i < n;i++)
	{
		RectangleShape block(Vector2f(10, arr[i]));
		block.setPosition(i * 10, 480 - arr[i]);
		if (!sorted)
		{
			if (i == index) block.setFillColor(Color::Green);
			else if (i == key) block.setFillColor(Color::Red);
		}
		else block.setFillColor(Color::Green);
		window.draw(block);
	}
	window.display();
}



bool insertionSort(RenderWindow& window, int* arr, int n)
{
	int key, j;
	for (int i = 1; i <= n - 1; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
			disp(window, arr, n, j, i, false);
		}
		arr[j + 1] = key;
	}
	return true;
}

int main()
{
	srand(time(0));
	const int length = 190;
	int arr[length];
	for (int i = 0; i < length; i++)
	{
		arr[i] = rand() % 391 + 10;
	}
	
	RenderWindow window(VideoMode(1900, 480), "Insertion Sort");
	window.setFramerateLimit(0);
	bool sorted = false;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

			while(!sorted) sorted = insertionSort(window, arr, length);
			disp(window, arr, length, -1, -1, sorted);
		}
	}
	
	return 0;
}