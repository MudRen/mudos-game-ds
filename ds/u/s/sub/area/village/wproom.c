// Room: /u/s/sub/area/village/wproom.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�o�̬O�@��������A�U�تZ���������a���b��W�C����ͧ�O���A
���~�����K�K�C�������}�o�̥X�~�������H���ٷ|�S�a�^�Ӹ������ʶR
�K���A������ͪ��W�n��[���T�G�C
LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"vi05",
]));
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/village_wpboss_20" : 1,
]));
	set("room_type", "sell");
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
