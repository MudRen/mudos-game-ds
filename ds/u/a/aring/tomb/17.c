// Room: /u/a/aring/tomb/17.c

inherit ROOM;

void create()
{
	set("short", "�j�Ӷ�мX��");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�o�������O�͡A�X�G�֬ݤ��X�o�̦���
�X�ӡA���O�����ɦ���P���̰ʡA�@�Ǧ��Ӥ��j���p�}�C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"18.c",
  "east" : __DIR__"16.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
