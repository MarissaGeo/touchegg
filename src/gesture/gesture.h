/**
 * Copyright 2011 - 2020 José Expósito <jose.exposito89@gmail.com>
 *
 * This file is part of Touchégg.
 *
 * Touchégg is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License  as  published by  the  Free Software
 * Foundation,  either version 3 of the License,  or (at your option)  any later
 * version.
 *
 * Touchégg is distributed in the hope that it will be useful,  but  WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE.  See the  GNU General Public License  for more details.
 *
 * You should have received a copy of the  GNU General Public License along with
 * Touchégg. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef GESTURE_GESTURE_H_
#define GESTURE_GESTURE_H_

#include "gesture/gesture-direction.h"
#include "gesture/gesture-type.h"

/**
 * Gestures implementations change depending on the driver/backend. This is the
 * basic interface of a gesture.
 */
class Gesture {
 public:
  Gesture() = default;

  Gesture(GestureType type, GestureDirection direction, int percentage,
          int fingers, double deltaX, double deltaY, double angleDelta,
          double radiusDelta, uint64_t elapsedTime)
      : gestureType(type),
        gestureDirection(direction),
        gesturePercentage(percentage),
        gestureFingers(fingers),
        gestureDeltaX(deltaX),
        gestureDeltaY(deltaY),
        gestureAngleDelta(angleDelta),
        gestureRadiusDelta(radiusDelta),
        gestureElapsedTime(elapsedTime) {}

  virtual ~Gesture() = default;

  /**
   * @returns The gesture type.
   * @see GestureType
   */
  virtual GestureType type() const { return this->gestureType; }

  /**
   * @returns The gesture direction.
   * @see GestureDirection
   */
  virtual GestureDirection direction() const { return this->gestureDirection; }

  /**
   * Percentage of the gesture performed, used for animations.
   * @return Value between 0 and 100.
   */
  virtual int percentage() const { return this->gesturePercentage; }

  /**
   * @returns The number of fingers used to perform the gesture.
   */
  virtual int fingers() const { return this->gestureFingers; }

  /**
   * @returns Gesture change in the X since its last update.
   */
  virtual double deltaX() const { return this->gestureDeltaX; }

  /**
   * @returns Gesture change in the Y since its last update.
   */
  virtual double deltaY() const { return this->gestureDeltaY; }

  /**
   * @returns If the gesture type is GestureType::PINCH, returns the angle
   * covered by a gesture since its last update, in degrees, clockwise.
   * For example: If the fingers are on the 12 and 6 location of a clock face
   * plate and they move to the 1 resp. 7 location in a single event then the
   * angle delta is 30 degrees.
   */
  virtual double angleDelta() const { return this->gestureAngleDelta; }

  /**
   * @returns If the gesture type is GestureType::PINCH, return the change in
   * the radius of the gesture since last update. Otherwise return 0.
   */
  virtual double radiusDelta() const { return this->gestureRadiusDelta; }

  /**
   * Elapsed time since the beginning of the gesture.
   * @returns The elapsed time in milliseconds.
   */
  virtual uint64_t elapsedTime() const { return this->gestureElapsedTime; }

 protected:
  GestureType gestureType = GestureType::NOT_SUPPORTED;
  GestureDirection gestureDirection = GestureDirection::UNKNOWN;
  int gesturePercentage = -1;
  int gestureFingers = -1;
  double gestureDeltaX = -1;
  double gestureDeltaY = -1;
  double gestureAngleDelta = -1;
  double gestureRadiusDelta = -1;
  uint64_t gestureElapsedTime = -1;
};

#endif  // GESTURE_GESTURE_H_
