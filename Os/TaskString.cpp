#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Os/TaskString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Os {

    TaskString::TaskString(const char* src) : StringBase()  {
        this->copyBuff(src,sizeof(this->m_buf));
    }

    TaskString::TaskString(const StringBase& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    TaskString::TaskString(const TaskString& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    TaskString::TaskString(void) {
        this->m_buf[0] = 0;
    }

    TaskString& TaskString::operator=(const TaskString& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    TaskString& TaskString::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    TaskString& TaskString::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    TaskString::~TaskString(void) {
    }

    const char* TaskString::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE TaskString::getCapacity(void) const {
        return FW_TASK_NAME_MAX_SIZE;
    }
}
