/*
 *  Copyright (c) 2017, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 *   This file contains definitions for a simple CLI CoAP server and client.
 */

#ifndef CLI_UDP_EXAMPLE_HPP_
#define CLI_UDP_EXAMPLE_HPP_

#include "openthread-core-config.h"

#include <openthread/udp.h>

#include "utils/lookup_table.hpp"
#include "utils/parse_cmdline.hpp"

namespace ot {
namespace Cli {

class Interpreter;

/**
 * This class implements a CLI-based UDP example.
 *
 */
class UdpExample
{
public:
    typedef Utils::CmdLineParser::Arg Arg;

    /**
     * Constructor
     *
     * @param[in]  aInterpreter  The CLI interpreter.
     *
     */
    explicit UdpExample(Interpreter &aInterpreter);

    /**
     * This method interprets a list of CLI arguments.
     *
     * @param[in]  aArgsLength  The number of elements in @p aArgs.
     * @param[in]  aArgs        An array of command line arguments.
     *
     */
    otError Process(uint8_t aArgsLength, Arg aArgs[]);

private:
    struct Command
    {
        const char *mName;
        otError (UdpExample::*mHandler)(uint8_t aArgsLength, Arg aArgs[]);
    };

    enum PayloadType
    {
        kTypeText      = 0,
        kTypeAutoSize  = 1,
        kTypeHexString = 2,
    };

    otError ProcessHelp(uint8_t aArgsLength, Arg aArgs[]);
    otError ProcessBind(uint8_t aArgsLength, Arg aArgs[]);
    otError ProcessClose(uint8_t aArgsLength, Arg aArgs[]);
    otError ProcessConnect(uint8_t aArgsLength, Arg aArgs[]);
    otError ProcessOpen(uint8_t aArgsLength, Arg aArgs[]);
    otError ProcessSend(uint8_t aArgsLength, Arg aArgs[]);
    otError ProcessLinkSecurity(uint8_t aArgsLength, Arg aArgs[]);
    otError WriteCharToBuffer(otMessage *aMessage, uint16_t aMessageSize);

    static void HandleUdpReceive(void *aContext, otMessage *aMessage, const otMessageInfo *aMessageInfo);
    void        HandleUdpReceive(otMessage *aMessage, const otMessageInfo *aMessageInfo);

    static constexpr Command sCommands[] = {
        {"bind", &UdpExample::ProcessBind},
        {"close", &UdpExample::ProcessClose},
        {"connect", &UdpExample::ProcessConnect},
        {"help", &UdpExample::ProcessHelp},
        {"linksecurity", &UdpExample::ProcessLinkSecurity},
        {"open", &UdpExample::ProcessOpen},
        {"send", &UdpExample::ProcessSend},
    };

    static_assert(Utils::LookupTable::IsSorted(sCommands), "Command Table is not sorted");

    Interpreter &mInterpreter;

    bool        mLinkSecurityEnabled;
    otUdpSocket mSocket;
};

} // namespace Cli
} // namespace ot

#endif // CLI_UDP_EXAMPLE_HPP_