inherit ROOM;

void create()
{
        set("short", "�a���}��");
        set("long", @LONG
�A���B�b�@�Ӧa���}�ޤ��A�ѩ󶧥��L�k�Ӯg�i�ӡA�ҥH�|�g�ɬO�º�
�����@���A�A�u��j�j���۩������e�i�C
LONG
        );
        set("current_light", 4);
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"npc/troll4" : 2,
          __DIR__"npc/troll5" : 2,
          __DIR__"npc/troll6" : 1,
        ]));
        set("exits", ([ /* sizeof() == 2 */
 "south" : __DIR__"cave2e",
]));

        setup();
        replace_program(ROOM);
}

