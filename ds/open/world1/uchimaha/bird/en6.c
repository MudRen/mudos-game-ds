#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A�{�b�Ө�F�_�A�L���`�B, �|�P�@�����t, �Ů�
�����@�ѷ÷ê��Pı, �O�H�Q�������ΪA, �A��F��|
�P, ���h��Ƥ��M, �A�����������ݨ�o�������F�_
�詵���U�h�C
LONG
    );
 
 set("exits",(["west":__DIR__"en5",
               "south":__DIR__"en4",
               "northeast":__DIR__"en7",
     ]));
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}           
