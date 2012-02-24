/* Copyright (c) 2012 Stanford University
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR(S) DISCLAIM ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL AUTHORS BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef LOGCABIN_RPC_SERVICE_H
#define LOGCABIN_RPC_SERVICE_H

namespace LogCabin {
namespace RPC {

// forward declaration
class ServerRPC;

/**
 * Base class for RPC services.
 * Each service handles a related set of RPCs from clients.
 */
class Service {
  public:
    /**
     * Constructor.
     */
    Service() {}

    /**
     * Destructor.
     */
    virtual ~Service() {}

    /**
     * This method is overridden by a subclass and invoked when a new RPC
     * arrives. It should call ServerRPC::sendReply() if and when it wants to
     * respond to the RPC request.
     */
    virtual void handleRPC(ServerRPC serverRPC) = 0;

    // Service is non-copyable.
    Service(const Service&) = delete;
    Service& operator=(const Service&) = delete;
}; // class Service

} // namespace LogCabin::RPC
} // namespace LogCabin

#endif /* LOGCABIN_RPC_SERVICE_H */
