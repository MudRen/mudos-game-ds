#include <ansi.h>
inherit NPC;
inherit __DIR__"fight_ai.c";

void create()
{
        set_name(HIG "��Ž" NOR, ({"treebeard ents", "treebeard", "ents","_BLOOD_FIELD_NPC_" }) );
        set("long",@long
��H�O�@�ع����몺�ͪ��A�L�̶V�ӶV�����C�C�ⵥ�C�L�̤]���@��
�P�R���z�I�A���Τ@�ǯ����˾�H�����j����C�@�W��H�q�`�u�@�ۯS�x
���جۦ������A��H�����]�ܹ��s����]���B�]���^�C��Ž�O��H�ڸ�
�����ѡA���D�`�j�������X�C
long
);
        set("title","��{�");
                set("race","evil");
                set("level", 55+random(10));
        set("age", 320);
        set("chat_chance", 8);
        set("chat_msg", ({
               (: command("think") :),
               (: command("hmm") :),
        }) );
                /* �԰��ʧ@ */
                 set("chat_chance_combat", 50);
                 set("chat_msg_combat", ({
                        (: do_fight_help :),        
                 }) );
                  
        set("attitude", "aggressive");
        set("addition/bar", 10);
        set("addition/wit", 10);
        set("addition/bio", 2);
        set("addition_armor", 300);
        set("max_hp",20000);
        setup();
        set_temp("apply/hit", 200);
        set_living_name("_BLOOD_FIELD_NPC_");
                carry_object(__DIR__"obj/q_stone");
                carry_object(__DIR__"obj/q_stone");
                carry_object(__DIR__"obj/q_stone");
}

