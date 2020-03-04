// Room: /u/k/kenshin/sha-zin-gu/room5.c

inherit ROOM;

void create()
{
        set("short", "�v�騦�J�f");
        set("long", @LONG
�o�̴N�O�v�騦���J�f�F�A�e���u�è�W�Ať���n�i�v�騦�A���X
��a���q���ҡA�p�G�����b��B�R�A�i�H�߰ݤ@�U�u�áA�K�i���D��B
�i�R�o�@�q���ҡC
LONG
        );
        set("outdoors", "land");
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"room6",
  "south" : __DIR__"room4",
]));
        set("no_clean_up", 0); 

        setup();
        replace_program(ROOM);
}

