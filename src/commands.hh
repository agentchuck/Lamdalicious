#ifndef COMMANDS_HH
#define COMMANDS_HH

#include <cstdint>
#include <utility>
#include "tools.hh"

class Command
{
  public:
    virtual ~Command();
    virtual std::pair<int, uint16_t> encode() = 0;
};

class Halt : public Command
{
  public:
    virtual std::pair<int, uint16_t> encode();
};

class Wait : public Command
{
  public:
    virtual std::pair<int, uint16_t> encode();
};

class Flip : public Command
{
  public:
    virtual std::pair<int, uint16_t> encode();
};

class SMove : public Command
{
  public:
    Coord ld;
    SMove(Coord const & ld_);
    virtual std::pair<int, uint16_t> encode();
};

class LMove : public Command
{
  public:
    Coord ld1;
    Coord ld2;
    LMove(Coord const & ld1_, Coord const & ld2_);
    virtual std::pair<int, uint16_t> encode();
};

class FusionP : public Command
{
  public:
    Coord ld;
    FusionP(Coord const & ld_);
    virtual std::pair<int, uint16_t> encode();
};

class FusionS : public Command
{
  public:
    Coord ld;
    FusionS(Coord const & ld_);
    virtual std::pair<int, uint16_t> encode();
};

class Fill : public Command
{
  public:
    Coord ld;
    Fill(Coord const & ld_);
    virtual std::pair<int, uint16_t> encode();
};


#endif
