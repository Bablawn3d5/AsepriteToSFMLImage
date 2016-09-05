// Aseprite Convert to SFML Library
// Copyright (c) 2016 Bablawn3d5 - <stephen.ma@bablawn.com>
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.
#include "AsepriteRgbaConvert/loader.h"
#include "Aseprite/SFML/convert.h"
#include <SFML/Graphics.hpp>

int main(int argc, char* const argv[]) {
  aseprite::Sprite s1 = aseprite::load_sprite_from_file("Sprite-0001.ase");
  aseprite::Sprite s2 = aseprite::load_sprite_from_file("Sprite-0002.ase");

  assert(s1.frames.size() == 9);
  assert(s2.frames.size() == 3);

  sf::Image image = aseprite::convertToSFML(s1);
  sf::Image image2 = aseprite::convertToSFML(s2);
  sf::Texture texture;
  texture.loadFromImage(image);
  sf::Texture texture2;
  texture2.loadFromImage(image2);
  sf::Sprite sprite(texture);
  sprite.scale(4, 4);
  sf::Sprite sprite2(texture2);
  sprite2.scale(4, 4);
  sprite2.move(360.f, 0.f);
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
  while ( window.isOpen() ) {
    sf::Event event;
    while ( window.pollEvent(event) ) {
      if ( event.type == sf::Event::Closed )
        window.close();
    }
    window.clear(sf::Color(50,120,200));
    window.draw(sprite);
    window.draw(sprite2);
    window.display();
  }
  return 0;
}
