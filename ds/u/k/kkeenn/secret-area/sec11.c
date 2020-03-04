#include <room.h>
inherit ROOM;
void create()
{
        set("short", "地下城北走道");
        set("long", @LONG
這裡是一條長長的街道，在街道的左邊有一家正在閃爍著誘人的霓
虹燈，原來是鼎鼎大名的特殊道具店，南邊是往地下城的南走道部分，
而在北邊則是往城主房子走去，在這裡有一些垃圾回收器，正在努力的
幫街道保持乾淨。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
     "south":__DIR__"sec10.c",
     "north":__DIR__"sec12.c",
     "west":__DIR__"combat_shop.c",
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}
