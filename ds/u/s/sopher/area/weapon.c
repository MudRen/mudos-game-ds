#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIR"�Z��"HIW"����ǹh���e"NOR);
        set ("long", @LONG
�F��N�O�o�@�޲z�Bĵ�è��˳ƪ��a��F�A�ݨӰ��F
���Y��ĵ�ƥ~�Aĵ�a�]�Ƥ]�۷�P���C
LONG);  
        set("exits", ([
        "west" : __DIR__"time4",
         ]) );
        set("hide_exits",([
        "east" :__DIR__"weapon1",
        ]));
        set("objects", ([
        __DIR__"npc/admin" : 1,
        ]) );
        set("light",1);
        setup();
        replace_program(ROOM);
}
