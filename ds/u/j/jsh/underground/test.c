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
        set_name(HIR"���Ƥ�"NOR, ({ "ant king","king" }) );
        set("long",@LONG
���ӬO�@���p����, �X�d�~�e�i��O����Y�Ǧ]��. ���餣����ı���ܤj
, �ٷ|����, �ۺٿ��Ƥ�,  ���O�Q�j�N���i�h�Ҿ�, ���b�@���Ϋ�����, 
�����D���h�֦~�S�X��, �U�ʤ]�ܪ����ݵL��CLONG
);
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "�I��","����","�e�}","��}","����",
        }) );
        set("title",HIG"�Ƥ�����"NOR);
        set("age",500+random(140));
        set("level",60);
        set("gender","����");
        set("race","monster");
        set("attitude", "aggressive");
        set_skill("mob_bite", 100);
        set("addition_armor",92);
        set("Merits/wit",5);
        add("apply/hit",60);
        set("addition_damage",600); 
        set("addition_armor",600);
        set("chat_chance_combat", 24);
        set("chat_msg_combat", ({
                (:command("say ����������.."):),
                         }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object(__DIR__"redarmor")->wield(); 
        carry_object(__DIR__"redtooth");}
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
        HIG"\n  [��      ��] "+HIR "���ݪ��u �� �� �� �v�Q+ob->name(1)+"�����F�C\n\n"+NOR,users());
        ob->add("popularity",2+random(4)); //�n��
        ::die();
        //destruct(this_object());
        return;
}

