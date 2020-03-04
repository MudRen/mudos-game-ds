#include <ansi2.h>

inherit ROOM;

void create()
{
        set("short", HIY"��G�۾�[���h]"NOR);
	set("long", @long
�A�{���b��G�۾𤧤W�A�b�o�̧A�i�H�n�M���ݨ�ѪŤW�X�d��
�U�ӤӶ��A��������|��M�o�ͳo�Ӳ����A�γ\�A�i�H�b�o�յۥΧA
�ߨ쪺��K���b��g�V�Ӷ��A��h�X�Ӫ��Ӷ��̤@�@�g�U�A������
�`�C
long);
	set("no_fight", 1);
	set("no_exert", 1);
	set("no_cast", 1);
	set("no_recall",1 );
	set("exits", ([
                "down" : __DIR__"tree3",
	]));

	setup();
}

void init()
{
//        add_action("do_search", "search");
	add_action("do_shoot", "shoot");
//        add_action("do_climb", "climb");
}

int do_climb(string arg)
{
        object me = this_player();

        if( arg != "tree" && arg != "moon tree" ) return 0;

        if( me->is_busy() || me->is_block() )
                return notify_fail("�A���b�����I\n");

        message_vision("$N�C�C�a��"HIY"��G�۾�"NOR"�W���F�W�h�C\n",me);
        me->move(__DIR__"tree3");
        me->start_busy(2);
        me->receive_wound("right_arm", 3+random(5));
        me->receive_wound("left_arm", 3+random(5));
        me->receive_wound("right_leg", 3+random(5));
        me->receive_wound("left_leg", 3+random(5));
	me->start_busy(2);
	return 1;
}

int do_search(string arg)
{
	object me, bow;
	me = this_player();

	if( arg == "tree" || arg == "moon tree" )
	{
		message_vision("$N�}�l�J�Ӫ��ˬd�o�Ӧa��...\n", me);
		me->start_busy(2);
		if( objectp(present("wood bow", me)) )
		{
			tell_object(me, "�g�L�J�Ӫ��j�d����, �A�S���o�{����i�ê��F��C\n");
			return 1;
		}
		bow = new(__DIR__"bow");
		if( bow->move(me) )
		{
			tell_object(me, HIW"�A�o�{�a�W���@��찵���}�I\n"NOR);
			return 1;
		}
	}
}

int do_shoot()
{
	object me, weapon;
	int power;

	me = this_player();
	weapon = me->query_temp("weapon");

        if( me->query("hp") < 51 )
	{
		write("�A����O�����H�g�b��Ӷ����̡C\n");
		return 1;
	}
	if( !weapon || !objectp(weapon) || weapon->query("id") != "wood bow" )
		return notify_fail("�Х��˳Ʀn��}�~��g�Ӷ��r�I\n");

	if( !weapon->query_temp("shooting") )
	{
		if( me->is_busy() ) { write("�A���b���ۡI\n"); return 1; }
                message_vision(HIW"$N�H�a�߰_�@���K���b�A�|�_�F$n�j�O�@�ԦV�ѪŴy�ǵۨ䤤���@�ӤӶ�....\n"NOR,me , weapon);
		tell_object(me, HIW"(�Y�A�{���y�ǧ������ܡA�Q�V�o�b�g�Ӷ��ɴN�ЦA���@��[shoot]�C\n"NOR);
		weapon->set("no_steal", 1);
		weapon->set("no_drop", 1);
		weapon->set_temp("shooting" ,1);
		me->receive_damage("hp", 50);
		call_out("add_power", 1, me, 1);
		return 1;
	}
	power = weapon->query_temp("shooting");
	message_vision(HIW"$N��M���A�}�����b�b�⤤���t���V�F�Ѫ�...\n"NOR, me);
	tell_object(me , RED"�g�����b��,�A�P����O�ɥ��C\n"NOR);
        if( random(20) < power )
	{
		__DIR__"tree"->do_record(me);
	}
	else {
		tell_object(me, HIR"�ݨӳo������,�g�����F....\n"NOR);
	}
	weapon->delete("no_steal");
	weapon->delete("no_drop");
	weapon->delete_temp("shooting");
	if( !random(5) )
	{
		message_vision(YEL"$N�@���p�߶^���U���h�F....\n"NOR, me);
		me->move("/open/world1/cominging/area/boo-lin");
	}
	me->start_busy(2);
	return 1;
}

void add_power(object me, int power)
{
	object weapon = me->query_temp("weapon");
	
	if( !weapon || !objectp(weapon) || weapon->query("id") != "wood bow" )
		return;

	if( !weapon->query("no_drop") ) return;

	if( power > 20 || random(25-power) < 5 )
	{
                this_object()->fail(weapon);
		return;
	}
	weapon->set_temp("shooting", power);
	me->add_busy(1);
	call_out("add_power", 1, me, power+1);
	return;
}

void fail(object weapon)
{
        message_vision(HIR"�]$N������A�o��j���ԤO�ӳQ�A���_�F�C\n"NOR, weapon);
	destruct(weapon);
	return;
}
