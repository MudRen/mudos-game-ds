// Room: /u/m/mulder/area/road7.c

inherit ROOM;

void create()
{
	set("short", "�s���o�� - �s���j��");
	set("long", @LONG
�A�Pı�o�ӫ����M��L���O�S��������O�A���A�Ӥ߬ݤ@�U
�A�N�|�@�˵oı�O�S���Ӥj�����O�A�u�O�D�D�D�D�D�D�D�D
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"road4",
  "east" : __DIR__"road8",
]));
	set("�s���o��", "- �s���o�j�D");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
