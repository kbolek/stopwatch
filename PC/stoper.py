# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'stoper.ui'
#
# Created by: PyQt5 UI code generator 5.15.4
#
# WARNING: Any manual changes made to this file will be lost when pyuic5 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(474, 473)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.start_button = QtWidgets.QPushButton(self.centralwidget)
        self.start_button.setGeometry(QtCore.QRect(160, 260, 131, 51))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(10)
        self.start_button.setFont(font)
        self.start_button.setObjectName("start_button")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(70, 380, 311, 31))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(8)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.hours = QtWidgets.QLabel(self.centralwidget)
        self.hours.setGeometry(QtCore.QRect(40, 100, 101, 91))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(55)
        self.hours.setFont(font)
        self.hours.setObjectName("hours")
        self.minutes = QtWidgets.QLabel(self.centralwidget)
        self.minutes.setGeometry(QtCore.QRect(170, 100, 101, 91))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(55)
        self.minutes.setFont(font)
        self.minutes.setObjectName("minutes")
        self.seconds = QtWidgets.QLabel(self.centralwidget)
        self.seconds.setGeometry(QtCore.QRect(300, 100, 101, 91))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(55)
        self.seconds.setFont(font)
        self.seconds.setObjectName("seconds")
        self.colon = QtWidgets.QLabel(self.centralwidget)
        self.colon.setGeometry(QtCore.QRect(140, 110, 91, 61))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(55)
        self.colon.setFont(font)
        self.colon.setObjectName("colon")
        self.colon_2 = QtWidgets.QLabel(self.centralwidget)
        self.colon_2.setGeometry(QtCore.QRect(270, 110, 91, 61))
        font = QtGui.QFont()
        font.setFamily("Arial")
        font.setPointSize(55)
        self.colon_2.setFont(font)
        self.colon_2.setObjectName("colon_2")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 474, 26))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.start_button.setText(_translate("MainWindow", "Start"))
        self.label.setText(_translate("MainWindow", "Stoper project by Dominik Chat & Krzysztof Bolek"))
        self.hours.setText(_translate("MainWindow", "00"))
        self.minutes.setText(_translate("MainWindow", "00"))
        self.seconds.setText(_translate("MainWindow", "00"))
        self.colon.setText(_translate("MainWindow", ":"))
        self.colon_2.setText(_translate("MainWindow", ":"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MainWindow = QtWidgets.QMainWindow()
    ui = Ui_MainWindow()
    ui.setupUi(MainWindow)
    MainWindow.show()
    sys.exit(app.exec_())
