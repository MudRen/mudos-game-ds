#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void create()
{
 set("short","����");
 set("long",@LONG 
�o�ǬO�뤤���s���, ���F��ܰ����q�s�U���갣�s�骺�x
�L���ӿv����, ��D�`����T, �ӥB��W���\�h���b�����̭��i
�H�V�~�g�b, �ݨӫ�����i�h�K.
LONG);
 set("exits",([ 
                "northwest":__DIR__"bandit1",
    ]));
 set("objects", ([__DIR__"npc/archer" : 1+random(4),
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();

}

