#include "ss-explorer.hpp"

TestWidget::TestWidget(QWidget *parent)
	: QDockWidget(parent),
	  ui(new Ui::SSExplorer)
{
	this->parent = parent;

	ui->setupUi(this);

	if (_printBtn_ptr == nullptr) {
		_printBtn_ptr = new QPushButton("Print");
	}

	if (_cancelBtn_ptr == nullptr) {
		_cancelBtn_ptr = new QPushButton("Cancel");
	}

	if (_Watcher_ptr == nullptr) {
		_Watcher_ptr = new QFileSystemWatcher();
	}

	this->setTitleBarWidget(new QWidget());

	this->setMinimumSize(1200, 768);

	_imgDir_str = QString(CURRENT_SOURCE_DIR) + "\\images\\";

	_Watcher_ptr->addPath(_imgDir_str);

	GetLatestImgList(_imgDir_str);

	if (_listImgFilePath.isEmpty()) {
		QMessageBox::critical(
			nullptr, "Error",
			"Images folder is empty, please check!!!");
		return;
	}

	if (_listImgFilePath.size() >= 1) {
		LoadLargeImg(_listImgFilePath[0]);
		_largeImgCurrIndex_in = 0;
	}

	if (_listImgFilePath.size() >= 2) {
		LoadSmallImg0(_listImgFilePath[1]);
		_smallImg0CurrIndex_in = 1;
	}

	if (_listImgFilePath.size() >= 3) {
		LoadSmallImg1(_listImgFilePath[2]);
		_smallImg1CurrIndex_in = 2;
	}

	if (_listImgFilePath.size() >= 4) {
		LoadSmallImg2(_listImgFilePath[3]);
		_smallImg2CurrIndex_in = 3;
	}

	if (_listImgFilePath.size() >= 5) {
		LoadSmallImg3(_listImgFilePath[4]);
		_smallImg3CurrIndex_in = 4;
	}

	_smallImgStartIndex_in = 0;

	_imagesPerPage_in = 4;

	_minScrollValue_in = 0;

	_smallImageHeight_in = 162;

	_maxScrollValue_in = (_listImgFilePath.size() - _imagesPerPage_in) *
			     _smallImageHeight_in;

	ui->verticalScrollBar->setMaximum(_maxScrollValue_in);

	ui->verticalScrollBar->setRange(0, _maxScrollValue_in);

	connect(ui->verticalScrollBar, &QScrollBar::valueChanged, this,
		&TestWidget::on_scrollbar);

	connect(ui->printBtn, &QPushButton::clicked, this,
		&TestWidget::on_print);

	connect(ui->cancelBtn, &QPushButton::clicked, this,
		&TestWidget::on_cancel);

	connect(_Watcher_ptr, &QFileSystemWatcher::directoryChanged, this,
		&TestWidget::on_automatic_update_img);

	this->setVisible(false);

	this->setFloating(true);
}

void TestWidget::CreateToolbar(QDockWidget *parent, const QString IconDir)
{
	QDir iconDir(IconDir);

	QToolBar *toolbar = new QToolBar(parent);

	QAction *hideAction = new QAction(parent);
	QIcon hideIcon(iconDir.absolutePath() + "/icons/" + "hide.png");
	hideAction->setIcon(hideIcon);
	connect(hideAction, &QAction::triggered, parent, &QDockWidget::hide);
	toolbar->insertAction(nullptr, hideAction);

	QAction *minimizeAction = new QAction(parent);
	QIcon minimizeIcon(iconDir.absolutePath() + "/icons/" + "hide.png");
	minimizeAction->setIcon(minimizeIcon);
	connect(minimizeAction, &QAction::triggered, parent,
		&QDockWidget::showMinimized);
	toolbar->insertAction(nullptr, minimizeAction);

	QAction *closeAction = new QAction(parent);
	QIcon closeIcon(iconDir.absolutePath() + "/icons/" + "close.png");
	closeAction->setIcon(minimizeIcon);
	connect(closeAction, &QAction::triggered, parent, &QDockWidget::close);
	toolbar->insertAction(nullptr, closeAction);

	parent->setTitleBarWidget(toolbar);
}

