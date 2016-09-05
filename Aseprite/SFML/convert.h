// Aseprite Convert to SFML Library
// Copyright (c) 2016 Bablawn3d5 - <stephen.ma@bablawn.com>
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#pragma once

#include "AsepriteRgbaConvert/doc-lite.h"
#include "SFML/Graphics.hpp"

namespace aseprite {

// Converts aseprite doc-lite Sprite to sf::Image
sf::Image convertToSFML(aseprite::Sprite s);

// Given aseprite doc-lite Sprite compute frame rects for final image.
std::vector<sf::IntRect> calcFrameOffsets(aseprite::Sprite s);

} // namespace aseprite