// Room: /tmr/garea/forest15.c

inherit ROOM;

void create()
{
	set("short", "�L���p��");
	set("long", @LONG
�A�����b�L�����@���p���A�ﭱ�j�Ӱ}�}�H���A���F�n�����B�A���G
�����H�u�ۤl���A�ۤ���o�Y����d�ڸ��A�Ǧn���h�F�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
	  "southeast" : __DIR__"forest13",
	  "northwest" : __DIR__"forest16",
	]));
	set("outdoors", "forest");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
