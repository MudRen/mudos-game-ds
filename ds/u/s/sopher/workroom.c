#include <room.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIG "流雲之家" NOR);
        set ("long", @LONG

淡淡幽香，和煦暖風，這裡正是流雲的家。你向四周望了望
，淺藍色的家具，點綴著純白色的天花板，更顯的神清氣爽
，在你身旁一位俏麗的女人，正式流雲的貼身秘書--瑩火(s
ophon)。
LONG      );

        set("valid_startroom", 1);
        set("exits", ([
        "wiz": "/d/wiz/hall1",
        ]));
        setup();

}

void init()
{
write("歡迎光臨流雲之家\n");
}
