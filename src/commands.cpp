#include "commands.hh"

#include <algorithm>
#include <fstream>
#include <ios>
#include <iostream>
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
  uint16_t temp = (((ld.i() + 15) & 0xff) |
                   ((0x04 << 8) & 0x0f00) |
                   ((ld.a() << 12) & 0x3000));
  return std::make_pair(2, temp);
}

LMove::LMove(Coord const & ld1_, Coord const & ld2_) :
  ld1(ld1_), ld2(ld2_)
{
}

std::pair<int, uint16_t>
LMove::encode()
{
  uint16_t temp = (((ld1.i() + 5) & 0x000f) |
                   (((ld2.i() + 5) << 4) & 0x00f0) |
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
  return std::make_pair(1, temp);
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
  return std::make_pair(1, temp);
}

Fill::Fill(Coord const & ld_) :
  ld(ld_)
{
}

std::pair<int, uint16_t>
Fill::encode()
{
  uint16_t temp = ((0x3 & 0x7) |
                   ((ld.nd_enc() << 3) & 0xf8));
  return std::make_pair(1, temp);
}

Fission::Fission(Coord const & ld_, uint8_t m_) :
  ld(ld_), m(m_)
{
}

std::pair<int, uint16_t>
Fission::encode()
{
  uint16_t temp = (((ld.nd_enc() << 11) & 0xf800) |
                   ((0x05 << 8) & 0x0f00) |
                   (m & 0x00ff));
  return std::make_pair(2, temp);
}



CommandList::CommandList()
{
}

CommandList::~CommandList()
{
  clear();
}

void
CommandList::clear()
{
  commands.clear();
}

void
CommandList::addCommand(std::shared_ptr<Command> command)
{
  commands.push_back(command);
}

void
CommandList::dumpToFile(const char *filename)
{
  std::ofstream outFile;
  outFile.open(filename, std::ios::out | std::ios::binary);
  
  for (auto it = commands.begin(); it != commands.end(); it++)
  {
    std::pair<int, uint16_t> encData = (*it)->encode();
    uint16_t data = encData.second;

    if (encData.first == 1)
    {
      outFile.write((char*)&data, 1);
    }
    else
    {
      uint8_t sep = data >> 8;
      outFile.write((char*)&sep, 1);
      sep = data & 0xff;
      outFile.write((char*)&sep, 1);
    }
  }
}


