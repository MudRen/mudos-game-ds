// File: /d/dead_forest/temple2.c
// Updated by tmr (Wed May 26 23:32:04 2004)

inherit ROOM;

void create()
{
          set("short", "����");
          set("long", @LONG
�o�O�y�������A�|�g�u�ѤU�ݯ}�������W�l���J���A�]�����C�a��
��A�����M�i�H�P���쥭�M�w�R����^�C
LONG
          );
          set("objects", ([ /* 1 element(s) */
        __DIR__"npc/kulasaier" : 1,
]));
          set("exits", ([ /* 1 element(s) */
                "out" : __DIR__"map_4_9",
        ]));

        setup();
        replace_program(ROOM);
}

