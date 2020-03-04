// Room: /open/world1/dragoncity/southroad2.c

inherit ROOM;

void create()
{
	set("short", "�n���j��");
	set("long", @LONG
�A�����b�@���ΫC�۾Q�N���j�D�C�V�F�N�O�B�r��f�A
�i�q���ȪZ���A�譱�]�O�@�Ӥj��f�A�A�n���ݨ�@���j��
�q�V�n���C�_���O�@���W�\����[���˪�����A�̭��O�֫�
�x�ΫӱF�򪺩���C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"south_din",
  "west" : __DIR__"southroad2w",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
