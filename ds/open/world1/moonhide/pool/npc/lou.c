#include <ansi.h>
inherit NPC;

void create()
{
      set_name(HIB"竭達羅" NOR,({"gua da-lou","lou"}) );
      set("title",HIC "英雄" NOR);   
      set("long",@LONG
與巨鵰對抗的英雄，本被巨鵰殺死，但經過妖精的巧手，
又再度復活，也且得到妖精之石，打造一把舉世無雙的神
弓，打算再與巨鵰來一場生死鬥。
LONG    
        );
        set("race", "human");    
        set("unit","隻");
        set("age",80);      
        set("level",70); 
        set("max_ap",10000);
        set("max_mp",10000); 
        set("max_hp",20000);
        set("combat_exp",600000);    
        set("limbs", ({ "頭部", "腹部","胸部","手部","腳部" }) );      
        add("addition_armor",300);
        add("addition_damage",300);  
        set("chat_chance", 100);
        set("chat_msg", ({
  (: command("reload bolt") :), 
}));
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
  (: command("shoot") :),   
  (: command("shoot") :),   
  (: command("cast shiro-spell") :),  
  (: command("cast shiro-spell") :),  
  (: command("reload bolt") :),    
  (: command("wield bow") :), 
})); 
      set_spell("shiro-spell",100);      
      set_skill("force",100);
   setup();
      carry_object(__DIR__"obj/purple-bow")->wield();   
      carry_object(__DIR__"obj/bolt"); 
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt"); 
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt"); 
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
      carry_object(__DIR__"obj/bolt");
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
        message("world:world1:vision",
    HIG"\t\t\n【不可能 之訊】"+HIB " ※竭達羅※"+HIW"與"+HIB"※"+ob->name(1)+"※"+HIC"戰的筋疲力盡！\n\n"      
    HIW"\t\t雙方在最後一擊的時候，"+HIB"竭達羅"+HIW"竟然"+HIR"輸"+HIW"了••••\n\n"+NOR,users());
        ob->add("popularity",9+random(3));  
        ob->set("guild_rank",HIB"竭達羅"HIW"之"HIR"抗鬥勇士"NOR);
        ::die();
        return;
}
