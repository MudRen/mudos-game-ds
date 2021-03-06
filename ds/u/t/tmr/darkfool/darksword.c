#include <weapon.h>
#include <ansi.h>

inherit SWORD;
inherit SSERVER;

void create()
{
	set_name("闇黑之劍",({"darkfool sword","sword"}) );
	set("long",@long
一把看來非常黝黑的長劍，尤如漆黑、寂靜的宇宙一般，毫無大自然
的生機，令人寒懼。這口長劍相傳為數百年前，一位宇宙探險家－「闇黑
傻瓜」，於一次探測「楊威利星座群」的「龍蝦黑洞」中所得到的「藍藍
的礦石」打鑄而成的。據聞此劍能容讓其主人的魔法力，而有更強力的攻
擊力，你不禁想試試(powerin)或是(stone)
long
	);
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
	set("unit","把");
	set("wield_msg","$N「刷」一聲，從腰間抽出一把漆黑長劍握在手上。 \n");
	set("value",500);
	set("material","iron");
	set("limit/str",30);
	set("weapon_prop/hit",30);
	set("weapon_prop/parry",30);
	set("weapon_prop/int",10);
	}
	init_sword(20);
	setup();	
}

void init()
{
	add_action("do_powerin","powerin");
	add_action("do_stone","stone");

}

void attack(object me,object target)
{
	int i;
	int kee;
	int skee;
	skee=this_object()->query_temp("swordkee");

	i=random(10);
	kee=random(2)+1;

	if(this_object()->query_temp("power") )
	{
	message_vision(HIW"\n\n$N手中的闇黑之劍忽發龍吟之嘯，登時劍氣四射，直攻"+target->query("name")+"命門要害！！\n\n "NOR,me);
	if (i==0)
		message_vision(HIY"$N於千鈞一髮之際，僥倖躲過劍氣的追擊，看來並無什麼大礙。\n"NOR,target);
	else
	{
		message_vision(HIR"只見$N拆招擋架不住，活生生地受了劍氣四道圍攻，猛然吐了一大口鮮血，看來受傷不輕。\n"NOR,target);	
		target->set("wound/body",2);
	}
	this_object()->set_temp("power",0);
	}

// 於戰鬥過程中，存劍氣.....
	if(random(2) ) //亂數決定，1/3 的機率不存劍氣..
	{
		if (me->query("mp") > 50)
		{
		tell_object(me,HIM"你覺得身體一陣乏力，「闇黑之劍」似乎吸走了你一些魔法力...\n"NOR);
		tell_object(me,HIC "吸走的魔法力->"+kee+"  劍氣->"+ skee+"\n"NOR);        //加這行只是為了方便查看...
		this_object()->set_temp("swordkee",skee+kee);
		me->add("mp",-kee);
		if(skee>30) 
 			tell_object(me,HIR"你感覺手中的「闇黑之劍」激烈地抖動，似乎它已吸足你所給的魔法力.......\n"NOR);
		}
	}

	if(this_object()->query_temp("kee_ok") )
	{
		tell_object(me,HIG"闇黑之石」測試成功...\n" NOR);
		this_object()->delete_temp("kee_ok");
		this_object()->add_temp("swordkee",-30);
	}
}

int do_powerin(string arg)
{
	object me,obj;
	me=this_player();
	obj=this_object();

 	if(arg) return 0;
	if(me->query("mp") <200) return notify_fail("你的魔法力不夠，不能加持。\n");
	if(me->is_busy() ) return notify_fail("你現在沒有空！\n");
	if(me->query_temp("powering") ) return notify_fail("你已在加持法力了。\n");
	me->set_temp("powering",1);
	me->start_busy(5);
	message_vision(HIW"\n\n       $N緊握著劍柄，喃喃地唸道：「龍蝦大大...請賜給我神祕的力量∼∼∼」\n"NOR,me);
	message_vision(HIG"\n只見$N的雙手發出一陣陣綠色的神聖光芒，漸漸地包圍住闇黑之劍。\n"NOR,me);
	call_out("powerin_msg",5,me,obj);			
	return 1;
}

int powerin_msg(object me,object obj)
{
	int i;
	if(!me) return 0;
	i=random(10);
	me->add("mp",-100);	
	message_vision(HIG "\n只見瑩繞著闇黑之劍的綠色神聖光芒漸漸地被劍所吸收了....\n" NOR ,me);
	
	if(i<2)
	{	
		tell_object(me,BLU"你覺得你所灌注的魔法力由如石沈大海一去無蹤.....\n"NOR);
	}	
	else
	{
		tell_object(me,BLU"輕過你幸苦地加持之後，闇黑之劍似乎更顯得耀眼、鋒銳。\n"NOR);
	}

	obj->set_temp("power",1);
	me->delete_temp("powering");
	return 1;
}

int do_stone()
{
	if(!this_player()->is_fighting() ) return notify_fail("「闇黑之石」須於戰鬥中才能使用。\n");
	if(this_object()->query_temp("swordkee") >30 )
	{
		message_vision(HIB"只見$N手中所握的「闇黑之劍」發出一道閃光。\n"NOR,this_player() );
		this_object()->set_temp("kee_ok",1);
	}
	else
		return notify_fail("闇黑之劍所儲存的魔法力不夠，不能使用「闇黑之石」。\n");
	return 1;
}