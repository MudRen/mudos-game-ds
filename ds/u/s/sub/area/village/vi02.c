// Room: /u/s/sub/area/village/vi02.c

inherit ROOM;

void create()
{
	set("short", "�p�|");
	set("long", @LONG
���Ǫ����F�@�ʴʪ��Q��A�ݰ_�Ӧܤ֦b�o���q�ߤF�n�X�Q�~�F�C�Z
�����K���N�ѪžB���F�j�b��A���o�̥|�u���۷�a���D�A����ť�쪺��
�s�n�����o�̪��I�R�C�F�䦳�@�y�p�s�C�A�p�|�V��n�詵���C
LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("outdoors", "land");
	set("current_light", 2);
	set("exits", ([ /* sizeof() == 2 */
  "southwest" : __DIR__"vi01",
  "eastup" : __DIR__"vi03",
]));

	setup();
	replace_program(ROOM);
}
