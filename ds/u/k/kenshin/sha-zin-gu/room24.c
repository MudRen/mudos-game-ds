// Room: /u/k/kenshin/sha-zin-gu/room24.c

inherit ROOM;

void create()
{
        set("short", "[0;1;36m�[1mZ[1m�[1m�[1m�[1m�[1m�[1m�[0m");
        set("long", @LONG
�V�ӶV����Z�Ǥ��a�A�P���������P�]�󰪤F�A�q�o�̴N��ť��
�̭����̤l�m�����[���n�A�u�O���®�C���訫�N���F�v�騦���A
���w�ƥ��A���C
LONG
        );
        set("outdoors", "land");
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room25",
  "south" : __DIR__"room11",
]));
        set("no_clean_up", 0);
        set("current_light", 4);

        setup();
        replace_program(ROOM);
}

