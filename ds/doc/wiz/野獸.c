// ★ 一般野獸
inherit NPC;

void create()
{
	set_name("野狗", ({ "dog" }) );
	set("race", "野獸");
	set("age", 3);
	set("level",2);

        set("long", "一隻渾身髒兮兮的野狗，看了令人生憐。\n");
	
	set("str",1);
	set("max_hp",10);
	set("dex",-3);
	set("int",1);
	set("con",1);

	set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("chat_chance", 6);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"野狗用鼻子聞了聞你的腳。\n",
		"野狗在你的腳邊挨挨擦擦的﹐想討東西吃。\n",
		"野狗對著你搖了搖尾巴。\n",
		"野狗用後腿抓了抓自己的耳朵。\n" }) );
		

	setup();
}


int accept_object(object who, object ob)
{
	if( ob->id("bone") || ob->is_food())
	{
		set_leader(who);
		message("vision", name() + "很快的吃掉了"+ob->name(1)+", 高興地汪汪叫了起來。\n", environment());
		destruct(ob);
		return 1;
	}
}

// ★★ 有特攻的野獸(1) (特殊能力特攻的寫法)


inherit NPC;

void create()
{
	set_name("闇蜘蛛", ({"dark spider","spider"}) );
	set("long", "一隻黑色的大蜘蛛，這種蜘蛛不結網而是靠毒牙捕食獵物。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "前足", "後足", "腹部" })); //受攻部位
	set("verbs", ({ "bite","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 10);
	set("level",19);
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));

	setup();

}

int special_attack(object me,object victim,int hitrole)
{
	if(!me || !victim) return 0;
	if(random(5)) return 0;
	
	message_vision(HIW"$N伸出毒牙對著$n一陣亂咬，"NOR,me,victim);
	if(hitrole > 100)
	{
		victim->->apply_condition("posion", target->query_condition("posion")+3);
		message_vision(HIW"$n閃躲不及而被咬中，臉色發紫。"NOR,me,victim);
		victim->receive_damage("hp",20+random(20),me);
		return 1;
	}
	else message_vision(HIW"但被$n機警的閃了過去。"NOR,me,victim);
	return 1;
}


// ★★★ 有特攻的野獸(2) (技能式的特攻寫法) 


inherit NPC;
inherit SSERVER;
void create()
{
	set_name("人面蜘蛛", ({"face pattern spider","spider"}) );
	set("long", "一隻背部有著人面花紋的巨大蜘蛛，正虎視眈眈的瞪著你。\n");
	set("unit","隻");
	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "前足", "後足", "腹部" })); //受攻部位
	set("verbs", ({ "bite","claw" })); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("age", 6);
	set("level",13);
//	set_temp("fly",1);
//	set("chat_chance",1);
//	set("chat_msg",({
//		(: this_object(), "random_move" :),
//	}));
        set("chat_chance_combat", 20); //戰鬥動作機率
        set("chat_msg_combat", ({
	        (: this_object(), "random_move" :),
	        (: do_hold :),
	        (: do_hold :),
       	 }) );
	setup();

}

void do_hold()
{
	object me,victim;
	me=this_object();
	if(!me ) return;
	if(!me->is_fighting()) return;
	victim=offensive_target(me);
	if(!victim) return;
	
	message_vision(HIW"$N對$n吐出一堆黏液，"NOR,me,victim);
	if(random(victim->query_dex()*3+victim->query_skill("dodge")) < random(200))
	{
		message_vision(HIW"$n閃躲不及而被黏液噴中，動彈不得。"NOR,me,victim);
		victim->start_busy(2);
		return 1;
	}
	else message_vision(HIW"但被$n機警的閃了過去。"NOR,me,victim);
	return 1;
}


// ★★★★★ 複雜動作之野獸(特攻部分寫成npc專用技能)

#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N張大嘴巴往$n的$l猛咬",
		"attact_type":  "bar",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"咬傷",
	]),
	([	"action":		"$N奮力往$n的$l撞了過去",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	([	"action":		"$N吐出橘黃色胃酸對準$n的$l噴了過去",
		"attact_type":  "bio",
		"damage_type":	"腐蝕",
	]),
	([	"action":		"$N張開大嘴對準$n的$l吐出一堆垃圾",
		"attact_type":  "bar",
		"damage_type":	"撞傷",
	]),
});

void do_clean();

void create()
{
        set_name("野槌",({"yeah chuay", "yeah","chuay" }) );
	set("long",@LONG

  牠就是傳說中的魔獸野槌, 外表看起來像是一隻巨大的蛆, 巨大的
嘴巴周圍露了好幾層的牙齒。牠的性情十分溫和, 但肚子卻永遠填不
飽。偶而會出現在有許多垃圾的地方, 曾經有人看過牠在一天之內把
一整座山的垃圾吃得乾乾淨淨, 所以人們又稱他為『食圾蟲』。

LONG
);
        set("title","魔獸");
        set("limbs", ({
		"頭部",	"頸部",	"胸口",	"後心",	"腰間",	"腹部",	"大嘴","尾巴",
	}) );
        set("age",500+random(99));
        set("level",40);
        set("dex",58);
        set("gender","雄性");
        set("race","妖魔");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"野槌舔了舔嘴唇, 緩緩的四處蠕動。\n",
  	"野槌的身體似乎越來越大了。\n",
}));
	set_skill("mob_bite", 64);
	set_skill("dodge", 37);
	set("addition_armor",42);
	set("addition_damage",48);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
	        (:command("exert mob_bite sacer"):),
	          (: do_clean :),
       	 }) );
	set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
	carry_object(__DIR__"eq/sacer_armor.c")->wear();
}

void do_clean()
{
        object ob,env,*item,obj;
        int i,k=0;

	ob=this_object();
	if(!ob) return;
	if( ob->is_busy() ) return;
	env=environment(ob);
	if(!env) return;
	item=all_inventory(env);
	if(sizeof(item)>1)
	{
	 for(i=0;i<sizeof(item);i++)
	 {
	  if(item[i]->is_character()) continue;
	  if(item[i]->query("no_get")) continue;
	  k++;
	 }
	 if(k>1)
	 {
	  obj=item[random(sizeof(item))];
	  if(obj->is_character()) return;
	  else if(obj->query("no_get")) return;
	  message_vision("$N張開大嘴把$n吞進了嘴裡。\n",ob,obj);
	  ob->receive_heal("hp",1+random(30));
	  destruct(obj);
	 } else 
	 {
	  	message_vision("$N突然伸直身體, 緩緩的鑽進了地底。\n",ob);
	  	destruct(this_object());
	 }
	}
	return;
}

mapping query_action()
{
	return combat_action[random(sizeof(combat_action))];
}

void die()
{
	object ob,env,*item;
	int i;
	
	if( !ob = query_temp("last_damage_from") )
	ob = this_player(1);
	env=environment(this_object());
	if(!env) return;
	item=all_inventory(env);
	for(i=0;i<sizeof(item)/2;i++)
	{
	  if(item[i]->is_character()) continue;
	  if(item[i]->query("no_get")) continue;
	  destruct(item[i]);
	}
	message_vision("  $N用最後的力氣一口氣吞下了附近大半的東西。\n",this_object());
	if( !ob )
	{
		::die();
		return;
	}
	message("world:world1:vision",
	CYN"\n  [小道消息] 傳說中的魔獸野槌被"+ob->name(1)+"殺死了。\n\n"+NOR
	,users());
	::die();
	//destruct(this_object());
	return;
}