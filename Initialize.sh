ARCH=$(uname)

if [ "$ARCH" == "Linux" ]; then
	
	echo Initializing......

	export BOOST_ROOT=/usr/local/lib/boost_1_70_0
	OPENSSL_ROOT_DIR=/usr/local/ssl

	echo $BOOST_ROOT
	echo $OPENSSL_ROOT_DIR

fi