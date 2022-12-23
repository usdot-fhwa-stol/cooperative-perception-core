/*
 * Copyright 2022 Leidos
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef ANGLE_HPP
#define ANGLE_HPP

#include <complex>
#include <math.h>
#include <units.h>

/**
 * @brief Angle type for representing and manipulating angles
 */
namespace cooperative_perception
{
class Angle
{
private:
  std::complex<double> value_{};

public:
  Angle(units::angle::radian_t angle_val) noexcept : value_{ units::math::cos(angle_val), units::math::sin(angle_val) }
  {
  }

  auto set_angle(units::angle::radian_t angle_val) noexcept -> void
  {
    value_ = std::complex<double>{ units::math::cos(angle_val), units::math::sin(angle_val) };
  }

  auto get_angle() const noexcept -> units::angle::radian_t
  {
    return units::angle::radian_t{ std::arg(value_) };
  }
};

}  // namespace cooperative_perception
#endif  // ANGLE_HPP