#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;
void create()
{
 set("short",HIR"���"NOR);
 set("long",@LONG
�i�J��o�~���i��ѱ��M�Ĥ@��, �A�o�{�o�̩M�ѱ��Z
�Ǥ@���Q�����P, �o�̩���N�O�@���{�ɷf�ت����, �����
���]�S��, ���~�O�A���i�ѱ�����, �b�_��������Ū���n�Ǩ�.
LONG);
 set("exits",([ "out":__DIR__"pill1",
                "northeast":__DIR__"pill3",
    ]));
 set("no_clean_up",0);
 set("light",1);
 setup();
 create_door("out","�p���","enter",DOOR_CLOSED,"nokey");
}           


