// Room: /open/world1/acme/area2/t16.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�G�h]");
	set("long", @LONG
�o�̤@�����¡A�|�P�@�L�O���A�u��N���Ӧ�A�o�̪����A�`
��A�R�o�A�V������l�A�̦n�������}�o�ӤH���Һ��C
LONG
	);
	set("current_light", 3);
	set("mob_amount", 3);
	set("mob_max", 3);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"t17",
  "east" : __DIR__"t15",
]));
	set("mob_object", ({ /* sizeof() == 1 */
  __DIR__"npc/man"
}));
	set("no_clean_up", 0);
	set("chance", 70);

	setup();
	replace_program(ROOM);
}
