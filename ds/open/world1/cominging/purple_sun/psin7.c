inherit ROOM;

void create()
{
	set("short", "�s�}�U");
	set("long", @LONG
�o�̤w�O�����s���s�}���U��F�A���W�N�O�@�h�h���s���F�A�s��
�~�k�T�򤣩��樫�A�`���Ǥ����W���H�N���@�h���^�A��Өƥ�]�]��
��W���t�@�����ӲH�H��֡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"1f5.c",
  "southwest" : __DIR__"psin6.c",
]));
	set("no_clean_up", 0);
    set("outdoors","forest");
	setup();
	replace_program(ROOM);
}

/*int valid_leave(object me, string dir)
{
	if( !query("fall_stone") )
		return ::valid_leave(me, dir);
	if( query("fall_stone") && dir == "up" )
	{
		write(HIW"���s�W�����Q���۩Ҿצ�, �Ӥ���q��I\n"NOR);
		return 1;
	}
}

void fall_stone()
{
	object b_stone = new(__DIR__"npc/obj/b_stone.c");
	if( !objectp(b_stone) ) CHANNEL_D->do_channel(this_object(), "sys", "ERROR: �䤣�� stone .");
	b_stone->move(this_object());
	set("fall_stone", 1);
	return;
}

void clean_stone()
{
	object b_stone = present("stack-road", this_object());
	destruct(b_stone);
	delete("fall_stone");
}*/
