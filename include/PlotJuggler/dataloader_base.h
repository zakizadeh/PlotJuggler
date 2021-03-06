#ifndef DATALOAD_TEMPLATE_H
#define DATALOAD_TEMPLATE_H

#include <QtPlugin>
#include <QMenu>
#include <QFile>
#include <functional>
#include "PlotJuggler/plotdata.h"

class DataLoader{

public:

    virtual const std::vector<const char*>& compatibleFileExtensions() const = 0;

    virtual PlotDataMap readDataFromFile(const QString& file_name,
                                         QString& default_configuration ) = 0;

    virtual const char* name() const = 0;

    virtual ~DataLoader() {}

    virtual bool isDebugPlugin() { return false; }

    virtual void setParentMenu(QMenu* menu) { _menu = menu; }

    virtual QWidget* embeddedWidget() { return nullptr; }

protected:
    QMenu* _menu;
};

QT_BEGIN_NAMESPACE

#define DataRead_iid "com.icarustechnology.PlotJuggler.DataLoader"

Q_DECLARE_INTERFACE(DataLoader, DataRead_iid)

QT_END_NAMESPACE


#endif

