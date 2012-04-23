/**
* @file dlgcontrollerlearning.h
* @author Sean M. Pappalardo  spappalardo@mixxx.org
* @date Thu 12 Apr 2012
* @brief The controller mapping learning wizard
*
*/
#ifndef DLGCONTROLLERLEARNING_H
#define DLGCONTROLLERLEARNING_H

// #include <QtCore>
#include <QtGui>

#include "controllers/ui_dlgcontrollerlearning.h"
#include "controllers/controller.h"
#include "configobject.h"
#include "mixxxcontrol.h"

class ControllerPreset;

class DlgControllerLearning : public QDialog, public Ui::DlgControllerLearning {
    Q_OBJECT
  public:
    DlgControllerLearning(QWidget *parent, Controller *controller);
    ~DlgControllerLearning();
  signals:
    void cancelLearning();
    void learn(MixxxControl control);
  public slots:
    void begin();   /** Begin the learning process */
    void next();    /** Ask to map the next control */
    void prev();    /** Ask to map the previous control */
    void controlMapped(QString); /** Gets called when a control has just been mapped successfully */
  private:
    void addControl(QString group, QString control, QString helpText);
    void addDeckControl(QString control, QString helpText);
    void addSamplerControl(QString control, QString helpText);
    Controller* m_pController;
    QList<MixxxControl> m_controlsToMap;
    int iCurrentControl; /** Used to iterate through the controls list */
    QShortcut* m_pSkipShortcut;
};

#endif
