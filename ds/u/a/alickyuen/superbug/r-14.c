// Room: /u/s/superbug/train/r-14.c

inherit ROOM;

void create()
{
	set("short", "�K�����Y");
	set("long", @LONG
�o�̬O�K�������Y�A�Ѱ�m�b�@�Ǫ��u��ݨӡA���G�O������@�b��
�u�{�]���Y�ǽt�G����F�A�s���W�e�ۤ@�Ӥj�j���uX�v�A�ٶK�ۤ@�i�G
�i�A���G���ǥO�A�P�쮣�ơC
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r-13.c",
]));
set("objects", ([
__DIR__"npc/killer" : 1,
]));
	set("world", "future");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
