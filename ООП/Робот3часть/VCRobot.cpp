// VCRobot.cpp : Определяет функции для статической библиотеки.
//
#define _USE_MATH_DEFINES
#include "pch.h"
#include "VCRobot.h"
#include <corecrt_math_defines.h>
#include <cmath>
#include <iostream>
using std::string;
namespace vcr
{
	VCRobot::VCRobot(float x, float y, float direction):
		x(x), y(y), direction(direction), visible(false), isCleaning(false), step(1.0f)
	{
		// Сделайте так, чтобы при инициализации робота угол ориентации робота всегда находился в диапазоне [0..360) градусов
		// добавьте в конструктор код, который бы вне зависимости от переданного в него значения параметра
		// direction (положительного, отрицательного, > 360 градусов) всегда приводил его к диапазону [0..360) градусов
		// например:
		//  direction = 45 приводится к углу 45
		//  direction = -45 приводится к углу 315
		//  direction = 360 приводится к углу 0
		//  direction = 4500 приводится к углу 180

		// Разместите свой код здесь
		direction = float(fmod((360 + fmod(direction, 360)), 360));
		this->direction = direction;

	}
	VCRobot::~VCRobot()
	{
		if (visible)
			Draw(false);
	}
	void VCRobot::Draw(bool show)
	{
		if (!window) return;
		window->clear();
		if (show)
		{
			if (isCleaning)
			{
				if (spriteOn.getTexture() != nullptr)
				{
					spriteOn.setPosition(x, y);
					window->draw(spriteOn);
				}	
			}
			else if (spriteOff.getTexture() != nullptr)
			{
				spriteOff.setPosition(x, y);
				window->draw(spriteOff);
			}
			window->display();
		}
	}
	void VCRobot::Show()
	{
		Draw(true);
		visible = true;
	}
	void VCRobot::Hide()
	{
		Draw(false);
		visible = false;
	}
	bool VCRobot::SetTextures(std::string textureOn, std::string textureOff)
	{
		bool load1 = this->textureOn.loadFromFile(textureOn);
		if (load1)
		{
			spriteOn.setTexture(this->textureOn);
			auto bounds = spriteOn.getLocalBounds();
			spriteOn.setOrigin(sf::Vector2f(bounds.width / 2, bounds.height / 2));
			spriteOn.setPosition(x, y);
			spriteOn.setRotation(direction);
		}
		bool load2 = this->textureOff.loadFromFile(textureOff);
		if (load2)
		{
			spriteOff.setTexture(this->textureOff);
			auto bounds = spriteOff.getLocalBounds();
			spriteOff.setOrigin(sf::Vector2f(bounds.width / 2, bounds.height / 2));
			spriteOff.setPosition(x, y);
			spriteOff.setRotation(direction);
		}
		return load1 && load2;
	}
	void VCRobot::Rotate(float angle)
	{
		// Дополните данный метод кодом, который бы приводил заданный угол поворота к диапазону [0..360) градусов
		// Аналогичное задание вы делали в коде конструктора робота
		angle = float(fmod((360 + fmod(angle, 360)), 360));
		spriteOn.setRotation(angle);
		spriteOff.setRotation(angle);
		direction = angle;
		Draw(true);
	}

	sf::FloatRect VCRobot::GetBounds() const
	{
		return GetBounds(x, y);
	}

	sf::FloatRect VCRobot::GetBounds(float x, float y) const
	{
		auto origin = spriteOn.getOrigin();
		return sf::FloatRect(x - origin.x, y - origin.y, origin.x * 2, origin.y * 2);
	}
	void VCRobot::SetRenderWindow(sf::RenderWindow* window)
	{
		VCRobot::window = window;
	}

	sf::Vector2u VCRobot::GetFieldSize()
	{
		if (window)
			return window->getSize();
		return sf::Vector2u(1600, 1200);
	}

	sf::RenderWindow* VCRobot::window = nullptr;

