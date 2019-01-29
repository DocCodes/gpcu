//  color.hpp
//  gpcu
//
//  Created by Evan Elias Young on 2019-01-25.
//  Copyright 2019 Evan Elias Young. All rights reserved.

#ifndef GPCU_COLOR_HPP_  // include guard
#define GPCU_COLOR_HPP_

#include <math.h>

#include <iomanip>
#include <iostream>
#include <exception>
#include <string>
#include <sstream>
#include <regex>

namespace gpcu {
  /**
   * Represents an RGB color
   */
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

  /**
   * Represents an RGB color declared declared by such.
   * @param [int] r The red value.
   * @param [int] g The green value.
   * @param [int] b The blue value.
   */
  Color::Color(int r, int g, int b) {
    red = r;
    green = g;
    blue = b;
    recalcHex();
    recalcHSVL();
    recalcLuminance();
  }

  /**
   * Represents an RGB color declared by hex.
   * @param [std::string] h The hex value.
   */
  Color::Color(std::string h) {
    setHex(h);
  }

  /**
   * Recalculates the hex value for the color object.
   */
  void Color::recalcHex() {
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << std::hex << red << green << blue;
    hex = ss.str();
  }

  /**
   * Recalculates the RGB values for the color object.
   */
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

  /**
   * Recalculates the HSVL values for the color object.
   */
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

    value = ::round(max * 100);
    lightness = ::round((max + min) * 50);
    d = max - min;
    if (d < 0.00001) {
      saturation = 0;
      hue = 0;
      return;
    }
    if (max > 0.0) {
      saturation = ::round(d / max) * 100;
    } else {
      saturation = 0;
      hue = 0;
      return;
    }
    hue = r >= max
    ? ::round((g - b) / d * 60)
    : g >= max
    ? ::round((2 + (b - r) / d) * 60)
    : ::round((4 + (r - g) / d) * 60);

    if (hue < 0) {
      hue += 360;
    }
  }

  /**
   * Recalculates the luminance value for the color object.
   */
  void Color::recalcLuminance() {
    luminance = ::round((red * 0.2126) + (green * 0.7152) + (blue * 0.0722));
  }

  /**
   * Gets the red value.
   * @return [int] The red value.
   */
  int Color::getRed() {
    return red;
  }

  /**
   * Sets the red value.
   * @param [int] newRed The new red value.
   */
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

  /**
   * Gets the green value.
   * @return [int] The green value.
   */
  int Color::getGreen() {
    return green;
  }

  /**
   * Sets the green value.
   * @param [int] The new green value.
   */
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

  /**
   * Gets the blue value.
   * @return [int] The blue value.
   */
  int Color::getBlue() {
    return blue;
  }

  /**
   * Sets the blue value.
   * @param [int] The new blue value.
   */
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

  /**
   * Gets the luminance value.
   * @return [int] The luminance value.
   */
  int Color::getLuminance() {
    return luminance;
  }

  /**
   * Gets the alpha value.
   * @return [int] The alpha value.
   */
  int Color::getAlpha() {
    return alpha;
  }

  /**
   * Sets the alpha value.
   * @param [int] The new alpha value.
   */
  void Color::setAlpha(int newAlpha) {
    if (newAlpha < 0 || newAlpha > 255) {
      throw std::out_of_range("newAlpha must be 0-255");
    }
    alpha = newAlpha;
  }
  int Color::getHue() {
    return hue;
  }

  /**
   * Sets the hue value.
   * @param [int] The new hue value.
   */
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

  /**
   * Sets the saturation value.
   * @param [int] The new saturation value.
   */
  void Color::setSaturation(int newSaturation) {
    if (newSaturation < 0 || newSaturation > 100) {
      throw std::out_of_range("newSaturation must be 0-100");
    }
    saturation = newSaturation;

    recalcRGB();
    recalcHex();
    recalcLuminance();
  }

  /**
   * Gets the lightness value.
   * @return [int] The lightness value.
   */
  int Color::getLightness() {
    return lightness;
  }

  /**
   * Sets the lightness value.
   * @param [int] The new lightness value.
   */
  void Color::setLightness(int newLightness) {
    if (newLightness < 0 || newLightness > 100) {
      throw std::out_of_range("newLightness must be 0-100");
    }
    lightness = newLightness;

    recalcRGB();
    recalcHex();
    recalcHSVL();
  }

  /**
   * Gets the value.
   * @return [int] The value.
   */
  int Color::getValue() {
    return value;
  }

  /**
   * Sets the value.
   * @param [int] The new value.
   */
  void Color::setValue(int newValue) {
    if (newValue < 0 || newValue > 100) {
      throw std::out_of_range("newValue must be 0-100");
    }
    value = newValue;

    recalcRGB();
    recalcHex();
    recalcLuminance();
  }

  /**
   * Gets the luminance value.
   * @return [std::string] The hex value.
   */
  std::string Color::getHex() {
    return hex;
  }

  /**
   * Sets the blue value.
   * @param [std::string] The new hex value.
   */
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
