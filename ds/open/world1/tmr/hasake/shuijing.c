// shuijing.c
inherit ROOM;

void create()
{
        set("short", "坎兒井");
        set("long", @LONG
山丘下灌木叢中有一眼坎兒井，是牧民們的水源。井台上有一個木杯
專供口渴的行人喝水。井邊有一個由人踏動的水車，水渠從這裡一直連到
了東邊的馬廄。
LONG);
        set("exits", ([
//                "eastup" : __DIR__"caochang",
                "southwest" : __DIR__"room-su",
                "northeast" : __DIR__"pmchang",                
        ]));
         set("objects", ([
                __DIR__"obj/hamigua" : 2
        ]));
        setup();
}
