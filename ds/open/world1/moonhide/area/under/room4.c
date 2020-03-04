#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
你看到通道前方有些許亮光，似乎有個廣闊的房間，心中不禁稍
微鬆了口氣。一條條的黃色光線，隱隱約約的射到這裡，給人的感覺
就像是，百鬼不侵的地方，說神聖，又有邪惡性，真是奇怪。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room3", 
  "north" : __DIR__"room5",
  "southwest" : __DIR__"room_4",
  "southeast" : __DIR__"room-4", 
  ]));
  set("light",1);
  set("objects", ([ /* sizeof() == 1 */
  // __DIR__"npc/boots-guard" : 1,
  __DIR__"npc/pants-guard" : 1,
  ]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}
