// Room: /u/d/darkfool/area1/c1.c

inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�o�̬O�s�մ������s���A�F�䤣���B���@�ڥ۬W�A�q�o�̦��X
�����ê��D���A���O�q����W�U�B�C�s�����@����F�@�����ȹ�����
���C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"31",
  "east" : __DIR__"c2",
  "west" : __DIR__"4",
  "northeast" : __DIR__"11",
  "south" : __DIR__"s1",
]));

	setup();
	replace_program(ROOM);
}
