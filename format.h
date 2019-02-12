#ifndef FORMAT_H
#define FORMAT_H

#include <QString>
#include <QLocale>
#include <QDateTime>
#include <QLineEdit>

#include "money.h"

// Helpers

inline static QString timeFormat(int64_t nTime)
{
    return QDateTime::fromTime_t(946684800 + nTime).toString("dd/MM/yyyy hh:mm:ss");
}

inline static QString AmountWithSign(int64_t nAmount, bool isDebit = false, QString strCurrency = "SMR")
{
    return QString("%1%2 %3").arg(isDebit ? "-" : "").arg(QString::number ( nAmount / coinAsDouble, 'f', 6 )).arg(strCurrency);
}

inline static QString Amount(int64_t nAmount)
{
    return QString::number ( nAmount / coinAsDouble, 'f', 6 );
}

inline static int64_t readInt(QLineEdit* lineEdit)
{
    return QLocale::system().toInt(lineEdit->text());
}

inline static double readDouble(QLineEdit* lineEdit)
{
    auto val = lineEdit->text();
    val.replace(QRegExp("[^0-9]"), QLocale::system().decimalPoint());
    return QLocale::system().toDouble(val);
}

#endif // FORMAT_H
