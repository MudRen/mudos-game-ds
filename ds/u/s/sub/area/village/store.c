// Room: /u/s/sub/area/village/store.c

inherit ROOM;

void create()
{
	set("short", "���f��");
	set("long", @LONG
�o�̪��\�]���áA�U���U�˪��f���H�N��m�C�������~�W���ٻX�W�@
�h�������ǡA�ݨӳo�̳f�~���y�q�v�۷��C�A���ӬO�]���o�̸��ָ�~
�ɱ�Ĳ�����Y�C���L�o�̪�����i�O�۷����H�Ϊ��A���@�S���]���ͷN
���n�Ӧ����󪺧��ܡC
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"vi06",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/village_shoper_20" : 1,
]));
	set("room_type", "shop");
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
