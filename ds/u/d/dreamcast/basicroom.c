#include <ansi.h>

inherit ROOM;

void create()
{
   ::create() ;
   set ("short", "鎮天妖關") ;
set ("long",
    "這裡就是鼎鼎大名的關卡，相傳從這出去之後，想回頭也
難，而這裡的人民都流傳著一個傳說，相傳這裡曾經有惡世天
妖在此造孽，被大神烈劫封印在此，而在他身上據說有一種神
秘的寶物，沒想到連匈奴人都想一探究竟......\n"



) ;
   set ("exits", ([
                    "north":__DIR__"desert1.c",
                    "south":__DIR__"infinite.c",
   ])  ) ;
        set("outdoors","desert");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

