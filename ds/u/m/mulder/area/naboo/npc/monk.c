#include <ansi.h>
inherit NPC;
inherit SSERVER;
void cast_fireball();

void create()
{
	set_name(HIW"修行者"NOR,({"monk"}) );
	set("long","一個到各宇宙修行的修行者。\n");
	set("age",30);
	set("level",40);
	set("race","人類");
	set("evil",-30);
	set("exp_point",4);	// 設定強度, exp及combat_exp會參考到這個值
				// 0 <= exp_point <= 9
				// 內定值為 0 , 請依據強度來設合理的值...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("smile"):),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 65);
	set("chat_msg_combat", ({
		(: cast_fireball :),
	}) );
	set_skill("dodge",70);
	set_skill("block",50);
	set_skill("parry",35);
	set_skill("unarmed",50);

	setup();

}

void cast_fireball()
{
	object ob,me;
	int damage,c;

	me = this_object();

	ob = offensive_target(me);
	if(!ob) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",30);
	message_vision("\n"+ob->query("name")+"嘆氣地說，為何要逼我出手呢？\n");


	tell_room(environment(me),"\n"+me->query("name")+"突然身子往後退了一步\n");
	tell_room(environment(me),"\n你驟眼看到他手中浮現出一個像"HIR"火球"NOR"的物體\n");

	if( ob->query_int() < random(150) )
	{
	    ob->add_busy(2);
	    message_vision(HIR"\n$N感覺有一種不祥的預感將會發生。\n",ob);
	    damage = random(100)+query_int()*3;
	    damage = damage/2+random(damage/2);
	    c=ob->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,ob,damage,"dodge");
	    ob->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n只聽見$N一聲慘叫，$N逃不了火球的擊勢，$N的整個身體被火球吞噬。\n"NOR,ob);
	    else
		message_vision(HIW"\n$N左閃右避才能避過這來勢洶洶的"HIR"火球。\n"NOR,ob);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(ob->query_temp("apply/show_damage") || ob->query_temp("show_damage") )
	        tell_object(ob,HIR"("+damage+")"NOR+" ("+ob->query("hp")+"/"+ob->query("max_hp")+")");
	    message_vision("\n",ob);
	    if(wizardp(ob) && ob->query("env/debug"))
	        tell_object(ob,"  造成"+damage+"點傷害!!\n"); 
	    COMBAT_D->report_status(ob);	

	}
	else message_vision("\n火球飛向$N之時，但反被$N破解了。\n",ob);

 	me->start_busy(1);

}