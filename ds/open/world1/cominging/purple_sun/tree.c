// 紫陽山大樹上

inherit ROOM;

void create()
{
        set("short", "大樹上");
        set("long",@LONG
你現在爬上了這棵樹，樹上的樹枝錯綜複雜，雜亂不已，有點擁擠
，樹上陰涼不少，比在下面還要涼了許多，不過這裡卻不怎麼透光，你
聽到有些嘶嘶聲．．
LONG
        );
        set("objects", ([
  __DIR__"npc/squirrel.c" : 2
]));
        set("exits", ([
  "down" : __DIR__"1f3.c",
]));
        set("no_drop",1);
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}

int query_max_capacity() { return 40; } // 有這項就不能有 replace_program(ROOM);, 最好設 no_drop
