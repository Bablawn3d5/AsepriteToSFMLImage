// Aseprite Convert to SFML Library
// Copyright (c) 2016 Bablawn3d5 - <stephen.ma@bablawn.com>
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#include "convert.h"

#include <vector>
#include <cassert>
#include <cmath>

using aseprite::Sprite;
using aseprite::PIXEL_RGBA;
using aseprite::WORD;

namespace aseprite {
void merge_pixels(std::vector<PIXEL_RGBA>& src, size_t w, size_t h,
                  const std::vector<PIXEL_RGBA>& dst, size_t destw, size_t desth,
                  size_t offset_x, size_t offset_y) {
  assert(w*h == src.size());
  assert(destw*desth == dst.size());
  for ( size_t y = 0; y < desth; ++y ) {
    for ( size_t x = 0; x < destw; ++x ) {
      src[(x + offset_x) + ((y + offset_y) * w)] = dst[x + (y * destw)];
    }
  }
}

std::vector<sf::IntRect> calcFrameOffsets(aseprite::Sprite s) {
  std::vector<sf::IntRect> offsets;
  auto frame_count = s.frames.size();
  size_t nearest_fit = static_cast<size_t>(ceil(sqrt(static_cast<float>(frame_count))));
  size_t x_off = 0;
  size_t y_off = 0;
  for ( size_t i = 0; i < s.frames.size(); ++i ) {
    offsets.push_back(sf::IntRect(x_off*s.w, y_off*s.h, s.w, s.h));
    x_off++;
    if ( x_off % nearest_fit == 0 ) {
      x_off = 0;
      y_off++;
    }
  }
  assert(offsets.size() == s.frames.size());
  return offsets;
}

sf::Image convertToSFML(aseprite::Sprite s) {
  sf::Image image;
  auto frame_count = s.frames.size();
  size_t nearest_fit = static_cast<size_t>(ceil(sqrt(static_cast<float>(frame_count))));

  std::vector<PIXEL_RGBA> pixels;
  size_t width = nearest_fit * s.w;
  size_t height = nearest_fit * s.h;
  pixels.resize(width * height);
  assert(s.frames.size() * s.w * s.h <= pixels.size());

  auto offsets = calcFrameOffsets(s);
  size_t frame_index = 0;
  for ( auto& f : s.frames ) {
    // Assuming all frames are of the same w,h. So we use sprite's w/h.
    merge_pixels(pixels, width, height,
                f.pixels, s.w, s.h,
                offsets[frame_index].left, offsets[frame_index].top);
    ++frame_index;
  }
  image.create(width, height, reinterpret_cast<sf::Uint8*>(pixels.data()));
  return image;
}
} // namespace aseprite