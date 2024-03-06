#ifndef EMPTY_RESULT_MONITORING_H
#define EMPTY_RESULT_MONITORING_H

/* *****************************************************************************
Copyright (c) 2016-2017, The Regents of the University of California (Regents).
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those
of the authors and should not be interpreted as representing official policies,
either expressed or implied, of the FreeBSD Project.

REGENTS SPECIFICALLY DISCLAIMS ANY WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
THE SOFTWARE AND ACCOMPANYING DOCUMENTATION, IF ANY, PROVIDED HEREUNDER IS
PROVIDED "AS IS". REGENTS HAS NO OBLIGATION TO PROVIDE MAINTENANCE, SUPPORT,
UPDATES, ENHANCEMENTS, OR MODIFICATIONS.

*************************************************************************** */

// Written by: Abiy

#include <SimCenterAppWidget.h>

class InputWidgetParameters;
class RandomVariablesContainer;
class QComboBox;
class QGridLayout;
class QVBoxLayout;
class QHBoxLayout;
class QSpinBox;
class QCheckBox;
class QLineEdit;
class LineEditRV;
class QTabWidget;
class QTableWidget;
class QGroupBox;
class QPushButton;
class EmptyDomainCFD;
class QDoubleSpinBox;
class QLabel;
class QRadioButton;

class EmptyResultMonitoring: public SimCenterAppWidget
{
    friend class EmptyDomainCFD;

    Q_OBJECT
public:
    explicit EmptyResultMonitoring(EmptyDomainCFD *parent = 0);
    ~EmptyResultMonitoring();

    bool outputToJSON(QJsonObject &jsonObject);
    bool inputFromJSON(QJsonObject &jsonObject);
    void updateWidgets();

signals:

public slots:
   void clear(void);
   void onAddProfileClicked();
   void onRemoveProfileClicked();
   void onShowProfilesClicked();
   void onAddPlaneClicked();
   void onRemovePlaneClicked();
   void onMonitorProfileChecked(int);
   void onMonitorPlaneChecked(int);


private:

   EmptyDomainCFD       *mainModel;

   QVBoxLayout          *layout;

   QGroupBox            *monitorWindProfileGroup;
   QGridLayout          *monitorWindProfileLayout;

   QTableWidget         *profileTable;
   QSpinBox             *profileWriteInterval;
   QLineEdit            *profileStartTime;
   QCheckBox            *monitorProfile;
   QPushButton          *addProfile;
   QPushButton          *removeProfile;
   QPushButton          *showProfiles;

   QGroupBox            *vtkSampleGroup;
   QGridLayout          *vtkSampleLayout;
   QTableWidget         *vtkSampleTable;
   QSpinBox             *vtkWriteInterval;
   QCheckBox            *monitorVTKPlane;
   QPushButton          *addPlane;
   QPushButton          *removePlane;
   QPushButton          *showPlane;

   void initializeProfileTable(int nProfile);
   void initializeVTKTable(int nVtk);

public:

};

#endif // EMPTY_RESULT_MONITORING_H
