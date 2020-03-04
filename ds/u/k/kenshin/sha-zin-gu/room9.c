// Room: /u/k/kenshin/sha-zin-gu/room9.c

inherit ROOM;

void create()
{
        set("short", "[0;1;32m�[1m�[1m�[1m�[1m�[1m�[0m");
        set("long", @LONG
�o�̴N�O�v�騦���ө���F�A�o�̦��\�h�����a�A�Ҧp�Z���E�B
���㩱�����A�p�G�A�ʤ��򪺸ܡA�i�H�즹�a�ӬݬݡA���Ӧ��A�ʪ�
���~�C
LONG
        );
        set("outdoors", "land");
        set("current_light", 3);
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 5 */
  "west" : __DIR__"room8",
  "east" : __DIR__"room14",
  "northwest" : __DIR__"room15",
  "north" : __DIR__"room12",
  "south" : __DIR__"room13",
]));

        setup();
        replace_program(ROOM);
}