TestWidget::~TestWidget()
{
	if (_printBtn_ptr != nullptr) {
		delete _printBtn_ptr;
		_printBtn_ptr = nullptr;
	}
	if (_cancelBtn_ptr != nullptr) {
		delete _cancelBtn_ptr;
		_cancelBtn_ptr = nullptr;
	}
	if (_Watcher_ptr != nullptr) {
		delete _Watcher_ptr;
		_Watcher_ptr = nullptr;
	}
	if (_threadSmallImg0_ptr != nullptr) {
		delete _threadSmallImg0_ptr;
		_threadSmallImg0_ptr = nullptr;
	}
	if (_threadSmallImg1_ptr != nullptr) {
		delete _threadSmallImg1_ptr;
		_threadSmallImg1_ptr = nullptr;
	}
	if (_threadSmallImg2_ptr != nullptr) {
		delete _threadSmallImg2_ptr;
		_threadSmallImg2_ptr = nullptr;
	}
	if (_threadSmallImg3_ptr != nullptr) {
		delete _threadSmallImg3_ptr;
		_threadSmallImg3_ptr = nullptr;
	}
	if (parent != nullptr) {
		delete parent;
		parent = nullptr;
	}
}

void TestWidget::GetLatestImgList(const QString ImgDir)
{
	QDir imgDir(ImgDir);

	QStringList filters;

	filters << "*.jpg"
		<< "*.png";

	QFileInfoList imgFileList = imgDir.entryInfoList(filters, QDir::Files);

	if (imgFileList.isEmpty()) {
		return;
	}

	// sort by newest modified
	std::sort(imgFileList.begin(), imgFileList.end(),
		  [](const QFileInfo &fileInfo1, const QFileInfo &fileInfo2) {
			  return fileInfo1.lastModified() >
				 fileInfo2.lastModified();
		  });

	QString imgFile = "";

	for (int i = 0; i < imgFileList.size(); ++i) {
		imgFile = imgDir.absolutePath() + "/" +
			  imgFileList.at(i).fileName();
		_listImgFilePath.push_back(imgFile);
	}
}

void TestWidget::LoadLargeImg(const QString ImgFilePath)
{
	QPixmap pixmap(ImgFilePath);

	if (pixmap.isNull()) {
		return;
	}

	ui->largeImg->setPixmap(pixmap.scaled(ui->largeImg->size(),
					      Qt::KeepAspectRatio,
					      Qt::SmoothTransformation));

	ui->largeImg->setScaledContents(true);
}

void TestWidget::LoadSmallImg0(const QString ImgFilePath)
{
	QPixmap pixmap(ImgFilePath);

	if (pixmap.isNull()) {
		return;
	}

	ui->smallImg0->setPixmap(pixmap.scaled(ui->smallImg0->size() / 2,
					       Qt::KeepAspectRatio,
					       Qt::SmoothTransformation));

	ui->smallImg0->setScaledContents(true);
}

void TestWidget::LoadSmallImg1(const QString ImgFilePath)
{
	QPixmap pixmap(ImgFilePath);

	if (pixmap.isNull()) {
		return;
	}

	ui->smallImg1->setPixmap(pixmap.scaled(ui->smallImg1->size() / 2,
					       Qt::KeepAspectRatio,
					       Qt::SmoothTransformation));

	ui->smallImg1->setScaledContents(true);
}

void TestWidget::LoadSmallImg2(const QString ImgFilePath)
{
	QPixmap pixmap(ImgFilePath);

	if (pixmap.isNull()) {
		return;
	}

	ui->smallImg2->setPixmap(pixmap.scaled(ui->smallImg2->size() / 2,
					       Qt::KeepAspectRatio,
					       Qt::SmoothTransformation));

	ui->smallImg2->setScaledContents(true);
}

