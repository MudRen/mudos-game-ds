#include <ansi.h>
inherit NPC;

mapping *combat_action = ({
        ([      "action":               "$N�ϥX�y�����w��ù�� �����}�r�Z�z�A���V$n��$l",
                "attact_type":  "bar",       
                "damage_type":  "����",
        ]),
        ([      "action":               "$N�ϥX�y�����w��ù�� �������r�Z�z�A���V$n��$l",
                "attact_type":  "bar",
                "damage_type":  "�ζ�",
        ]),
        ([      "action":               "$N�ϥX�y�����w��ù�� ������r�Z�z�A���V$n��$l",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
        ([      "action":               "$N�ϥX�y�����w��ù�� ����⾦r�Z�z�A�ĦV$n��$l",
                "attact_type":  "bar",
                "damage_type":  "����",
        ]),
});
void create()
{
        set_name(HIR"��ù��"NOR,({"shiro king", "shiro","king" }) );
        set("long",@LONG
�W�j���Q���A�]���ӱj�F�A�Q�ѯ��ʦL�b�����̡A
�֦��H�����H�Q�����O�q�C
LONG
);
        set("title",HIC"����"NOR);
        set("limbs", ({
                "�Y��", "�V��", "�ݤf", "��y", "�y��", "����", "���}","�k�}",
        }) );
        set("age",200);
        set("level",70);
        set("race","human");
        set("addition_armor",300);
        set("addition_damage",300); 
        set_spell("shiro-spell",100);
        set_skill("force",100);
        set_skill("dodge",200);
        set("chat_msg_combat", ({
                (:command("cast shiro-spell"):),
         }) );
        set("default_actions", (: call_other, __FILE__, "query_action" :));
        setup();
        carry_object(__DIR__"obj/shiro-king-armor")->wear(); 
        carry_object(__DIR__"obj/shiro-king-spear")->wield();
}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        {
                ::die();
                return;
        }
        message("world:world1:vision",
        HIB"\n�i�^�����y�j"+HIC""+ob->name(1)+""+HIW"���\\���D�ԤF"+HIR"��ù��\n\n"+NOR
        ,users());
        ob->add("popularity",10); //�n��
        ::die();
        return;
}

