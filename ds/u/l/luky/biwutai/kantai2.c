// �s��(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "���ݥx");
	set ("long", @LONG
�o�O�p���촸��Z�������ݥx�A�ݥx�W���@�Ʊƪ��������C�A���b
�o���@�V������Z�x�W�@����Z�L�ۧA����ݱo�D�`�M���C�o���ٴ��ѧK
�O�������C
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"biwutai",
		"northwest"   : __DIR__"kantai1",
		"northeast"   : __DIR__"kantai3",
		"south"   : __DIR__"zoulang",
	]));
	setup();
}

void init()
{
	add_action ("do_work","ansuan");
}

int do_work()
{
	write("�o������ϥγo�ӫ��O�I\n");
	return 1;
}

int valid_leave(object me, string dir)
{
        object tai=load_object(__DIR__"biwutai");
        object *inv=all_inventory(tai);
	object ob, where;
        int i=sizeof(inv);

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="up" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("��Z�w�g�}�l�F�A�A���O��⤣��W�x�C\n");
		if(i>=2)
			return notify_fail("��Z�x�W�w�g����W���A�A�{�b����W�x�C\n");
	}
        return ::valid_leave(me, dir);
}
