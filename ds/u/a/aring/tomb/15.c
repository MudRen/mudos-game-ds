// Room: /u/a/aring/tomb/15.c

inherit ROOM;

void create()
{
	set("short", "current_light 0");
	set("long", @LONG
�A�����b�@�y�X�Ӫ��W�Y�A�o�������O�͡A�|�P�٦��@�ǳQ�ʪ�
�������|�}�A���p�߸}�ٷ|����g�̥h�C
LONG
	);
	set("light", "0");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"16.c",
  "south" : __DIR__"14.c",
]));
	set("current_light", 1);

	setup();
	replace_program(ROOM);
}
