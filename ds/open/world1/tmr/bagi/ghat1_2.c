// Room: /open/world1/tmr/bagi/ghat1.c

inherit ROOM;

void create()
{
        set("short", "�a�V�e");
        set("long", @LONG
�A���B�b�~���{�U���k���e�A���U��h�A�u���}�}������¶�A���H��
�ɡC����_�䦳���s�D�q�V�@���պG�G�����a�Aŧŧ�H���j�ӡA���T�O�H
���F�G�ۡC
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ghat1",
]));
        set("world", "past");
    set("outdoors","snow");
        set("no_clean_up", 0);
        set("forest", "snow");

        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ghat12",
]));

        setup();
        replace_program(ROOM);
}

