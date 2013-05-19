# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'F:\parai@foxmail.com\github\gainos-tk\tool\gainos-studio\ui\forms\cd_add.ui'
#
# Created: Sun May 19 10:15:08 2013
#      by: PyQt4 UI code generator 4.8.3
#
# WARNING! All changes made in this file will be lost!

from PyQt4 import QtCore, QtGui

try:
    _fromUtf8 = QtCore.QString.fromUtf8
except AttributeError:
    _fromUtf8 = lambda s: s

class Ui_cd_add(object):
    def setupUi(self, cd_add):
        cd_add.setObjectName(_fromUtf8("cd_add"))
        cd_add.resize(258, 410)
        self.trModule = QtGui.QTreeWidget(cd_add)
        self.trModule.setGeometry(QtCore.QRect(20, 20, 221, 341))
        self.trModule.setObjectName(_fromUtf8("trModule"))
        self.layoutWidget = QtGui.QWidget(cd_add)
        self.layoutWidget.setGeometry(QtCore.QRect(40, 370, 158, 25))
        self.layoutWidget.setObjectName(_fromUtf8("layoutWidget"))
        self.horizontalLayout = QtGui.QHBoxLayout(self.layoutWidget)
        self.horizontalLayout.setMargin(0)
        self.horizontalLayout.setObjectName(_fromUtf8("horizontalLayout"))
        self.btnAdd = QtGui.QPushButton(self.layoutWidget)
        self.btnAdd.setObjectName(_fromUtf8("btnAdd"))
        self.horizontalLayout.addWidget(self.btnAdd)
        self.btnCancel = QtGui.QPushButton(self.layoutWidget)
        self.btnCancel.setObjectName(_fromUtf8("btnCancel"))
        self.horizontalLayout.addWidget(self.btnCancel)

        self.retranslateUi(cd_add)
        QtCore.QMetaObject.connectSlotsByName(cd_add)

    def retranslateUi(self, cd_add):
        cd_add.setWindowTitle(QtGui.QApplication.translate("cd_add", "Add Autosar Component", None, QtGui.QApplication.UnicodeUTF8))
        self.trModule.headerItem().setText(0, QtGui.QApplication.translate("cd_add", "Autosar Component", None, QtGui.QApplication.UnicodeUTF8))
        self.btnAdd.setText(QtGui.QApplication.translate("cd_add", "Add", None, QtGui.QApplication.UnicodeUTF8))
        self.btnCancel.setText(QtGui.QApplication.translate("cd_add", "Cancel", None, QtGui.QApplication.UnicodeUTF8))


if __name__ == "__main__":
    import sys
    app = QtGui.QApplication(sys.argv)
    cd_add = QtGui.QDialog()
    ui = Ui_cd_add()
    ui.setupUi(cd_add)
    cd_add.show()
    sys.exit(app.exec_())

