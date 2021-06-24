#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/InternalInterfaceString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fw {

    InternalInterfaceString::InternalInterfaceString(const char* src) : StringBase()  {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    InternalInterfaceString::InternalInterfaceString(const StringBase& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    InternalInterfaceString::InternalInterfaceString(const InternalInterfaceString& src) : StringBase()  {
        this->copyBuff(src.m_buf, src.getCapacity());
    }

    InternalInterfaceString::InternalInterfaceString(void) : StringBase()  {
        this->m_buf[0] = 0;
    }

    InternalInterfaceString& InternalInterfaceString::operator=(const InternalInterfaceString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    InternalInterfaceString& InternalInterfaceString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    InternalInterfaceString& InternalInterfaceString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    InternalInterfaceString::~InternalInterfaceString(void) {
    }

    const char* InternalInterfaceString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE InternalInterfaceString::getCapacity(void) const {
        return FW_INTERNAL_INTERFACE_STRING_MAX_SIZE;
    }
}
