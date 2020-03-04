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

void create()
{
        set_name("�D�w��",({"morality book" ,"book", "_MORALITY_BOOK_"}));
        set("gender", "�k��");
        set("long",@LONG
�o�O�D���D�ä��̦��W�u���D�C�ҡv�����D�w���C���Y�}�v
���q�g�ۡu�ӤW���H�A�����G�D�w�F�䦸���j�G�����F�䦸���j
�G�өM�F�䦸���R�G�Ѧa�F�䦸���ۥG�����F�䦸�����G�j�t�C
�ҹD�w�A�ҥH�i�D�Ӥ��i��]�v�C
LONG
        );
        set("level",30);
        set("age",300);
        set("title","���D�C��");
        set_skill("parry", 100);
        set_skill("block", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("attitude", "aggressive");
          set("attack_merits", "sou");
        set_temp("fly",1);

        setup();
        set_temp("apply/damage",100);
        set_temp("apply/armor",200);
        set_temp("apply/shield",200);
        if(random(10)>=8) carry_object(__DIR__"obj/book1");
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

        ob->add("popularity", 1);
        tell_object(ob,HIG "(�A���n��W�[�@�I�F�C)\n" NOR);

        ::die();

        return;
}

