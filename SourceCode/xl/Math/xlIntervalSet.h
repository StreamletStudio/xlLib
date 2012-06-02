//------------------------------------------------------------------------------
//
//    Copyright (C) Streamlet. All rights reserved.
//
//    File Name:   xlIntervalSet.h
//    Author:      Streamlet
//    Create Time: 2012-06-01
//    Description: 
//
//    Version history:
//
//
//
//------------------------------------------------------------------------------

#ifndef __XLINTERVALSET_H_0D40B708_46DD_4421_A698_83BFE8AA4066_INCLUDED__
#define __XLINTERVALSET_H_0D40B708_46DD_4421_A698_83BFE8AA4066_INCLUDED__


#include <xl/Containers/xlSet.h>
#include <xl/Math/xlInterval.h>

namespace xl
{
    template <typename T>
    class IntervalSet
    {
    public:
        typedef Interval<T> IntervalType;

    private:
        Set<IntervalType> m_setIntervals;

    public:
        IntervalSet()
        {

        }

        IntervalSet(const IntervalSet &that)
        {
            this->m_setIntervals = that.m_setIntervals;
        }

        ~IntervalSet()
        {

        }

    public:
        IntervalSet &operator = (const IntervalSet &that)
        {
            if (this != &that)
            {
                this->m_setIntervals = that.m_setIntervals;
            }

            return *this;
        }

        bool operator == (IntervalSet &that) const
        {
            return this->m_setIntervals == that.m_setIntervals;
        }

        bool operator != (IntervalSet &that) const
        {
            return this->m_setIntervals != that.m_setIntervals;
        }

    public:
        Set<IntervalType> GetIntervals()
        {
            return m_setIntervals;
        }

    public:
        bool IsEmpty() const
        {
            return m_setIntervals.Empty();
        }

    public:
        void Intersect(const IntervalType &interval)
        {
            Set<IntervalType> setIntervals;

            if (!interval.IsEmpty())
            {
                for (auto it = m_setIntervals.Begin(); it != m_setIntervals.End(); ++it)
                {
                    IntervalType i = it->Intersection(interval);

                    if (!i.IsEmpty())
                    {
                        setIntervals.Insert(i);
                    }
                }
            }

            m_setIntervals = setIntervals;
        }

        void Union(const IntervalType &interval)
        {
            if (interval.IsEmpty())
            {
                return;
            }

            IntervalType i = interval;

            for (auto it = m_setIntervals.Begin(); it != m_setIntervals.End(); )
            {
                if (it->Contains(interval))
                {
                    return;
                }

                if (interval.Touched(*it))
                {
                    i = i.UnionTouched(*it);
                    it = m_setIntervals.Delete(it);
                }
                else
                {
                    ++it;
                }                
            }

            m_setIntervals.Insert(i);
        }

        void Exclude(const IntervalType &interval)
        {
            if (interval.IsEmpty())
            {
                return;
            }

            Set<IntervalType> s;

            for (auto it = m_setIntervals.Begin(); it != m_setIntervals.End(); )
            {
                if (it->HasIntersectionWith(interval))
                {
                    Set<IntervalType> intervals = it->Exclude(interval);
                    s.Insert(intervals.Begin(), intervals.End());

                    it = m_setIntervals.Delete(it);
                }
                else
                {
                    ++it;
                }
            }

            m_setIntervals.Insert(s.Begin(), s.End());
        }

    public:
        IntervalSet Intersection(const IntervalSet &that) const
        {
            if (this->IsEmpty() || that.IsEmpty())
            {
                return IntervalSet();
            }

            IntervalSet res = *this;

            for (auto it = that.m_setIntervals.Begin(); it != that.m_setIntervals.End(); ++it)
            {
                res.Intersect(*it);

                if (res.IsEmpty())
                {
                    return res;
                }
            }

            return res;
        }

        IntervalSet Union(const IntervalSet &that) const
        {
            if (that.IsEmpty())
            {
                return *this;
            }

            if (this->IsEmpty())
            {
                return that;
            }

            IntervalSet res = *this;

            for (auto it = that.m_setIntervals.Begin(); it != that.m_setIntervals.End(); ++it)
            {
                res.Union(*it);
            }

            return res;
        }

        IntervalSet Exclude(const IntervalSet &that) const
        {
            if (that.IsEmpty() || that.IsEmpty())
            {
                return *this;
            }

            IntervalSet res = *this;

            for (auto it = that.m_setIntervals.Begin(); it != that.m_setIntervals.End(); ++it)
            {
                res.Exclude(*it);
            }

            return res;
        }
    };

} // namespace xl



#endif // #ifndef __XLINTERVALSET_H_0D40B708_46DD_4421_A698_83BFE8AA4066_INCLUDED__
