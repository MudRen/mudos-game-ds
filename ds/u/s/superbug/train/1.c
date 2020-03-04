// Room: /u/s/superbug/train/1.c

inherit ROOM;

void create()
{
	set("short", "�¥@�ɦa�U�K");
	set("long", @LONG
�o�̬O�@���Q�����ª������A�������M�٦b��i�۫o�w�g�S���h�֤H
�b�f�ӡA�A�����Q���o�̴��g�O�@�ӤH�鬤�骺�a��A�A�J�Ӥ@����W��
���۶�~�A���٦��@�i�����ɨ��C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "�����ɨ��" : "�o�O�@�i�������ɨ��A���L�w�g���ǯ}��A�A�i�H�յ�Ū(read)�ݬݡC
",
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"2.c",
  "out" : __DIR__"3.c",
  "climbup" : __DIR__"8.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
