#include "player.h"

Player::Player(const QString& fileName)
{
    imagePlayer = new QPixmap(fileName);
}
