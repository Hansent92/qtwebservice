/****************************************************************************
**
** Copyright (C) 2011 Tomasz Siekierda
** All rights reserved.
** Contact: Tomasz Siekierda (sierdzio@gmail.com)
**
** This file is part of the QWebService library, QtNetwork Module.
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

#ifndef QWEBSERVICE_P_H
#define QWEBSERVICE_P_H

#include "qwebservice.h"
#include "qwebmethod.h"
#include "qwsdl.h"

class QWebServicePrivate {

    Q_DECLARE_PUBLIC(QWebService)

public:
    QWebServicePrivate() {}
    QWebServicePrivate(QWebService *q) : q_ptr(q) {}
    QWebService *q_ptr;

    void init();
    bool enterErrorState(const QString &errMessage = QString());

    bool errorState;
    QString errorMessage;
    QString webServiceName;
    QUrl m_hostUrl;
    QWsdl *wsdl;
    // This is general, but should work for custom classes.
    QMap<QString, QWebServiceMethod *> *methods;
};

#endif // QWEBSERVICE_P_H
