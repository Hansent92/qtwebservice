#ifndef TESTCASE2_WSDL_H
#define TESTCASE2_WSDL_H

#include <QPushButton>
#include "../QWebService/headers/QWebService.h"

class testCase2_wsdl : public QPushButton
{
    Q_OBJECT
public:
    explicit testCase2_wsdl(QWidget *parent = 0);
    ~testCase2_wsdl();

signals:

public slots:

private:
    void runWsdlTest(QString filePathOrUrl);

    QWsdl *wsdl;
};

#endif // TESTCASE2_WSDL_H
