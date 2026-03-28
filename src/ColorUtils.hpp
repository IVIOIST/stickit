#pragma once
#ifndef COLORUTILS_HPP
#define COLORUTILS_HPP

#include <string>
#include "PostIt.hpp"

std::string colorToAnsi(Color color);

Color stringToColor(const std::string& color);

std::string colorToString(Color color);
#endif