void TestWidget::LoadSmallImg3(const QString ImgFilePath)
{
	QPixmap pixmap(ImgFilePath);

	if (pixmap.isNull()) {
		return;
	}

	ui->smallImg3->setPixmap(pixmap.scaled(ui->smallImg3->size() / 2,
					       Qt::KeepAspectRatio,
					       Qt::SmoothTransformation));

	ui->smallImg3->setScaledContents(true);
}

void TestWidget::showImageNumber() {}

void TestWidget::on_click_img0()
{
	LoadLargeImg(_listImgFilePath[_smallImg0CurrIndex_in]);
	_largeImgCurrIndex_in = _smallImg0CurrIndex_in;
}

void TestWidget::on_click_img1()
{
	LoadLargeImg(_listImgFilePath[_smallImg1CurrIndex_in]);
	_largeImgCurrIndex_in = _smallImg1CurrIndex_in;
}

void TestWidget::on_click_img2()
{
	LoadLargeImg(_listImgFilePath[_smallImg2CurrIndex_in]);
	_largeImgCurrIndex_in = _smallImg2CurrIndex_in;
}

void TestWidget::on_click_img3()
{
	LoadLargeImg(_listImgFilePath[_smallImg3CurrIndex_in]);
	_largeImgCurrIndex_in = _smallImg3CurrIndex_in;
}

void TestWidget::on_scrollbar(int value)
{
	_smallImgStartIndex_in = value / _smallImageHeight_in;

	_smallImgEndIndex_in = _smallImgStartIndex_in + _imagesPerPage_in - 1;

	StartThreadLoadSmallImg0();

	StartThreadLoadSmallImg1();

	StartThreadLoadSmallImg2();

	StartThreadLoadSmallImg3();
}

void TestWidget::StartThreadLoadSmallImg0()
{
	_threadSmallImg0_ptr = new QThread();

	if (_threadSmallImg0_ptr == nullptr) {
		return;
	}

	connect(_threadSmallImg0_ptr, &QThread::started, this,
		&TestWidget::ReloadSmallImg0);

	connect(_threadSmallImg0_ptr, &QThread::finished, _threadSmallImg0_ptr,
		&QObject::deleteLater);

	this->moveToThread(_threadSmallImg0_ptr);

	_threadSmallImg0_ptr->start();
}

void TestWidget::StartThreadLoadSmallImg1()
{
	_threadSmallImg1_ptr = new QThread();

	if (_threadSmallImg1_ptr == nullptr) {
		return;
	}

	connect(_threadSmallImg1_ptr, &QThread::started, this,
		&TestWidget::ReloadSmallImg1);

	connect(_threadSmallImg1_ptr, &QThread::finished, _threadSmallImg1_ptr,
		&QObject::deleteLater);

	this->moveToThread(_threadSmallImg1_ptr);

	_threadSmallImg1_ptr->start();
}

void TestWidget::StartThreadLoadSmallImg2()
{
	_threadSmallImg2_ptr = new QThread();

	if (_threadSmallImg2_ptr == nullptr) {
		return;
	}

	connect(_threadSmallImg2_ptr, &QThread::started, this,
		&TestWidget::ReloadSmallImg2);

	connect(_threadSmallImg2_ptr, &QThread::finished, _threadSmallImg2_ptr,
		&QObject::deleteLater);

	this->moveToThread(_threadSmallImg2_ptr);

	_threadSmallImg2_ptr->start();
}

void TestWidget::StartThreadLoadSmallImg3()
{
	_threadSmallImg3_ptr = new QThread();

	if (_threadSmallImg3_ptr == nullptr) {
		return;
	}

	connect(_threadSmallImg3_ptr, &QThread::started, this,
		&TestWidget::ReloadSmallImg3);

	connect(_threadSmallImg3_ptr, &QThread::finished, _threadSmallImg3_ptr,
		&QObject::deleteLater);

	this->moveToThread(_threadSmallImg3_ptr);

	_threadSmallImg3_ptr->start();
}

void TestWidget::ReloadSmallImg0()
{
	LoadSmallImg0(_listImgFilePath[_smallImgStartIndex_in]);
	_smallImg0CurrIndex_in = _smallImgStartIndex_in;
}

