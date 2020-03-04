// Room: /open/world1/dragoncity/westroad.c

inherit ROOM;

void create()
{
	set("short", "�褺�j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j��A�F���O�@���W�\����[��
�˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C�_���O�ΫC�۾Q
���j��D�C�n���O�@�Ӥj���Q�r��D�A�u���H�ӤH���A�D�`
���x�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"west_din",
  "north" : __DIR__"northroad2w",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}
