// Room: /u/s/superbug/train/a-6.c

inherit ROOM;

void create()
{
	set("short", "�h����[�F��]");
	set("long", @LONG
�o�̬O�h���Ϫ��F��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A���n
�観�@�����_�����p�ΡA�γ��W�ݥߵۤ@�Ӥp�p���Q�r�[�A�ݨӦ��G�O��
�а�A�]�\�o�O�o�̰ߤ@�w�R���a��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-5.c",
  "south" : __DIR__"a-22.c",
  "east" : __DIR__"a-7.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
