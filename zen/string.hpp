#ifndef ZEN_STRING_HPP
#define ZEN_STRING_HPP

#include <string>

#include "zen/maybe.hpp"

namespace zen {

  // TODO This should be a strong type
  using glyph_t = char32_t;

  inline constexpr const glyph_t eof = 0xFFFF;

  // TODO The internal representation should be converted to UTF-8
  using string = std::basic_string<glyph_t>;

  template<>
  class maybe<glyph_t> {

    glyph_t value;

  public:

    inline maybe():
      value(eof) {}

    inline maybe(glyph_t value):
      value(value) {}

    glyph_t* operator->() {
      return &value;
    }

    bool is_some() {
      return value != eof;
    }

    bool is_empty() {
      return value == eof;
    }

  };

  // FIXME Currently only works for ASCII values.
  inline string from_utf8(std::string_view raw) {
    return string { raw.begin(), raw.end() };
  }

  template<std::size_t N>
  inline string from_utf8(const char ptr[N]) {
    return string { ptr, ptr + N };
  }

#define ZEN_STRING_LITERAL(literal) ::zen::from_utf8(literal)

}

#endif // of #ifndef ZEN_STRING_HPP