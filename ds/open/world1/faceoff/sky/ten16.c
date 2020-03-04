#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", CYN"一江客棧 - 二樓"NOR);
        set("long", @LONG
一上來二樓，原先脫俗的氣氛更為濃厚，二樓的牆壁是
由青竹所編成，微風輕輕的從縫中吹入，而在最顯眼的位置
，坐著一位身穿粗布衫的漢子，他的風度穩健而又不顯得呆
滯，也許你該同他攀談攀談..
LONG
        );
        set("exits", ([   "down":__DIR__"ten15.c",
]));
        set("room_type","hotel");       //旅館
        set("no_fight", 1);
        set("light",1);
        set("no_clean_up", 0); 
        set("no_drop",1);
        setup();
}

void init()
{
     ::init();
     if( sizeof(filter_array( children(__DIR__"npc/chen_chi"), (: clonep :) )) == 0 ) 
     new(__DIR__"npc/chen_chi")->move(this_object());
}
