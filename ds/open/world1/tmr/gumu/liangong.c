// liangong.c �m�\��
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�m�\\��");
	set("long", @LONG
�o�y�۫ǧΪ��ƬO�_�S�A�e����e�A������ΡA�F��b��A����o
�@�T���Ϊ��A��ӳo�O�H�e�������v���m�\�ǡA�e���m�x�A�Z�e�Ϯ��A
�F���C�A�訤�o��C
LONG	);
	set("exits", ([
		"northeast" : __DIR__"mudao03",
	]));
        set("objects", ([ /* sizeof() == 1*/
          __DIR__"npc/apprentice" : 3,

        ]));      

	setup();
	replace_program(ROOM);
}
