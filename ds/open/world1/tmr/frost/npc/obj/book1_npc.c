#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$n��Ū�D�w���u�ѧg���k�v�@���A�W�䤣�o���",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "�D�w�����@��u�Ҫ����ҥH�͡A�\\���ҥH���A���ͥG�L�ΡA�ΥѥG�L�W�v�A$n�W��}�[���M�L�k��|",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$n�J���p��u���q�D�͡v���[�q�A���W��}�[�A��������ҫ�",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
        ([  "action":       "$n��Ū�u�j�D���A�@�аI�A�ѤU��j�áv����r�A���o�VŪ�V�߷зN��",
                 "damage": 10,
                "attact_type":  "sou",
                "damage_type":  "����",
        ]),
});

/* �۩w�԰��T�� */
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void do_die() {
         message_vision(CYN "$N�Ƨ@�@�}���Ϯ����F...\n" NOR, this_object() );
         destruct(this_object());
}

// ���D�H�ɦ�
void do_heal() {
        object ppl;
        ppl = query("owner");
        if( !ppl || this_object()->is_fight(ppl) ) {
                message_vision(CYN "$N�Ƨ@�@�}���Ϯ����F...\n" NOR, this_object() );
                destruct(this_object());
                return;
        }

        if( ppl->query("hp") > ppl->query("max_hp")/4*3 ) return;
        if( environment(ppl) != environment(this_object()) ) return;
                
        message_vision(YEL "$N½�}�u���g�u�l�v�g�A�u���䤤����r���o�X���~...\n" NOR, this_object(), ppl);
        add("times", 1);
        if(ppl->is_fighting() )
                ppl->receive_heal("hp", 1 + ppl->query("max_hp")/30 );
        else
                ppl->receive_heal("hp", 1 + ppl->query("max_hp")/20 );

        tell_object(ppl, HIG "(�Aı�o�ۤw���ͩR�O�S������F�C)\n" NOR);
        if( query("times") >= 50 ) do_die();
}

void create()
{
        set_name("�D�w��",({"morality book" ,"book"}));
        set("gender", "�k��");
        set("long",@LONG
�o�O�D���D�ä��̦��W�u���D�C�ҡv�����D�w���C���Y�}�v
���q�g�ۡu�ӤW���H�A�����G�D�w�F�䦸���j�G�����F�䦸���j
�G�өM�F�䦸���R�G�Ѧa�F�䦸���ۥG�����F�䦸�����G�j�t�C
�ҹD�w�A�ҥH�i�D�Ӥ��i��]�v�C
LONG
        );
        set("level", 15);
        set("age",5);
        set("title","���D�C��");
        set_skill("parry", 50);
        set_skill("block", 50);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("fly",1);

        set("chat_chance",30);
        set("chat_msg",({
                (: do_heal() :),
        }) );

        setup();
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        set("actions", (: call_other, __FILE__, "query_action" :));
}

