// Aseprite Convert to RGBA library
// Copyright (c) 2016 Bablawn3d5
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.
#include "AsepriteRgbaConvert/loader.h"
#include "Aseprite/SFML/convert.h"
#include <SFML/Graphics.hpp>

int main(int argc, char* const argv[]) {
  aseprite::Sprite s1 = aseprite::load_sprite_from_file("Sprite-0001.ase");
  sf::Image image = convert(s1);
  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Sprite sprite(texture);
  sprite.scale(4, 4);

  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  while ( true ) {
    window.clear(sf::Color(50,120,200));
    window.draw(sprite);
    window.display();
  }
  return 0;
}
