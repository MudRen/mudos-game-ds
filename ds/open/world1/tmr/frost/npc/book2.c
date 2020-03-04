#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�H�Ѥ����v���A�ϰf�������ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o���ͱO�`�A�κI���R���ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�q�f�g�D�A�Ѯ`�a�ꪺ�ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�]�ð��שh���n�f�ΰ��k���ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�����D�k�A���n�g�媺�ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�����R�¡A���r�S���ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�ۭ�t�h�A�ܤH�]�����ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�r�S�T���A����ѯf���ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF�o�԰s���ʡA��޴c�f���ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
                "damage_type":  "����",
        ]),
        ([  "action":       "$nŪ��$N�A�o�{�ۤw�H�ϤF���o�����ۥ��A�ۧ@�§Q���ٱ�",
                "attact_type":  "sou",
                 "damage": 10,
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
        set_name("���ٳ�",({"against book" ,"book", "_AGAINST_BOOK_"}));
        set("gender", "�k��");
        set("long",@LONG
�o�O�D���D�ä��̦��W�u���D�C�ҡv�������ٳ��C���Y�O��
�F�Q�١B�ӤW�}���F�_���]�_�u�w�Ӵ��z���@�j�١B�Ӿ]��ѤQ
���Q�c�ηL�w�Ӹg�Q�ٵ��ٱ��C
LONG
        );
          set("level",32);
        set("age",300);
          set("attack_merits", "sou");
        set("title","���D�C��");
        set_skill("parry", 100);
        set_skill("block", 100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("attitude", "aggressive");
        set_temp("fly",1);

        setup();
        set_temp("apply/damage",100);
        set_temp("apply/armor",200);
        set_temp("apply/shield",200);

        if(random(10)>=7) carry_object(__DIR__"obj/book2");

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

