#include <ansi.h>
#include <path.h>

inherit NPC;
inherit SSERVER;

// ����.
void do_arc() 
{
        object me,target,wp;
        me=this_player();
        target = offensive_target(me);  // �ĤH
        if(!me || !target) return;
        wp=target->query_temp("weapon");
        if(!wp) {
                command("exert sorgi_sword");
                return ;
        }

        message_vision(HIW "����@���A���M�X�{�@�D����e��V$n"HIW"���Z��������I�I\n" NOR,me,target);
        if( (target->is_busy() || random(100)<30  )  && wp->unequip()  ) {
                message_vision(HIC"�u��v"NOR"�a�@�n�T�A"HIC"����"NOR"���o$N�渨�F�⤤���Z���I�I\n" NOR ,target);
                target->start_busy(1);
        } else {
                message_vision(CYN "�u��v"NOR"�a�@�n�T�A����@���W$N�⤤���Z���ϦӳQ�_�H�F�I�I\n" NOR,target);
        }
}

void create()
{
        set_name("�ƺ~",({ "madman","man" }));
        set("long" ,@LONG
�@�ө��Y���v���ѤH�A��i�y���Q��v�G�l�B�h�j�b�A�u�S�X�Ŭ}��
�b���������A���ɦa�C�q���s�A���G�O�ӯ��g���ê��Ƥl���C
LONG
        );
        set("attitude","friendly");
        set("age", 60);
        set("level", 30);
        set("gender","�k��");
        set("race","�H��");
        set_temp("sorgitimes",12);

        set_skill("sword", 90);
        set_skill("dodge", 95);
        set_skill("force", 100);
        set_skill("parry", 80);
        set_skill("sorgi_sword",85);
        set_skill("fogseven",100);
        set_skill("moon_force",100);
        map_skill("sword","sorgi_sword");
        map_skill("dodge","fogseven");

        set("chat_chance",10);
        set("chat_msg", ({
                (: command("crazy madman") :),
                "�ƺ~���M�ƨg�몺��_�ۤw���G�l�A�����b�𸣤���...\n",
                "�ƺ~�����@½�A�L�̤����b�B���Ǥ���....\n",

        }));
        set_temp("class_wind/power",250);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
  		(: command,"exert sorgi_sword" :),
                (: do_arc :),
        }));
        setup();
        carry_object(__DIR__"wp/half-sword")->wield();
          carry_object(TMR_PAST"bagi/npc/obj/left-leg");
}

