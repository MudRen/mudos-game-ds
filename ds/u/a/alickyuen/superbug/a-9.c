// Room: /u/s/superbug/train/a-9.c

inherit ROOM;

void create()
{
	set("short", "�h����[���]");
	set("long", @LONG
�o�̬O�h���Ϫ����A�o�̤��R���ۥO�A�P��äߪ�����A�A�u�Q�n
���֪����}�o�̡A�b���ٽ��۴X�Ӭy���~�b�ݵۧA�A���G�Ʊ�A���m�I
���򵹥L�̡A���F�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"a-10.c",
  "east" : __DIR__"8.c",
]));
set("objects", ([
__DIR__"npc/vagrant" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
