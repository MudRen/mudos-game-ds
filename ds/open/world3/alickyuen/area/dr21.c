// Room: /u/a/alickyuen/area/dr21.c

inherit ROOM;

void create()
{
	set("short", "ST�CHospital�ISickroom");
	set("long", @LONG
�o�̫K�O�p���M�Ϊ��f�СA���M�L�̳��f�F�A���L�̤���۰�l�A��
�۪���A�@�_���A�A���S���e�A��^�ܦn�A�n����ͯf�����Ʊ��ѱo�@��
�G�b�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"dr18",
]));
set("objects", ([
__DIR__"npc/hchild" : 1,
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
