#include "APIGUIWindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QScrollArea>
#include <QGroupBox>
#include <QMessageBox>
#include <QFileDialog>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <QFile>
#include <QApplication>
#include <QDesktopServices>
#include <QUrl>
#include <QPrinter>
#include <QPainter>
#include <QDate>

APIGUIWindow::APIGUIWindow(QWidget *parent)
    : QMainWindow(parent), centralWidget(nullptr), mainSplitter(nullptr),
      sidebarWidget(nullptr), menuList(nullptr), categoryList(nullptr),
      contentWidget(nullptr), searchBox(nullptr), cardsContainer(nullptr),
      apiCardsList(nullptr), detailsPanel(nullptr), currentCategory("All")
{
    setWindowTitle("LunaLite API Reference");
    setWindowIcon(QIcon(":/images/lunalite_icon.png"));
    setGeometry(100, 100, 1400, 800);
    
    // Initialize styling
    setupStylesheet();
    
    // Setup UI
    initializeUI();
    
    // Load API data
    loadAPIData();
    
    // Populate components
    populateMenu();
    populateAPICards();
    createCategoryButtons();
    
    // Setup connections
    setupConnections();
    
    // Show welcome message
    displayClassDoc("Welcome to LunaLite API Reference");
}

APIGUIWindow::~APIGUIWindow() {
}

