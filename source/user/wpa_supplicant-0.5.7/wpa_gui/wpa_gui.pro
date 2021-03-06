TEMPLATE	= app
LANGUAGE	= C++

CONFIG	+= qt warn_on release

DEFINES += CONFIG_CTRL_IFACE

win32 {
  LIBS += -lws2_32 -static
  DEFINES += CONFIG_NATIVE_WINDOWS CONFIG_CTRL_IFACE_NAMED_PIPE
} else:win32-g++ {
  # cross compilation to win32
  LIBS += -lws2_32 -static
  DEFINES += CONFIG_NATIVE_WINDOWS CONFIG_CTRL_IFACE_NAMED_PIPE
} else {
  DEFINES += CONFIG_CTRL_IFACE_UNIX
}

INCLUDEPATH	+= . .. ../../hostapd

HEADERS	+= wpamsg.h

SOURCES	+= main.cpp \
	../wpa_ctrl.c

FORMS	= wpagui.ui \
	eventhistory.ui \
	scanresults.ui \
	userdatarequest.ui \
	networkconfig.ui


unix {
  UI_DIR = .ui
  MOC_DIR = .moc
  OBJECTS_DIR = .obj
}

qtver = $$[QT_VERSION]
isEmpty( qtver ) {
	message(Compiling for Qt 3.x)
	DEFINES += Q3ListViewItem=QListViewItem
} else {
	message(Compiling for Qt $$qtver)
	QT += qt3support
	CONFIG += uic3
}
