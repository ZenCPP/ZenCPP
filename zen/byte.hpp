#ifndef ZEN_BYTE_HPP
#define ZEN_BYTE_HPP

namespace zen {

  using byte_t = unsigned char;

#define ZEN_BYTE_LITERAL(literal) ((const byte_t*)(literal))

}

#endif // of #ifndef ZEN_BYTE_HPP