// Room: /tmr/ship/2.c

inherit ROOM;

void create()
{
	set("short", "���f");
	set("long", @LONG
�o�O�@�Ӧ��濤�����f�A���k��ݥh�O�����e�s���j�B�e�C
LONG
	);
	set("no_clean_up", 0);
	set("no_kill",1);
	set("no_magic",1);

	setup();
	replace_program(ROOM);
}
