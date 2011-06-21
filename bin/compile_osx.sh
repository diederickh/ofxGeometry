#!/bin/sh
set -x
d=${PWD}
bd=${d}/build

export PKG_CONFIG=${bd}/bin/pkg-config
export PKG_CONFIG_PATH=${bd}/lib/pkgconfig
export MACOSX_DEPLOYMENT_TARGET=10.6
#export CC="gcc-4.0"
ldflags="-arch i386 -L${bd}/lib/"
cppflags="-arch i386 -I${bd}/include"
cflags="-arch i386  -L${bd}/lib/"
export LDFLAGS=${ldflags}
export CFLAGS=${cflags}
export CPPFLAGS=${cppflags}
export PATH=${bd}/bin:${PATH}

# pkg-config
if [ ! -d ${bd} ] ; then
	mkdir ${bd}
fi

if [ ! -d pkg ] ; then 
	tar -zxvf pkg-config-0.23.tar.gz
	mv pkg-config-0.23 pkg
fi

if [ ! -f ${bd}/bin/pkg-config ] ; then 
	cd pkg
	./configure --prefix=${bd} --enable-libffi=no
	make 
	make install
fi	

# iconv
if [ ! -d iconv ] ; then
	tar -zxvf libiconv-1.13.1.tar.gz
	mv libiconv-1.13.1 iconv
fi

if [ ! -f ${bd}/bin/iconv ] ; then
	cd iconv
	./configure --prefix=${bd} --enable-static=yes
	make 
	make install
fi

# gettext
if [ ! -d gettext ] ; then
	tar -zxvf gettext.tgz
fi
if [ -d gettext-0.18.1.1 ] ; then
	mv gettext-0.18.1.1 gettext
fi
if [ ! -d ${bd}/share/gettext ] ; then 
	cd gettext
	./configure --prefix=${bd} --enable-static=yes
	make
	make install
fi

# glib
if [ ! -d glib ] ; then
	tar -zxvf glib-2.25.9.tar.gz
fi

if [ -d glib-2.25.9 ] ; then 
	mv glib-2.25.9 glib
fi

if [ ! -d ${bd}/lib/glib-2.0 ] ; then
	cd glib
	./configure --disable-dependency-tracking \
		--disable-dtrace --enable-static=yes \
		--prefix=${bd} CFLAGS="${cflags}" \
		LDFLAGS="${ldflags}" CPPFLAGS="${cppflags}"
	make 
	make install
fi

# gts
if [ ! -d gts ] ; then
	tar -zxvf gts-0.7.6.tar.gz
	mv gts-0.7.6 gts
fi
cd gts 
./configure --enable-static=yes --prefix=${bd}

