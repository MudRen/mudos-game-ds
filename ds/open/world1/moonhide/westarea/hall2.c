// Room: /open/world1/moonhide/westarea/hall1.c

inherit ROOM;

void create()
{
        set("short", "太陽崗哨");
        set("long", @LONG
太陽崗哨是雲端空島上的一處空地，在太陽崗哨出去就是大片
無盡的藍天，要是失足踩空，可是會摔的粉身碎骨。太陽崗哨放置
五座炮台，在日光下閃閃發光。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"way4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("objects", ([
                __DIR__"npc/trainee" : 3,
        ]) );

        setup();
        replace_program(ROOM);
}

