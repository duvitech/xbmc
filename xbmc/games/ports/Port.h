/*
 *      Copyright (C) 2017 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include <memory>

namespace PERIPHERALS
{
  class CPeripheral;
}

namespace KODI
{
namespace JOYSTICK
{
  class IInputHandler;
}

namespace GAME
{
  class CGameClient;

  class CPort
  {
  public:
    CPort(JOYSTICK::IInputHandler* inputHandler, CGameClient& gameClient);
    ~CPort();

    void RegisterDevice(PERIPHERALS::CPeripheral *device);
    void UnregisterDevice(PERIPHERALS::CPeripheral *device);

  private:
    JOYSTICK::IInputHandler* const m_inputHandler;
    std::unique_ptr<JOYSTICK::IInputHandler> m_controller;
    std::unique_ptr<JOYSTICK::IInputHandler> m_inputSink;
  };
}
}
