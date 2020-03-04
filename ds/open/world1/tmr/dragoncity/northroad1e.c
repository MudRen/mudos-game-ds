// Room: /open/world1/tmr/dragoncity/northroad1e.c

inherit ROOM;

void create()
{
	set("short", "�j��f");
	set("long", @LONG
�o��O�_�������Q�r��f�A�D�`���x�A�p�Ӥp�c�̦b�V
��H�[�ܵۡA�°�L�̪��ӫ~�C���M�Y�s������H�x�I�Z�A
���o��ݤ��X�H�̦����@����i�A�n���L�̤w�q�Ũ��D�B��
�H���`�F�C�_���M�F���O�p�ˡA�\�h�Y�s�����Ѧʩm��b��
���A�譱�M�n���O�C�۾Q�N���j��C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"northroad1",
  "south" : __DIR__"eastroad",
  "north" : __DIR__"shop",
]));
	set("outdoors", "land");
	set("current_light", 5);

	setup();
	replace_program(ROOM);
}
