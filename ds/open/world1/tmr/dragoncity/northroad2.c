// Room: /open/world1/tmr/dragoncity/northroad2.c

inherit ROOM;

void create()
{
	set("short", "�_���j��");
	set("long", @LONG
�A�����b�@���ΫC�۾Q�N���j�D�C�V�F�N�O�B�r��f�A
�i�q���ȪZ���A�譱�]�O�@�Ӥj��f�A�A�n���ݨ�@���j��
�q�V�n���C�n���O�@���W�\����[���˪�����A�̭��O�֫�
�x�ΫӱF�򪺩���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"northroad2w",
  "east" : __DIR__"north_din",
]));
	set("current_light", 2);
	set("no_clean_up", 0);
	set("outdoors", "land");

	setup();
	replace_program(ROOM);
}
