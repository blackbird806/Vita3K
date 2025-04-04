// Vita3K emulator project
// Copyright (C) 2025 Vita3K team
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

#pragma once

#include <bit>
#include <cstdint>
#include <type_traits>

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T align(const T &value, std::uint64_t align) {
    return static_cast<T>((value + (align - 1)) & ~(align - 1));
}

template <typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
constexpr T align_down(const T &value, std::uint64_t align) {
    return static_cast<T>(value & ~(align - 1));
}

template <class T>
constexpr T next_power_of_two(T num) {
    return std::bit_ceil(num);
}
