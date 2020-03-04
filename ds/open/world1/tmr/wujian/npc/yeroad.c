#include <ansi.h>

inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N��������$n��$l",
                "attact_type":  "sou",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "���",
        ]),
        ([      "action":               "$N��$n��$l�@��",
                "attact_type":  "sou",
                "damage_type":  "���",
        ]),
        ([      "action":               "$N��$n��$l�����a��F�@�}",
                "attact_type":  "sou",
                "damage_type":  "���",
        ]),
        ([      "action":               "$N���_���Y��$n��$l���h",
                "attact_type":  "sou",
                "damage_type":  "���",
        ]),
        ([      "action":               "$N���$n��$l�ΤO���X�@��",
                "attact_type":  "sou",
                "damage_type":  "���",
        ]),

});

/* �۩w�԰��T�� */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}


void kill_ob(object ob)
{
        object *guard;
        int i;
        if(!ob || ob==this_object()) return;
        ::kill_ob(ob);

                 guard = all_inventory(environment(this_object()));
        for(i=0;i<sizeof(guard);i++) {
                if( !guard[i]->id("_WUJIAN_") ) continue;
                if( guard[i] == this_object() ) continue;
                if( guard[i]->is_killing(ob->id()) ) continue;

                // guard to kill
                guard[i]->kill_ob(ob);
        }
}

int special_attack(object me,object target,int hitchance) {
                int dmg;
                if( is_busy() ) return 0;
                if( query_temp("do_attack") ) return 0;
            // 30%���v�o�ʯS��
            if( random(100) < 70 )
                return 0;

                dmg = query_damage() + random(query_damage());
                dmg = COMBAT_D->Merits_damage(me,target, dmg,"sou");

                if(dmg <1) dmg = 1;
        message_vision(HIY"\n�~�~�F�]��ư��ƦʹD�P�K�R�ѡA���O���W���ޡi�@���@�s�@���@�]�@��@�j�I�I\n"
                        +HIR"�Ʀʱ��K���������D��¶�W$n"HIR"�A�b�G�s�n���ư����H�I�I("+ dmg + ")\n\n"NOR, me, target);
         target->receive_damage("hp", dmg, this_object());
         target->receive_damage("ap", 1 + dmg/2, this_object());
        return 1;
}


void create()
{
        set_name(HIR "�~�~�F" NOR,({"yeroad spirit", "yeroad","spirit",  "_WUJIAN_"}));
        set("gender", "�k��");
        set("long",@LONG
�X�����ҡA�b�Ʀʦ~�e�O�P�����áB�������X�١u�T�~�P�v���׻a��
���j�]�Y�A�B�����������A�ߦ��@���Ѭ���ѼġC�~�~�F�۱q���R�E
�T�ɴ��X����A�Y�P�����áB�������B�Q�T���F�j�x�W�ҡA�y�����F
��C���T�~�P���z�I�X�X�i�Q�C�ڧl�p�w�ҤơX�X�Q���x��A�Q�y
�@�C�L�ҤƩ�C�P����O�A�u���ǥѤ@�f�u�����󹮭ưk�X������
�è��W�C�o�q�ɶ����A�å����Ӥj�@���C
LONG
        );

        set("level", 50);
        set("age", 400);
         set("race","tiger");
        set("title", CYN "�T�~�P" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("sword",100);
            set("max_hp",15000);
        setup();
        set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
                carry_object(__DIR__"obj/liyuan-claw")->wield();
                if(random(3)==1) carry_object(__DIR__"obj/mercury-lode");

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }

         ob->add("popularity", 2);
         tell_object(ob,HIG "(�A��o 2 �I�n��C)\n" NOR);

        ::die();

        return;
}


