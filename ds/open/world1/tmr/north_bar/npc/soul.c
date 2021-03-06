#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":  
   "$N使出了腳踏個陣勢，施展"HIR"「移形換影」"NOR"，身形消失於陰影之中，悄然現身突襲$n的$l！",
                "attact_type":  "bio",
                "damage" : 700,
                "damage_type":  "迷暈傷",
        ]),
        ([      "action":  

	    "$N集中內力，施展恐怖的"HIG"【閃靈滅魔爪】"NOR"，頓時數爪由於鬼哭神號似的抓向$n$l！",
                 "attact_type":  "bar",
                "damage" : 600,
                "damage_type":  "爆裂傷",
        ]),
        ([      "action":
   "$N默念了一道咒語"HIG"『震魂咒』"NOR"，頓時地面劇烈狂震，彷彿要裂開了！！",
               "attact_type":  "sou",
                "damage" : 800,
                "damage_type":  "震傷",
        ]),
});

void do_clean();

void create() 
{ 
  set_name( "影爪邪魂", ({ "umbra-claw soul", "soul" }) );
  set("race", "human");
  set("level",50);
  set("max_hp",15000); 
  set("str",120); 
  set("con",120); 
  set("int",100); 
  set("dex",100); 
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set("long",@LONG        
牠看起來十分溫馴，但是眼神卻十分可怕。影爪邪魂原本是在洞口
附近居住，守護著附近的動物野獸，但卻在一次的意外之中死於山崩，
死後屍身卻沒有任何人願意掩埋，因此他的魂魄漸漸充滿對人類的仇恨
，自此長期居住在千年古洞，已經殺害了不知多少的生物了。看著牠長
長的利爪，不禁讓人感到恐懼！！
LONG); 

  setup();
   carry_object(__DIR__"eq/soul_armor")->wear();
   carry_object(__DIR__"wp/soul-blade")->wield();
  set("actions", (: call_other, __FILE__, "query_action" :));

}
 mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
              HIB"\n\t"HIG"居住在千年古洞的惡靈「影爪邪魂」終於被勇者" + ob->name(1)+HIG"消滅了！\n"+NOR,users());
        ob->add("popularity", 2); //聲望
        tell_object(ob,HIG"(你得到了 2 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

