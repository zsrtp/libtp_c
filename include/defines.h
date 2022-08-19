#ifndef LIBTP_C_DEFINES_H
#define LIBTP_C_DEFINES_H

#include <utility>

#ifdef WII_PLATFORM
#define LIBTP_DEFINE_FUNC(gcLabel, wiiLabel, rettype, name, args) \
extern "C" {rettype wiiLabel args;} \
template <typename... Args> \
inline auto name(Args&&... a) -> decltype(wiiLabel(std::forward<Args>(a)...)) { \
  return wiiLabel(std::forward<Args>(a)...); \
}
#else
#define LIBTP_DEFINE_FUNC(gcLabel, wiiLabel, rettype, name, args) \
extern "C" {rettype gcLabel args;} template <typename... Args> inline auto name(Args&&... a) -> decltype(gcLabel(std::forward<Args>(a)...)) { return gcLabel(std::forward<Args>(a)...); }
#endif

#endif  // !LIBTP_C_DEFINES_H