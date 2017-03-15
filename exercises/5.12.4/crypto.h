#ifndef __CRYPTO_H__
#define __CRYPTO_H__

#include <QVector>
#include <QString>

class Crypto
{
public:
    Crypto(ushort key, QString opseq, ushort charsiz = 1);
    QString encrypt(const QString &str);
    QString decrypt(const QString &str);

private:
    QString shift(const QString &str);
    QString unshift(const QString &str);
    QString permute(const QString &str);
    QString unpermute(const QString &str);
    int limitedRand(int max);
    QVector<int> randomPerm(int n);

    ushort m_Key;
    QString m_OpSequence;
    ushort m_CharSetSize;
    QVector<int> m_Perm;
};

#endif
