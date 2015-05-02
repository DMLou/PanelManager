/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <iostream>
#include <string>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <DbWrapper.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_saveButton_clicked()
{
    QString conventionName = ui->conventionName->displayText();
    if (conventionName.isEmpty())
    {
        QMessageBox::information(this, "Convention Name", "Convention name not specified.",
                                 QMessageBox::Ok);
        return;
    }
    int conventionYear = ui->conventionYear->value();
    std::string startDate = ui->startDate->date().toString("d/M/yyyy").toStdString();
    std::string endDate = ui->startDate->date().toString("d/M/yyyy").toStdString();

    std::cout << "Save button clicked. "
              << "Convention name: " << conventionName.toStdString() << " "
              << "Convention year: " << conventionYear << " "
              << "Convention start date: " << startDate << " "
              << "Convention end date: " << endDate << std::endl;

    QString documentsDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Save new panel schedule",
                                                    documentsDir,
                                                    "Panel Databases (*.panels)");
    std::cout << "User will save to filename: " << fileName.toStdString() << std::endl;

    // TODO if filename already exists, delete it to reset it to empty

    DbWrapper db;
    try
    {
        db.open(fileName.toStdString());
    }
    catch (DbWrapper::Error& ex)
    {
        QMessageBox::critical(this, "Database error", ex.what(), QMessageBox::Ok);
        return;  // TODO something better?
    }

    try
    {
        std::string sql("CREATE TABLE Version (version INTEGER);");
        db.execute(sql);
        sql = "INSERT INTO Version (version) VALUES (0);"; // DB version 0 (initial testing)
        db.execute(sql);
    }
    catch (DbWrapper::Error& ex)
    {
        QMessageBox::critical(this, "Database error", ex.what(), QMessageBox::Ok);
        // TODO something better?
    }
}

