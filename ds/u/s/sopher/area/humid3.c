#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", YEL"沼澤"NOR);
        set ("long", @LONG
哇!你簡直不敢相信你自己的眼睛，這片沼澤還真
大咧，簡直可以用湖來形容。你向沼澤裡望去，好像
有生物在活動，可是又不太像..在好奇心的驅使下，
你一步步走向這片沼澤的中央地帶。
LONG);  
        
        set("exits", ([
        "west" : __DIR__"humid2",
        "north" : __DIR__"humid4",
        "south" : __DIR__"humid5",
        ]) );
        set("outdoors","workroom.c"); 
        setup();
        replace_program(ROOM);
}
