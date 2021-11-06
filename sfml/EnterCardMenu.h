#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "TextBox.h"
#include "TextArea.h"
#include "Assets.h"
#include "Controller.h"
#include "Menu.h"

using namespace sf;

class EnterCardMenu : public Menu {

private:

	RenderWindow& window;

	void init() 
	{
		btnOkCard = Button("Start", { 200,50 }, 20, Color::White, Color::Black, Assets::Instance().textureBox);
		btnOkCard.setPosition({ 400, 350 });
		btnOkCard.setFont(Assets::Instance().arial);
		btnOkCard.setVisible(false);

		areaCard = TextArea("Input card number", { 300,50 }, 20, Color::White, Color::Black, Assets::Instance().textureLabel);
		areaCard.setFont(Assets::Instance().arial);
		areaCard.setPosition({ 350,200 });
		areaCard.setVisible(false);

		boxCardNum = Textbox(25, Color::Black, true, Assets::Instance().textureBox);
		boxCardNum.setFont(Assets::Instance().arial);
		boxCardNum.setPosition({ 450,300 });
		boxCardNum.setVisible(false);
		boxCardNum.clear();
		boxCardNum.setSecret(false);
		boxCardNum.setlimit(true, 5);
	}

public:

	Button btnOkCard;
	TextArea areaCard;
	Textbox boxCardNum;

	EnterCardMenu(RenderWindow& par) : window(par) { init(); }

	~EnterCardMenu() {}

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		target.draw(btnOkCard);
		target.draw(areaCard);
		target.draw(boxCardNum);
	}

private:

	void setVisibleAllMembers(bool isVisible) override
	{
		btnOkCard.setVisible(isVisible);
		areaCard.setVisible(isVisible);
		boxCardNum.setVisible(isVisible);
	}
};
