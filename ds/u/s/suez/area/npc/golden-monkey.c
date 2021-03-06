
#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N撲到$n的身上往$n的$l猛咬",
		"attact_type":  "bar",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"咬傷",
	]),
	([	"action":		"$N一爪往$n的$l抓了過去",
		"attact_type":  "bar",
		"damage_type":	"抓傷",
	]),
	([	"action":		"$N抓了一把土石對準$n的$l丟了過去",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	([	"action":		"$N跳到$n身上用力拉扯$n的$l",
		"attact_type":  "bar",
		"damage_type":	"拉傷",
	]),
});

void do_clean();
#include <ansi.h>
void create()
{
        set_name(HIY"火眼金猿"NOR,({"golden-monkey", "monkey" }) );
	set("long",@LONG

    紅色圓圓大大的眼睛，靈活的望著你，金黃色像絲綢一般的皮毛閃閃 
發光，可愛的樣子讓你忍不住想抱牠一抱。可是牠幾乎有你的一半大，加
上牠嘴角及手指上的血跡，看來牠可能沒你想像中的可愛喔﹗


LONG
);
        set("limbs", ({
		"頭部",	"胸口",	"背部",	"腰部",	"臀部",	"手臂","腿部",
	}) );
        set("age",70+random(70));
        set("level",40);
        set("dex",100);
        set("gender","雄性");
        set("race","野獸");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	"火眼金猿好像一直挖著一旁的土堆，不知道在做什麼。\n",
  	"火眼金猿拿起地上血淋淋的肉塊，放到嘴中咀嚼著。\n",
}));
      set("attitude", "aggressive"); //主動攻擊,生性好鬥的的 NPC。

	set_skill("mob_bite", 64);
	set_skill("dodge", 100);
	set("addition_armor",20);
	set("addition_damage",20);
	set("default_actions", (: call_other, __FILE__, "query_action" :));

        setup();
}

int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIR"$N爬到$n的身上，一雙猴爪一把抓向$n的喉嚨﹗\n"NOR,me,victim);
	if(hitrole > 100)
	{
		message_vision(MAG"$n被猴爪抓到後，覺得傷處一陣麻癢。\n"NOR,me,victim);
		victim->receive_damage("hp",50+random(20),me);
                        victim->start_busy(3);
		return 1;
	}
	else message_vision(HIW"$n抓住$N用力一甩，將$N摔到數尺之外。\n"NOR,me,victim);
            me->start_busy(3);
	return 1;
}
mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}
void die()
{
        object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        ob->add("popularity",1); //聲望
 message_vision( "$N 打敗了火眼金猿後，將火眼金猿的皮剝了下來，留下一具血淋淋的屍塊。"  ,ob );  
       obj=new(__DIR__"eq/golden_m_s");
       obj->move(environment(this_object() ) );
        ::die();
        return;
}
