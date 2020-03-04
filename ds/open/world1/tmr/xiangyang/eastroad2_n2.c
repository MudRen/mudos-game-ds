// Room: /open/world1/tmr/xiangyang/eastroad2_n2.c

inherit ROOM;

void create()
{
	set("short", "�F���j��");
	set("long", @LONG
�o�O�@���C�۾Q�N���j��C�譱�O�@���\�۬���[���˪�
����A�̭��O�����u���j�N��������j�|�C�_���O�@�ӤQ�r
��D�A�u���H�ӤH���A�D�`���x�A�n���O�ΫC�۾Q����D�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"eastroad2_n1",
  "north" : __DIR__"jiekou2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
