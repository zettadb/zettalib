/*
  Copyright (c) 2019-2021 ZettaDB inc. All rights reserved.

  This source code is licensed under Apache 2.0 License,
  combined with Common Clause Condition 1.0, as detailed in the NOTICE file.
*/
#ifndef _ERR_CUP_H_
#define _ERR_CUP_H_

#include <string.h>
#include <stdarg.h>
#include <stdio.h>
namespace kunlun {
class ErrorCup {
public:
  ErrorCup() { bzero(m_errbuf_, 4096); }
  int setErr(const char *fmt, ...) __attribute__((format(printf, 2, 3))) {
    va_list arg;
    va_start(arg, fmt);

    int retVal = vsnprintf(m_errbuf_, sizeof(m_errbuf_) - 1, fmt, arg);
    va_end(arg);
    return retVal;
  }
  int setExtraErr(const char *fmt, ...) __attribute__((format(printf, 2, 3))) {
    va_list arg;
    va_start(arg, fmt);

    int retVal = vsnprintf(m_errbuf_, sizeof(m_errbuf_) - 1, fmt, arg);
    va_end(arg);
    return retVal;
  }

  char *getErr() { return m_errbuf_; }

  char *getExtraErr() { return m_errbuf_; }
  void removeErr() { m_errbuf_[0] = '\0'; }

private:
  char m_errbuf_[4096];
};
} // namespace kunlun

#endif /* _ERR_CUP_H_ */
