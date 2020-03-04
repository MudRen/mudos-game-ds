// Room: /u/s/sub/area/village/bank.c

inherit ROOM;

void create()
{
	set("short", "���v");
	set("long", @LONG
�o�̬O�a��W�����O�H�h�w�����t�w����a�A���C�۷����R�C���O
���������o�S���@�ѫU��A��ܥX�o�̪��D�H�D�`���S����աC���L�ѩ�
�L���D�`�������O���]�I�A�ҥH�a��W���H���֩�N������ѥL�ӫO�ޡC
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"vi07",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/village_banker_20" : 1,
]));
	set("room_type", "bank");
	set("current_light", 2);

	setup();
	replace_program(ROOM);
}
