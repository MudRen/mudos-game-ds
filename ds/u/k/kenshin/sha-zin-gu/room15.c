// Room: /u/k/kenshin/sha-zin-gu/room15.c

inherit ROOM;

void create()
{
        set("short", "�p��");
        set("long", @LONG
���}�F�ө���A�Pı�]�������ө��󪺼��x�A�ݨ�e���@�ǥѤW
�~�������C�����Ѥ����b����U�H�ѡA�A�]ť�쨺�ǦѤ������F�@�l
�Ѧӧn�[�A�O�H�Q��A�H�ͤC�Q�~�}�l�C
LONG
        );
        set("outdoors", "land");
        set("current_light", 2);
        set("objects", ([ /* sizeof() == 3 */
  __DIR__"obj/npc/oldman3" : 1,
  __DIR__"obj/npc/oldman1" : 1,
  __DIR__"obj/npc/oldman2" : 1,
]));
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"room9",
  "west" : __DIR__"room16",
]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