	void VCRobot::TurnLeft(float angle)
	{
		if (angle < 0) return;
		angle = float(fmod((360 + fmod(angle, 360)), 360));
		spriteOn.rotate(-angle);
		spriteOff.rotate(-angle);
		direction -= angle;
		direction = float(fmod((360 + fmod(direction, 360)), 360));
		// Дополните данный метод кодом, который бы приводил итоговый угол поворота к диапазону [0..360) градусов
		// Аналогичное задание вы делали в коде конструктора робота

		Draw(true);
	}
	void VCRobot::TurnRight(float angle)
	{
		if (angle < 0) return;
		angle = float(fmod((360 + fmod(angle, 360)), 360));
		spriteOn.rotate(angle);
		spriteOff.rotate(angle);
		direction += angle;
		direction = float(fmod((360 + fmod(direction, 360)), 360));
		// Дополните данный метод кодом, который бы приводил итоговый угол поворота к диапазону [0..360) градусов
		// Аналогичное задание вы делали в коде конструктора робота

		Draw(true);
	}
	void VCRobot::SetStepSize(float stepSize)
	{
		// Напишите код сеттера, позволяющего устанавливать шаг перемещения для робота
		step = stepSize;
	}
	void VCRobot::CleaningOn()
	{
		if (spriteOn.getTexture() != nullptr)
		{
			isCleaning = true;
			Draw(true);
		}
	}
	void VCRobot::CleaningOff()
	{
		if (spriteOff.getTexture() != nullptr)
		{
			isCleaning = false;
			Draw(true);
		}
	}
	sf::Vector2f VCRobot::GetPosition() const
	{
		return sf::Vector2f(x,y);
	}
	float VCRobot::GetRotation() const
	{
		return direction;
	}
	bool VCRobot::IsCleanOn() const
	{
		return isCleaning;
	}
	float VCRobot::GetStepSize() const
	{
		// Напишите код геттера, позволяющего получить текущий шаг перемещения для робота
		return step;
	}
	void VCRobot::MoveForward()
	{
		// Напишите здесь код, перемещающий робота на 1 шаг вперед

		// 1.
		float angleForX = direction + 90; // Выставляем угол относительно оси x, если направление совпадает с осью y, оно будет равно нулю
		angleForX = float(fmod((360 + fmod(angleForX, 360)), 360)); // Нормализуем угол

		// 2.
		float dir = (angleForX / 180) * PI; // Переводим градусы в радианы
		float x1 = x + step * cos(dir); // Высичляем новые координаты робота
		float y1 = y + step * sin(dir); 

		// 3. 
		x = x1, y = y1; // Помещаем координаты в поле обьекта для последующей отрисовки робота на новой позиции

		Draw(true);// Не удаляйте данную строку, в конце перемещения робота нужно перерисовать
	}
	void VCRobot::MoveBackward()
	{
		// Напишите здесь код, перемещающий робота на 1 шаг назад

		// 1.
		float angleForX = direction + 270; // Выставляем угол относительно оси x, если направление совпадает с осью y, оно будет равно нулю
		angleForX = float(fmod((360 + fmod(angleForX, 360)), 360)); // Нормализуем угол

		// 2.
		float dir = (angleForX / 180) * PI; // Переводим градусы в радианы
		float x1 = x + step * cos(dir); // Высичляем новые координаты робота
		float y1 = y + step * sin(dir); 

		// 3. 
		x = x1, y = y1; // Помещаем координаты в поле обьекта для последующей отрисовки робота на новой позиции

		Draw(true);// Не удаляйте данную строку, в конце перемещения робота нужно перерисовать
	}

	bool VCRobot::CanMoveForward() const
	{
		// 1. Сначала вычисляем куда пойдет робот следующим шагом
		float angleForX = direction + 90;
		angleForX = float(fmod((360 + fmod(angleForX, 360)), 360));

		float dir = (angleForX / 180) * PI;
		float x1 = x + step * cos(dir);
		float y1 = y + step * sin(dir);

		// 2. Границы робота в новых координатах
		sf::FloatRect coordSprite = GetBounds(x1, y1);
		sf::Vector2u coordField = GetFieldSize();

		float c1 = coordSprite.left;
		float c2 = coordSprite.top;
		float c3 = c1 + coordSprite.width;
		float c4 = c2 + coordSprite.height;

		// 3. Проверяем на пересечения
		bool leftTopValid = (c1 >= 0) && (c2 >= 0);
		bool rightTopValid = (c3 < coordField.x) && (c2 >= 0);
		bool leftBottomValid = (c1 >= 0) && (c4 < coordField.y);
		bool rightBottomValid = (c3 < coordField.x) && (c4 < coordField.y);

		// 4. Возвращаем будевое выражение
		return leftTopValid && rightTopValid && leftBottomValid && rightBottomValid;
	}

	bool VCRobot::CanMoveBackward() const // Здесь все аналогично методу CanMoveForward, меняется только направление
	{
		float angleForX = direction + 270;
		angleForX = float(fmod((360 + fmod(angleForX, 360)), 360));

		float dir = (angleForX / 180) * PI;
		float x1 = x + step * cos(dir);
		float y1 = y + step * sin(dir);

		sf::FloatRect coordSprite = GetBounds(x1, y1);
		sf::Vector2u coordField = GetFieldSize();

		float c1 = coordSprite.left;
		float c2 = coordSprite.top;
		float c3 = c1 + coordSprite.width;
		float c4 = c2 + coordSprite.height;

		bool leftTopValid = (c1 >= 0) && (c2 >= 0);
		bool rightTopValid = (c3 < coordField.x) && (c2 >= 0);
		bool leftBottomValid = (c1 >= 0) && (c4 < coordField.y);
		bool rightBottomValid = (c3 < coordField.x) && (c4 < coordField.y);

		return leftTopValid && rightTopValid && leftBottomValid && rightBottomValid;
	}

};