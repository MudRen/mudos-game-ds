#include <ansi.h>
#include <room.h>
inherit ROOM; 
void create()
{
 set("short","���D");
 set("long",@LONG
�q�D�������ܼe�F�\�h�M�ӥB�ⰼ�}���W���o�O�]�h�F�_��
�M�ҥH�Y�K�O�����S�������M�A�٬O�i�H�M�����ݲM���񪺱��p
. �q�D�~��q���s�몺�`�B.
LONG);
 set("exits",([ 
                "west":__DIR__"bandit10", 
                "northeast":__DIR__"bandit8", 
    ]));

 set("no_clean_up",0);
 set("light",1);
 setup();

}

