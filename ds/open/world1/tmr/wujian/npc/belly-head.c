//buddha war �j�Y�� �p�Ӧ�

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

void combat_ai() {
                if( is_busy() ) return;
                if( query_temp("do_attack") ) return;
                message_vision(HIR "�������ʰʡu�R��\\���v�����ۡA�|�g��y�g�ۡA�������y�a�l���A�ۤW���ӡI�I\n" NOR, this_object());
                set_temp("do_attack",1);    // mark �קK�h������
                add_temp("apply/damage",50);
                add_temp("apply/hit",300);
                        attack();
                        attack();
                add_temp("apply/hit",-300);
                add_temp("apply/damage",-50);
                delete_temp("do_attack");
}


void create()
{
        set_name(HIR "������" NOR,({"belly-head spirit","spirit", "_WUJIAN_"}));
        set("gender", "�k��");
        set("long",@LONG
�X�����ҡA�b�Ʀʦ~�e�O�P�����áB�~�~�F�X�١u�T�~�P�v���׻a��
���j�]�Y�C
LONG
        );

        set("level", 45);
        set("age", 400);
         set("race","tiger");
        set("title", CYN "�T�~�P" NOR);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge",100);
        set_skill("sword",100);
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (:combat_ai:), 
         }) );        
                 setup();
            set_temp("apply/damage",100);
        set_temp("apply/armor",100);
        set_temp("apply/shield",100);
                carry_object(__DIR__"obj/liyuan-claw")->wield();
                if(random(3)==1) carry_object(__DIR__"obj/mercury-lode");

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
                carry_object("/open/world1/eq/bh_leg")->wear();
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


