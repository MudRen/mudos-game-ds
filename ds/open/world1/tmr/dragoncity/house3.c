// Room: /open/world1/tmr/dragoncity/house3.c

inherit ROOM;

void create()
{
	set("short", "�֫ө��Ы��U");
	set("long", @LONG
�o�̬O�֫ө������U�C�U�����j�A�o�G�m�������P�C�F���a���ۥ|�T
�̱��Aø���O�����˵�|�ت�c�F����a�����O�K�L��V�C���U�~�����O
�@�i�K�P��C��W�ݩ�ۤ@�M����A����\��ۥ|�i�ȭ��ȡA��o�����j
��C�U���U�\��ۤ@�֨d����A���G���o�̱a�Ӥ@���x�N�C
LONG
	);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kou-zhong" : 1,
]));
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"house2",
  "north" : __DIR__"house4",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
