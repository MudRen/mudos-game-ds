// /daemon/class/hunter/clemaster.c	by Luky
#include <path.h>
#include <ansi.h>
inherit LUKY+"guildmaster";
void dispel();

void create()
{
	set_name("梭利",({"solid"}));
	set("gender", "男性");
	set("long","他是一位教會的神職人員, 也是牧師公會的協調人。\n\n"
	+"  如果要加入公會請打 join <職業> \n"
	+"  要看此公會技能請打 list \n"
	+"  要學習公會技能請打 train <技能> \n\n"
	);
	set("title","大牧師");
	set("adv_class",2);
	set("class","caster");
	set("adv_class2","cleric");
	set("level",70);
	set("age",40);
	set("lck",140);
	set("evil",-300);
	set("jointerm","evil<20");
	set("jointerm_msg","梭利打量了你一眼, 對你說: 邪惡的人我們是不歡迎的.\n");
	set_skill("dispel",350);
	set_skill("multi_arrow",500);
	set_skill("arrow",2000);
	set_skill("bless",500);
	set_skill("dodge",310);
	set_skill("wand",210);
	set_skill("staff",210);
	set_skill("aid",320);
	set_skill("mostlight",410);
	set_skill("armor",1000);
	set("env/spellpower",5);
        set("guild_skills",([  // 難度, 等級1可學到的技能等級上限, 上限
		"dodge"		:({48,3,200}), // 基本閃躲
		"dispel"	:({38,6,420}), // 惡靈退散
		"bless"		:({30,5,350}), // 祝福術
		"scanbody"	:({999,1,90}), // 活體探測
		"armor"		:({20,9,600}), 
		"aid"		:({33,6,420}), 
		"mostlight"	:({33,6,420}), 
		"meditate"	:({48,2,140}), 
		"invoke"	:({50,2,140}), 
		"recharge"	:({50,2,140}), 
		"staff"		:({48,3,210}), 
		"wand"		:({48,3,210}), 
        ]) );
        set_temp("apply/armor",300);	//在eq還沒寫好前暫用
	set("accept",1);		//新增可以接受東西
        set("chat_chance", 10 );
	set("chat_msg", ({
	(:command("say 小兄弟捐點錢吧, 上帝會祝福你的."):),
	(:command,"get all":),
	(:command,"drink potion":),
	(:command("smile"):),
	}) );

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
	(: command, "say ...神聖之地怎麼能容許\你在此放肆!!\n" :),
	(: cast_spell2, "multi_arrow":),
	(: cast_spell2, "mostlight":),
	(: cast_spell2, "aid":),
	(: command, "get all" :),
	(: command, "drink potion" :),
	(: cast_spell2, "armor":),
	(: dispel :),
	(: dispel :),
	(: dispel :),
	}) );
	set("msg_guildclass0",HIG"$n高興的向全世界的神職人員宣佈:"NOR"\n\n");
	set("msg_guildclass1",HIW"【從今天起, $N弟兄正式加入我們$c公會成為神的子民.】\n"NOR);
	set("msg_guildclass2",HIW"【希望大家今後都能相互扶持, 將天主的福音散播到世界的每個角落!!】\n\n"NOR);
   	setup();
	set("coin",2000);
	carry_object(__DIR__"eq/holyrobe")->wear();
	carry_object(__DIR__"wp/cross")->wield();
	//carry_object(__DIR__"hmclothes")->wear();
}
/*
void init()
{
 add_action("do_give","give");	
}
*/
void dispel()
{
	command("sigh");
	tell_room(environment(this_object()),"\n梭利突然身子往後退了一步\n");
	command("c dispel");
}

int accept_money(object me, int money_amount ,string money)
{
 string who;
 who = me->query("name");
 if(money_amount<1) return 0;
 if(this_object()->is_fighting()) return 0;
if(me->query_temp("cast")) return 0;
if(me->is_fighting()) return 0;
 if( money == "coin" )
 {
   if( this_player()->query("coin") < money_amount ) return notify_fail("你沒有那麼多錢.\n");
   me->add("coin", - money_amount );
   this_object()->add("coin", money_amount/5);
   message_vision("$N拿了一些錢給梭利.\n",this_player());
   message_vision(HIY"梭利很高興的對$N說: "HIG"謝謝你的奉獻!! 天主會保佑你的!!.\n"NOR,me);
if(!me->query_temp("bless") || !me->query_temp("db"))
{
   if(random(money_amount) > 8000 ) command("c armor "+me->query("id"));
   else if(random(money_amount) > 5000 ) command("c bless "+me->query("id"));
}
// by pudon
   if(me->query("evil") > -9999 && money_amount>999 ) me->add("evil",- random(money_amount/180));
   return 1;
 } else return 0;
}

int accept_object(object who, object ob)
{
        int val;

        val = ob->value();
        if( !val )
                return notify_fail("他不想收你的東西。\n");
        else if( val > 100 ) {
                if( (who->query("evil") > 0)
                &&      (random(val/10) > (int)who->query("level")) )
                        who->add("evil", - (random((int)who->query("level")) + val/1000) );
        }
        say( "旅客說道﹕多謝這位" + RANK_D->query_respect(who)
                + "﹐神明一定會保佑你的。\n");

        return 1;
}
