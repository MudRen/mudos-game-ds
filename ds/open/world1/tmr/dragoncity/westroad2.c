// Room: /open/world1/dragoncity/westroad2.c

inherit ROOM;

void create()
{
	set("short", "�褺�j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j��A�F���O�@���W�\����[��
�˪�����A�̭��O�֫ӭx�ΫӱF�򪺩���C�n���O�ΫC�۾Q
���j��D�C�_���O�@�Ӥj���Q�r��D�A�u���H�ӤH���A�D�`
���x�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"southroad2w",
  "north" : __DIR__"west_din",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}
