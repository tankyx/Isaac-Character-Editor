#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDir>
#include <QIntValidator>
#include <QLabel>
#include <QMainWindow>
#include <QSettings>
#include <array>
#include "draw.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = 0);
    ~MainWindow();
    Character* GetCurrentCharacter();
    void DrawBackground(bool vaporwave = false);
    void SetUpHealthAndConsumableLabels();
    void GenerateComboBoxes();
    void GenerateCharacterComboBox();
    void GenerateSpacebarComboBox();
    void GenerateCardComboBox();
    void GenerateTrinketComboBox();
    void GenerateCostumeComboBox();
    void GenerateSkinColorComboBox();
    void DefaultDrawFamiliar(std::vector<int>);
    std::array<QLabel*, 12> SetUpHeartLabels();
public slots:
    void SetCurrentCharacter(int characterToSet);
    void SetRedHearts(QString value);
    void SetSoulHearts(QString value);
    void SetBlackHearts(QString value);
    void SetCoins(QString value);
    void SetBombs(QString value);
    void SetKeys(QString value);
    void SetItems();
    void SetSpacebar(QString value);
    void SetCard(int cardIndex);
    void SetTrinket(QString value);
    void SetCostume(int costumeIndex);
    void SetSkinColor(int skinColorIndex);
    void SetTears(int checkState);
    void PillCheckBoxChanged(int checkState);
    void CardCheckBoxChanged(int checkState);
    void TrinketCheckBoxChanged(int checkState);
    void SortCheckBoxChanged(int checkState);
    void AfterbirthCheckBoxChanged(int checkState);
    void PathTextEditChanged();
    void EditNameButtonClicked();
    void RestoreDefaultPath();
    void CompassButtonClicked();
    void NotepadButtonClicked();
    void PurgeButtonClicked();
    void ReadButtonClicked();
    void ExportButtonClicked();
    void RandomSpacebarButtonClicked();
    void RandomCardButtonClicked();
    void RandomTrinketButtonClicked();
    void RandomCostumeButtonClicked();
    void RandomEverythingButtonClicked();
private:
    void LoadSettings();
    void SaveSettings();
    Ui::MainWindow* ui;
    Draw _draw;
    Random _rng = Random();
    QIntValidator* _healthValidator = new QIntValidator(0, 24, this);
    QIntValidator* _consumableValidator = new QIntValidator(0, 99, this);
    std::array<QLabel*, 12> _heartLabels = SetUpHeartLabels();

    //Ugly
#if defined(Q_OS_WIN)
    const QString _defaultPath = "C:/Program Files (x86)/Steam/SteamApps/common/The Binding of Isaac Rebirth";
    const QFont _font = QFont("Segoe UI", 9);
#elif defined(Q_OS_MAC)
    const QString _defaultPath = QDir::homePath() + "/Library/Application Support/Steam/steamapps/common/The Binding of Isaac Rebirth/The Binding of Isaac Rebirth.app/Contents/Resources/";
    QFont _font = QFont("Helvetica Neue", 12);
#elif defined(Q_OS_LINUX)
    const QString _defaultPath = QDir::homePath() + "/.steam/steam/steamapps/common/The Binding of Isaac Rebirth/";
    const QFont _font = QFont("Droid Sans", 9);
#else
#error Platform not supported
    const QString _defaultPath = QString::null;
#endif

    QString _isaacPath = _defaultPath;
};

#endif // MAINWINDOW_H
