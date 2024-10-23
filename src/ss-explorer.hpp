#ifndef SS_EXPLORER_H
#define SS_EXPLORER_H

#include "ui_ss-explorer.h"
#include <QObject>
#include <QWidget>
#include <QDockWidget>
#include <QPushButton>
#include <QHboxLayout>
#include <QVboxLayout>
#include <QLabel>
#include <QPixmap>
#include <QVector>
#include <QDir>
#include <QFileInfoList>
#include <QFileSystemWatcher>
#include <QMouseEvent>
#include <QToolBar>
#include <QMessageBox>
#include <QThread>
#include <QString>
#include <QByteArray>
#include <Windows.h>
#include <Psapi.h>

class TestWidget : public QDockWidget {
	Q_OBJECT

public:
	explicit TestWidget(QWidget *parent = nullptr);
	~TestWidget();

	void mousePressEvent(QMouseEvent *event)
	{
		int _mainSceneWidth = parentWidget()->width();
		int _smallImgWidth = _mainSceneWidth / 4;
		int _mainSceneHeight = height();

		int _smallImgHeight = _mainSceneHeight / 4;
		QRect _rectSmallImg0(0, 0, _smallImgWidth, _smallImgHeight);
		QRect _rectSmallImg1(0, _smallImgHeight, _smallImgWidth,
				     _smallImgHeight);
		QRect _rectSmallImg2(0, 2 * _smallImgHeight, _smallImgWidth,
				     _smallImgHeight);
		QRect _rectSmallImg3(0, 3 * _smallImgHeight, _smallImgWidth,
				     _smallImgHeight);

		setMaximumWidth(_smallImgWidth);

		if (event->button() == Qt::LeftButton) {
			QPoint pos = event->pos();
			if (_rectSmallImg0.contains(pos)) {
				emit on_click_img0();
			}
			if (_rectSmallImg1.contains(pos)) {
				emit on_click_img1();
			}
			if (_rectSmallImg2.contains(pos)) {
				emit on_click_img2();
			}
			if (_rectSmallImg3.contains(pos)) {
				emit on_click_img3();
			}
		}

		QWidget::mousePressEvent(event);
	}

private:
	Ui::SSExplorer *ui;

	QWidget *parent = nullptr;

	QPushButton *_printBtn_ptr = nullptr;
	QPushButton *_cancelBtn_ptr = nullptr;
	QFileSystemWatcher *_Watcher_ptr = nullptr;

	QThread *_threadSmallImg0_ptr = nullptr;
	QThread *_threadSmallImg1_ptr = nullptr;
	QThread *_threadSmallImg2_ptr = nullptr;
	QThread *_threadSmallImg3_ptr = nullptr;

	QVector<QString> _listImgFilePath;
	QString _imgDir_str = "";

	int _smallImgStartIndex_in = 0;
	int _smallImgEndIndex_in = 0;
	int _imagesPerPage_in = 0;
	int _minScrollValue_in = 0;
	int _smallImageHeight_in = 0;
	int _maxScrollValue_in = 0;

	int _largeImgCurrIndex_in = 0;
	int _smallImg0CurrIndex_in = 0;
	int _smallImg1CurrIndex_in = 0;
	int _smallImg2CurrIndex_in = 0;
	int _smallImg3CurrIndex_in = 0;

protected:
	void GetLatestImgList(const QString ImgDir);
	void LoadLargeImg(const QString ImgFilePath);
	void LoadSmallImg0(const QString ImgFilePath);
	void LoadSmallImg1(const QString ImgFilePath);
	void LoadSmallImg2(const QString ImgFilePath);
	void LoadSmallImg3(const QString ImgFilePath);
	void CreateToolbar(QDockWidget *parent, const QString IconDir);
	void StartThreadLoadSmallImg0();
	void StartThreadLoadSmallImg1();
	void StartThreadLoadSmallImg2();
	void StartThreadLoadSmallImg3();
	LPCWSTR ConvertQString2LPCWSTR(const QString &qstr);
	void ClosePrintManagerWindows();

public slots:
	void showImageNumber();
	void on_click_img0();
	void on_click_img1();
	void on_click_img2();
	void on_click_img3();
	void on_scrollbar(int value);
	void on_print();
	void on_cancel();
	void on_automatic_update_img();
	void on_toggel_dock_widget();
	void ReloadSmallImg0();
	void ReloadSmallImg1();
	void ReloadSmallImg2();
	void ReloadSmallImg3();
};

#endif