inherit ROOM;

void create()
{
        set("short", "固山寨壕溝");
        set("long", @LONG
修建寨子的時候，繞著寨子一周挖了兩三丈深的溝渠，然後
引泉水灌入，固山寨既有地勢的優勢，又有護城河拒敵，是一座
頗為重要的寨壘。可惜因為寨子太堅固，所以�堶掛n守的軍隊大
多都是步兵。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"camp005",
  "south" : __DIR__"camp007",
]));
        set("light",1);
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

