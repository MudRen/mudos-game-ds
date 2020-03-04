// Room: /open/world1/dragoncity/eastroad2.c

inherit ROOM;

void create()
{
	set("short", "�F���j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j��A�譱�O�@���W�\����[��
�˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C�n���O�ΫC�۾Q
���j��D�C�_���O�@�Ӥj���Q�r��D�A�u���H�ӤH���A�D�`
���x�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southroad1e",
  "north" : __DIR__"east_din",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 6);

	setup();
	replace_program(ROOM);
}
