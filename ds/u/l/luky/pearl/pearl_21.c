// Room: /u/l/luky/room/pearl_21.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠北街"NOR);
set("long", @LONG

��╲                                                   ╱��
�� :▏＿＿    你正走在珍珠大道上。左邊是一座 ＿＿＿＿╱: ��
�� :▏: :   非常壯觀的燈塔，但是似乎沒有路可  : : :▕: : ��
�� :▏: :   以進去。往南可以到本鎮的出口處，  : : :▕: : ��
�� :▏￣￣  再往北去則可通往本鎮的商店街。   ￣￣￣￣╲: ��
��╱                                                   ╲��


LONG
	);
set("objects",([
__DIR__"npc/pagurian":1,
]));
set("exits", ([ /* sizeof() == 2 */
"south" : __DIR__"pearl_2",
"north" : __DIR__"pearl_20",
]));
set("no_clean_up", 0);
set("light",1);
setup();
replace_program(ROOM);
}
