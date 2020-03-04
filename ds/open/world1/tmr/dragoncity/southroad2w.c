// Room: /open/world1/tmr/dragoncity/northroad2w.c

inherit ROOM;

void create()
{
	set("short", "�j��f");
	set("long", @LONG
�o��O�n�������Q�r��f�A�D�`���x�A�p�Ӥp�c�̦b�V
��H�[�ܵۡA�°�L�̪��ӫ~�C���M�Y�s������H�x�I�Z�A
���o��ݤ��X�H�̦����@����i�A�n���L�̤w�q�Ũ��D�B��
�H���`�F�A�n���M�譱�O�J�P�A�\�h�Y�s�����Ѧʩm��b��
���A�F���M�_���O�C�۾Q�N���j��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"westroad2",
  "east" : __DIR__"southroad2",
]));
	set("current_light", 3);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
