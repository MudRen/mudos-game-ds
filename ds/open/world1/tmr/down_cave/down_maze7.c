// File: /d/down_cave/down_maze7.c
// Updated by tmr (Mon Aug 18 02:30:49 2003)

inherit ROOM;

void create()
{
          set("short", "�Ŭ}��");
          set("long", @LONG
�A���b�@�ӪŪŦp�]���}�ޤ��A�|�P�º������A�ݪ����O�ܲM���C
LONG
          );
          set("exits", ([ /* 5 element(s) */
        "east" : __DIR__"down_maze1",
        "up" : __DIR__"map_13_16",
        "west" : __DIR__"down_maze1",
        "down" : __DIR__"down_maze1",
        "north" : __DIR__"down_maze1",
]));

        set("objects",([
                __DIR__"npc/bandit2" : 4
        ]) );
        setup();
          replace_program(ROOM);
}

