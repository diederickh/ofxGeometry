#!/bin/sh
set -x
if [ ! -d glib ] ; then
	mkdir glib
	mkdir gobject
	mkdir gts
	mkdir iconv
	mkdir intl
fi

function exar {
	lib="$1"
	d="$2"
	if [ ! -d ${d} ] ; then 
		mkdir ${d}
	fi
	cp "./${lib}" ${d}/
	cd ${d}
	ar -x ${lib}
	echo ${lib}
	cd ..
}

exar "libglib-2.0.a" "glib"
exar "libgobject-2.0.a" "gobject"
exar "libgts.a" "gts"
exar "libiconv.a" "iconv"
exar "libintl.a" "intl"


function createlib {
	cd ${2}
	ar rcs "../${1}" *.o
	cd ..
}

function removeLib {
	if [ -f ${1} ] ; then
		rm ${1}
	fi	
}

mylib="ofxGeometryLocale.a"
removeLib ${mylib}
createlib ${mylib} "iconv"
createlib ${mylib} "intl"

mylib="ofxGeometryGts.a"
removeLib ${mylib}
createlib ${mylib} "glib"
createlib ${mylib} "gobject"
createlib ${mylib} "gts"

