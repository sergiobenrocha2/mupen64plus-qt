/***
 * Copyright (c) 2013, Dan Hasting
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the organization nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ***/

#ifndef ROMCOLLECTION_H
#define ROMCOLLECTION_H

#include <QCryptographicHash>
#include <QObject>
#include <QProgressDialog>

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "common.h"
#include "global.h"
#include "thegamesdbscrapper.h"


class RomCollection : public QObject
{
    Q_OBJECT
public:
    explicit RomCollection(QStringList fileTypes, QStringList romPaths, QWidget *parent = 0);
    void cachedRoms(bool imageUpdated = false);
    void updatePaths(QStringList romPaths);

    QStringList getFileTypes(bool archives = false);
    QStringList romPaths;

public slots:
    void addRoms();

signals:
    void romAdded(Rom *currentRom, int count);
    void updateEnded(int romCount, bool cached = false);
    void updateStarted(bool imageUpdated = false);

private:
    void initializeRom(Rom *currentRom, bool cached);
    void setupDatabase();
    void setupProgressDialog(int size);

    Rom addRom(QByteArray *romData, QString fileName, QString directory, QString zipFile, QSqlQuery query);

    QStringList fileTypes;

    QWidget *parent;
    QProgressDialog *progress;
    QSqlDatabase database;

    TheGamesDBScrapper *scrapper;
};

#endif // ROMCOLLECTION_H
