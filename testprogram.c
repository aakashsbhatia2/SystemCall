{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\fswiss\fcharset0 Helvetica;\f1\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red0\green0\blue0;\red219\green39\blue218;\red202\green51\blue35;
\red57\green192\blue38;\red209\green113\blue37;}
{\*\expandedcolortbl;;\csgray\c0;\cssrgb\c89513\c29738\c88483;\cssrgb\c83898\c28665\c18024;
\cssrgb\c25704\c77963\c19556;\cssrgb\c85991\c52029\c18734;}
\paperw11900\paperh16840\margl1440\margr1440\vieww28600\viewh16580\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #i
\f1\fs22 \cf2 \CocoaLigature0 nclude <unistd.h>\
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0
\cf3 #include \cf4 <stdio.h>\cf2 \
\cf3 #include \cf4 <stdlib.h>\cf2 \
\cf3 #include \cf4 <errno.h>\cf2 \
\cf3 #include \cf4 <sys/syscall.h>\cf2 \
\cf3 #include \cf4 <string.h>\cf2 \
\cf3 #include \cf4 <linux/kernel.h>\cf2 \
\cf3 #include \cf4 <getopt.h>\cf2 \
\
\cf5 int\cf2  main (\cf5 int\cf2  n, \cf5 char\cf2  *ch[])\
\{\
        \cf5 int\cf2  sork;\
        \cf5 char\cf2  s[\cf4 50\cf2 ];\
        \cf5 int\cf2  k;\
        \cf6 while\cf2  ((sork = getopt(n,ch,\cf4 "s:k:"\cf2 )) != -\cf4 1\cf2 )\
        \{\
                \cf6 switch\cf2 (sork)\
                \{\
                        \cf6 case\cf2  \cf4 's'\cf2 :\
                                strcpy(s,optarg);\
                                \cf6 break\cf2 ;\
                        \cf6 case\cf2  \cf4 'k'\cf2 :\
                                k = atoi(optarg);\
                                \cf6 break\cf2 ;\
                        \cf6 default\cf2 :\
                                printf(\cf4 \'93Error in input\'93\cf2 );\
							  break;\
                \}\
        \}\
        \cf5 int\cf2  x = syscall(\cf4 335\cf2 , s, k);\
        \cf6 return\cf2  \cf4 0\cf2 ;\
\}\
}