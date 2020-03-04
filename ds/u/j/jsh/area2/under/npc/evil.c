#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIR"魔"NOR, ({ "evil" }) );
        set("long",@LONG
長年壓制在地底下，與天妖乃同出一轍，生性好強，對污濁
它的生物，只有「死」這個辦法。 
LONG
);  
        set("gender", "男性");  
        set("race", "人類");
        set("attitude","aggressive");
        set("level",45+random(10));
        set("age",200+random(100));
        set("evil",-20);
        set("title",HIC"天"NOR); 
        set_skill("unarmed",120);
        set_skill("dodge",150); 
        set_skill("parry",100);       
        set_skill("combat",100);
        set("combat_exp",200000);
        set("max_exp",80000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/evil-armor")->wear();
     carry_object(__DIR__"obj/evil-spear")->wield();  
     //carry_object(__DIR__"obj/evil-eye");   
     carry_object(__DIR__"obj/evil-pants")->wear();
     carry_object(__DIR__"obj/evil-cloak")->wear(); 
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance*10) > tdex+tcon)
    {
      message_vision("\n"
                    +HIR"$N忽然向後一躍........\n" NOR     
                    +HIR"~ 轟 ! ! ~ 的一聲........！！\n"NOR
                    +HIR"一道火束疾向$n而去，造成嚴重的燒傷..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",300+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N忽然向後一躍........\n" NOR         
           +HIR"~ 轟 ! ! ~ 的一聲........！！\n"NOR                    +HIR"$n巧妙的閃過$N的火束，不料還是被餘燄給燒到......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",200+random(100), this_object());
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
 HIC"\n\t\t\t  "+ob->name(1)+"與眾位英雄大戰天魔數百回合後，伺機擊向天魔的天靈！！\n\n"+NOR   
    HIR"\n\t\t       一掌粉碎了天魔的元靈顱骨，天魔應聲倒地，邪靈從破碎的顱骨疾出！！\n\n"+NOR   
    HIW"\n\t\t\t\t\t　幻化為無數白光，破雲而逝！！\n\n"+NOR,users());  
   //HIG"\n\t\t\t\t\t 直直奔向幽靈聖地──《修羅域》\n\n"+NOR
        ob->add("popularity",6); 
        ::die();
        return;
}

