#include <ansi.h>

inherit NPC;

void create()
{
        set_name("煦倥", ({ "xu kong","kong" }) );
        set("race","human");
        set("gender", "男性");
        set("level",38);
        set("age",70);
        set("evil",-15);
        set("title",HIR"聖炎龜使"NOR);
        set("long",@LONG
矮小、滿臉皺紋，白髮蒼蒼的老頭子，看起來弱不禁風，毫
不起眼，但是可別小看他了，他可是聖炎使者之中最具智慧
之人，而且他的炎術威力可是凌駕於其他術士之上的。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/gr_ring")->wear();
        carry_object(__DIR__"../wp/ds_staff")->wield();
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
                    +HIR"$N全身發出紅光，無比強大的火炎急遽壓縮在他體內......\n"
                    +"$N嘴一張，一道火炎光柱射出，貫穿了$n......\n"
                    +"$n已經瀕臨死亡了......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",180+random(100),this_object());
      target->apply_condition("blooding", target->query_condition("blooding")+2);
      me->add_busy(3);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N全身發出紅光，無比強大的火炎急遽壓縮在他體內......\n"
                    +"$N嘴一張，一道火炎光柱射出，雖沒直接命中但其所造成的風壓已經重打擊了$n......\n"
                    +"$n被風壓掃得飛了出去......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",80+random(30),this_object());
      me->add_busy(1);
      return 1;
    }
}
