// Room: /u/s/superbug/train/a-13.c

inherit ROOM;

void create()
{
	set("short", "�h����[�n��]");
	set("long", @LONG
�o�̬O�h���Ϫ��n��A�o�̤��R���ۥO�A�P��äߪ�����A�A�u�Q�n
���֪����}�o�̡A�b���ٽ��۴X�Ӭy���~�b�ݵۧA�A���G�Ʊ�A���m�I
���򵹥L�̡A���_�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"a-14.c",
  "north" : __DIR__"8.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
