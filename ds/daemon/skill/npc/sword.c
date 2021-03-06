#include <ansi.h>
#include <command.h>

inherit NPC;

int is_corpse() { return 1; }
int is_character() { return 0; }
int pk(object target);

void create()
{
	set_name("飛劍", ({ "flying sword" }));
	set("long", 
                "一把由人所發出的劍氣控制而飄浮在空中的劍．\n" );
	set("value", 1);
	set("no_get", 1);
	set("no_sac", 1);
	set("no_give", 1);
        set("unit", "把");
	set("level", 50);
	setup();
	set("status_desc", "正在空中飄浮著");
	set("damage", 10); // 預設傷害值
	set("destruct", 0); // 消失標記
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
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"。\n");
        damage -= ((target->query_armor()/3) + target->query("level")); 
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"。\n");
        damage = damage*5/8;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"。\n");
	damage -= target->query_Merits("tec")*10;
        if( target->query_Merits("tec") > query_leader()->query_Merits("tec") )
		damage -= (target->query_Merits("tec")-query_leader()->query_Merits("tec"))*10;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"。\n");
        damage += query_leader()->query_skill("sevenstar-sword")*query_leader()->query_Merits("tec")/3;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"。\n");
        damage += (query_leader()->query_damage()/6);
        if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"^AC\n");
	damage = damage * query("durable") / 100;
	if(wizardp(query_leader()) )tell_object(query_leader(),"damage : "+damage+"。\n");
        damage -= random(target->query_armor()/4);
	query_leader()->add_temp("wind_skill/num", -1);
        if( damage < 10 ) damage = 10;

	message_vision(HIY"$N"HIY"突以極速飛行飛插去$n"HIY"身上！！\n"NOR, this_object(), target);
        if( wizardp(query_leader()) ) //|| query_leader()->query_temp("show_damage") )
		tell_object(query_leader(), "攻擊命中率: "+co2+" , 敵方閃避率: "+co1+"。\n");
//        if( ( co2 >= co1 && random(5) ) || ( co1 > co2 && random(3) > 0 ) )
        if( random(100) <= (query_leader()->query_dex()*4/5) )
	{
//         if( wizardp(query_leader()) || query_leader()->query_temp("show_damage") )
                        message_vision(HIY"造成$N"HIR+damage+HIY"點的傷害。"NOR, target);
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
			message_vision(WHT"$N被打到動彈不得 !...\n"NOR, target);
			target->add_busy(busy);
		}
	} else {
                message_vision("只見$N冷汗直流，狼狽的避開了。\n", target);
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
			message_vision(HIY"$N飛回到$n手中。\n"NOR, this_object(), query_leader() );
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
        set("name", HIW"飛。"NOR+wp->name()+""NOR);
	wp->move(this_object());
	set("long",
		"一把由"+who->name()+"所發出的劍氣控制而飄浮在空中的飛劍．\n");
	set("damage", damage);
	wp->move(this_object());
	who->map_skill("sword");
	who->reset_action();
}

void die()
{
	message_vision("$N慢慢地在空氣中消失了...\n",this_object());
	foreach(object ob in all_inventory(this_object()))
	{
		ob->move(environment(this_object()));
	}
	destruct(this_object());
	return;
}

void gone()
{
        message_vision(YEL"$N沒有足夠的力量支持著$n，於是把$n收回了。\n"NOR, query_leader(), this_object());
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

	message_vision(YEL"$N飛回到$n手中。\n"NOR, this_object(), query_leader());

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

