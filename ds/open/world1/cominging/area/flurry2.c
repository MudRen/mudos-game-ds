inherit ROOM;

void create()
{
        set("short", "�e�����J�f�j��");
        set("long", @LONG
�o�̴N�O�e�������j���F�A�o�̦��⮰���g�K�Ұ������j���A��w
��s���������}�A�������䦳��Ӧu���çL�b�u�õۡA���G���ƫ��Y��
�ˤl�A�ä��e����}�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"flurry1.c",
  "north" : __DIR__"flurry3.c",
]));
        set("objects",([
  __DIR__"npc/fguard": 2,
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("light",1);
        setup();
        replace_program(ROOM);
}

