// ====================================================================== 
// \title  PathName.cpp
// \author bocchino
// \brief  cpp file for FilePacket::PathName
//
// \copyright
// Copyright 2009-2016, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

#include <string.h>

#include <Fw/FilePacket/FilePacket.hpp>
#include <Fw/Types/Assert.hpp>

namespace Fw {

   FilePacket::PathName ::
    initialize(const char *const value)
  {
     U32 length = ::strnlen(value, MAX_LENGTH);
    this->length = length;
    this->value = value;
  }

  U32 FilePacket::PathName ::
    bufferSize(void) const
  {
     sizeof(this->length) + this->length;
  }

  SerializeStatus FilePacket::PathName ::
    SerialBuffer(SerialBuffer& serialBuffer) 
  {

    {
       SerializeStatus status = 
        serialBuffer.deserialize(this->length);
       (status != FW_SERIALIZE_OK)
         status;
    }

    {
       U8* addrLeft = serialBuffer.getBuffAddrLeft();
      U8 bytes[this->length];
       SerializeStatus status =
        serialBuffer.popBytes(bytes, this->length);
       (status != FW_SERIALIZE_OK)
        return status;
      this->value = reinterpret_cast<const char*>(addrLeft);
    }

     FW_SERIALIZE_OK;

  }

  SerializeStatus FilePacket::PathName ::
    toSerialBuffer(SerialBuffer& serialBuffer) const
  {

    {
       SerializeStatus status =
        serialBuffer.serialize(this->length);
       (status != FW_SERIALIZE_OK)
         status;
    }

    {
       SerializeStatus status = serialBuffer.pushBytes(
          reinterpret_cast<const U8 *const>(this->value), 
          this->length
      );
       (status != FW_SERIALIZE_OK)
          status;
    }

         FW_SERIALIZE_OK;

  }

}