void TestWidget::ReloadSmallImg1()
{
	LoadSmallImg1(_listImgFilePath[_smallImgStartIndex_in + 1]);
	_smallImg1CurrIndex_in = _smallImgStartIndex_in + 1;
}

void TestWidget::ReloadSmallImg2()
{
	LoadSmallImg2(_listImgFilePath[_smallImgStartIndex_in + 2]);
	_smallImg2CurrIndex_in = _smallImgStartIndex_in + 2;
}

void TestWidget::ReloadSmallImg3()
{
	LoadSmallImg3(_listImgFilePath[_smallImgStartIndex_in + 3]);
	_smallImg3CurrIndex_in = _smallImgStartIndex_in + 3;
}

LPCWSTR TestWidget::ConvertQString2LPCWSTR(const QString &qstr)
{
	QByteArray ba = qstr.toUtf8();

	const char *utf8Str = ba.constData();

	int utf8Size = ba.size() + 1;

	int unicodeSize =
		MultiByteToWideChar(CP_UTF8, 0, utf8Str, utf8Size, NULL, 0);

	if (unicodeSize == 0) {
		return NULL;
	}

	wchar_t *unicodeStr = new wchar_t[unicodeSize];

	MultiByteToWideChar(CP_UTF8, 0, utf8Str, utf8Size, unicodeStr,
			    unicodeSize);

	return unicodeStr;
}

void TestWidget::on_print()
{
	QString imgFile = _listImgFilePath[_largeImgCurrIndex_in];

	if (imgFile.isEmpty()) {
		return;
	}

	LPCWSTR imagePath = ConvertQString2LPCWSTR(imgFile);

	LPCWSTR action_str = L"print";

	HINSTANCE result = ShellExecute(NULL, action_str, imagePath, NULL, NULL,
					SW_SHOWNORMAL);
}

void TestWidget::ClosePrintManagerWindows()
{
	HWND hWnd = FindWindow(NULL, NULL);

	while (hWnd) {
		DWORD processId;

		GetWindowThreadProcessId(hWnd, &processId);

		HANDLE hProcess =
			OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ,
				    FALSE, processId);

		if (hProcess != NULL) {
			WCHAR szProcessName[MAX_PATH];

			if (GetProcessImageFileName(hProcess, szProcessName,
						    MAX_PATH) != 0) {
				if (wcsstr(szProcessName, L"spoolsv.exe") !=
				    NULL) {
					PostMessage(hWnd, WM_CLOSE, 0, 0);
				}
			}
			CloseHandle(hProcess);
		}
		hWnd = FindWindowEx(NULL, hWnd, NULL, NULL);
	}
}

void TestWidget::on_cancel()
{
	ClosePrintManagerWindows();
}

void TestWidget::on_automatic_update_img()
{
	_listImgFilePath.clear();

	GetLatestImgList(_imgDir_str);

	if (_listImgFilePath.isEmpty()) {
		QMessageBox::critical(
			nullptr, "Error",
			"Images folder is empty, please check!!!");
		return;
	}

	if (_listImgFilePath.size() >= 1) {
		LoadLargeImg(_listImgFilePath[0]);
		_largeImgCurrIndex_in = 0;
	}

	if (_listImgFilePath.size() >= 2) {
		LoadSmallImg0(_listImgFilePath[1]);
		_smallImg0CurrIndex_in = 1;
	}

	if (_listImgFilePath.size() >= 3) {
		LoadSmallImg1(_listImgFilePath[2]);
		_smallImg1CurrIndex_in = 2;
	}

	if (_listImgFilePath.size() >= 4) {
		LoadSmallImg2(_listImgFilePath[3]);
		_smallImg2CurrIndex_in = 3;
	}

	if (_listImgFilePath.size() >= 5) {
		LoadSmallImg3(_listImgFilePath[4]);
		_smallImg3CurrIndex_in = 4;
	}
}

void TestWidget::on_toggel_dock_widget()
{
	this->close();
}