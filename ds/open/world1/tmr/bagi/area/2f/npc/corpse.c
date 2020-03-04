#include <path.h>
#include <ansi.h>
inherit NPC;
inherit SSERVER;

void do_bite()
{
       object me,target;
        me=this_player();
        target = offensive_target(me);  // 敵人
        if(!me || !target) return;
        if(me->is_busy()) return;
        message_vision(HIR"$N張嘴露出滿口尖牙，「唰」地一聲咬掉了$n身上的肉....\n" NOR,me,target);
        target->apply_condition("blooding", 3);
}

void create()
{
        set_name("行屍走肉",({"walking corpse","corpse"}));
        set("long" ,@long
一具已經沒有靈魂的腐爛屍體，正緩慢移動地，一副會攻擊人的樣子。
long
);
        set("attitude", "aggressive");
        set("age", 40);
        set("gender","男性");
        set("level", 20);
        set("chat_chance",10);
        set("chat_msg",({
                (: random_move :),
        }) );
        set("chat_chance_combat",20);
        set("chat_msg_combat", ({
                  (:do_bite :),
                  (:command("bite") :),
        }) );
        setup();
        if( random(10)<3 )
                carry_object(TMR_PAST"bagi/npc/obj/right-leg");
}
