#!/bin/bash -ex

if [ $# -lt 5 ] ; then
    echo "Usage: $0 basedir outdir releasedir commit host"
    exit 1
fi

BASEDIR=$1
OUTDIR=$2
RELEASEBASE=$3
COMMIT=$4
HOST=$5

RELEASEDIR=$BASEDIR/$RELEASEBASE/$COMMIT/$HOST

mkdir -p $RELEASEDIR

if [ -d "$OUTDIR" ]; then
  cp $OUTDIR/bin/* $RELEASEDIR/
fi

count=`ls -1 *.dmg 2>/dev/null | wc -l`
if [ $count != 0 ]
then 
# MaxOSX artifacts
cp -a *.dmg $RELEASEDIR || true
fi

count=`ls -1 *.exe 2>/dev/null | wc -l`
if [ $count != 0 ]
then 
# Windows artifacts
cp -a *.exe $RELEASEDIR || true
fi 

tar -cvzf package-$HOST.tgz $RELEASEDIR
