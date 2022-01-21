#include "SFML/Graphics.hpp"
#include "const.h"
using namespace sf;

int main()
{
	
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow window(VideoMode(window_width, window_height), "SFML Works!");
	window.setFramerateLimit(60);
	float r = 100.f;
	CircleShape circle(r,100);
	circle.setPosition(400.f-r, 300.f-r);
	float speedx = 2.5f;
	float speedy = 3.5f;
	// ������� ���� ����������. �����������, ���� ������� ����

	while (window.isOpen())
	{
		// 1������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event))
		{
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
		}
		
		//2 �������� ������� �������� update
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
		// 3-1 ������� ����
		window.clear(Color(250,220,100,0));
		//3-2 ������ ������� �������
		window.draw(circle);
		// 3��������� ����	
		window.display();
	}

	return 0;
}