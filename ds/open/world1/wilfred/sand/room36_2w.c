// Room: /open/world1/wilfred/sand/room36_2.c

inherit ROOM;

void create()
{
        set("short", "���F��");
        set("long", @LONG
�g�~�֤몺���F�A��X�F�o�����F�C���a�A�C���W�o�󤣥͡A��
�~�����A��a�H�٤����y���F���z�A���C�����s���½Y�s���P���F�D
���n�D�A�c�W�L�����y���F���z���s��K�b�o����C
LONG
        );
        set("no_clean_up", 0);
        set("objects", ([ /* sizeof() == 2 */
          __DIR__"npc/npc20_1" : 3,
          __DIR__"npc/npc20_2" : 3,
        ]));
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room36_2",
]));
        set("outdoors", "land");
        set("current_light", 2);
        set("no_recall", 1);

        setup();
        replace_program(ROOM);
}

