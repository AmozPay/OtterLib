%%%
title = "OtterNetwork's UDP Communication Protocol (OUDPCP)"
abbrev = "OtterNetwork"
updates = []
ipr= "trust200902"
area = "Internet"
workgroup = "OtterLib Team"
keyword = ["markdown", "xml", "mmark"]

[seriesInfo]
status = "informational"
name = "Internet-Draft"
value = "otternetwork-internet-draft"
stream = "IETF"

[[author]]
initials="C."
surname="Vidal"
fullname="C. (hollow) Vidal"
organization = "Epitech"
  [author.address]
  email = "corentin.vidal@epitech.eu"

# RFC Style documentation https://www.rfc-editor.org/rfc/rfc7322
# QUIC rfc https://www.rfc-editor.org/rfc/rfc9000
# TCP rfc  https://www.rfc-editor.org/rfc/rfc793

%%%

.# Abstract

This document describes the network protocol of the OtterNetwork module for the OtterLib game engine.
<!--
The OtterLib is an ECS engine as a static library, developped for the needs ot the R-Type Epitech project.
This library includes client-server networking, permitted by a specific protocol implemented with the OtterNetwork library.
This RFC describes the mentionned protocol.
-->

{mainmatter}

# Introduction

The objective of the OtterNetwork UDP Communication Protocol (ONUDPCP) is to be an easy to use, implement and exetend network protocol for game engines.
The protocol is UDP based and meant to send primarily unimportant messages. Important data can be sent reliably at the cost of efficiency.

This paper assumes basic knowledge of the User Datagram Protocol (UDP) [@RFC0768].

## Interfaces

The ONUDPCP interfaces on one side to the OtterCore engine and on the other side to the lower level protocol UDP.

The interfaces between the OtterCore and ONUDPCP and between UDP and ONUDPCP are both explained within this document. They consist of a set of calls like an operating system provides for manipulating files. There are calls to send data and close connections.

## Terminology

endpoint

  An endpoint is a combination of an Internet Protocol (IP) Address and a port allowing to uniquely identify a host on the network.

ONUDPCP message

  An ONUDPCP message is a single data serialized with boost binary archive. It can be anything as long as it's not larger than the size of an UDP datagram minus the size of the size of the ONUDPCP header.

ONUDPCP packet

  An ONUDPCP packet is an agregate of ONUDPCP messages preceded by the ONUDPCP header.

# Functional Specification

## Header Format
ONUDPCP packets are sent in UDP datagrams. The UDP header already carries several information fields, including the source and destination host endpoints.

ONUDPCP Header Format

~~~ ascii-art
 0                   1                   2                   3
 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Magic Number                         |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Sequence Number                      |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
|                          Client ID                            |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
| Message Count    |                     data                   |
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+...
~~~
Figure: ONUDPCP Header Format

Magic Number:  32 bits

  The magic number identifying the game protocol used.

Sequence Number:  32 bits

  The sequence number of the packet, used to keep track of lost packets and acknowledges.

Client ID:  32 bits

  Used to identify the client uniquely, allows for seamless reconnection with a different endpoint.

Message Count:

  Number of ONUDPCP messages in the packet.

## Establishing a connection

The connection is implicitly started on client first packet, when the server gets an ONUDPCP packet it first checks the magic number to ensure the right version is being used, then it checks a list of currently active connection based on the Client ID, if the Client ID is 0 or not in the list the server adds the client in the list by storing it's endpoint and gives it an ID which will be sent to the client in the next response.

## Reconnecting a lost connection

When a server receive a packet with a known ID but from a different endpoint, it must consider it as a reconnection. The stored endpoint must be updated to match the new connection.

# Security Considerations

As this protocol isn't meant to  be used for critical operations, no security considerations were added to it's conception. A connection could easily be overtaken using the reconnection mechanic.

{backmatter}