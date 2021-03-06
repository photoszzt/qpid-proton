#
# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.
#

from __future__ import absolute_import

from cproton import PN_TIMEOUT, PN_INTR


class ProtonException(Exception):
    """
    The root of the proton exception hierarchy. All proton exception
    classes derive from this exception.
    """
    pass


class Timeout(ProtonException):
    """
    A timeout exception indicates that a blocking operation has timed
    out.
    """
    pass


class Interrupt(ProtonException):
    """
    An interrupt exception indicates that a blocking operation was interrupted.
    """
    pass


EXCEPTIONS = {
    PN_TIMEOUT: Timeout,
    PN_INTR: Interrupt
}


class MessageException(ProtonException):
    """
    The MessageException class is the root of the message exception
    hierarchy. All exceptions generated by the Message class derive from
    this exception.
    """
    pass


class DataException(ProtonException):
    """
    The DataException class is the root of the Data exception hierarchy.
    All exceptions raised by the Data class extend this exception.
    """
    pass


class TransportException(ProtonException):
    pass


class SSLException(TransportException):
    pass


class SSLUnavailable(SSLException):
    pass


class ConnectionException(ProtonException):
    pass


class SessionException(ProtonException):
    pass


class LinkException(ProtonException):
    pass
