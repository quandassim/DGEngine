#pragma once

#include "Action.h"
#include "Button.h"
#include "Game.h"
#include <string>

class ActButtonClick : public Action
{
private:
	std::string id;
	bool playSound;

public:
	ActButtonClick(const std::string& id_, bool playSound_)
		: id(id_), playSound(playSound_) {}

	virtual bool execute(Game& game)
	{
		auto button = game.Resources().getResource<Button>(id);
		if (button != nullptr)
		{
			button->click(game, playSound);
		}
		return true;
	}
};

class ActButtonEnable : public Action
{
private:
	std::string id;
	bool enable;

public:
	ActButtonEnable(const std::string& id_, bool enable_)
		: id(id_), enable(enable_) {}

	virtual bool execute(Game& game) noexcept
	{
		auto button = game.Resources().getResource<Button>(id);
		if (button != nullptr)
		{
			button->enable(enable);
		}
		return true;
	}
};

class ActButtonSetColor : public Action
{
private:
	std::string id;
	sf::Color color;

public:
	ActButtonSetColor(const std::string& id_, const sf::Color& color_)
		: id(id_), color(color_) {}

	virtual bool execute(Game& game)
	{
		auto button = game.Resources().getResource<Button>(id);
		if (button != nullptr)
		{
			button->setColor(color);
		}
		return true;
	}
};
