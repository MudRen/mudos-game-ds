#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(CYN"青龍紫炎霸王丹"NOR, ({ "super pill","pill" }));
        set("long",
@LONG
這顆神丹據聞是集百家練丹之術的精華, 以及近三百種藥材,
加上內功深厚的練丹術士, 啟千斤巨鼎烘燒融合七七四十九天方
能造出一顆----青龍紫炎霸王丹, 神效無比, 但此丹藥天下間只
有十顆, 十分罕見, 故一般丹坊大部份不識此丹.
LONG
	);
        set("weight",50);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
        set("unit", "顆");
        set("heal_hp",1);      
	set("value",1);
        set("heal_mp",1);
	set("heal_ap",1);
        set("heal_body",20);
	set("heal_hand",20);
	set("heal_head",20);
	set("heal_foot",20);
	set("needaward",2);
	set("eat_msg","$N吃下一顆斗大如饅頭的巨大藥丸。");
        set("eff_msg",HIW"你忽然覺得體內通體舒暢，而且瞬間充滿了力量。" NOR );
	}
        setup();
}
void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	string type,msg;
	object ob,me,env;
	me = this_player();
	ob = this_object();
	if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
	if( me->is_busy() )
		return notify_fail("你上一個動作還沒有完成。\n");
	if( ob->query("do_eat") )
                return notify_fail("你已服下了。\n");
	if( query("heal_hp"))
		me->receive_heal("hp", me->query("max_hp") - me->query("hp"));
	if( query("heal_mp"))
		me->receive_heal("mp", me->query("max_mp") - me->query("mp"));
	if( query("heal_ap"))
		me->receive_heal("ap", me->query("max_ap") - me->query("ap"));
	if( query("heal_head"))
		me->receive_curing("head", query("heal_head"));
	if( query("heal_body"))
		me->receive_curing("body", query("heal_body"));
	if( query("heal_hand"))
	{
		me->receive_curing("left_arm", query("heal_hand"));
		me->receive_curing("right_arm", query("heal_hand"));
	}

	if( query("heal_foot"))
	{
		me->receive_curing("left_leg", query("heal_foot"));
		me->receive_curing("right_leg", query("heal_foot"));
	}
	if( me->is_fighting() ) me->start_busy(2);
	message_vision("$N拿起$n, 一口氣吞了下去。\n",me,ob);
	if(stringp(msg=query("eff_msg"))) tell_object(me,msg+"\n");
	if(!ob->query("super_used") && !me->query_temp("super_used") )
	{
		tell_object(me,HIR"你忽然覺得全身力量充盈無比！\n" NOR);
        	me->add_temp("apply/str",3); //附加
		me->add_temp("apply/con",2);
		me->add_temp("super_used",1);
		ob->set("super_used",1);
        	ob->set("do_eat",1);
        	ob->set("no_drop",1);
        	ob->set("no_sac",1);
        	ob->set("no_give",1);
		ob->set("no_sell",1);
            call_out("delay",750,me);     //附加屬性維持時間
	}
	else 
	{
		query("pill/function");
		if( !ob->finish_eat() )
			destruct(ob);
	}
        return 1;
}

void delay(object me)
{
        if(!me) return;
                tell_object(me,"你覺得青龍紫炎霸王丹的藥力已過, 你的力量似乎消弱了下來。\n" );
        me->add_temp("apply/str",-3);
	me->add_temp("apply/con",-2);
	me->delete_temp("super_used");
		destruct(this_object());
}

int is_pill() {	return 1; }

int query_autoload() { return 1; }
