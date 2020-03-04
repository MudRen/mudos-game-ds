#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N�i�j�L�ڴµ�$n��$l�@�}�r�r",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "�r��",
        ]),
        ([      "action":               "$N��M��$n����V���F�L�h",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([      "action":               "$N���$n��$l�r�M�R�X�@�D�H��",
                "attact_type":  "bio",
                "damage_type":  "�G�k",
        ]),
    ([  "action":       "$N���㪺�R�ʧQ���g��$n��$l",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
});

void do_clean();

void create()
{
        set_name(HIW"�N��"NOR,({"cold moon monster", "monster" }) );
        set("long",@LONG
�N�묰�@�������պG�H���]�~�A�����T�ئ��l�A��ʳߴH�A�Ⲵ�`��
�a�����սu�A�ӦӪ����I�l�ᵲ�F�|�P���Ů�A�����Ȥ򦥦��a�����H��
���A�L�H���D�N��q��ӥ͡A�u���j�Ѭ۶Ǫ��@�y�֡G�u�J���J�]���i��
�A�N��H��R����C�v
LONG
);
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "�I��","�y��"
                ,"����","�e��","��L","����",
        }) );
        set("title","�u�]�~�v");
        set("age",500+random(99));
        set("level",50);
        set("gender","����");
        set("race","monster");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
        "�N��o�X�}�}���R�q�n�C\n",
        "�N�먭�W���B�����b�a�W�o�X�ست��n���C\n",
        "�����M�j�_�@�}�H���᪺���H�ݤ��L��ӡC\n",
        "�����M�j�_�@�}�H���᪺���H�ݤ��L��ӡC\n",
        }));
        set_temp("coldmoon_posion",100);
        set_skill("mob_bite", 80);
          set("addition_armor",100);
    set("Merits/wit",3);
        set("addition_damage",50);
        add("apply/hit",50);

        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object(__DIR__"wp/moon_tooth.c")->wield();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
           HIG"\n�i��������j"+HIW"�ϤH�D�����x���N���~�ש�Q"+ob->name(1)+"�����F�C\n\n"+NOR,users());
            ob->add("popularity",3); //�n��
        ::die();
        return;
}

