#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIY"蚩尤"NOR,({"tsz joaur","joaur"}) );
        set("title", HIC"太古"HIY"帝王"NOR);
        set("long",
   "遠古皇帝 蚩尤」為一遠古生物，早在盤古開天闢地的同時 \n"   
   ",蚩尤就存在了,為當今的一代霸王,手持的 虎魄 神刀 讓他\n"
   "足以天地稱皇。\n"); 
        set("level",60);
        set("age",6542879);
        set("attitude", "heroism");

        set("combat_exp",30000);
            //set("max_hp",25000);
        set("chat_chance_combat",10);
        set("chat_msg_combat",({
  (: command("wield blade") :),
  "蚩尤說:你最好不要讓我出去,要不然.........\n",
  "蚩尤說:你就完了....!!\n",
}) );
        set("title",HIC"太古帝王"NOR);
        set("nickname",HIY"虎魄稱皇"NOR);
        set_skill("blade",130);
        set_skill("dodge",160); 
        set_skill("combat",100);
        set_skill("parry",101);
        set_skill("unarmed",120);
        setup();
        carry_object("/u/t/tako/tiger^^blade.c")->wield();
        carry_object("/u/t/tako/chiyo surcoat.c")->wear(); 
        carry_object("/u/t/tako/chiyo waist.c")->wear();
        carry_object("/u/t/tako/chiyo hold.c")->wear();
        carry_object("/u/t/tako/chiyo boots.c")->wear();
        carry_object("/u/t/tako/chiyo armor.c")->wear(); 
        carry_object("/u/t/tako/chiyo cloth.c")->wear(); 
        carry_object("/u/t/tako/chiyo pants.c")->wear();
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
        message("world:world1:vision", HIY"\n【武林消息】"+HIW "太古帝王「蚩尤」死在"+ob->name(1)+"的手中。\n\n"+NOR ,users());
        ob->add("popularity", 4);         ::die();
        return;
}

