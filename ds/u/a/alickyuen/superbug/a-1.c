// Room: /u/s/superbug/train/a-1.c

inherit ROOM;

void create()
{
	set("short", "�h����[�_��]");
	set("long", @LONG
�o�̬O�h���Ϫ��_��A�o�̤��R���ۥO�A�P��äߪ�����A�b�A���F
��O�@���}�ª����]�A��W�g�ۤj�j���u�G���v��Ӧr�A�A�����Q�����|
���H�N�۵P���o�˪��W�r�A���n�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"a-2.c",
  "south" : __DIR__"8.c",
  "east" : __DIR__"a-17.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
