#include "Rectangle.h"
#include "Game.h"
#include "GameUtils.h"
#include "Utils/Utils.h"

void Rectangle::updateSize(const Game& game)
{
	if (game.StretchToFit() == true)
	{
		return;
	}
	auto pos = getPosition();
	auto size = getSize();
	GameUtils::setAnchorPosSize(anchor, pos, size, game.OldWindowSize(), game.WindowSize());
	setPosition(pos);
	setSize(size);
}

bool Rectangle::getProperty(const std::string& prop, Variable& var) const
{
	if (prop.size() <= 1)
	{
		return false;
	}
	auto props = Utils::splitStringIn2(prop, '.');
	return GameUtils::getUIObjProp(*this, str2int16(props.first.c_str()), props.second, var);
}
