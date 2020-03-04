inherit ROOM;

void create()
{
	set("short", "�p�ФU�ܮw");
	set("long", @LONG
�o�̬O�ܮw�U�誺�p�ܮw�A�C���\�h���~���Ѱs�A���T�O�A�Q�n�j
�ܤ@�f�A�b�o�䤤���F�k����A�դz�A�п����`�ܪ��s���A�b�o�̥R��
�F�s�����D�A�O�H���I�t�w�A�a�W���@�������s�|�A�̭����O�˵۰s�A
�����w�i�H���ܴX�f�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"kitchen2.c",
]));
	set("objects",([
  __DIR__"npc/obj/winepot.c":1,
]));
	set("light", 1);
	set("no_clean_up", 0);
	setup();
}

void init()
{
	add_action("do_potation","potation");
}

int do_potation(string arg)
{
	object me;
	string a;
	me = this_player();

	if( !arg || sscanf(arg,"from %s",a)!=1 )
		return notify_fail("�A�n�ܤ���r�H(potation from <�F��>)\n");
    if( a!="wine" && a!="bodega" && a!="wine bodega" )
        return notify_fail("�A�n�q���ܰs�r�H\n");
	if( this_player()->is_busy() )
		return notify_fail("�A�W�@�Ӱʧ@�٨S�������C\n");
	if( this_player()->is_fighting() ) this_player()->add_block(1);
    me->receive_damage("hp",1);
    me->receive_heal("ap",20);
	if( me->query_temp("grogginess") < 35 || !me->query_temp("grogginess") )
		message_vision("$N�q�s�|���ܤF�X�f���s�A���G���ǾK�N�C\n",me);
	else message_vision("$N�K�N�I�I�A�S�q�s�|���ܤF�X�f�s�A�}�l���ǰs�K�F�C\n",me);
	me->start_busy(2);
	me->add_temp("grogginess",5);
	if( (int)me->query_temp("grogginess") > 70 )
	{
		me->unconcious();
		me->delete_temp("grogginess");
	}
        return 1;
}
