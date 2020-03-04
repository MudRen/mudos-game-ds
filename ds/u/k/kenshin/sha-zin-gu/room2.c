// Room: /u/k/kenshin/sha-zin-gu/room2.c

inherit ROOM;

void create()
{
        set("short", "�˪L");
        set("long", @LONG
�b�o�@�M��񺩨B���˪L�̡A���K���H�P�즳�I�L�O�A���O�e
�観�@�D���u�A�Q���N�O�˪L���X�f�F�A�ڤH���ҥܡA�e��N�O�e
�Z�L�֫L����M�Ҧ��B�A�W�s�i�v�騦�j�C
LONG
        );
        set("current_light", 2);
        set("outdoors", "forest");
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",
  "east" : __DIR__"room1",
  ]));
        set("no_clean_up", 0);

        setup();
replace_program(ROOM);
}


