#include <ansi.h>
inherit NPC;

void create()
{
        set_name(YEL"�����"NOR, ({"Longhair Monster", "monster","longhair"}) );
        set("long", "
�@�ӥ����������Ħ���򪺥~�P�H�A�L�����ʧ����j�A�S�F�@������X�ӡA
�ݰ_�Ӧn���b�Ȥf�����ˤl�A�[�W�@�ƴc�������������n�ۧA�@�A
�ϧAı�o���G�n��A���]�F���Pı�A�ݨӤ����N�ӹ藍�_�ۤv�F�C�I\n");
        set("race", "monster");
        set("gender", "�k��"); 
        set("age", 83);
        set("level", 20);
      set("bellicosity",10000);
        set("evil", -90);
        set("combat_exp",900);
        set("env/wimpy", 25);        
        set("chat_chance", 3 );
        set("chat_msg", ({   
        "����ǵo�X�q�q���C�I�n��\n",
        "����ǭI�W�����Ħ������ݤF�_��\n",
        (:command("say"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("say Fresh meat"):),
        (:command("say �۴M����"):),
        }) );
        setup(); 
}


