// Room: /u/s/superbug/train/a-7.c

inherit ROOM;

void create()
{
	set("short", "�h����[�F��]");
	set("long", @LONG
�o�̬O�h���Ϫ��F��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A���n
��O�@�����j���ө��A���f�ٰ�۳\�h���ӫ~�A�]�\�A�i�H���@�Ǧn�F
��A����i�H�q�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-6.c",
  "south" : __DIR__"a-23.c",
  "east" : __DIR__"a-8.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
