// File: /d/duli_forest/cave_path3.c
// Updated by tmr (Sat Aug 16 20:42:19 2003)

inherit ROOM;

void create()
{
          set("short", "�F�ޤp�D");
          set("long", @LONG
�A�����b�@���F�ޤp�D���A���g�N�N�|�M�|�P���F���i����A���_��
�ǹ����H�y�³s�s�C
LONG
          );
          set("exits", ([ /* 1 element(s) */
        "north" : __DIR__"cave_path1",
]));
        set("objects",([
                  __DIR__"npc/bear":2,
        ]));
        
        setup();
        replace_program(ROOM);
}

