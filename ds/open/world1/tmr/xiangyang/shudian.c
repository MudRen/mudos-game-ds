// Room: /d/xiangyang/shudian.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;

void create()
{
	set("short", "�ѩ�");
	set("long", @LONG
�o�̪������q�n���h�ӡAť���H�e�L���b�C�s�֪L�x�X
�L�a�A�ᤣ�������]�S�٤F�U�A�M����Ѭ��͡C�u���ѩ���
�n�ܤj�A�H�e���O�@�y����C
LONG );
	set("exits", ([
		"east" : __DIR__"westroad2",
	]));
	set("objects", ([
		__DIR__"npc/shudianboss" : 1,
	]));
	set("coor/x", -540);
	set("coor/y", -480);
	set("coor/z", 0);
	setup();
	replace_program(ROOM);
}
