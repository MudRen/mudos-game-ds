#include <ansi.h>
#include <command.h>

inherit NPC;

int is_corpse() { return 1; }
int is_character() { return 0; }
int pk(object target);

void create()
{
	set_name("���C", ({ "flying sword" }));
	set("long", 
                "�@��ѤH�ҵo�X���C�𱱨���ƯB�b�Ť����C�D\n" );
	set("value", 1);
	set("no_get", 1);
	set("no_sac", 1);
	set("no_give", 1);
        set("unit", "��");
	set("level", 50);
	setup();
	set("status_desc", "���b�Ť��ƯB��");
	set("damage", 10); // �w�]�ˮ`��
	set("destruct", 0); // �����аO
	set("durable", 0);
}

void init()
{
	object me, *ob;

	me = query_leader();

	remove_call_out("die");

	if( !me ) call_out("die", 3);
/*
        ob = all_inventory(environment(this_object()));
	foreach(object target in ob)
	{
                if( living(target) && !target->query("damage") && target != me && !environment(target)->query("no_fight") &&
		( (!userp(target) && userp(me)) || !userp(me) ) )
			call_out("pk", 1, target);
	}
*/
}

int pk(object target)
{
	int co1, co2;
	int damage, busy;

	if( environment(target) != environment(query_leader()) ) return 1;
        co1 = target->query_skill("dodge") + target->query_dex() - (COMBAT_D->dodge_factor(target,"dodge")*10/15);
        co2 = query_leader()->query_skill("dodge") + query_leader()->query_dex() + (COMBAT_D->attack_factor(query_leader(), "sword")*10/15) + query_leader()->query("level");
	damage = query("damage");
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"�C\n");
        damage -= ((target->query_armor()/3) + target->query("level")); 
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"�C\n");
        damage = damage*5/8;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"�C\n");
	damage -= target->query_Merits("tec")*10;
        if( target->query_Merits("tec") > query_leader()->query_Merits("tec") )
		damage -= (target->query_Merits("tec")-query_leader()->query_Merits("tec"))*10;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"�C\n");
        damage += query_leader()->query_skill("sevenstar-sword")*query_leader()->query_Merits("tec")/3;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"�C\n");
        damage += (query_leader()->query_damage()/6);
        if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"^AC\n");
	damage = damage * query("durable") / 100;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"�C\n");
        damage -= random(target->query_armor()/4);
	query_leader()->add_temp("wind_skill/num", -1);
        if( damage < 10 ) damage = 10;

	message_vision(HIY"$N"HIY"��H���t���歸���h$n"HIY"���W�I�I\n"NOR, this_object(), target);
        if( wizardp(query_leader()) ) //|| query_leader()->query_temp("show_damage") )
		tell_object(query_leader(), "�����R���v: "+co2+" , �Ĥ�{�ײv: "+co1+"�C\n");
//        if( ( co2 >= co1 && random(5) ) || ( co1 > co2 && random(3) > 0 ) )
        if( random(100) <= (query_leader()->query_dex()*4/5) )
	{
//         if( wizardp(query_leader()) || query_leader()->query_temp("show_damage") )
                        message_vision(HIY"�y��$N"HIR+damage+HIY"�I���ˮ`�C"NOR, target);
        target->receive_damage("hp", damage, query_leader());
	if( living(target) )	COMBAT_D->report_status(target);
	target->kill_ob(query_leader());
        if( target->is_busy() && target->query_busy() < 5 )
	{
		busy = random(2);
	}
	else { busy = 1; }
		if( busy )
		{
			message_vision(WHT"$N�Q����ʼu���o !...\n"NOR, target);
			target->add_busy(busy);
		}
	} else {
                message_vision("�u��$N�N�����y�A�T�V���׶}�F�C\n", target);
	}
	foreach(object ob in all_inventory(this_object()))
	{
//                ob->set_durable(ob->query_durable()-1);
		ob->attack();
                ob->attack();
                ob->attack();
                ob->attack();
		ob->attack();
		ob->attack();
                if( ob->query_durable() < 1 )
		{
		set("destruct", 1);
		if( ob->move(query_leader()) ) 
		{
			message_vision(HIY"$N���^��$n�⤤�C\n"NOR, this_object(), query_leader() );
                        query_leader()->start_busy(1);
		}
			else ob->move(environment(this_object()));
		}
		else set("durable", ob->query_durable() );
	}
        if( query("destruct") ) this_object()->gone();
	return 1;
}

void rename(object who, object wp, int damage)
{
	set_leader(who);
        set("name", HIW"���C"NOR+wp->name()+""NOR);
	wp->move(this_object());
	set("long",
		"�@���"+who->name()+"�ҵo�X���C�𱱨���ƯB�b�Ť������C�D\n");
	set("damage", damage);
	wp->move(this_object());
	who->map_skill("sword");
	who->reset_action();
}

void die()
{
	message_vision("$N�C�C�a�b�Ů𤤮����F...\n",this_object());
	foreach(object ob in all_inventory(this_object()))
	{
		ob->move(environment(this_object()));
	}
	destruct(this_object());
	return;
}

void gone()
{
        message_vision(YEL"$N�S���������O�q�����$n�A��O��$n���^�F�C\n"NOR, query_leader(), this_object());
	foreach(object ob in all_inventory(this_object()))
	{
                ob->move(query_leader());
	}
	destruct(this_object());
	return;
}

int receive_damage(string type, int damage, object who)
{
	return 1; 
}

int heal_up()
{
	object master;

	master = query_leader();

	if( !master )
	{
		heal_up();
		return this_object()->die();
	}

	if( environment(this_object()) != environment(master) )
	{
		if( this_object()->money_type() != master->money_type() )
			this_object()->die();
		else this_object()->move(environment(master));
	}

	::heal_up();

	return 1;
}

void end()
{
	if( !query_leader() ) return;

	message_vision(YEL"$N���^��$n�⤤�C\n"NOR, this_object(), query_leader());

	foreach(object ob in all_inventory(this_object()))
	{
		if( !ob->move(query_leader()) ) ob->move(environment(query_leader()));
	}
	destruct(this_object());

	return;
}

int follow_me(object ob, string dir)
{
	if( ob==leader )
	{
		GO_CMD->main(this_object(), dir);
		return 1;
	}
	return 0;
}

