// Room: /u/s/superbug/train/a-11.c

inherit ROOM;

void create()
{
	set("short", "�h����[���]");
	set("long", @LONG
�o�̬O�h���Ϫ����A�o�̤��R���ۥO�A�P��äߪ�����A�b�A���n
��O�@���p�p���t�����A���f��۴X�i��l�M�Ȥl�A�ݰ_�Ӧ��G�ͷN����
���ˤl�A���@�s�H�b����A���F�i�H�e�������ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"a-12.c",
  "south" : __DIR__"a-25.c",
  "east" : __DIR__"a-10.c",
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
