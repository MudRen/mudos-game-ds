#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���D"NOR);

 set("long",@LONG
�i�J��o�~���i��ѱ��w�b�@��, �A�o�{�o�̩M�ѱ��Z
�Ǥ@���@��, ��W���\�h������J��, �A�P�ɤ]�o�{�A���F�n�_
���O�@�����������D, ����h�O�A���i�ѱ�����.
LONG
    );
 set("exits",([ "east":__DIR__"pill3",
            "west":__DIR__"pill1",
            "north":__DIR__"walk1",
            "south":__DIR__"walk2",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 replace_program(ROOM);
}           
           

