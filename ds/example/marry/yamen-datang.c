// Room: /d/ruzhou/yamen-datang.c
// llm 1999/07/04

inherit ROOM;

void create()
{
	set("short", "�����j��");
	set("long", @LONG
�����@�����谪�a���j�СA�O�U�a���Ū����ƪ��a��C�j�󪺦a�W���o�x�G�o
������ݨ�@�I�I���岪�A�ݨӬO�j��ΦD�ɯd�U������C����U�U�@�ǵ��R�B�^
�ת��P�l�A�����Ǥ��¦۫㪺�Pı�C
LONG
	);
	set("exits", ([
	   "south" : __DIR__"yamen-damen",
	]));
	set("objects", ([
		__DIR__"npc/jiang-yaoting":1,
      __DIR__"npc/yayi":4,
	]));

	setup();
	replace_program(ROOM);
}

