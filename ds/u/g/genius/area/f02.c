inherit ROOM;

void create()
{
set("short","小麥田");
        set("long", @LONG
這是愛門村南邊的麥田，放眼望去整片都是農夫辛勤耕作的結果。這裡
的農作是全年無休的，在氣候稍微寒冷的冬季，這裡也會種植一些玉蜀黍之
類的作物。
LONG
        );
      set("item_desc",([
      "稻草人":"這是一個殘破的稻草人，上面還站了幾隻麻雀\n",
      ]));
        set("exits", ([
        "west":__DIR__"f01",
        "east":__DIR__"f03",
        "southeast":__DIR__"f12",
]));
        set("objects", ([
        __DIR__"npc/sparrow" :1,
]));

        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}


