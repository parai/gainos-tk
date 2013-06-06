# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\github\gainos-tk\tool\gainos-studio\ui\forms\cd_select.ui'
#
# Created: Thu Jun 06 20:42:14 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_cd_select(object):
    def setupUi(self, cd_select):
        cd_select.setObjectName(_fromUtf8("cd_select"))
        cd_select.resize(326, 95)
        cd_select.setStyleSheet(_fromUtf8("font: 12pt \"Consolas\";"))
        self.cmbxSelect = QtGui.QComboBox(cd_select)
        self.cmbxSelect.setGeometry(QtCore.QRect(20, 20, 291, 22))
        self.cmbxSelect.setObjectName(_fromUtf8("cmbxSelect"))
        self.layoutWidget = QtGui.QWidget(cd_select)
        self.layoutWidget.setGeometry(QtCore.QRect(80, 60, 158, 29))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setMargin(0)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.btnYes = QtGui.QPushButton(self.layoutWidget)
        self.btnYes.setObjectName(_fromUtf8("btnYes"))
        self.horizontalLayout.addWidget(self.btnYes)
        self.btnNo = QtGui.QPushButton(self.layoutWidget)
        self.btnNo.setObjectName(_fromUtf8("btnNo"))
        self.horizontalLayout.addWidget(self.btnNo)

        self.retranslateUi(cd_select)
        QtCore.QMetaObject.connectSlotsByName(cd_select)

    def retranslateUi(self, cd_select):
        cd_select.setWindowTitle(QtGui.QApplication.translate("cd_select", "Dialog", None, QtGui.QApplication.UnicodeUTF8))
        self.btnYes.setText(QtGui.QApplication.translate("cd_select", "Yes", None, QtGui.QApplication.UnicodeUTF8))
        self.btnNo.setText(QtGui.QApplication.translate("cd_select", "No", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    cd_select = QtGui.QDialog()
    ui = Ui_cd_select()
    ui.setupUi(cd_select)
    cd_select.show()
    sys.exit(app.exec_())

