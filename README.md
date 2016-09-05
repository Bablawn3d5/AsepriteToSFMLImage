# AsepriteToSFMLImage
Convert Aseprite binaries into SFML Images

---

Example usage:
```
  aseprite::Sprite s1 = aseprite::load_sprite_from_file("Sprite-0001.ase");
  assert(s1.frames.size() == 9);
  sf::Image image = aseprite::convertToSFML(s1);
```
