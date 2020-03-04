#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"地下墓穴"NOR);
        set("long", @LONG
來到通道的這一段，你似乎覺得背後有不知名的東西緊跟著你，
無名的壓力讓你不敢轉回頭看，彷彿將會看見自己永遠不想看到的東
西，你喃喃唸了幾句，繼續往前走去。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"room1", 
  "north" : __DIR__"room3",
  "southwest" : __DIR__"room_2",
  "southeast" : __DIR__"room-2",]));
set("light",1);
        set("objects", ([ /* sizeof() == 1 */
 __DIR__"npc/boots-guard" : 1,
]));
        set("no_light",1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

