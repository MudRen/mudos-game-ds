#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIY"龍王"NOR, ({ "dragon king","king" }));
        set("long","幼龍塔的老大，殺傷力極度高。\n");

        set("race","野獸");
        set("level", 15);
        set("age", 533);  
        set("exp",5000);        set("title",HIR"幼龍谷"NOR);
        set("limbs", ({ "龍頭","尾巴","鱗甲","觸角","前腳","後腳","背鰭" }) );
        set("verbs", ({ "bite", "claw","poke" }));


       setup();
        add_money("coin",3000); 
carry_object(__DIR__"eq/dragon-helmet")->wear();
}
int special_attack(object me,object target,int hitchance)
{
    if(!me || !target) return 0;
    if(random(10)) return 0;
    {
      message_vision(HIR"龍王突然眼睛發光，向$n瘋狂的亂抓！！\n"NOR,me,target);
      target->receive_damage("hp",50+random(50), this_object());
      return 1; 
    }
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
HIW"\n\t\t"+ob->name(1)+""HIR"擊敗了幼龍塔 "HIW"龍王"HIR"，證明自己的實力已非新手！！\n\n"+NOR,users());
          ob->add("popularity",1); 
        ::die();

        return;

}

