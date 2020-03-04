#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":       "$N�i�j�L�ڴµ�$n��$l�@�}�r�r",
                "attact_type":  "bar",  // �]�w�ޯ઺��������
                                        // ������ �ͪ�(bio) �~��(bar)
                                        // �]�k(wit)���F(sou)���(tec)
                "damage_type":  "�r��",
        ]),
        ([      "action": "$N��M��$n����V���F�L�h",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
        ([      "action": "$N�@�i�L�A���$n��$l�R�X�@�D���y",
                "attact_type":  "bio",
                "damage_type":  "�N��",
        ]),
        ([      "action": "$N��M�����ư��@�Τ��y�r�M��$n�����h",
                "attact_type":  "bio",
                "damage_type":  "�N��",
        ]),
        ([  "action":       "$N���㪺�R�ʧQ���g��$n��$l",
                "attact_type":  "bar",
                "damage_type":  "���",
        ]),
});

void create()
{
        set_name(HIY"�H��"NOR,({"freeze sun monster", "monster" }) );
        set("long",@LONG
�H���~���������F�����⪺����A�����������������ۧA�A���G�ئ�
�l�����ڦ��G�a�ۤ��᥿�b�L�L�̰ʡA��������e�����𥿱q�H���~���W
���������o�X�ӡA�|�P�򪺮�Ŧ��G�]�V�ͪm�˪��{�סC
LONG
);
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "�I��","�y��","����","�e��","��L","����",
        }) );
        set("title","�]�~");
        set("age",500+random(99));
        set("level",66);
        set("gender","����");
         set("race","beast");
        set("attitude", "aggressive");
        set("chat_chance", 13);
        set("chat_msg",({ 
                "�@��������]��q�H���~���W����۴��o�X��....\n",
        }));
        //set_skill("mob_bite", 84);
        set("addition_damage",120);
        set("addition_armor",120);
        set("Merits/wit",3);
        add("apply/hit",60);
        set("chat_chance_combat", 42);
        set("chat_msg_combat", ({
        }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
         carry_object(__DIR__"eq/mask")->wear();
}
mapping query_action()
{
        return combat_action[random(sizeof(combat_action))];
}

void die()
{
        object ob;
        object body; // ���H����
        
        if( !ob = query_temp("last_damage_from") ) ob = this_player(1);
        if( !ob )
        {
                ::die();
                return;
        }
        message("world:world1:vision",
        HIG"\n�i�Z�L�����j"HIW"�K���T�a���u�@�~-�H�� ���M�Q"+ob->name(1)+HIW"�����F�I�I\n\n"+NOR,users());

        ob->add("popularity",3); //�n��
        if( random(100)<30 )
                body=new("open/world1/tmr/bagi/npc/obj/doll_body");
        else  if( random(100)<30 )
                body=new("open/world1/tmr/bagi/npc/obj/left-leg");
        else
                body=new("open/world1/tmr/bagi/npc/obj/left-arm");

        body->move( this_object() );
        ::die();
        return;
}

