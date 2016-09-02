//
// Created by alexey on 02.09.16.
//

#ifndef SQLLITE_CONSOLE_CLOG_H
#define SQLLITE_CONSOLE_CLOG_H


class CLog {
public:
    enum {
        All = 0, Debug, Info, Warning, Error, Fatal, None
    };

    static void Write(int nLevel, const char *szFormat, ...);
    static void Write(int nLevel, std::string msg);

    static void SetLevel(int nLevel);

protected:
    static void CheckInit();

    static void Init();

private:
    CLog();

    static bool m_bInitialised;
    static int m_nLevel;
};

#endif //SQLLITE_CONSOLE_CLOG_H
