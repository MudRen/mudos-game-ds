#include <ansi.h>

inherit NPC;

void create()
{
        set_name(HIW"石魔巨人"NOR, ({ "evil man-stone","stone" }) );
        set("long",@LONG
 石魔巨人，是為了讓入侵古墓禁地的人所設計的，高大
 ，寬碩，全身的石子緊密地結合，為維護古墓的平衡的
 重要功臣。
LONG
);  
        set("gender", "男性");  
        set("race", "beast");
        set("attitude","aggressive");
        set("level",40);
        set("age",2014);
        set("evil",-20);
        set("title",MAG"迷宮守護者"NOR); 
        set_skill("unarmed",100);
        set_skill("dodge",80);
        set_skill("combat",90);
        set("combat_exp",120000);
        set("max_exp",10000);
        set("max_hp",4000);
     setup(); 
        carry_object(__DIR__"stone-fist")->wield();
        carry_object(__DIR__"stone-armor")->wear();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(4)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIW"$N奮力的往自己身上拍了一下，瞬間...身上的石子爆射開來....\n"
                    +"數以百計的石子飛向$n........！！\n"
                    +"$n慌張無所措，硬生生被砸得渾身是傷......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",200+random(180), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIW"$N奮力的往自己身上拍了一下，瞬間...身上的石子爆射開來....\n"
                    +"數以百計的石子飛向$n........！！\n"
                    +"$n巧妙的閃過$N的射擊，不料還是被碎石打到......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",100+random(80), this_object());
      return 1;
    }
}

