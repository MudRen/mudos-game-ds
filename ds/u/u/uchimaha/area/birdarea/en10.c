#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short","�F�_�A�L");

 set("long",@LONG
�A�{�b�Ө쪰�W�ު��}�f, ��{���@�}�}���ƨ�,
�A�Pı���񦺮�I�I��, �n���H�ɷ|���i�Ȫ��O�o�ͤ@
��, �A���T���_�N��, �ߤ��Q�ۨ쩳�n���n�i�h�}�̩O?
�A���e��K�O���W���_�ޤF�C
 
LONG
    );
 
 set("exits",(["enter":__DIR__"en11",
               "southeast":__DIR__"en9",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
}           
