#pragma once
#include <iostream> 
#include <SFML/Graphics.hpp>

class Button {
public:
	Button() {}
	Button(std::string t, sf::Vector2f size, int charSize, sf::Color bgColor, sf::Color textColor, sf::Texture& texture) {
		text.setString(t);
		text.setFillColor(textColor);
		text.setCharacterSize(charSize);
		button.setSize(size);
		button.setFillColor(bgColor);
		button.setTexture(&texture);
	}
	void setFont(sf::Font& font) {
		text.setFont(font);
	}
	void setBackColor(sf::Color ?olor) {
		button.setFillColor(?olor);
	}
	void setTextColor(sf::Color color) {
		text.setFillColor(color);
	}
	void setPosition(sf::Vector2f pos) {
		this->position = pos;
		button.setPosition(pos);

		float xPos = (pos.x + button.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
		float yPos = (pos.y + button.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);
		text.setPosition({ xPos, yPos });
	}
	void drawTo(sf::RenderWindow& window) {
		window.draw(button);
		window.draw(text);
	}
	void setVisible(bool b) {
		if (b) {
			setPosition(position);
		}
		else {
			button.setPosition({3000,3000});

			float xPos = (3000 + button.getGlobalBounds().width / 3) - (text.getGlobalBounds().width / 2);
			float yPos = (3000 + button.getGlobalBounds().height / 3) - (text.getGlobalBounds().height / 2);
			text.setPosition({ xPos, yPos });
		}
	}
	bool isMouseOver(sf::RenderWindow& window) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;

		float btnPosX = button.getPosition().x;
		float btnPosY = button.getPosition().y;

		float btnsPosWidth = button.getPosition().x + button.getLocalBounds().width;
		float btnyPosHeight = button.getPosition().y + button.getLocalBounds().height;
		if (mouseX < btnsPosWidth && mouseX > btnPosX && mouseY < btnyPosHeight && mouseY > btnPosY) {
			return true;
		}
		return false;
	}

private:
	sf::Vector2f position;
	sf::RectangleShape button;
	sf::Text text;
};
