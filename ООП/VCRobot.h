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
	// �����������
	VCRobot(float x, float  y, float rotationAngle);
	// ����������
	virtual ~VCRobot();

	static void SetRenderWindow(sf::RenderWindow* window); // ����������� ����� ���������� � �����

	// �������
	void Draw(bool); // ������ ��� �������� ������ �� ������, � ����������� �� �������� ����������� ����������� ���������.
	// �������
	void Show(); // ���������� ������ �� ������.
	// �������
	void Hide(); // �������� ������ � ������.
	void MoveForward(); // ����������� �� 1 ��� ������ �� ����������� ���������� ������ (�������� ���� �������� ����� ������, ������� �� ���������� � ������ ����� (��. ����).
	void MoveBackward(); // ����������� �� 1 ��� ����� �� ����������� ���������� ������  (�������� ���� �������� ����� ������, ������� �� ���������� � ������ ����� (��. ����).
	void SetStepSize(float); // ����������� �� 1 ��� ����� �� ����������� ���������� ������  (�������� ���� �������� ����� ������, ������� �� ���������� � ������ ����� (��. ����).
	// �������
	float GetStepSize() const; // ���������� ������� �������� ���� ����������� ������.
	// �������
	void TurnLeft(float); // ������� ������ ������� ������� �� �������� ���-�� ��������, ������������ ��� ������� ����������.
	// �������
	void TurnRight(float); // ������� �o ������� ������� �� �������� ���-�� ��������, ������������ ��� ������� ����������.
	// �������
	void Rotate(float); // ������������ ������ � ��������� ����(���������� ��������).
	// �������
	void CleaningOn(); // ��������� ������ ��������
	// �������
	void CleaningOff(); // ���������� ������ ��������
	// �������
	sf::Vector2f GetPosition() const; // ��������� ������� ������� ������ � ���� ������� ������ sf::Vector2f.
	// �������
	float GetRotation() const; // ��������� �������� ���� �������� ������ (0-360 ����) � ���� ����� float.
	//bool IsCleanOn() const; // ��������� �������� ��������� ��������� �������� (true � �������, false � ��������).
	bool CanMoveForward() const; // ���������� true, ���� ����� ����� ������������� � ����� �� ����������� ��������, ��� ������ �� ������� ������, � false � ��������� ������.
	bool CanMoveBackward() const; // ���������� true, ���� ����� ����� ������������� � ����� ��� ������ �� ������� ������, � false � ��������� ������.

	// �������
	bool SetTextures(string, string);
	// �������
	bool IsCleaning() const;
};