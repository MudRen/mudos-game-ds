// �s��(adx) by snow 2000-05-15

inherit ROOM;

void create ()
{
	set ("short", "��Z�ݥx");
	set ("long", @LONG
�A���b��Z���e�@�B�j�ݥx�A�ݥx�W���@�Ʊƪ���s�����A�A�i
�H���b�o�̡A��Z�x�W�@����Z�L�ۧA����ݱo�D�`�M���C�o���ٴ��ѧK
�O�������C
LONG);
	set("no_fight",1);
	set("no_clean_up",1);
	set("exits", ([
		"up"   : __DIR__"biwutai",
		"south"   : __DIR__"zoulang",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object tai=load_object(__DIR__"biwutai");
	object *inv=all_inventory(tai);
	object ob, where;
	int i,j;
	for(j=0;j<sizeof(inv);j++)
		if( userp(inv[j]) && !wizardp(inv[j])  ) i++;

	if (!where=find_object(__DIR__"gate"))
		where=load_object(__DIR__"gate");
	if(!objectp(ob=present("da go ko", where)))         return ::valid_leave(me, dir);

	if ( !wizardp(me) && dir=="up" ) {
		if( ob->query("start/start") && !me->query("biwu_fighter") )
			return notify_fail("��Z�w�g�}�l�F�A�A���O��⤣��W�x�C\n");
		if(i>=2)
			return notify_fail("��Z�x�W�w�g����W���A�A�{�b����W�x�C\n");
	}
        return ::valid_leave(me, dir);
}
