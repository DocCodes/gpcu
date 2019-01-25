//  color.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-25.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_COLOR_HPP_  // include guard
#define GPCU_COLOR_HPP_

#include <math.h>

#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <regex>

namespace gpcu {
  class Color {
  private:
    int red;
    int green;
    int blue;
    int luminance;
    int alpha;
    int hue;
    int saturation;
    int lightness;
    int value;
    std::string hex;
    void recalcHex();
    void recalcRGB();
    void recalcHSVL();
    void recalcLuminance();
  public:
    Color (int, int, int);
    Color (std::string);
    int getRed();
    void setRed(int);
    int getGreen();
    void setGreen(int);
    int getBlue();
    void setBlue(int);
    int getLuminance();
    int getAlpha();
    void setAlpha(int);
    int getHue();
    void setHue(int);
    int getSaturation();
    void setSaturation(int);
    int getLightness();
    void setLightness(int);
    int getValue();
    void setValue(int);
    std::string getHex();
    void setHex(std::string);
  };

  Color::Color(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
    recalcHex();
    recalcHSVL();
    recalcLuminance();
  }
  Color::Color(std::string h) {
    setHex(h);
  }

  void Color::recalcHex() {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << std::hex << red << green << blue;
    hex = ss.str();
  }
  void Color::recalcRGB() {
    std::stringstream ss;
    ss << hex.substr(0, 2);
    ss >> std::hex >> red;
    std::stringstream().swap(ss);
    ss << hex.substr(2, 2);
    ss >> std::hex >> green;
    std::stringstream().swap(ss);
    ss << hex.substr(4, 2);
    ss >> std::hex >> blue;
  }
  void Color::recalcHSVL() {
    double min;
    double max;
    double d;
    double r;
    double g;
    double b;

    r = red;
    g = green;
    b = blue;
    r /= 255;
    g /= 255;
    b /= 255;

    min = r < g ? r : g;
    min = min < b ? min : b;
    max = r > g ? r : g;
    max = max > b ? max : b;

    value = std::round(max * 100);
    lightness = std::round((max + min) * 50);
    d = max - min;
    if (d < 0.00001) {
      saturation = 0;
      hue = 0;
      return;
    }
    if (max > 0.0) {
      saturation = std::round(d / max) * 100;
    } else {
      saturation = 0;
      hue = 0;
      return;
    }
    hue = r >= max
    ? std::round((g - b) / d * 60)
    : g >= max
    ? std::round((2 + (b - r) / d) * 60)
    : std::round((4 + (r - g) / d) * 60);

    if (hue < 0) {
      hue += 360;
    }
  }
  void Color::recalcLuminance() {
    luminance = std::round((red * 0.2126) + (green * 0.7152) + (blue * 0.0722));
  }

  int Color::getRed() {
    return red;
  }
  void Color::setRed(int newRed) {
    if (newRed < 0 || newRed > 255) {
      throw std::out_of_range("newRed must be 0-255");
    }
    red = newRed;

    recalcRGB();
    recalcHex();
    recalcHSVL();
    recalcLuminance();
  }
  int Color::getGreen() {
    return green;
  }
  void Color::setGreen(int newGreen) {
    if (newGreen < 0 || newGreen > 255) {
      throw std::out_of_range("newGreen must be 0-255");
    }
    green = newGreen;

    recalcRGB();
    recalcHex();
    recalcHSVL();
    recalcLuminance();
  }
  int Color::getBlue() {
    return blue;
  }
  void Color::setBlue(int newBlue) {
    if (newBlue < 0 || newBlue > 255) {
      throw std::out_of_range("newBlue must be 0-255");
    }
    blue = newBlue;

    recalcRGB();
    recalcHex();
    recalcHSVL();
    recalcLuminance();
  }
  int Color::getLuminance() {
    return luminance;
  }
  int Color::getAlpha() {
    return alpha;
  }
  void Color::setAlpha(int newAlpha) {
    if (newAlpha < 0 || newAlpha > 255) {
      throw std::out_of_range("newAlpha must be 0-255");
    }
    alpha = newAlpha;
  }
  int Color::getHue() {
    return hue;
  }
  void Color::setHue(int newHue) {
    if (newHue < 0 || newHue > 360) {
      throw std::out_of_range("newHue must be 0-360");
    }
    hue = newHue;

    recalcRGB();
    recalcHex();
    recalcLuminance();
  }
  int Color::getSaturation() {
    return saturation;
  }
  void Color::setSaturation(int newSaturation) {
    if (newSaturation < 0 || newSaturation > 100) {
      throw std::out_of_range("newSaturation must be 0-100");
    }
    saturation = newSaturation;

    recalcRGB();
    recalcHex();
    recalcLuminance();
  }
  int Color::getLightness() {
    return lightness;
  }
  void Color::setLightness(int newLightness) {
    if (newLightness < 0 || newLightness > 100) {
      throw std::out_of_range("newLightness must be 0-100");
    }
    lightness = newLightness;

    recalcRGB();
    recalcHex();
    recalcHSVL();
  }
  int Color::getValue() {
    return value;
  }
  void Color::setValue(int newValue) {
    if (newValue < 0 || newValue > 100) {
      throw std::out_of_range("newValue must be 0-100");
    }
    value = newValue;

    recalcRGB();
    recalcHex();
    recalcLuminance();
  }
  std::string Color::getHex() {
    return hex;
  }
  void Color::setHex(std::string newHex) {
    if (!std::regex_match(newHex, std::regex("^#?([[:xdigit:]]{3,4}|[[:xdigit:]]{6}|[[:xdigit:]]{8})$"))) {
      throw std::invalid_argument("invalid value for hex variable");
    }
    newHex = std::regex_replace(newHex, std::regex("#"), "");
    if (newHex.length() <= 4) {
      newHex.insert(0, 1, newHex[0]);
      newHex.insert(2, 1, newHex[2]);
      newHex.insert(4, 1, newHex[4]);
      if (newHex.length() == 7) {
        newHex.insert(6, 1, newHex[6]);
      }
    }

    hex = newHex;

    recalcRGB();
    recalcHSVL();
    recalcLuminance();
  }
}  // namespace gpcu

#endif  // GPCU_COLOR_HPP_
