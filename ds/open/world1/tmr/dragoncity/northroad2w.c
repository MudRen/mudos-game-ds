// Room: /open/world1/tmr/dragoncity/northroad2w.c

inherit ROOM;

void create()
{
	set("short", "�j��f");
	set("long", @LONG
�o��O�_�������Q�r��f�A�D�`���x�A�p�Ӥp�c�̦b�V
��H�[�ܵۡA�°�L�̪��ӫ~�C���M�Y�s������H�x�I�Z�A
���o��ݤ��X�H�̦����@����i�A�n���L�̤w�q�Ũ��D�B��
�H���`�F�C�_���M�譱�O�J�P�A�\�h�Y�s�����Ѧʩm��b��
���A�F���M�n���O�C�۾Q�N���j��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"westroad",
  "east" : __DIR__"northroad2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
