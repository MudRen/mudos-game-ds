// Room: /u/s/superbug/train/a-5.c

inherit ROOM;

void create()
{
	set("short", "�h����[�F��]");
	set("long", @LONG
�o�̬O�h���Ϫ��F��A�o�̤��R���ۥO�A�P��äߪ�����A�A�u�Q�n
���֪����}�o�̡A�b���ٽ��۴X�Ӭy���~�b�ݵۧA�A���G�Ʊ�A���m�I
���򵹥L�̡A����i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"8.c",
  "east" : __DIR__"a-6.c",
]));
set("objects", ([
__DIR__"npc/vagrant" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}