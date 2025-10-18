#pragma once

#define WIN32_LEAN_AND_MEAN             // Исключите редко используемые компоненты из заголовков Windows
#include <SFML/Graphics.hpp>
namespace vcr
{
	class VCRobot
	{
		float x, y;
		float direction;
		float step;
		bool isCleaning;
		bool visible;

		sf::Sprite spriteOn, spriteOff;
		sf::Texture textureOn, textureOff;

		static sf::RenderWindow* window;

		const double PI = 3.141592653589793;
	public:
		VCRobot(float x, float y, float direction);
		virtual ~VCRobot();
		// метод загрузки текстур
		bool SetTextures(std::string textureOn, std::string textureOff);
		// управление видимостью и отрисовка
		virtual void Draw(bool show);
		// отобразить робота
		void Show();
		//скрыть робота
		void Hide();
		// поворот в заданное направление
		void Rotate(float angle);
		// поворот налево на указанный угол
		void TurnLeft(float angle = 1.f);
		// поворот направо на указанный угол
		void TurnRight(float angle = 1.f);
		// установка заданного шага перемещения
		void SetStepSize(float stepSize);
		// включение уборки
		void CleaningOn();
		// Выключение уборки
		void CleaningOff();
		//получение позиции роботп
		sf::Vector2f GetPosition() const;
		// получение направления робота
		float GetRotation() const;
		// включен ли режим уборки
		bool IsCleanOn() const;
		// получение размера шага перемещения
		float GetStepSize() const;
		// перемещение вперед на 1 шаг
		void MoveForward();
		// перемещение назад на 1 шаг
		void MoveBackward();
		// проверка, можно ли переместиться вперед на 1 шаг
		bool CanMoveForward() const;
		// проверка, можно ли переместиться назад на 1 шаг
		bool CanMoveBackward() const;
		// метод, возвращающий координаты прямоугольника, описанного вокруг робота
		sf::FloatRect GetBounds() const;
		// метод, возвращающий координаты прямоугольника, описанного вокруг робота, если бы он находился в позиции x,y
		sf::FloatRect GetBounds(float x, float y) const;
		// установка окна рендеринга SFML
		static void SetRenderWindow(sf::RenderWindow* window);
		// возвращает ширину и высоту поля уборки в пикселях
		static sf::Vector2u GetFieldSize();


		bool CanMoveToPosition(float, float) const;
	};
};