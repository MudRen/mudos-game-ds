// File: /d/dead_forest/map_25_5.c
// Updated by tmr (Fri Dec 26 20:34:55 2003)

inherit ROOM;

void create()
{
          set("short", "�p�|");
          set("long", @LONG

LONG
          );
          set("map_long", 1);
          set("exits", ([ /* sizeof() == 2 */
          "northeast" : __DIR__"map_24_6",
        "west" : __DIR__"map_25_4",
]));
        set( "objects" , ([
                __DIR__"npc/wildman_quest" : 1,
                  __DIR__"npc/corpse" : 3,
        ]) );
        setup();
          replace_program(ROOM);
}

