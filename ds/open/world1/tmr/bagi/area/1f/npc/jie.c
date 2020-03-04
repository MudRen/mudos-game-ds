#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SSERVER;

void do_attack();

void create()
{
        set_name("�P�H��",({"zhou ren jie","zhou","jie"}) );
        set("long",@long
�@�@�P�H�Ǫ������Y���j�A��ۤ@��K���I��A�S�X�������ު��٦סA�u
�O��西������r�y�W���ۤ@��Ӥp�������A�d��F�X�������C�P�H��
�O�U��������U�G�̤l�A�@����Y�\�Ҩϱo���ͭ��A�b����W�ᦳ�W��
�A�u�O�U����a�z�����A��������H����|���{�즹�C
long
);
        set("age",40);
        set("race","�H��");
        set("level",30);
        set("attitude", "peaceful");
        set("title","�U����ĤQ�T�N�̤l");
        set("gender", "�k��" );
        set("chat_chance",6);
        set("chat_msg",({
                "�P�H�ǳ��ۻy�a���D�G�O�ɤd���U�W�~�M�ӳo��A��a�N�A�]�S���䥦�i�ø�H...\n"
                "�P�H�ǹ�ۨ������̤l�ܹD�G�O���i�I�I�ֵ��ڥh�|�B��䦳�S���i�ê��a��I�I\n"
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
        add_money("coin",2000);
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
                 target_wp->set_durable((target_wp->query_durable() - 1 -random (3) ) );
        } else {
                message_vision(HIR"$N�{�����ΡA�Τ@���״x�w�O���U�F�o�������A���]�Q�_�a�R�����...\n"NOR,target);
                target->receive_damage("hp",50+random(20));
        }
        return ;
}

