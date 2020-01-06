{\rtf1\ansi\ansicpg1252\cocoartf1671\cocoasubrtf600
{\fonttbl\f0\fnil\fcharset0 Menlo-Regular;}
{\colortbl;\red255\green255\blue255;\red219\green39\blue218;\red202\green51\blue35;\red0\green0\blue0;
\red57\green192\blue38;\red209\green113\blue37;}
{\*\expandedcolortbl;;\cssrgb\c89513\c29738\c88483;\cssrgb\c83898\c28665\c18024;\csgray\c0;
\cssrgb\c25704\c77963\c19556;\cssrgb\c85991\c52029\c18734;}
\paperw11900\paperh16840\margl1440\margr1440\vieww28600\viewh16580\viewkind0
\pard\tx560\tx1120\tx1680\tx2240\tx2800\tx3360\tx3920\tx4480\tx5040\tx5600\tx6160\tx6720\pardirnatural\partightenfactor0

\f0\fs22 \cf2 \CocoaLigature0 #include\cf3 <linux/kernel.h>\cf4 \
\cf2 #include\cf3 <linux/syscalls.h>\cf4 \
\cf2 #include\cf3 <uapi/linux/errno.h>\cf4 \
\
SYSCALL_DEFINE2(sys_s2_encrypt,\cf5 char\cf4  *, ch, \cf5 int\cf4 , n)\
\{\
        \cf6 if\cf4 ((n>=\cf3 1\cf4 ) && (n<=\cf3 5\cf4 ))\
        \{\
        \cf5 int\cf4  length = \cf3 0\cf4 ;\
        \cf5 int\cf4  i=\cf3 0\cf4 ;\
        \cf6 while\cf4  (*(ch)!=\cf2 '\\0'\cf4 )\
        \{\
                length = length + \cf3 1\cf4 ;\
                ch++;\
        \}\
\
        \cf6 for\cf4 (i=\cf3 0\cf4 ;i<=length+1;i++)\
        \{\
                *(ch) = *(ch) + n;\
                \cf6 if\cf4 ((*(ch)<\cf3 'a'\cf4 ) && (*(ch)>\cf3 'Z'\cf4 ))\
                \{\
                        *(ch)=*(ch) + n -\cf3 26\cf4 ;\
                \}\
\
                \cf6 if\cf4 ((*(ch))>\cf3 'z'\cf4 )\
                \{\
                        *(ch)=*(ch)-\cf3 26\cf4 ;\
                \}\
                ch--;\
                printk(\cf3 "\cf2 %s\cf3 "\cf4 , ch);\
        \}\
        \cf6 return\cf4  \cf3 0\cf4 ;\
        \}\
        \cf6 else\cf4 \
        \{\
                printk(\cf3 "Values out of  bound"\cf4 );\
                \cf6 return\cf4  \cf3 EINVAL\cf4 ;\
        \}\
\}}