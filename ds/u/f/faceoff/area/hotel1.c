#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{


 set("short", HIG"�s���ȴ�"NOR);
set("long", @LONG
�o�O�ߤ@�@�a�b�s���̹D�Y�a�H���٦s�d���ȴ�, �b�s
���̹D�_���H��, ��Ǫ��ȴ̦]���ӥ��ƭ˳�, �p���o����
�̤]�u�O�a�ۦ��d�Q�U�j�s���C�Ⱥ��ͤF....
LONG
        );
 set("exits",([ "east":__DIR__"ten_mountain9", 
    ]));
 set("objects", ([__DIR__"npc/waiter" : 1,
    ]));
set("valid_startroom", 1);
set("no_clean_up",0);
set("no_fight",1);
 set("no_fight", 1);
 set("light",1);
 setup();
 replace_program(ROOM);
}
