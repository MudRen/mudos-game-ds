// �����s�ĤT�h

inherit ROOM;

void create()
{
	set("short", "�����s�p�Y");
	set("long", @LONG
�o�O�@�Ӥp�Y�A�A�ݨ�A���U�ӴN��F�s���F�A�ߤ����Ǫ��߮��A
�ݬݭ�訫�Ӫ����A���G���ܪ�²��\�h�F�A���W���M�ШF�����A�O�H
�ݤ��M�����C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"3f2.c",
  "up" : __DIR__"4f1.c",
]));
	set("world", "past");
	set("no_clean_up", 0);
	set("outdoors","forest");
	setup();
	replace_program(ROOM);
}
