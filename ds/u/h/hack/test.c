#include <ansi.h>
inherit NPC;

void create()
{          set_name(HIC"遠古"HIY"皇帝"HIR"蚩尤"NOR,({"tsz juioa","ts","ju"}) );
      set("title",HIC"遠古"HIY"皇帝"NOR);
set("long" ,"「遠古皇帝 蚩尤」為一遠古生物，早在盤古開天闢地的同時
  ,蚩尤 就存在了,為當今的一代霸王,手持的 虎魄 神刀 讓他足
  以天地稱皇。
\n");
               set("race", "人類");    
        set("unit","隻");
        set("age",6542879);
        set("level",50);
        set("attitude", "heroism");    
         
        set("chat_chance_combat",50);
        set("chat_chance", 10);
        setup();
        carry_object("/u/t/tako/tiger-blade")->wield();
        carry_object("/u/t/tako/tiger-armor")->wear();
}
void die()
{
   object ob,obj;
        if( !ob = query_temp("last_damage_from") )
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
   HIG"\n【武林消息】"+HIW "遠古黃帝「蚩尤」死在"+ob->name(1)+"的手中。\n\n"+NOR
        ,users());

        }





