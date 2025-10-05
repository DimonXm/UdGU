#include "VCRobotLib.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;

sf::RenderWindow* VCRobot::window = nullptr;

void VCRobot::SetRenderWindow(sf::RenderWindow* pWindow) {
	window = pWindow;
}

// Конструктор с инициализацией нужных нам полей
VCRobot::VCRobot(float x, float y, float rotationAngle): x(x), y(y), rotationAngle(rotationAngle) {
	if (rotationAngle < 0 || rotationAngle > 360) {
		cout << "Некорректное значения угла поворота!" << endl;
		return;
	}
}

VCRobot::~VCRobot() {}

// robot_clean_on.png robot_clean_off.png
bool VCRobot::SetTextures(string fileNameOnRobot, string fileNameOffRobot) {
	bool f1 = VCRobot::textureOn.loadFromFile(fileNameOnRobot);
	bool f2 = VCRobot::textureOff.loadFromFile(fileNameOffRobot);

	if (f1 == true && f2 == true)
		return true;
	return false;
}

// show - вывод робота на жкран или нет 
// cleaningMode - какой спрайт выводить, включенный или нет
void VCRobot::Draw(bool show) {
	if (show) {
		if (VCRobot::cleaningMode) {
			VCRobot::spriteOn.setTexture(VCRobot::textureOn);
			VCRobot::spriteOn.setOrigin(VCRobot::textureOn.getSize().x / 2, VCRobot::textureOn.getSize().y / 2); // Опорную точку ставим по центру спрайта
			VCRobot::spriteOn.setPosition(VCRobot::textureOn.getSize().x / 2, VCRobot::textureOn.getSize().y / 2); // Делаем так чтобы наш робот был полностью виден на экране
			window->draw(VCRobot::spriteOn);
		}
		else {
			VCRobot::spriteOff.setTexture(VCRobot::textureOff);
			VCRobot::spriteOff.setOrigin(VCRobot::textureOff.getSize().x / 2, VCRobot::textureOff.getSize().y / 2); // Опорную точку ставим по центру спрайта
			VCRobot::spriteOff.setPosition(VCRobot::textureOff.getSize().x / 2, VCRobot::textureOff.getSize().y / 2);
			window->draw(VCRobot::spriteOff);
		}
	}
	// show == false
	// в этом случае также определяем текстуры но при этом в спрайте меняем цвет на черный и скрываем робота с экрана
	else {
		if (VCRobot::cleaningMode) {
			VCRobot::spriteOn.setTexture(VCRobot::textureOn);
			VCRobot::spriteOn.setOrigin(VCRobot::textureOn.getSize().x / 2, VCRobot::textureOn.getSize().y / 2); // Опорную точку ставим по центру спрайта
			VCRobot::spriteOn.setPosition(VCRobot::textureOn.getSize().x / 2, VCRobot::textureOn.getSize().y / 2);
			VCRobot::spriteOn.setColor(sf::Color::Black);
			window->draw(VCRobot::spriteOn);
		}
		else {
			VCRobot::spriteOff.setTexture(VCRobot::textureOff);
			VCRobot::spriteOff.setOrigin(VCRobot::textureOff.getSize().x / 2, VCRobot::textureOff.getSize().y / 2); // Опорную точку ставим по центру спрайта
			VCRobot::spriteOff.setPosition(VCRobot::textureOff.getSize().x / 2, VCRobot::textureOff.getSize().y / 2); 
			VCRobot::spriteOff.setColor(sf::Color::Black);
			window->draw(VCRobot::spriteOff);
		}
	}
}

void VCRobot::Hide() {
	Draw(false);
}

void VCRobot::Show() {
	Draw(true);
}

void VCRobot::CleaningOn() {
	//Hide();
	VCRobot::cleaningMode = true;
	//Show();
}

void VCRobot::CleaningOff() {
	//Hide();
	VCRobot::cleaningMode = false;
	//Show();
}

bool VCRobot::IsCleaning() const{
	if (cleaningMode) {
		return true;
	}
	return false;
}

void VCRobot::Rotate(float angle) {
	if (angle >= 0 && angle <= 360) {
		VCRobot::rotationAngle = angle;
		VCRobot::spriteOn.setRotation(VCRobot::rotationAngle);
		VCRobot::spriteOff.setRotation(VCRobot::rotationAngle);
		return;
	}
	return;
}

void VCRobot::TurnLeft(float angle) {
	if (angle >= 0 && angle <= 360) {
		VCRobot::rotationAngle = VCRobot::rotationAngle - angle;
		VCRobot::spriteOn.setRotation(VCRobot::rotationAngle);
		VCRobot::spriteOff.setRotation(VCRobot::rotationAngle);
		return;
	}
	return;
}

void VCRobot::TurnRight(float angle) {
	if (angle >= 0 && angle <= 360) {
		VCRobot::rotationAngle = VCRobot::rotationAngle + angle;
		VCRobot::spriteOn.setRotation(VCRobot::rotationAngle);
		VCRobot::spriteOff.setRotation(VCRobot::rotationAngle);
		return;
	}
	return;
}

// Реализация геттеров
sf::Vector2f VCRobot::GetPosition() const{
	return sf::Vector2f(VCRobot::x, VCRobot::y);
}

float VCRobot::GetRotation() const{
	return VCRobot::rotationAngle;
}

float VCRobot::GetStepSize() const{
	return VCRobot::stepSize;
}