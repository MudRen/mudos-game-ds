// Room: /u/l/lestia/area/sn17.c

inherit ROOM;

void create()
{
	set("short", "�_��j�˪L-�p�|");
	set("long", @LONG

����o�̡A�쥻���ۧA�������N�����w������ɥ��h�F�ܼv�A���ӥN
�����h�O�@���I�R�L�n�����ߡA���F�X�������b��W�������~�A�N�u�����
�M�N���b����ۧA�A�쥻�٦��@�I���u���˪L��F�o�̤]�����]���L�ߡA
���c�h���ܱo�·t�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"sn18",
  "west" : __DIR__"sn16",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
