#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
	([	"action":		"$N張大嘴巴用尖牙往$n的$l猛咬",
		"attact_type":  "bar",	// 設定技能的攻擊種類
					// 種類有 生物(bio) 獸性(bar)
					// 魔法(wit)心靈(sou)科技(tec)
		"damage_type":	"咬傷",
	]),
	([	"action":		"$N奮力往$n的$l撞了過去",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
	([	"action":		"$N吐出酸液對準$n的$l射了過去",
		"attact_type":  "bio",
		"damage_type":	"腐蝕",
	]),
	([	"action":		"$N一個轉身，巨大的尾巴旋風般的揮向$n的$l",
		"attact_type":  "bar",
		"damage_type":	"瘀傷",
	]),
});

void do_clean();

void create()
{
        set_name("鼠神",({"huge rat", "rat" }) );
	set("long",@LONG

  牠就是傳說中的巨大白鼠。牠的體型比人還高大，嘴巴裡的三顆尖
牙就像寶劍一般銳利。十分小心謹慎的牠，平常並不會出現在有人的
地方，但在有許多垃圾的地方偶而會有人看到牠。傳說所有的老鼠都
會聽從牠的指揮所以人們又稱他為『鼠神』。

LONG
);
        set("title","魔獸");
        set("limbs", ({
		"頭部",	"頸部",	"胸口",	"後心",	"腰間",	"腹部",	"尖牙","尾巴",
	}) );
        set("age",100+random(99));
        set("level",43);
        set("int",48);
        set("gender","雌性");
        set("race","monster");
        set("chat_chance", 36);
        set("chat_msg",({ 
  	(: do_clean :),
  	(: do_clean :),
  	(: do_clean :),
  	"鼠神舔了舔前腳。\n",
    "鼠神的肚子似乎越來越大了。\n",
}));
	set_skill("mob_bite", 72);
	set_skill("dodge", 77);
	set("addition_armor",62);
	add("apply/hit",70);
	set("addition_damage",69);
        set("chat_chance_combat", 38);
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
	  	message_vision("$N突然挖了個地洞, 迅速的鑽了進去。\n",ob);
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
	message("world:world2:vision",
	CYN"\n  [本日頭條新聞] 傳說中的鼠神被"+ob->name(1)+"殺死了。\n\n"+NOR
	,users());
	ob->add("popularity",1); //聲望
	::die();
	//destruct(this_object());
	return;
}
