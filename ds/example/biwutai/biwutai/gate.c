// �s��(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "��Z���j��");
	set ("long", @LONG
�o�O�p���촸��Z�����j���A�@�y���������P�{�A�W�ѡy��Z���z
�T���^���j�r�C�o���g�`�|��U����������Z�j�|�C�Ҧ����H�������|��
�[�C
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"north"   : __DIR__"zoulang",
		"south"   : "/d/bianliang/guangming",
	]));
	set("objects", ([
		__DIR__"npc/gongping" : 1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob, where;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	ob=present("gongping zi", where);

	if ( !wizardp(me) && dir=="north" ) {
		if(me->query("snowzongshi"))
			return ::valid_leave(me, dir);
		if( ob->query("fangshi")!="�ӤH��" && !ob->query("start/start"))
			return notify_fail("�{�b�S�������Z�A�A����i�h�C\n");
	}
	return ::valid_leave(me, dir);
}
