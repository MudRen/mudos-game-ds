#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���h��"NOR);

 set("long",@LONG
�o�̴N�O�ۦW�Z�L�����h�ӤF, �o�̦����O�@�Ǭݯ}�@��
�����~���h, �ѩ�ѱ����L�����W�]���ˤ]�S����L�Z�L���H�|
�ӳo�����Z, �ӱL��k�]���L�ݳo�̪���, �ҥH���B��O���~��
�Ѱ�.
LONG
    );
 set("exits",([ "east":__DIR__"woodhouse1",
                "west":__DIR__"eastroad2",
                "south":__DIR__"woodhouse2",
                "north":__DIR__"eastroad4",
    ]));
set("no_clean_up",0);
set("light",1);
 setup();
 replace_program(ROOM);
}
