/****************************************************************************
**
** Copyright (C) 2011 Tomasz Siekierda
** All rights reserved.
** Contact: Tomasz Siekierda (sierdzio@gmail.com)
**
** This file is part of the qtWsdlConverter tool.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MESSAGEGENERATOR_H
#define MESSAGEGENERATOR_H

#include <QtCore/qobject.h>
#include <QtCore/qstring.h>
#include <QtCore/qmap.h>
#include <QtCore/qdir.h>
#include <QtCore/qtextstream.h>
//#include <QWebService>
#include <qwebservicemethod.h>
#include "flags.h"

class MessageGenerator : public QObject
{
    Q_OBJECT
public:
    explicit MessageGenerator(QMap<QString, QWebServiceMethod *> *methods,
                              const QDir &workingDir, Flags *flgs, QObject *parent = 0);
    QString errorMessage();
    bool createMessages();

private:
    bool enterErrorState(const QString errMessage = QString());
    bool createSubclassedMessageHeader(QWebServiceMethod *msg);
    bool createSubclassedMessageSource(QWebServiceMethod *msg);
    bool createMessageHeader(QWebServiceMethod *msg);
    bool createMessageSource(QWebServiceMethod *msg);
    bool createMainCpp();

    void assignAllParameters(QWebServiceMethod *msg, QTextStream &out);

    QMap<QString, QWebServiceMethod *> *methods;
    QDir workingDir;
    Flags *flags;
    bool errorState;
    QString m_errorMessage;
};

#endif // MESSAGEGENERATOR_H