void APIGUIWindow::setupStylesheet() {
    // RPG Maker MZ Color Palette
    QString stylesheet = R"(
        QMainWindow {
            background-color: #0f0f1e;
        }
        
        QWidget {
            background-color: #0f0f1e;
            color: #e8e8e8;
        }
        
        /* Header Styling */
        #headerFrame {
            background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, 
                                       stop: 0 #2a2a5a, stop: 1 #1a1a3a);
            border-bottom: 3px solid #c69c6d;
        }
        
        #titleLabel {
            color: #c69c6d;
            font-size: 24px;
            font-weight: bold;
            text-shadow: 2px 2px 4px rgba(0, 0, 0, 0.8);
        }
        
        #subtitleLabel {
            color: #a0a0a0;
            font-size: 12px;
            font-style: italic;
        }
        
        /* Window Frames */
        QGroupBox {
            background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, 
                                       stop: 0 #2a2a4a, stop: 1 #1f1f3a);
            border: 3px solid;
            border-color: #606098 #202038 #202038 #606098;
            border-radius: 0px;
            margin-top: 10px;
            padding-top: 15px;
            font-weight: bold;
            color: #c69c6d;
        }
        
        QGroupBox::title {
            subcontrol-origin: margin;
            left: 10px;
            padding: 0 3px 0 3px;
            background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, 
                                       stop: 0 #4a7aaa, stop: 1 #3a5a8a);
            color: #c69c6d;
            text-shadow: 1px 1px 2px rgba(0, 0, 0, 0.7);
            padding: 5px 10px;
        }
        
        /* List Widgets */
        QListWidget {
            background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, 
                                       stop: 0 #2a2a4a, stop: 1 #1f1f3a);
            border: 3px solid;
            border-color: #606098 #202038 #202038 #606098;
            color: #e8e8e8;
            outline: 0;
        }
        
        QListWidget::item {
            padding: 8px 5px;
            border-bottom: 1px solid rgba(100, 100, 150, 0.3);
        }
        
        QListWidget::item:hover {
            background-color: rgba(74, 122, 170, 0.3);
            color: #c69c6d;
        }
        
        QListWidget::item:selected {
            background-color: rgba(74, 122, 170, 0.6);
            color: #c69c6d;
            font-weight: bold;
            border-left: 3px solid #c69c6d;
            padding-left: 2px;
        }
        
        /* Text Edit */
        QTextEdit {
            background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 1, 
                                       stop: 0 #1a1a3a, stop: 1 #232350);
            border: 2px solid #606098;
            color: #e8e8e8;
            padding: 10px;
        }
        
        /* Line Edit (Search Box) */
        QLineEdit {
            background-color: #1a1a3a;
            border: 2px solid #606098;
            border-radius: 3px;
            color: #e8e8e8;
            padding: 5px 10px;
            font-size: 11px;
        }
        
        QLineEdit:focus {
            border: 2px solid #4a7aaa;
            background-color: #232350;
        }
        
        /* Push Buttons */
        QPushButton {
            background: qlineargradient(to bottom, #3a4a6a, #2a3a5a);
            color: #e8e8e8;
            border: 2px solid #606098;
            border-radius: 3px;
            padding: 8px 15px;
            font-weight: bold;
            text-align: center;
        }
        
        QPushButton:hover {
            background: qlineargradient(to bottom, #4a5a7a, #3a4a6a);
            border-color: #4a7aaa;
            color: #c69c6d;
            box-shadow: 0 0 8px rgba(74, 122, 170, 0.4);
        }
        
        QPushButton:pressed {
            background: qlineargradient(to bottom, #2a3a5a, #1a2a4a);
            border-color: #c69c6d;
        }
        
        /* Scrollbar */
        QScrollBar:vertical {
            background-color: #0f0f1e;
            width: 12px;
            border: none;
        }
        
        QScrollBar::handle:vertical {
            background-color: #4a7aaa;
            border-radius: 6px;
            min-height: 20px;
        }
        
        QScrollBar::handle:vertical:hover {
            background-color: #6a9acc;
        }
        
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            background: none;
        }
        
        /* Status Bar */
        QStatusBar {
            background: qlineargradient(to right, #2a2a4a, #1a1a3a);
            color: #a0a0a0;
            border-top: 2px solid #606098;
        }
    )";
    
    qApp->setStyleSheet(stylesheet);
}

void APIGUIWindow::initializeUI() {
    // Create central widget
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);
    
    // Create main layout
    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);
    
    // Create header
    QWidget *headerFrame = new QWidget();
    headerFrame->setObjectName("headerFrame");
    headerFrame->setStyleSheet("background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #2a2a5a, stop: 1 #1a1a3a); border-bottom: 3px solid #c69c6d;");
    headerFrame->setMaximumHeight(100);
    
    QVBoxLayout *headerLayout = new QVBoxLayout(headerFrame);
    headerLayout->setContentsMargins(20, 20, 20, 20);
    
    QLabel *titleLabel = new QLabel("LunaLite API Reference");
    titleLabel->setObjectName("titleLabel");
    titleLabel->setStyleSheet("color: #c69c6d; font-size: 28px; font-weight: bold;");
    
    QLabel *subtitleLabel = new QLabel("RPG Maker MZ & MV Documentation");
    subtitleLabel->setObjectName("subtitleLabel");
    subtitleLabel->setStyleSheet("color: #a0a0a0; font-size: 11px; font-style: italic;");
    
    headerLayout->addWidget(titleLabel);
    headerLayout->addWidget(subtitleLabel);
    headerLayout->addStretch();
    
    mainLayout->addWidget(headerFrame);
    
    // Create main content splitter
    mainSplitter = new QSplitter(Qt::Horizontal);
    
    // Create sidebar
    sidebarWidget = new QWidget();
    QVBoxLayout *sidebarLayout = new QVBoxLayout(sidebarWidget);
    sidebarLayout->setContentsMargins(0, 10, 10, 10);
    sidebarLayout->setSpacing(15);
    
    // Navigation group
    QGroupBox *navGroup = new QGroupBox("Navigation");
    QVBoxLayout *navLayout = new QVBoxLayout(navGroup);
    menuList = new QListWidget();
    menuList->setMaximumHeight(200);
    navLayout->addWidget(menuList);
    sidebarLayout->addWidget(navGroup);
    
    // Categories group
    QGroupBox *catGroup = new QGroupBox("Categories");
    QVBoxLayout *catLayout = new QVBoxLayout(catGroup);
    categoryList = new QListWidget();
    categoryList->setMaximumHeight(250);
    catLayout->addWidget(categoryList);
    sidebarLayout->addWidget(catGroup);
    
    sidebarLayout->addStretch();
    
    // Create content area
    contentWidget = new QWidget();
    QVBoxLayout *contentLayout = new QVBoxLayout(contentWidget);
    contentLayout->setContentsMargins(10, 10, 10, 10);
    contentLayout->setSpacing(10);
    
    // Search box
    QHBoxLayout *searchLayout = new QHBoxLayout();
    QLabel *searchLabel = new QLabel("Search:");
    searchLabel->setStyleSheet("color: #c69c6d; font-weight: bold;");
    searchBox = new QLineEdit();
    searchBox->setPlaceholderText("Search API classes and methods...");
    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(searchBox);
    contentLayout->addLayout(searchLayout);
    
    // API Cards list
    apiCardsList = new QListWidget();
    contentLayout->addWidget(apiCardsList);
    
    // Details panel
    QLabel *detailsLabel = new QLabel("Details");
    detailsLabel->setStyleSheet("color: #c69c6d; font-weight: bold; font-size: 12px;");
    detailsPanel = new QTextEdit();
    detailsPanel->setReadOnly(true);
    detailsPanel->setMaximumHeight(150);
    contentLayout->addWidget(detailsLabel);
    contentLayout->addWidget(detailsPanel);
    
    // Buttons layout
    QHBoxLayout *buttonsLayout = new QHBoxLayout();
    exportBtn = new QPushButton("Export to JSON");
    printBtn = new QPushButton("Print");
    aboutBtn = new QPushButton("About");
    
    buttonsLayout->addStretch();
    buttonsLayout->addWidget(exportBtn);
    buttonsLayout->addWidget(printBtn);
    buttonsLayout->addWidget(aboutBtn);
    contentLayout->addLayout(buttonsLayout);
    
    // Add to splitter
    mainSplitter->addWidget(sidebarWidget);
    mainSplitter->addWidget(contentWidget);
    mainSplitter->setStretchFactor(0, 1);
    mainSplitter->setStretchFactor(1, 2);
    mainSplitter->setCollapsible(0, false);
    
    mainLayout->addWidget(mainSplitter, 1);
    
    // Create status bar
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);
    
    QLabel *classCountLabel = new QLabel("Classes: 50+");
    QLabel *methodCountLabel = new QLabel("Methods: 500+");
    QLabel *versionLabel = new QLabel("Version: 1.0.0");
    QLabel *statusLabel = new QLabel("Status: Online");
    statusLabel->setStyleSheet("color: #6aff6a;");
    
    statusBar->addWidget(classCountLabel);
    statusBar->addPermanentWidget(methodCountLabel);
    statusBar->addPermanentWidget(versionLabel);
    statusBar->addPermanentWidget(statusLabel);
}

