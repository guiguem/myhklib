#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <sstream>
#include <pthread.h>
#include <map>
#include <Store.h>
#include <unistd.h>

/**
 * \struct DataModelThread_args
 *
 * This is both an base class for any thread argument struct used in the tool threaded Tool templates.
Effectivly this acts as a place to put variable that are specfic to that thread and can be used as a place to transfer variables from the main thread to sub threads.
 *
 *
 * $Author: B.Richards $
 * $Date: 2019/05/26 18:34:00 $
 *
 */

struct Thread_args{

    Thread_args(){ ///< Simple constructor
        kill=false;
    }

    virtual ~Thread_args(){ ///< virtual constructor
        running =false;
        kill=true;
    }

    std::string ThreadName; ///< name of thread (deffined at creation)
    void (*func)(Thread_args*); ///< function pointer to thread with args
    pthread_t thread; ///< Simple constructor underlying thread that interface is built ontop of
    bool running; ///< Bool flag to tell the thread to run (if not set thread goes into wait cycle
    bool kill; ///< Bool flay used to kill the thread

};


/**
 * \class Utilities
 *
 * This class can be instansiated in a Tool and provides some helpful threading, dynamic socket descovery and promotion functionality
 *
 *
 * $Author: B.Richards $
 * $Date: 2019/05/26 18:34:00 $
 *
 */

class Utilities{

public:

    Utilities(); ///< Simple constructor
    Thread_args* CreateThread(std::string ThreadName,  void (*func)(Thread_args*), Thread_args* args); ///< Create a thread with more complicated data exchange definned by arguments
    bool KillThread(Thread_args* &args); ///< Kill a thread assosiated to args
    bool KillThread(std::string ThreadName); ///< Kill a thread by name

    template <typename T>  bool KillThread(T* pointer){

        Thread_args* tmp=pointer;
        return KillThread(tmp);

    } ///< Kill a thread with args that inheirt form base Thread_args



protected:

    static void* Thread(void *arg); ///< Thread with args
    std::map<std::string, Thread_args*> Threads; ///< Map of threads managed by the utilities class.


};

namespace util {
/*
  ///Contains the start and end of a time window, along with an ID (nominally trigger number)
  struct Window {
    int m_trigger_num;
    TimeDelta m_start;
    TimeDelta m_end;
    Window() {}
  Window(int trigger_num, TimeDelta start, TimeDelta end) :
      m_trigger_num(trigger_num), m_start(start), m_end(end) {}
  };

  ///When sorting Window structs, sort by the start time
  static bool WindowSorter(const Window & lhs,
			   const Window & rhs) {
    return lhs.m_start < rhs.m_start;
  }
*/
    /// Check if a file exists
    bool FileExists(std::string pathname, std::string filename);
    bool FileExists(std::string filepathname);

    /// Format messages in the same way as for tools
    void Log(const std::string & message, const int message_level);

    /// Format messages in the same way as for tools
    void Log(std::stringstream & message, const int message_level);

    /// Log level enumerations
    enum LogLevel {FATAL=-1, ERROR=0, WARN=1, INFO=2, DEBUG1=3, DEBUG2=4, DEBUG3=5};

} //namespace util



#endif