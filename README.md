# AsepriteToSFMLImage
Convert Aseprite binaries into SFML Images.

Please checkout http://www.aseprite.org/, or https://github.com/aseprite/aseprite for more infromation about Aseprite!

---

### Example usage:
```
  #include "Aseprite/SFML/convert.h"

  aseprite::Sprite s1 = aseprite::load_sprite_from_file("Sprite-0001.ase");
  sf::Image image = aseprite::convertToSFML(s1);
```


### Copying:

The AsepriteToSFMLImage is licensed and distributed under MIT license.

Copyright 2016 Bablawn3d5, all rights reserved.

See LICENSE.txt for full details.
