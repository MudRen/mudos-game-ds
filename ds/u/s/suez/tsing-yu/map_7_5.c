// Room: /u/s/suez/tsing-yu/map_7_5.c

inherit ROOM;

void create()
{
	set("short", "�s����");
	set("long", @LONG
    �o�̪����O�@���������j��A�A�i�H�ݨ��\�h�I�ۦ��n���ȤH�H��
����e�P�ۦb���ȤH�C�X�ӬD�ҧ��b���񵥤H���ΡA���f���j���w�w�Ӧ�
�A�M�n�����u�ۦ�j�D�j�F�L�ӡA���a�ۨǳ\��y�����D�C�p�Y�����Ǩ�
�}�}�������O�H���T�����j�ʡA�@�ǶǨӦY�Y�����n�A�X�ӥ���ɻ쪺�C
�k���G��A�o�~�a�Ӫ��ȫȥR���n�_�A�ɥ۲M�ܪ��I���n�H�۬h�K�\���A
�@���í��]�H�������C

LONG
	);
	set("world", "undefine");
	set("no_clean_up", 0);
	set("map_long", 1);
	set("exits", ([ /* sizeof() == 6 */
  "east" : __DIR__"map_7_6",
  "north" : __DIR__"map_6_5",
  "west" : __DIR__"map_7_4",
  "southeast" : __DIR__"map_8_6",
  "south" : __DIR__"map_8_5",
  "northeast" : __DIR__"map_6_6",
]));

	setup();
	replace_program(ROOM);
}
