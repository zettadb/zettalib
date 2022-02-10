#ifndef _Z_THREAD_H_
#define _Z_THREAD_H_

#include "pthread.h"
namespace kunlun {

class ZThread {
public:
  ZThread();
  virtual ~ZThread();
  int start();

protected:
  virtual int run() = 0;
  // 0: will or have already exit
  // 1: working
  int m_state;

private:
  static void *threadEntry(void *);
  void initAttr();
  pthread_t m_threadId;
  pthread_attr_t m_attr;
};

} // namespace kunlun

#endif /*_Z_THREAD_H_*/
