#!/bin/bash

echo '###################################################'
echo '#              Résultats des tests                #'
echo '###################################################'
echo ''

bin='../referencesCroisee'
resTemp='res_temp.txt'
state=0

########################################################################
#                           TEST N°1                                   #
########################################################################
${bin} -e -k 'key1.txt' 'file1.cpp' 'file1.h' | sort > ${resTemp}
hashValide=$(md5sum 'file1.res' | cut -d ' ' -f 1 )
hashTemp=$(md5sum ${resTemp} | cut -d ' ' -f 1 )

if [ "${hashValide}" == "${hashTemp}" ]
then
    echo 'Test N°1 : Réussi'
else
    echo 'Test N°1 : Echoué'
    state=1
fi

########################################################################
#                           TEST N°2                                   #
########################################################################
${bin} -k 'key2.txt' 'file2.cpp' 'file2.h' | sort > ${resTemp}
hashValide=$(md5sum 'file2.res' | cut -d ' ' -f 1 )
hashTemp=$(md5sum ${resTemp} | cut -d ' ' -f 1 )

if [ "${hashValide}" == "${hashTemp}" ]
then
    echo 'Test N°2 : Réussi'
else
    echo 'Test N°2 : Echoué'
    state=1
fi



########################################################################
#                           TEST N°3                                   #
########################################################################
${bin} 'file3.cpp' | sort > ${resTemp}
hashValide=$(md5sum 'file3.res' | cut -d ' ' -f 1 )
hashTemp=$(md5sum ${resTemp} | cut -d ' ' -f 1 )

if [ "${hashValide}" == "${hashTemp}" ]
then
    echo 'Test N°3 : Réussi'
else
    echo 'Test N°3 : Echoué'
    state=1
fi


########################################################################
#                           TEST N°4                                   #
########################################################################
${bin} -e 'file4.cpp' | sort > ${resTemp}
hashValide=$(md5sum 'file4.res' | cut -d ' ' -f 1 )
hashTemp=$(md5sum ${resTemp} | cut -d ' ' -f 1 )

if [ "${hashValide}" == "${hashTemp}" ]
then
    echo 'Test N°4 : Réussi'
else
    echo 'Test N°4 : Echoué'
    state=1
fi



rm -f ${resTemp}
exit ${state}
