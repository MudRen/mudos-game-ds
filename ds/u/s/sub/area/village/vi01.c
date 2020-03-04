// Room: /u/s/sub/area/village/vi01.c

inherit ROOM;

void create()
{
	set("short", "�p�|");
	set("long", @LONG
�@���Ѱʪ��Ҩ��X�Ӫ��p�|�A��������O�͡A�a�W�W�Y�����A�D�`�a
�����C���O�̤��ɶǨӦU���U�˪����λ�s�n�A�ϱo�o�Ӧa�観�@�ػ���
�X�Ӫ���D�C�p�|�V�F�_�詵���A�����q����B�C�l�n��i�H�q���@�B�k
���C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 4);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"tree4",
  "northeast" : __DIR__"vi02",
]));

	setup();
	replace_program(ROOM);
}
