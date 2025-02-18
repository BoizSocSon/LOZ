#ifndef JMATRIGONOMETRIC_H
#define JMATRIGONOMETRIC_H

#include "dolphin/types.h"
#include "utility.h"

template<typename T>
struct TAngleConstant_;

template<>
struct TAngleConstant_<f32> {
    static inline f32 RADIAN_DEG360() { return 6.2831855f; }
};

template<int N, typename T>
struct TSinCosTable {
    std::pair<T, T> table[1 << N];

    T sinShort(s16 v) const { return table[(u16)v >> (16U - N)].first; }
    T cosShort(s16 v) const { return table[(u16)v >> (16U - N)].second; }

    inline T sinLap(T v) {
        if (v < (T)0.0) {
            return -table[(u16)(-(T)(1 << N) * v) & ((1 << N) - 1)].first;
        }
        return table[(u16)((T)(1 << N) * v) & ((1 << N) - 1)].first;
    }

    inline T sinDegree(T degree) {
        if (degree < (T)0.0) {
            return -table[(u16)(((T)(1 << N) / 360.0) * degree) & ((1 << N) - 1)].first;
        } 
        return table[(u16)(((T)(1 << N) / 360.0) * degree) & ((1 << N) - 1)].first;
    }

    inline T cosDegree(T degree) {
        if (degree < (T)0.0) {
            degree = -degree;
        } 
        return table[(u16)(((T)(1 << N) / 360.0) * degree) & ((1 << N) - 1)].second;
    }

    inline T sinRadian(T radian) {
        if (radian < (T)0.0) {
            return -table[(u16)(-(T)(1 << N) / TAngleConstant_<T>::RADIAN_DEG360() * radian) & ((1 << N) - 1)].first;
        }
        return table[(u16)((T)(1 << N) / TAngleConstant_<T>::RADIAN_DEG360() * radian) & ((1 << N) - 1)].first;
    }
};

struct TAtanTable {
    f32 table[1025];
    u8 pad[0x1C];
};

struct TAsinAcosTable {
    f32 table[1025];
    u8 pad[0x1C];
};

namespace JMath {
extern TSinCosTable<13, f32> sincosTable_;
extern TAtanTable atanTable_;
extern TAsinAcosTable asinAcosTable_;
};  // namespace JMath

inline f32 JMASCosShort(s16 v) {
    return JMath::sincosTable_.cosShort(v);
}
inline f32 JMASinShort(s16 v) {
    return JMath::sincosTable_.sinShort(v);
}

inline f32 JMASCos(s16 v) {
    return JMASCosShort(v);
}
inline f32 JMASSin(s16 v) {
    return JMASinShort(v);
}

inline f32 JMASinLap(f32 v) {
    return JMath::sincosTable_.sinLap(v);
}

inline f32 JMASinDegree(f32 degree) {
    return JMath::sincosTable_.sinDegree(degree);
}

inline f32 JMACosDegree(f32 degree) {
    return JMath::sincosTable_.cosDegree(degree);
}

inline f32 JMASinRadian(f32 radian) {
    return JMath::sincosTable_.sinRadian(radian);
}

#endif /* JMATRIGONOMETRIC_H */
