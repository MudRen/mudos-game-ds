// Room: /open/world1/tmr/xiangyang/eastroad2.c

inherit ROOM;

void create()
{
	set("short", "�F���j��");
	set("long", @LONG
�o�O�@���C�۾Q�N���j��C�譱�O�@���\�۬���[���˪�
����A�̭��O�����u���j�N��������j�|�C�F���O���P���A
�]���Q�l�~�ӡA���O�������B��ܻX�j�x���I�����묹���H�S
�O�h�A�e���W���������H��ö�����C�_���O�@�ӤQ�r��D�A�u
���H�ӤH���A�D�`���x�A�n���O�ΫC�۾Q����D�C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"eastroad1",
  "east" : __DIR__"zhonglie",
  "north" : __DIR__"eastroad2_n1",
]));
	set("coor", ([ /* sizeof() == 3 */
  "y" : -490,
  "x" : -480,
  "z" : 0,
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
