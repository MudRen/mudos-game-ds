// Room: /u/m/mulder/area/road11.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - ��D");
	set("long", @LONG
�i��o����Oĵ������Y�A�O�A���������a�ƪ��߱��A��
�E�o�_�A�����ɦw�}�ߡD�A�٭n�N�A���Ҧ����m���o�����D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road14",
  "north" : __DIR__"shop1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
