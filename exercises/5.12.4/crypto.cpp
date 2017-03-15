#include <QTextStream>
#include <QString>
#include <stdlib.h>
#include <assert.h>
#include "crypto.h"

Crypto::Crypto(ushort key, QString opseq, ushort charsiz):
    m_Key(key),
    m_OpSequence(opseq),
    m_CharSetSize(charsiz)
{
    ;
}

QString Crypto::encrypt(const QString &str)
{
    QString ret = str;

    for (QString::const_iterator it = this->m_OpSequence.constBegin(),
            end = this->m_OpSequence.constEnd(); it != end; ++it)
    {
        if ('p' == (*it))
        {
            ret = this->permute(ret);
        } else if ('s' == (*it)) {
            ret = this->shift(ret);
        }
    }

    return ret;
}

QString Crypto::decrypt(const QString &str)
{
    QString ret = str;

    for (QString::const_iterator it = this->m_OpSequence.constEnd(),
            end = this->m_OpSequence.constBegin(); it != end;)
    {
        --it; /* must be here */
        if ('p' == (*it))
        {
            ret = this->unpermute(ret);
        } else if ('s' == (*it)) {
            ret = this->unshift(ret);
        }
    }

    return ret;
}

QString Crypto::shift(const QString &str)
{
    QString ret;
    QTextStream ts(&ret);

    srandom(this->m_Key);

    for (int i = 0; i < str.length(); ++i)
    {
        unsigned char old_c = str.at(i).toLatin1();
        unsigned char new_c = (old_c + this->limitedRand(256)) % 256;
        ts << QChar(new_c);
    }

    return ret;
}

QString Crypto::unshift(const QString &str)
{
    QString ret;
    QTextStream ts(&ret);

    srandom(this->m_Key);

    for (int i = 0; i < str.length(); ++i)
    {
        unsigned char old_c = str.at(i).toLatin1();
        unsigned char new_c = (256 + old_c - this->limitedRand(256)) % 256;
        ts << QChar(new_c);
    }

    return ret;
}

QString Crypto::permute(const QString &str)
{
    QString ret;
    QTextStream ts(&ret);
    QVector<int> map;

    srandom(this->m_Key);
    map = this->randomPerm(str.length());

    for (int i = 0; i < str.length(); ++i)
    {
        ts << str.at(map[i]);
    }

    return ret;
}

QString Crypto::unpermute(const QString &str)
{
    QString ret;
    QTextStream ts(&ret);
    QVector<int> map;

    srandom(this->m_Key);
    map = this->randomPerm(str.length());

    for (int i = 0; i < str.length(); ++i)
    {
        ts << str.at(map.indexOf(i));
    }

    return ret;
}

int Crypto::limitedRand(int max)
{
    return random() % max;
}

template<class T>
inline void myswap(QVector<T> &v, int i, int j)
{
    assert(0 <= i && i < v.length());
    assert(0 <= j && j < v.length());

    T tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

QVector<int> Crypto::randomPerm(int n)
{
    QVector<int> ret(n);

    for (int i = 0; i < n; ++i)
    {
        ret[i]= i;
    }

    srandom(m_Key);
    for (int i = 0; i < n; ++i) {
        myswap(ret, i, this->limitedRand(n));
    }

    return ret;
}
