#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SSERVER;

void do_attack();

void create()
{
        set_name("�P�^��",({"zhou ying jie","zhou","jie"}) );
        set("long",@long
�@�@�P�^�Ǫ����@�i���y�A���������A�ݰ_�Ӧ��G�O���ú~���ˤl�A
�����@�L�y�a�W�ت��@���ɨءA�W�Y���G�D�ۡu�U��v�G�r�A�@�L�o��
�~�����ҼˡA�ˤ]�ݤ��X�O�U������̤l�C
long
);
        set("age",25);
        set("race","�H��");
        set("level",25);
        set("attitude", "peaceful");
        set("title","�U����ĤQ�T�N�̤l");
        set("gender", "�k��" );
        set("chat_chance",6);
        set("chat_msg",({
                "�P�^�ǳ��ۻy�a���D�G�����v�S�����쩳�Ǥ��ǡA�o�ذ��a��|���_�öܡH\n",
                (: command("shrug") :),
        }) );
        set_skill("unarmed",80);
        set_skill("axe",80);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:do_attack:),
        }) );

        setup();
        carry_object(__DIR__"wp/huge-axe")->wield();
        carry_object(__DIR__"eq/armor")->wear();
        carry_object(TMR_PAST"bagi/npc/obj/right-arm");
}



void do_attack()
{
        object me=this_object(),target,wp,target_wp;
        target = offensive_target(me);  // �ĤH
        if(!me || !target) return;
        if(me->is_busy() ) return;
        if(!me->query_temp("weapon") ) command("wield axe");
        wp=me->query_temp("weapon");
        if(!wp) return;
        target_wp=target->query_temp("weapon");
        message_vision(HIW"$N�j�ۤ@�n�G�u�@��ʤs�ˡv�A�⤤����b��t���U�a�ۤ������V$n....\n"NOR,me,target);
        if( target_wp ) {
                message_vision(HIC"�u���v�a�@�n���T�A$N�Τ⤤$n"HIC"�פF�U��...\n"NOR,target,target_wp);
                target_wp->set_durable((target_wp->query_durable() - 1 ) );
        } else {
                message_vision(HIR"$N�{�����ΡA�Τ@���״x�w�O���U�F�o�������A���]�Q�_�a�R�����...\n"NOR,target);
                target->receive_damage("hp",20+random(10));
        }
        return ;
}

