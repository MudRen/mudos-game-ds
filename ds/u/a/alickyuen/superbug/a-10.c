// Room: /u/s/superbug/train/a-10.c

inherit ROOM;

void create()
{
	set("short", "�h����[���]");
	set("long", @LONG
�o�̬O�h���Ϫ����A�o�̤��R���ۥO�A�P��äߪ�����A�b�A���_
����G�O�@���A�����A�q���f��i�h���G��n�۳\�h����A�A���W�ٶK��
�@�i�g�ۡu�G���X��v������l�A���F�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-11.c",
  "north" : __DIR__"a-24.c",
  "east" : __DIR__"a-9.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
