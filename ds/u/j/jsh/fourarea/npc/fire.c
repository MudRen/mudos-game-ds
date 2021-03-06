#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"元素"NOR, ({ "fire-element","fire","element" }) );
        set("long",@LONG
全身環繞著火燄的謎，是四大元素之一。 
LONG
);  
        set("gender", "男性");  
        set("race", "人類");
        set("attitude","aggressive");
        set("level",40);
        set("age",10000+random(100));
        set("evil",-20);
        set("title",HIR"火"NOR); 
        set_skill("unarmed",200);
        set_skill("dodge",200); 
        set_skill("parry",200);       
        set_skill("combat",200);
        set("combat_exp",500000);
        set("max_exp",50000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/fire-key");
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
                    +HIR"$N忽然向後一躍........\n" NOR                    +HIR"~ 轟 ! ! ~ 的一聲........！！\n"NOR
                    +HIR"一道火束疾向$n而去，造成嚴重的燒傷..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",600+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N忽然向後一躍........\n" NOR                    +HIR"~ 轟 ! ! ~ 的一聲........！！\n" NOR                    +HIR"$n巧妙的閃過$N的火束，不料還是被餘燄給燒到......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",300+random(100), this_object());
      return 1;
    }
}
void die()
{
   object ob,obj;
   obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
        message("world:world1:vision",
    HIC"\n【元素之謎】"+HIR "元素「 火 」的生命，就熄滅在"+ob->name(1)+"的手裡。\n\n"+NOR     
       ,users());
        ob->add("popularity",10); 
     message_vision( "$N"+BLU  "像熄滅般的，慢慢地 . . . 慢慢的不見 .  . "NOR ,this_object() ); 
        ::die();
        return;
}

