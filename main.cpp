#include "SFML/Graphics.hpp"
#include "const.h"
using namespace sf;

int main()
{
	
	// Объект, который, собственно, является главным окном приложения
	RenderWindow window(VideoMode(window_width, window_height), "SFML Works!");
	window.setFramerateLimit(60);
	float r = 100.f;
	CircleShape circle(r,100);
	circle.setPosition(400.f-r, 300.f-r);
	float speedx = 2.5f;
	float speedy = 3.5f;
	// Главный цикл приложения. Выполняется, пока открыто окно

	while (window.isOpen())
	{
		// 1Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
		}
		
		//2 изменеие игровых объектов update
		circle.move(speedx, speedy);
		if (circle.getPosition().x + 2 * r >= window_width) {
			speedx = -speedx;
		}
		if (circle.getPosition().x <= 0) {
			speedx = -speedx;
		}
		if (circle.getPosition().y + 2 * r >= window_height) {
			speedy = -speedy;
		}
		if (circle.getPosition().y <= 0) {
			speedy = -speedy;
		}
		// 3-1 очистка окна
		window.clear(Color(250,220,100,0));
		//3-2 рисуем игровые объекты
		window.draw(circle);
		// 3Отрисовка окна	
		window.display();
	}

	return 0;
}