//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlCriticalSection.h
//    Author:      Streamlet
//    Create Time: 2011-01-04
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLCRITICALSECTION_H_C580E922_6ED8_483E_8223_2174E0EF7310_INCLUDED__
#define __XLCRITICALSECTION_H_C580E922_6ED8_483E_8223_2174E0EF7310_INCLUDED__


#include <xl/Meta/xlUtility.h>
#include <Windows.h>

namespace xl
{
    class CriticalSection : public NonCopyable
    {
    public:
        CriticalSection()
        {
            InitializeCriticalSection(&m_CriticalSection);
        }

        ~CriticalSection()
        {
            DeleteCriticalSection(&m_CriticalSection);
        }

    public:
        void Lock()
        {
            EnterCriticalSection(&m_CriticalSection);
        }

        void UnLock()
        {
            LeaveCriticalSection(&m_CriticalSection);
        }

        bool TryLock()
        {
            if (!TryEnterCriticalSection(&m_CriticalSection))
            {
                return false;
            }

            return true;
        }

    private:
        CRITICAL_SECTION m_CriticalSection;
    };

} // namespace xl

#endif // #ifndef __XLCRITICALSECTION_H_C580E922_6ED8_483E_8223_2174E0EF7310_INCLUDED__
