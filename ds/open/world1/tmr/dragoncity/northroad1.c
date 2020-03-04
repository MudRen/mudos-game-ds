// Room: /open/world1/tmr/dragoncity/northroad1.c

inherit ROOM;

void create()
{
	set("short", "�_���j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j�D�C�V��N�O�B�r��f�A�u��
�_�����ɦ��������b�ӥX�A�F���]�O�@�Ӥj��f�A�A�n����
��@���j��q�V�n���C�n���O�@���W�\����[���˪�����A
�̭��O�֫ӭx�ΫӱF�򪺩���C
LONG
	);
	set("current_light", 4);
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"bank",
  "west" : __DIR__"north_din",
  "east" : __DIR__"northroad1e",
]));

	setup();
	replace_program(ROOM);
}
