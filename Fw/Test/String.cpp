#include <Fw/Test/String.hpp>
#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Test {

    String::String(const char* src) : StringBase() {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    String::String(const StringBase& src) : StringBase() {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    String::String(const String& src) : StringBase() {
        this->copyBuff(src.m_buf, src.getCapacity());
    }

    String::String(void) : StringBase() {
        this->m_buf[0] = 0;
    }

    String& String::operator=(const String& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    String& String::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    String& String::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    String::~String(void) {
    }

    const char* String::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE String::getCapacity(void) const {
        return STRING_SIZE;
    }
}
