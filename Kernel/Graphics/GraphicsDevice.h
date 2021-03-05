/*
 * Copyright (c) 2021, Liav A. <liavalb@hotmail.co.il>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/String.h>
#include <AK/Types.h>
#include <Kernel/Devices/BlockDevice.h>
#include <Kernel/Graphics/FramebufferDevice.h>
#include <Kernel/PhysicalAddress.h>

namespace Kernel {
class FramebufferDevice;
class GraphicsDevice : public RefCounted<GraphicsDevice> {
public:
    enum class Type {
        VGACompatible,
        Bochs,
        SVGA,
        Raw
    };
    virtual ~GraphicsDevice() = default;
    virtual void initialize_framebuffer_devices() = 0;
    virtual Type type() const = 0;

protected:
    GraphicsDevice() = default;
};

}
