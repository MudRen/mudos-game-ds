// Room: /u/k/kenshin/sha-zin-gu/room4.c

inherit ROOM;

void create()
{
        set("short", "�˪L�X�f");
        set("long", @LONG
�ש󨫥X���@���¯Q�Q���˪L�F�A�@�X�˪L���e�@��A���@�B�c�a
�����H�A�Q�����@�w�O�Z�L�֫L����M���Ҧb�B�A�v�騦�F�C���F�c�a
������A�٦��������Mħ�i�˪���ݵۻ��Ӫ��B�͡A�߸̤��T�Q�F�Q�A
��B�����a���a��A�w�g���h�F!!
LONG
        );
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"room3",
  "north" : __DIR__"room5",
]));
        set("outdoors", "land");
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}


