#ifndef DATALOAD_CSV_H
#define DATALOAD_CSV_H

#include <QObject>
#include <QtPlugin>
#include "PlotJuggler/dataloader_base.h"


class  DataLoadCSV: public QObject, DataLoader
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.icarustechnology.PlotJuggler.DataLoader" "../dataloader.json")
    Q_INTERFACES(DataLoader)

public:
    DataLoadCSV();
    virtual const std::vector<const char*>& compatibleFileExtensions() const override;

    virtual PlotDataMap readDataFromFile(const QString& file_name,
                                         QString &load_configuration  ) override;

    virtual ~DataLoadCSV();

    virtual const char* name() const override { return "DataLoad CSV"; }

protected:
    int parseHeader(QFile *file, std::vector<std::pair<bool, QString> > &ordered_names);

private:
    std::vector<const char*> _extensions;


};

#endif // DATALOAD_CSV_H
