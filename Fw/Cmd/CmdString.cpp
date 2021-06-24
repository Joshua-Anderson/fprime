#include <Fw/Types/StringType.hpp>
#include <Fw/Types/BasicTypes.hpp>
#include <Fw/Cmd/CmdString.hpp>
#include <Fw/Types/Assert.hpp>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

namespace Fw {

    CmdStringArg::CmdStringArg(const char* src) : StringBase() {
        this->copyBuff(src, sizeof(this->m_buf));
    }

    CmdStringArg::CmdStringArg(const StringBase& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    CmdStringArg::CmdStringArg(const CmdStringArg& src) : StringBase()  {
        this->copyBuff(src.toChar(), src.getCapacity());
    }

    CmdStringArg::CmdStringArg(void) : StringBase() {
        this->m_buf[0] = 0;
    }

    CmdStringArg& CmdStringArg::operator=(const CmdStringArg& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    CmdStringArg& CmdStringArg::operator=(const StringBase& other) {
        this->copyBuff(other.toChar(), other.getCapacity());
        return *this;
    }

    CmdStringArg& CmdStringArg::operator=(const char* other) {
        this->copyBuff(other, sizeof(this->m_buf));
        return *this;
    }

    CmdStringArg::~CmdStringArg(void) {
    }

    const char* CmdStringArg::toChar(void) const {
        return this->m_buf;
    }

    NATIVE_UINT_TYPE CmdStringArg::getCapacity(void) const {
        return FW_CMD_STRING_MAX_SIZE;
    }
}