void APIGUIWindow::populateMenu() {
    QStringList menuItems;
    menuItems << "Classes" << "Interfaces" << "Enumerations" 
              << "Modules" << "Global Functions" << "Search API";
    
    for (const QString &item : menuItems) {
        menuList->addItem(item);
    }
}

void APIGUIWindow::populateAPICards() {
    // Sample API data
    struct CardData {
        QString name;
        QString description;
        QString type;
    };
    
    QList<CardData> cards = {
        {"Graphics", "The rendering system for visual content with resolution and scaling support.", "Core"},
        {"AudioManager", "Audio playback system for BGM, SFX, and ME audio files.", "Audio"},
        {"Input", "Keyboard, gamepad, and touch input handling.", "Input"},
        {"SceneManager", "Scene initialization and management system.", "System"},
        {"Sprite", "PIXI sprite wrapper with animation support.", "Graphics"},
        {"Window", "Base window class for UI elements with selectable content.", "UI"},
        {"Bitmap", "Image data structure with drawing capabilities.", "Graphics"},
        {"DataManager", "Manages game data loading and storage.", "System"},
        {"CacheEntry", "Cache entry system for efficient resource management.", "Utils"},
        {"TouchInput", "Touch and mouse input handling system.", "Input"}
    };
    
    apiCardsList->clear();
    for (const CardData &card : cards) {
        QString itemText = QString("%1\n%2").arg(card.name, card.description.mid(0, 50) + "...");
        apiCardsList->addItem(itemText);
    }
}

void APIGUIWindow::createCategoryButtons() {
    QStringList categories = {"Graphics", "Audio", "Input", "Game Objects", "Scenes & Windows", "Utils"};
    
    categoryList->clear();
    for (const QString &category : categories) {
        categoryList->addItem(category);
    }
}

void APIGUIWindow::setupConnections() {
    connect(menuList, &QListWidget::itemClicked, this, &APIGUIWindow::onMenuItemClicked);
    connect(apiCardsList, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        displayClassDoc(item->text().split('\n')[0]);
    });
    connect(categoryList, &QListWidget::itemClicked, this, [this](QListWidgetItem *item) {
        filterByCategory(item->text());
    });
    connect(searchBox, &QLineEdit::textChanged, this, &APIGUIWindow::onSearchTextChanged);
    connect(exportBtn, &QPushButton::clicked, this, &APIGUIWindow::exportToJSON);
    connect(printBtn, &QPushButton::clicked, this, &APIGUIWindow::printView);
    connect(aboutBtn, &QPushButton::clicked, this, &APIGUIWindow::showAboutDialog);
}

