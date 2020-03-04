// Room: /open/world1/dragoncity/southroad1.c

inherit ROOM;

void create()
{
	set("short", "�n���j��");
	set("long", @LONG
�o�O�@���ΫC�۾Q�N���j�D�C�V��N�O�B�r��f�A�u��
�n�����ɦ��������b�ӥX�A�F���]�O�@�Ӥj��f�A�A�n����
��@���j��q�V�n���C�_���O�@���W�\����[���˪�����A
�̭��O�֫ӭx�ΫӱF�򪺩���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"southroad1e",
  "west" : __DIR__"south_din",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 4);

	setup();
	replace_program(ROOM);
}
