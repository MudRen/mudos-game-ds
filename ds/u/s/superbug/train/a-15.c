// Room: /u/s/superbug/train/a-15.c

inherit ROOM;

void create()
{
	set("short", "�h����[�n��]");
	set("long", @LONG
�o�̬O�h���Ϫ��n��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A���F
�観���o���������㪺���㩱�A�۵P�W�g�ۤj�j���u���@�v��Ӧr�A�ݰ_
�Ӧ��G���@�I�O�A�P��߰ʡA���_�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a-14.c",
  "south" : __DIR__"a-16.c",
  "east" : __DIR__"a-20.c",
]));
	set("world", "undefine");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
