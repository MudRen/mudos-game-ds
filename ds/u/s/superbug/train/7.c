// Room: /u/s/superbug/train/7.c

inherit ROOM;

void create()
{
	set("short", "�k�Z��");
	set("long", @LONG
�o�̬O�@���k�Z�ҡA�N�~�a�ݰ_�ӤQ�����b�A�J�Ӥ@�ݦ��G���H�b�M
�����ˤl�A�b���٦��@��Ƚc�M�Y���������A�ݰ_�Ӧ��G���H�b�o�r�d
���ˤl�A:�]�\�A�i�H���Y�ǽu���C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"4.c",
]));
        set("world", "future");
        set("light", 1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
