#include <ansi.h>
inherit NPC;
void create()
{
        set_name("強盜", ({ "bandits" }) );
        set("long","看起來一臉凶神惡煞的樣子，常常賴賬不給錢，還會無故出手打人，搶\n"
                   "路人的財物。\n");
        set("level",20+random(10));
        set("age",18+random(3));

        set("chat_chance", 4);
        set("chat_msg", ({
  "強盜說：快把身上的錢交出來\n",
  "強盜說：要錢要命...\n"
}));
        
        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (:command("say 花錢消災，給錢了事！"):),
                (:command("wield all"):),
                (:command("say 快給錢不然殺你全家！"):),
                (:command("say 『格老子的』！！！敢攻擊我，活得不耐煩了！"):),
                       }) );
        
        set_skill("blade", 80);
        set_skill("parry", 70);
        set_skill("unarmed", 76);
        set_skill("dodge", 65);

        setup();
        carry_object(__DIR__"obj/steelblade")->wield();
        carry_object(__DIR__"obj/banditspants")->wear();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(4)) return 0;
     if( !me->query_temp("weapon") ) return 0; 
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIR"$N大喊一聲 『格老子的』，不要命的衝向$n，揮刀亂砍......\n"
                    +"$N迅速地往$n撞上去，$n閃避不急，重了數刀\n"NOR
                    ,me,target);
      target->receive_damage("hp",50+random(50), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N大喊一聲 『格老子的』，不要命的衝向$n，揮刀亂砍......\n"
                    +"$N迅速地往$n，但是$n在千鈞一髮之際往右急閃......\n"
                    +"$n雖然閃過$N的正面撞擊，但還是不小心被$N手上的鋼刀給砍傷了......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",25+random(25), this_object());
      return 1;
    }
}



