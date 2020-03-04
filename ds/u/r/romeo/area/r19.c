// Room: /u/k/king/area/r19.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[1;37m-[1;35m����[2;37;0m");
	set("long", @LONG
���F�@�q�۷�������A�ﴡ��L���M�����A�g���j���ۤ@�Ѧ���A
��b���O���b���a�A�o�̶Z�ӳ��c�v���@���������A�q�o�̩��|�g�ݥh
�A�u����観�ۧ�e�s���a��A���ر�h�A�b���������i�H����@�y�y
�����j�J���A�۹�i�áC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r20",
  "northwest" : __DIR__"r18",
]));
	set("world", "undefine");
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/man" : 3,
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
