#include <path.h>
#include <ansi.h>
inherit NPC;
inherit SSERVER;

void do_bite()
{
       object me,target;
        me=this_player();
        target = offensive_target(me);  // �ĤH
        if(!me || !target) return;
        if(me->is_busy()) return;
        message_vision(HIR"$N�i�L�S�X���f�y���A�u�|�v�a�@�n�r���F$n���W����....\n" NOR,me,target);
        target->apply_condition("blooding", 3);
}

void create()
{
        set_name("��ͨ���",({"walking corpse","corpse"}));
        set("long" ,@long
�@��w�g�S���F��G�����A���w�C���ʦa�A�@�Ʒ|�����H���ˤl�C
long
);
        set("attitude", "aggressive");
        set("age", 40);
        set("gender","�k��");
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
