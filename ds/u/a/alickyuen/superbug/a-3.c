// Room: /u/s/superbug/train/a-3.c

inherit ROOM;

void create()
{
	set("short", "�h����[�_��]");
	set("long", @LONG
�o�̬O�h���Ϫ��_��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A����
����G�O�@���s�a�A���f���ۤ@�T���j���۵P�g�ۡu�S��s�a�v�A���f��
���X�ӾK�Ȧb��ѡA���n�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"a-2.c",
  "north" : __DIR__"a-4.c",
  "west" : __DIR__"a-19.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
