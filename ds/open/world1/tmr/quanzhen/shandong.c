// shantong.c 後山山洞
// Winder Oct.10 1998

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "後山山洞");
        set("long", @LONG
這裡是全真教開山祖師王重陽真人靜修的山洞。洞不大，但
裡面佈置得很雅致，像大戶人家的客廳一樣。洞壁上掛著一副畫
(hua)，桌椅茶几都很精緻。
LONG
        );
        set("exits", ([
                "out" : __DIR__"xiaolu12",
        ]));
        set("item_desc", ([
        "hua": "畫中是一個中年道士的背影，看不出什麼相貌，畫中人一手指天，畫角題
著‘"+MAG"活死人像"NOR+"’幾個大字。\n"
        ]) );

        set("objects", ([
                CLASS_D("quanzhen")+"/wang" : 1,
        ]));

	set("coor/x", -2670);
	set("coor/y", 130);
	set("coor/z", 150);
	setup();
        replace_program(ROOM);
}