#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/FixedLengthString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fw {

    FixedLengthString::FixedLengthString(const char* src) : StringBase() {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    FixedLengthString::FixedLengthString(const StringBase& src) : StringBase() {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    FixedLengthString::FixedLengthString(const FixedLengthString& src) : StringBase() {
        this->copyBuff(src.m_buf, src.getCapacity());
    }

    FixedLengthString::FixedLengthString(void) : StringBase() {
        this->m_buf[0] = 0;
    }

    FixedLengthString& FixedLengthString::operator=(const FixedLengthString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    FixedLengthString& FixedLengthString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    FixedLengthString& FixedLengthString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    FixedLengthString::~FixedLengthString(void) {
    }

    const char* FixedLengthString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE FixedLengthString::getCapacity(void) const {
        return STRING_SIZE;
    }
}
