#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","���D");
 set("long",@LONG 
�q�D�������ܼe�F�\�h�M�ӥB�ⰼ�}���W���o�O�]�h�F�_��
, �ҥH�Y�K�O�����S�������M�A�٬O�i�H�M�����ݲM���񪺱��p
. �q�D�~��q���s�몺�`�B. ���F�n����V���G�٦����p��.
LONG);
 set("exits",([ 
                "northwest":__DIR__"bandit7", 
                "southwest":__DIR__"bandit9",  
    ]));
 set("hide_exits", ([ "southeast" : __DIR__"bandit12" ]));

 set("no_clean_up",0);
 set("light",1);
 setup();

}

