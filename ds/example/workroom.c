#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIR"���y�u�@��"NOR);

 set("long",@LONG
�A�o�{�o�̰��F�@�Ӥj�j������d�M�@�ӨF�o�H�~�@�L�Ҧ�, 
�A���T�ôb�o�̦��H�ζ�?......
LONG
    );
 set("exits",([ "wiz":"/d/wiz/hall1",
                "old":"/open/world1/meetroom",]));



 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
