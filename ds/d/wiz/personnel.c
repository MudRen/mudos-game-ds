// personnel.c �H�ƺ޲z�B

inherit ROOM;

void create()
{
	set("short", "�H�ƺ޲z�B");
	set("long",@LONG
�o�̬O�ڤۤC��޲z�H�ƪ��a��...���a���x�Ův���ݭn�b�o��Post
...�Ův�i�H�b�o�d�ߨC�@��Ův�����Ť�¾��...
LONG
	);
	set("exits",([
		"west" : __DIR__"hall1",
		"east" : __DIR__"entrance",
	]));

	set("light",1);
	set("no_clean_up",0);
	setup();
	call_other("obj/board/personnel_b.c", "???");
//	replace_program(ROOM);
}

void init()
{
	add_action("do_list","list");
}

int do_list(string arg)
{

	write("yes...\n");
	return 1;
}