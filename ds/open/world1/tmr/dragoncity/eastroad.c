// Room: /open/world1/tmr/dragoncity/eastroad.c

inherit ROOM;

void create()
{
	set("short", "�F���j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j��A�譱�O�@���W�\����[��
�˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C�_���O�ΫC�۾Q
���j��D�C�n���O�@�Ӥj���Q�r��D�A�u���H�ӤH���A�D�`
���x�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"east_din",
  "north" : __DIR__"northroad1e",
]));
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
