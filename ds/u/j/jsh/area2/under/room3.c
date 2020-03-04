#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
這段路似乎越走越窄，頭頂及兩旁的牆壁好像要朝你倒下似的，
想著想著突然有東西碰了你一下，瞬間汗毛直豎，也顧不得頭上掉落
的沙土，快步往前走。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room2", 
  "north" : __DIR__"room4",
  "southwest" : __DIR__"room_3",
  "southeast" : __DIR__"room-3",]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/boots-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