void APIGUIWindow::onMenuItemClicked(QListWidgetItem *item) {
    QString menuItem = item->text();
    displayClassDoc(menuItem);
}

void APIGUIWindow::onSearchTextChanged(const QString &text) {
    currentSearchText = text;
    
    if (text.isEmpty()) {
        populateAPICards();
        return;
    }
    
    // Filter cards based on search text
    QString lowerText = text.toLower();
    apiCardsList->clear();
    
    for (int i = 0; i < apiCardsList->count(); ++i) {
        QListWidgetItem *item = apiCardsList->item(i);
        if (item && item->text().toLower().contains(lowerText)) {
            apiCardsList->addItem(item);
        }
    }
}

void APIGUIWindow::filterByCategory(const QString &category) {
    currentCategory = category;
    detailsPanel->setText(QString("\n--- Category: %1 ---\n\nShowing items from the %1 category.\n").arg(category));
}

void APIGUIWindow::displayClassDoc(const QString &className) {
    QString documentation = QString(
        "<h2 style='color: #c69c6d;'>%1</h2>"
        "<p style='color: #e8e8e8;'>"
        "This is the documentation for the %1 class.<br><br>"
        "<b>Description:</b> Core component of the LunaLite API.<br><br>"
        "<b>Methods:</b><br>"
        "• initialize()<br>"
        "• update()<br>"
        "• draw()<br><br>"
        "<b>Properties:</b><br>"
        "• width: number<br>"
        "• height: number<br>"
        "• visible: boolean"
        "</p>"
    ).arg(className);
    
    detailsPanel->setHtml(documentation);
}

void APIGUIWindow::exportToJSON() {
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Export API Reference"), "",
        tr("JSON Files (*.json);;All Files (*)"));
    
    if (fileName.isEmpty()) return;
    
    QJsonArray classesArray;
    for (int i = 0; i < apiCardsList->count(); ++i) {
        QListWidgetItem *item = apiCardsList->item(i);
        if (item) {
            QString text = item->text();
            QStringList parts = text.split('\n');
            
            QJsonObject classObj;
            classObj["name"] = parts[0];
            if (parts.size() > 1) {
                classObj["description"] = parts[1];
            }
            classesArray.append(classObj);
        }
    }
    
    QJsonObject root;
    root["version"] = "1.0.0";
    root["classes"] = classesArray;
    root["timestamp"] = QDate::currentDate().toString();
    
    QJsonDocument doc(root);
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        file.write(doc.toJson());
        file.close();
        QMessageBox::information(this, "Success", "API reference exported successfully!");
    }
}

void APIGUIWindow::printView() {
    QPrinter printer;
    printer.setPageSize(QPrinter::A4);
    
    QPainter painter(&printer);
    if (!painter.isActive()) {
        QMessageBox::warning(this, "Error", "Failed to initialize printer.");
        return;
    }
    
    painter.drawText(100, 100, "LunaLite API Reference");
    painter.drawText(100, 150, detailsPanel->toPlainText());
    
    painter.end();
    QMessageBox::information(this, "Success", "Document printed successfully!");
}

void APIGUIWindow::showAboutDialog() {
    QMessageBox::about(this, "About LunaLite API Reference",
        "<h2>LunaLite API Reference</h2>"
        "<p>Version 1.0.0</p>"
        "<p>A comprehensive API documentation viewer for RPG Maker MZ & MV.</p>"
        "<p>Built with Qt C++ Framework</p>"
        "<p><b>Features:</b></p>"
        "<ul>"
        "<li>Browse all available classes and methods</li>"
        "<li>Search functionality</li>"
        "<li>Export to JSON</li>"
        "<li>Print documentation</li>"
        "<li>Native desktop application</li>"
        "</ul>"
        "<p>&copy; 2024 LunaLite Team</p>");
}

void APIGUIWindow::closeEvent(QCloseEvent *event) {
    QMessageBox::StandardButton reply = QMessageBox::question(this,
        "Confirm Exit", "Are you sure you want to exit?",
        QMessageBox::Yes | QMessageBox::No);
    
    if (reply == QMessageBox::Yes) {
        event->accept();
    } else {
        event->ignore();
    }
}

void APIGUIWindow::loadAPIData() {
    // Load API data from definition files
    // This would typically load from the .d.ts files in the definitions folder
}

void APIGUIWindow::onCategoryClicked() {
    // Handle category button clicks
}
