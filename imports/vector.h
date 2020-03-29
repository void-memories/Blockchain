// -*- C++ -*-
//===--------------------------- vector ------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

#ifndef _LIBCPP_EXPERIMENTAL_VECTOR
#define _LIBCPP_EXPERIMENTAL_VECTOR
/*
    experimental/vector synopsis

// C++1z
namespace std {
namespace experimental {
inline namespace fundamentals_v1 {
namespace pmr {

  template <class T>
  using vector = std::vector<T, polymorphic_allocator<T>>;

} // namespace pmr
} // namespace fundamentals_v1
} // namespace experimental
} // namespace std

 */

#include <experimental/__config>
#include <vector>
#include <experimental/memory_resource>

#if !defined(_LIBCPP_HAS_NO_PRAGMA_SYSTEM_HEADER)
#pragma GCC system_header
#endif

_LIBCPP_BEGIN_NAMESPACE_LFTS_PMR

template <class _ValueT>
using vector = _VSTD::vector<_ValueT, polymorphic_allocator<_ValueT>>;

_LIBCPP_END_NAMESPACE_LFTS_PMR

#endif /* _LIBCPP_EXPERIMENTAL_VECTOR */