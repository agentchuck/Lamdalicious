#include "commands.hh"

#include <utility>

Command::~Command() {}

std::pair<int, uint16_t>
Halt::encode()
{
  return std::make_pair(1, 0xff);
}

std::pair<int, uint16_t>
Wait::encode()
{
  return std::make_pair(1, 0xfe);
}

std::pair<int, uint16_t>
Flip::encode()
{
  return std::make_pair(1, 0xfd);
}

SMove::SMove(Coord const & ld_) :
  ld(ld_)
{
}

std::pair<int, uint16_t>
SMove::encode()
{
  uint16_t temp = (ld.i() & 0xff) |
                  ((((ld.a() << 4) | 0x04) & 0xff) << 8 );
  return std::make_pair(2, temp);
}

LMove::LMove(Coord const & ld1_, Coord const & ld2_) :
  ld1(ld1_), ld2(ld2_)
{
}

std::pair<int, uint16_t>
LMove::encode()
{
  uint16_t temp = ((ld1.i() & 0x000f) |
                   ((ld2.i() << 4) & 0x00f0) |
                   ((0x0c << 8) & 0x0f00) |
                   ((ld1.a() << 12) & 0x3000) |
                   ((ld2.a() << 14) & 0xc000));
  return std::make_pair(2, temp);
}


FusionP::FusionP(Coord const & ld_) :
  ld(ld_)
{
}

std::pair<int, uint16_t>
FusionP::encode()
{
  uint16_t temp = ((0x7 & 0x7) |
                   ((ld.nd_enc() << 3) & 0xf8));
  return std::make_pair(2, temp);
}

FusionS::FusionS(Coord const & ld_) :
  ld(ld_)
{
}

std::pair<int, uint16_t>
FusionS::encode()
{
  uint16_t temp = ((0x6 & 0x7) |
                   ((ld.nd_enc() << 3) & 0xf8));
  return std::make_pair(2, temp);
}


