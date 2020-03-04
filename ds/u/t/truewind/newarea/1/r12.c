#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "飛雲廳");
        set("long", NOR""+
"這兒是三樓的飛雲廳，廳中橫掛著無數的字畫，畫中的仕人淑女\n"+
"眉開眼笑，神情愉悅，與畫中的高山流水形成微妙的對比。此處已然\n"+
"沒有二樓那般喧嘩，是故可以一邊品嚐美食，一邊瞭望朝天湖附近的\n"+
"美景。\n\n");
        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"r09",
        "north" : __DIR__"r11",
        "up" : __DIR__"r13",
]));
	setup();
}