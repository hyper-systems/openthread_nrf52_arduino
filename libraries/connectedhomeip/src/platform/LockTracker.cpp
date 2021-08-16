/*
 *
 *    Copyright (c) 2021 Project CHIP Authors
 *
 *    Licensed under the Apache License, Version 2.0 (the "License");
 *    you may not use this file except in compliance with the License.
 *    You may obtain a copy of the License at
 *
 *        http://www.apache.org/licenses/LICENSE-2.0
 *
 *    Unless required by applicable law or agreed to in writing, software
 *    distributed under the License is distributed on an "AS IS" BASIS,
 *    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *    See the License for the specific language governing permissions and
 *    limitations under the License.
 */

#include <platform/LockTracker.h>

#if CHIP_STACK_LOCK_TRACKING_ENABLED

#include <platform/CHIPDeviceLayer.h>
#include <platform/PlatformManager.h>
#include <support/CodeUtils.h>
#include <support/logging/CHIPLogging.h>
namespace chip {
namespace Platform {
namespace Internal {

void AssertChipStackLockedByCurrentThread(const char * file, int line)
{
    if (!chip::DeviceLayer::PlatformMgr().IsChipStackLockedByCurrentThread())
    {
        ChipLogError(DeviceLayer, "Chip stack locking error at '%s:%d'. Code is unsafe/racy", file, line);
#if CHIP_STACK_LOCK_TRACKING_ERROR_FATAL
        chipDie();
#endif
    }
}

} // namespace Internal
} // namespace Platform
} // namespace chip

#endif