#pragma once
#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class VCRobot {
private:
	float x, y, rotationAngle, stepSize;
	bool cleaningMode, visibility;

	sf::Texture textureOn;
	sf::Texture textureOff;

	sf::Sprite spriteOn;
	sf::Sprite spriteOff;

	static sf::RenderWindow* window;
public:
	// Конструктор
	VCRobot(float x, float  y, float rotationAngle);
	// Деструктор
	virtual ~VCRobot();

	static void SetRenderWindow(sf::RenderWindow* window); // Статический метод работающий с окном

	// Сделано
	void Draw(bool); // рисует или скрывает робота на экране, в зависимости от значения переданного логического параметра.
	// Сделано
	void Show(); // показывает робота на экране.
	// Сделано
	void Hide(); // скрывает робота с экрана.
	void MoveForward(); // перемещение на 1 шаг вперед по направлению ориентации робота (величина шага задается полем класса, которое вы определили в списке полей (см. выше).
	void MoveBackward(); // перемещение на 1 шаг назад по направлению ориентации робота  (величина шага задается полем класса, которое вы определили в списке полей (см. выше).
	void SetStepSize(float); // перемещение на 1 шаг назад по направлению ориентации робота  (величина шага задается полем класса, которое вы определили в списке полей (см. выше).
	// Сделано
	float GetStepSize() const; // возвращает текущее значение шага перемещения робота.
	// Сделано
	void TurnLeft(float); // поворот против часовой стрелки на заданное кол-во градусов, относительно его текущей ориентации.
	// Сделано
	void TurnRight(float); // поворот пo часовой стрелки на заданное кол-во градусов, относительно его текущей ориентации.
	// Сделано
	void Rotate(float); // поворачивает робота в указанный угол(абсолютное значение).
	// Сделано
	void CleaningOn(); // включение режима пылесоса
	// Сделано
	void CleaningOff(); // выключение режима пылесоса
	// Сделано
	sf::Vector2f GetPosition() const; // получение текущей позиции робота в виде объекта класса sf::Vector2f.
	// Сделано
	float GetRotation() const; // получение текущего угла поворота робота (0-360 град) в виде числа float.
	//bool IsCleanOn() const; // получение текущего состояния включения пылесоса (true – включен, false – выключен).
	bool CanMoveForward() const; // возвращает true, если робот может переместиться в перед по направлению движения, без выхода за пределы экрана, и false в противном случае.
	bool CanMoveBackward() const; // возвращает true, если робот может переместиться в назад без выхода за пределы экрана, и false в противном случае.

	// Сделано
	bool SetTextures(string, string);
	// Сделано
	bool IsCleaning() const;
};