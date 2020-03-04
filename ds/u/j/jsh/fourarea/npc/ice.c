#include <ansi.h>

inherit NPC;

void create()
{
        set_name("元素", ({ "element" }) );
        set("long",@LONG
全身覆蓋著雪霜的謎，是四大元素之一。 
LONG
);  
        set("gender", "男性");  
        set("race", "人類");
        set("attitude","aggressive");
        set("level",50);
        set("age",10000+random(75));
        set("evil",20);
        set("title",HIC"冰"NOR); 
        set_skill("unarmed",200);
        set_skill("dodge",200); 
        set_skill("parry",200);       
        set_skill("combat",200);
        set("combat_exp",500000);
        set("max_exp",50000);
        set("max_hp",30000);
     setup();  
     carry_object(__DIR__"obj/tear-ice");
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
                    +HIC"$N腳跟微提.....眼睛微瞇了一下...\n" NOR    
                +HIC"一顆顆的冰球飛向$n........！！\n"NOR
                    +HIR"$n被數以千顆的冰球砸到，造成嚴重的瘀傷..!!!\n"NOR
                    ,me,target);
      target->receive_damage("hp",1000+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
     +HIC"$N腳跟微提.....眼睛微瞇了一下...\n" NOR               
     +HIC"一顆顆的冰球飛向$n........！！\n"NOR                
     +HIR"$n左閃右躲的跑來跑去，但是數量真是太多了，還是被掃到幾顆......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",500+random(100), this_object());
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
    HIC"\n【元素之謎】"+HIW "元素「 冰 」的生命，就融化在"+ob->name(1)+"的手裡。\n\n"+NOR     
       ,users());
        ob->add("popularity",10); 
     message_vision( "$N"+BLU  "像融化般的，慢慢地 . . . 慢慢的不見 .  . "NOR ,this_object() ); 
        ::die();
        return;
}

