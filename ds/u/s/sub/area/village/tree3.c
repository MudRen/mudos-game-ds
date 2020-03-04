// Room: /u/s/sub/area/village/tree3.c

inherit ROOM;

void create()
{
	set("short", "��K�W");
	set("long", @LONG
�}�}���j���ﭱ�jŧ�ӨӡA���Hı�o�b�o�̯�í�}�B�]�O�@�ذ��D�C
�Z���a�������ק�O�ϤH�P���Y�w�دt�A�p�G���O�}�U�ʧ�����K���H�P
��L�񪺦w�ߡA���ȨS�X�ӤH�����L�o�̡C���_�䨫�i�H����r�r���k��
�W�A�n��i�H�쯫��W���C
LONG
	);
	set("outdoors", "land");
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"tree4",
  "south" : __DIR__"tree2",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
