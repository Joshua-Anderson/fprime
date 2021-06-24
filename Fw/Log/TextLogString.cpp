#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Log/TextLogString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fw {

    TextLogString::TextLogString(const char* src) : StringBase() {
        this->copyBuff(src,sizeof(this->m_buf));
    }

    TextLogString::TextLogString(const StringBase& src): StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    TextLogString::TextLogString(const TextLogString& src): StringBase()  {
        this->copyBuff(src.m_buf, src.getCapacity());
    }

    TextLogString::TextLogString(void): StringBase()  {
        this->m_buf[0] = 0;
    }

    TextLogString& TextLogString::operator=(const TextLogString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    TextLogString& TextLogString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    TextLogString& TextLogString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    TextLogString::~TextLogString(void) {
    }

    const char* TextLogString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE TextLogString::getCapacity(void) const {
        return FW_LOG_TEXT_BUFFER_SIZE;
    }
}
