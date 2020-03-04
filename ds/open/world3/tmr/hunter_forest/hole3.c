// Room: /tmr/future/hunter_forest/hole3.c

inherit ROOM;

int call_npc(object me);
void create()
{
	set("short", "�s�}��");
	set("long", @LONG
�A�����b�@�Ӥs�}���A�a�W���������O�G�֡A���o�X�Ӫ�������~��
�o���ǥͽ��A�A�@�F�@�|�P�A���G�䤣���L���q�D�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
	  "south" : __DIR__"hole1",
	]));
	set("light", 1);
	set("world", "future");

	setup();
}
void init()
{
	object me,c;
	me=this_player();
	if(!objectp(present("pulp",me)) ) return;

	if(objectp( c=present("yalen cirri",me) ) )
		if (c->query("catch_ok")==1) return;
	call_out("call_npc",1,me);
}

int call_npc(object me)
{
	object ob;
	ob=new(__DIR__"npc/gu-name");
	if(!objectp(present("gu name") ) )
	{
		tell_room(__FILE__,"���M�q�a�����X�@���ʪ��A���G�Q"+me->query("name")+"���W�������ҧl�ޡC\n");
		ob->move(__FILE__);
	}
	return 1;
}
