#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "鴛鴦廳");
        set("long", NOR""+
"這兒就是春風樓的大廳，人稱鴛鴦廳，來此的騷人墨客多半流連\n"+
"忘返，光是溫香軟玉鶯聲燕語就足以融化每個男人的腦袋，更不要說\n"+
"華麗的裝飾和美食了，這就是到朝天樓的旅客幾乎都會到此地一遊的\n"+
"原因。\n\n");

        set("current_light", 1);
        set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"r02",
        "south" : __DIR__"r04",
]));
        set("objects",([
        __DIR__"obj/desk01" : 1,
        __DIR__"npc/01" : 1 ,
        __DIR__"npc/02" : 1 ,
]));
	setup();
}