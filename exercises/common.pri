# required by qDebug()
CONFIG += debug

win32 {
	MOC_DIR = _moc
	UI_DIR = _ui
	OBJECTS_DIR = _obj
} else {
	MOC_DIR = .moc
	UI_DIR = .ui
	OBJECTS_DIR = .obj
}

# valid for TEMPLATE=app projects only
app {
	DESTDIR=$$OUT_PWD

	mac {
		CONFIG -= app_bundle
	}

	win32 {
		CONFIG += console
	}
}
