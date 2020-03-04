inherit ROOM;
 
void create()
{
        set("short", "�g��");
        set("long", @LONG
�A�����b�@���p���A�u���o�|�g�ɬO�@�������A���⤣�������A���e
��h�A���������u���j�j����V�\�p��.....
LONG
        );
	set("no_recall",1);
	set("outdoors","forest");
        setup();
}
void init()
{
	call_out("check_seal",0,this_player() );
	add_action("do_go","go");
}

int do_go(string dir)
{
	object me;
	me=this_player();
	if(me->query_temp("garea/road") == 5 && random(10) == 1 )
	{
		me->delete_temp("garea/road");
		me->move(__DIR__"forest16");
		tell_room(environment(me),"$N�^�^�����B���y�����a���o�]�ӡC\n",me);
	}
	else
	{
		tell_object(me,"�A���ۨ���...�o�{�|�P������G�S����...\n");
		me->add_temp("garea/road",1);
		if(me->query_temp("garea/road") == 6 ) me->set_temp("garea/road",1);
	}
	return 1;
}

int check_seal(object me)
{
	object obj;
	if(objectp(obj=present("seal",me) ) && obj->query("name")=="�X����" )
	{
	tell_object(me,"���M�_�F�@�}�e���A��A�|�g���g���j�}�F�C\n");
	me->move(__DIR__"forest16");
	}
	return 1;

}
