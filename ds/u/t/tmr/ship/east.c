// Room: /tmr/ship/1.c

inherit ROOM;

void create()
{
	set("short", "�F��f");
	set("long", @LONG
�o�O�@�Ӧ��濤���F��f�C
LONG
	);
	set("objects",([
		__DIR__"shipman":1,
	]) );

	set("no_kill",1);
	set("no_magic",1);
	set("no_clean_up", 0);
	
	setup();
}