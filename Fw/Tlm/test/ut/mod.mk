#
#   Copyright 2004-20015, by the California Institute of Technology.
#   ALL RIGHTS RESERVED. United States Government Sponsorship
#   acknowledged.
#
#

TEST_SRC = TlmTest.cpp

TEST_MODS = Fw/Tlm Fw/Com Fw/Types Fw/Obj Fw/Port Fw/Time gtest


COMPARGS = -I$(CURDIR)/test/ut/Handcode
