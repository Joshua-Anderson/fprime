#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Types/EightyCharString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fw {

    EightyCharString::EightyCharString(const char* src) : StringBase() {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    EightyCharString::EightyCharString(const StringBase& src) : StringBase() {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    EightyCharString::EightyCharString(const EightyCharString& src) : StringBase() {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    EightyCharString::EightyCharString(void) : StringBase() {
        this->m_buf[0] = 0;
    }

    EightyCharString& EightyCharString::operator=(const EightyCharString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    EightyCharString& EightyCharString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    EightyCharString& EightyCharString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    EightyCharString::~EightyCharString(void) {
    }

    const char* EightyCharString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE EightyCharString::getCapacity(void) const {
        return STRING_SIZE;
    }
}
