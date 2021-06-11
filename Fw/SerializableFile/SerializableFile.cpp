// ====================================================================== 
// \title  SerializableFile.cpp
// \author dinkel 
// \brief  cpp file for SerializableFile 
//
// \copyright
// Copyright 2009-2016, California Institute Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// 
// ====================================================================== 

 "Fw/SerializableFile/SerializableFile.hpp"
 "Fw/Types/Assert.hpp"
 "Os/File.hpp"

Fw {

  SerializableFile::SerializableFile(MemAllocator* allocator, NATIVE_UINT_TYPE maxSerializedSize) :
    allocator(allocator),
    recoverable(false), // for compiler; not used
    actualSize(maxSerializedSize),
    buffer( (U8 *const) this->allocator->allocate(0, actualSize, recoverable), actualSize)
  {
    // assert allocator returns smaller size
    FW_ASSERT(maxSerializedSize == actualSize,maxSerializedSize,actualSize);
    FW_ASSERT(NULL != buffer.getBuffAddr());
  }

  SerializableFile::~SerializableFile() {
    this->allocator->deallocate(0, this->buffer.getBuffAddr());
  }
  
  SerializableFile::Status SerializableFile::load(const char* fileName, Serializable& serializable) {
    Os::File file;
    Os::File::Status status;
    status = file.open(fileName, Os::File::OPEN_READ);
    ( Os::File::OP_OK != status ) {
       FILE_OPEN_ERROR;
    }

    NATIVE_INT_TYPE capacity = this->buffer.getBuffCapacity();
    NATIVE_INT_TYPE length = capacity;
    status = file.read(this->buffer.getBuffAddr(), length, false);
    ( Os::File::OP_OK != status ) {
      file.close();
       FILE_READ_ERROR;
    }
    file.close();

    this->reset();
    SerializeStatus serStatus;
    serStatus = this->buffer.setBuffLen(static_cast<NATIVE_UINT_TYPE>(length));
    FW_ASSERT(FW_SERIALIZE_OK == serStatus, serStatus);
    serStatus = serializable.deserialize(this->buffer);
    (FW_SERIALIZE_OK != serStatus) {
       DESERIALIZATION_ERROR;
    }

     SerializableFile::OP_OK;
  }

  SerializableFile::Status SerializableFile::save(const char* fileName, Serializable& serializable) {
    this->reset();
    SerializeStatus serStatus = serializable.serialize(this->buffer);
    FW_ASSERT(FW_SERIALIZE_OK == serStatus, serStatus);

    Os::File file;
    Os::File::Status status;
    status = file.open(fileName, Os::File::OPEN_WRITE);
    ( Os::File::OP_OK != status ) {
       FILE_OPEN_ERROR;
    }

    NATIVE_INT_TYPE length = this->buffer.getBuffLength();
    NATIVE_INT_TYPE size = length;
    status = file.write(this->buffer.getBuffAddr(), length);
    ( (Os::File::OP_OK != status) ||
        (length != size) ) 
    {
      file.close();
         FILE_WRITE_ERROR;
    }

    file.close();

      SerializableFile::OP_OK;
  }

       SerializableFile::reset() {
    this->buffer.resetSer(); //!< reset beginning buffer reuse serialization
    this->buffer.resetDeser(); //!< reset deserialization beginning
  }
}
