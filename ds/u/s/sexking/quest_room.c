#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIM"迷題練習室"NOR);
        set("long", @LONG
這訴一間sexking練習寫quest的房間..
LONG 
);
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"workroom3",
        ]));
        set("objects",([
       __DIR__"child" : 1,
       ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_recall",1);
        set("no_kill",1); 
        setup();
}
