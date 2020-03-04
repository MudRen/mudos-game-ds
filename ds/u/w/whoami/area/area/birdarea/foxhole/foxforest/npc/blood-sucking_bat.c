#include <ansi2.h> 
inherit NPC;

void create() 
{
        set_name(HIW+BLK"噬血蝙蝠"NOR,({"blood-sucking bat","bat"}));   
        set("long","一種會飛的哺乳動物，形似老鼠，手足和身體都有膜相連如翼，\n"
                   "晝伏夜出，多捕食蛾、蚊，也有少數喜食人血•\n");         
        set("level",27+random(5));
        set("attitude", "peaceful");
        set("race", "野獸");
        set("max_hp",3500+random(4000));
        set("str",30+random(2));  
        set("dex",50+random(2));   
        set("addition_damage",75+random(20));  
        set("addition_shield",50);  
        set("Merits/bar",4+random(2));  
        set("Merits/wit",4+random(2)); 
        set("age", 26);
        set("limbs", ({ "頭部", "身體", "雙翼"}) );
        set("verbs", ({ "bite", "claw" ,"crash"}) ); 
        setup(); 
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(10)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();

    if(random(hitchance*20) > tdex+tcon)
    {
      message_vision("\n$N"HIY"一個俯衝向前，$n的身上就多了一個不停流血的齒痕…\n"+NOR,me,target); 
      target->receive_damage("hp",200+random(45), this_object()); 
      target->apply_condition("blooding", target->query_condition("blooding") + random(8));
      return 1; 
    }
}

void die()
{
        object me=this_object(),
               ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);

        switch( random(30) ){
         case 0:
          new(__DIR__"eq/bat_mask")->move(me);
         }
        if(!random(7)){
        ob->add("popularity",1); 
        tell_object(ob,HIG"你得到 1 點聲望。"NOR);  
        }     
        ::die();
        return;
}        

