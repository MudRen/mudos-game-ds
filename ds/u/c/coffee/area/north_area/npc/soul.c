#include <ansi.h>
inherit NPC; 
mapping *combat_action = ({
        ([      "action":  
   "$N使出了腳踏個陣勢，施展"HIR"「"HIC"移形換影"HIR"」"NOR"，然後暗中突襲$n，使$n身上出現了數條血痕！！",
                "attact_type":  "dex",
                "damage" : 700,
                "damage_type":  "迷暈傷",
        ]),
        ([      "action":  
   "$N集中內力，施展恐怖的"HIG"【"HIR"閃靈"HIB"滅"HIB"魔"HIY"爪"HIG"】"NOR"，頓時"HIR"鬼哭神號"NOR"，擊中$n的胸口，讓$n無法招架，彷彿胸口將爆裂開來！！",
                "attact_type":  "bar",
                "damage" : 600,
                "damage_type":  "爆裂傷",
        ]),
        ([      "action":
   "$N默念了一道咒語"HIG"『"HIB"震魂咒"HIG"』"NOR"，頓時地面狂震，彷彿要裂開了！！頓時震傷了$n，導致$n吐了口鮮血！",
               "attact_type":  "con",
                "damage" : 800,
                "damage_type":  "創傷",
        ]),
});

void do_clean();

void create() 
{ 
  set_name(HIR"影爪魂"NOR, ({ "umbra-claw soul", "soul" }) );
  set("race", "human");
  set("level",60);
  set("max_hp",15000); 
  set("str",120); 
  set("con",120); 
  set("int",100); 
  set("dex",100); 
  set("title",HIR"幻"HIC"影"HIW"之"HIY"魂"NOR);
  set("combat_exp",1000000); 
  set("attitude","friendly");
  set("long",@LONG        
牠看起來十分溫馴，但是眼神確十分可怕。牠原本是在洞口
附近居住，守護著附近的動物野獸。但是因為陰錯陽差，牠
遭到山崩塌下來的山壓死，心中開始種下悔恨之意。牠開始
長期居住在這個古洞穴長達一千年。看著牠長長的爪子，不
禁讓人感到恐懼！！
LONG); 

  setup();
   carry_object("/u/c/coffee/area/north_area/eq/soul_armor")->wear();
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object("/u/c/coffee/area/north_area/eq/soul_armor")->wear();

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
HIB"\n\t※"HIY"千年古洞"HIB"※"HIG"再古洞裡為非作歹的妖魂"HIB"「"HIR"影爪魂"HIB"」"HIG"終於被勇士"HIC+ob->name(1)+HIG"消滅了！！\n\n"+NOR,users());
        ob->add("popularity", 5); //聲望
  switch( random(100) )
  {
    case  0..10: new("/u/c/coffee/area/north_area/wp/soul-sword")->move(this_object());
          break;
  }
        tell_object(ob,HIG"(因為你殺死了影爪魂，所以得到了 5 點聲望。)"NOR);
        ::die();
        //destruct(this_object());
        return;
}

