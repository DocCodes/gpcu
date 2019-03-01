/**
*  @file      color.cpp
*  @brief     Implementation for the color class.
*
*  @author    Evan Elias Young
*  @date      2019-02-26
*  @date      2019-03-01
*  @copyright Copyright 2019 Evan Elias Young. All rights reserved.
*/

#ifndef GPCU_COLOR_H_
#define GPCU_COLOR_H_

#include "stdafx.h"
#include "color.h"

namespace gpcu
{
/**
* @brief Represents an RGB color
* @since 2.0.9-29 (0x020009001D)
*/
class Color
{
private:
  /* @brief The red value of the color */
  int red;
  /* @brief The green value of the color */
  int green;
  /* @brief The blue value of the color */
  int blue;
  /* @brief The luminance value of the color */
  int luminance;
  /* @brief The alpha value of the color */
  int alpha;
  /* @brief The hue value of the color */
  int hue;
  /* @brief The saturation value of the color */
  int saturation;
  /* @brief The lightness value of the color */
  int lightness;
  /* @brief The value of the color */
  int value;
  /* @brief The hex value of the color */
  std::string hex;
  void recalcHex();
  void recalcRGB();
  void recalcHSVL();
  void recalcLuminance();

public:
  Color(const int &, const int &, const int &);
  explicit Color(const std::string &);
  int getRed();
  void setRed(const int &);
  int getGreen();
  void setGreen(const int &);
  int getBlue();
  void setBlue(const int &);
  int getLuminance();
  int getAlpha();
  void setAlpha(const int &);
  int getHue();
  void setHue(const int &);
  int getSaturation();
  void setSaturation(const int &);
  int getLightness();
  void setLightness(const int &);
  int getValue();
  void setValue(const int &);
  std::string getHex();
  void setHex(std::string);
};

/**
* @brief Represents an RGB color declared declared by such.
* @since 2.0.9-29 (0x020009001D)
* @param r The red value.
* @param g The green value.
* @param b The blue value.
*/
Color::Color(const int &r, const int &g, const int &b)
{
  red = r;
  green = g;
  blue = b;
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief Represents an RGB color declared by hex.
* @since 2.0.9-29 (0x020009001D)
* @param h The hex value.
*/
Color::Color(const std::string &h)
{
  setHex(h);
}

/**
* @brief Recalculates the hex value for the color object.
* @since 2.0.9-29 (0x020009001D)
*/
void Color::recalcHex()
{
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(2) << std::hex << red << green << blue;
  hex = ss.str();
}

/**
* @brief Recalculates the RGB values for the color object.
* @since 2.0.9-29 (0x020009001D)
*/
void Color::recalcRGB()
{
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
* @brief Recalculates the HSVL values for the color object.
* @since 2.0.9-29 (0x020009001D)
*/
void Color::recalcHSVL()
{
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
  if (d < 0.00001)
  {
    saturation = 0;
    hue = 0;
    return;
  }
  if (max > 0.0)
  {
    saturation = ::round(d / max) * 100;
  }
  else
  {
    saturation = 0;
    hue = 0;
    return;
  }
  hue = r >= max
            ? ::round((g - b) / d * 60)
            : g >= max
                  ? ::round((2 + (b - r) / d) * 60)
                  : ::round((4 + (r - g) / d) * 60);

  if (hue < 0)
  {
    hue += 360;
  }
}

/**
* @brief Recalculates the luminance value for the color object.
* @since 2.0.9-29 (0x020009001D)
*/
void Color::recalcLuminance()
{
  luminance = ::round((red * 0.2126) + (green * 0.7152) + (blue * 0.0722));
}

/**
* @brief  Gets the red value.
* @since  2.0.9-29 (0x020009001D)
* @return The red value.
*/
int Color::getRed()
{
  return red;
}

/**
* @brief Sets the red value.
* @since 2.0.9-29 (0x020009001D)
* @param newRed The new red value.
*/
void Color::setRed(const int &newRed)
{
  if (newRed < 0 || newRed > 255)
  {
    throw std::out_of_range("newRed must be 0-255");
  }
  red = newRed;

  recalcRGB();
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief  Gets the green value.
* @since  2.0.9-29 (0x020009001D)
* @return The green value.
*/
int Color::getGreen()
{
  return green;
}

/**
* @brief Sets the green value.
* @since 2.0.9-29 (0x020009001D)
* @param newGreen The new green value.
*/
void Color::setGreen(const int &newGreen)
{
  if (newGreen < 0 || newGreen > 255)
  {
    throw std::out_of_range("newGreen must be 0-255");
  }
  green = newGreen;

  recalcRGB();
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief  Gets the blue value.
* @since  2.0.9-29 (0x020009001D)
* @return The blue value.
*/
int Color::getBlue()
{
  return blue;
}

/**
* @brief Sets the blue value.
* @since 2.0.9-29 (0x020009001D)
* @param newBlue The new blue value.
*/
void Color::setBlue(const int &newBlue)
{
  if (newBlue < 0 || newBlue > 255)
  {
    throw std::out_of_range("newBlue must be 0-255");
  }
  blue = newBlue;

  recalcRGB();
  recalcHex();
  recalcHSVL();
  recalcLuminance();
}

/**
* @brief  Gets the luminance value.
* @since  2.0.9-29 (0x020009001D)
* @return The luminance value.
*/
int Color::getLuminance()
{
  return luminance;
}

/**
* @brief  Gets the alpha value.
* @since  2.0.9-29 (0x020009001D)
* @return The alpha value.
*/
int Color::getAlpha()
{
  return alpha;
}

/**
* @brief Sets the alpha value.
* @since 2.0.9-29 (0x020009001D)
* @param newAlpha The new alpha value.
*/
void Color::setAlpha(const int &newAlpha)
{
  if (newAlpha < 0 || newAlpha > 255)
  {
    throw std::out_of_range("newAlpha must be 0-255");
  }
  alpha = newAlpha;
}

/**
* @brief  Gets the hue value.
* @since  2.0.9-29 (0x020009001D)
* @return The hue value.
*/
int Color::getHue()
{
  return hue;
}

/**
* @brief Sets the hue value.
* @since 2.0.9-29 (0x020009001D)
* @param newHue The new hue value.
*/
void Color::setHue(const int &newHue)
{
  if (newHue < 0 || newHue > 360)
  {
    throw std::out_of_range("newHue must be 0-360");
  }
  hue = newHue;

  recalcRGB();
  recalcHex();
  recalcLuminance();
}

/**
* @brief  Gets the saturation value.
* @since  2.0.9-29 (0x020009001D)
* @return The saturation value.
*/
int Color::getSaturation()
{
  return saturation;
}

/**
* @brief Sets the saturation value.
* @since 2.0.9-29 (0x020009001D)
* @param newSaturation The new saturation value.
*/
void Color::setSaturation(const int &newSaturation)
{
  if (newSaturation < 0 || newSaturation > 100)
  {
    throw std::out_of_range("newSaturation must be 0-100");
  }
  saturation = newSaturation;

  recalcRGB();
  recalcHex();
  recalcLuminance();
}

/**
* @brief  Gets the lightness value.
* @since  2.0.9-29 (0x020009001D)
* @return The lightness value.
*/
int Color::getLightness()
{
  return lightness;
}

/**
* @brief Sets the lightness value.
* @since 2.0.9-29 (0x020009001D)
* @param newLightness The new lightness value.
*/
void Color::setLightness(const int &newLightness)
{
  if (newLightness < 0 || newLightness > 100)
  {
    throw std::out_of_range("newLightness must be 0-100");
  }
  lightness = newLightness;

  recalcRGB();
  recalcHex();
  recalcHSVL();
}

/**
* @brief  Gets the value.
* @since  2.0.9-29 (0x020009001D)
* @return The value.
*/
int Color::getValue()
{
  return value;
}

/**
* @brief Sets the value.
* @since 2.0.9-29 (0x020009001D)
* @param newValue The new value.
*/
void Color::setValue(const int &newValue)
{
  if (newValue < 0 || newValue > 100)
  {
    throw std::out_of_range("newValue must be 0-100");
  }
  value = newValue;

  recalcRGB();
  recalcHex();
  recalcLuminance();
}

/**
* @brief  Gets the luminance value.
* @since  2.0.9-29 (0x020009001D)
* @return The hex value.
*/
std::string Color::getHex()
{
  return hex;
}

/**
* @brief Sets the blue value.
* @since 2.0.9-29 (0x020009001D)
* @param newHex The new hex value.
*/
void Color::setHex(std::string newHex)
{
  if (!std::regex_match(newHex, std::regex("^#?([[:xdigit:]]{3,4}|[[:xdigit:]]{6}|[[:xdigit:]]{8})$")))
  {
    throw std::invalid_argument("invalid value for hex variable");
  }
  newHex = std::regex_replace(newHex, std::regex("#"), "");
  if (newHex.length() <= 4)
  {
    newHex.insert(0, 1, newHex[0]);
    newHex.insert(2, 1, newHex[2]);
    newHex.insert(4, 1, newHex[4]);
    if (newHex.length() == 7)
    {
      newHex.insert(6, 1, newHex[6]);
    }
  }

  hex = newHex;

  recalcRGB();
  recalcHSVL();
  recalcLuminance();
}
} // namespace gpcu

#endif // GPCU_COLOR_H_