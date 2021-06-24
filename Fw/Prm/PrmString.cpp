#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Prm/PrmString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fw {

    ParamString::ParamString(const char* src) : StringBase()  {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    ParamString::ParamString(const StringBase& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    ParamString::ParamString(const ParamString& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    ParamString::ParamString(void) : StringBase()  {
        this->m_buf[0] = 0;
    }

    ParamString& ParamString::operator=(const ParamString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    ParamString& ParamString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    ParamString& ParamString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    ParamString::~ParamString(void) {
    }

    const char* ParamString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE ParamString::getCapacity(void) const {
        return FW_PARAM_STRING_MAX_SIZE;
    }
}
