// Room: /open/world1/tmr/xiangyang/jiekou2.c

inherit ROOM;

void create()
{
	set("short", "�j��f");
	set("long", @LONG
�]���o��O�Q�r��f�A�ҥH�D�`���x�C�p�Ӥp�c�̦b�V��
�H�[�ܵۡA�°�L�̪��ӫ~�C���M���������X�j�x�I�Z�A���o
��ݤ��X�H�̦����@����i�A�n���L�̤w�q�Ũ��D�B�ߥH���`
�F�C�_���M�F���O�p�ˡA�\�h���������Ѧʩm��b�̭��A�n��
�M�譱�O�C�۾Q�N���j��C
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/kid" : 1,
]));
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"northroad2",
  "south" : __DIR__"eastroad2_n1",
  "east" : __DIR__"xiaorong1",
  "north" : __DIR__"xiaorong2",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
