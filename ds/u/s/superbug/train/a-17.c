// Room: /u/s/superbug/train/a-17.c

inherit ROOM;

void create()
{
	set("short", "�������]");
	set("long", @LONG
�o�̬O�h���ϰߤ@���@�����]�A�@��i�o�̧A�N�Q�o�̴c�H�����ҩ�
���~�A�A���h�ë��|���H�Q��b�o�ع��U���諸���]�A�o�̰ߤ@���n�B
���G�u������C�G�Ӥw�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"a-1.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
