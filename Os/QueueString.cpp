#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Os/QueueString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Os {

    QueueString::QueueString(const char* src) : StringBase()  {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    QueueString::QueueString(const StringBase& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    QueueString::QueueString(const QueueString& src)  : StringBase() {
        this->copyBuff(src.m_buf, src.getCapacity());
    }

    QueueString::QueueString(void) : StringBase()  {
        this->m_buf[0] = 0;
    }

    QueueString& QueueString::operator=(const QueueString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    QueueString& QueueString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    QueueString& QueueString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    QueueString::~QueueString(void) {
    }

    const char* QueueString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE QueueString::getCapacity(void) const {
        return FW_QUEUE_NAME_MAX_SIZE;
    }
}
