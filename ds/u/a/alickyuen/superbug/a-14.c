// Room: /u/s/superbug/train/a-14.c

inherit ROOM;

void create()
{
	set("short", "�h����[�n��]");
	set("long", @LONG
�o�̬O�h���Ϫ��n��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A����
�観���o�������Z�����Z�����A�۵P�W�g�ۤj�j���u����v��Ӧr�A�ݰ_
�Ӧ��G���@�I�O�A�P�쮣�ơA���_�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a-13.c",
  "south" : __DIR__"a-15.c",
  "west" : __DIR__"a-21.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
