#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({"Were Wolf", "wolf","WF"}) );
        set("long", "�O�j�L�a�����F��,�ӥB�㦳�H�������z,�b����ɧ��o���������O�q�I\n
ť���u���Ȼs���Z���~������F�L!\n");
        set("race", "���]");
        set("gender", "�k��"); 
        set("age", 83);
        set("attitude", "heroson");
        set("level", 5);
        set("evil", 99);
        set("combat_exp",500);
        set("chat_chance", 2);    
        set("chat_msg", ({   
        (:command("say �ڪ��W�l����!!!"):),
        (:command("hehe"):),
        "�����ݵۤ�G�j��...... �f�c �f�X �f�X �f�X ����\n",
        (:command("say ���!!���!!"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        "�����z�q�D:�������������\n",
        (:command(""):),
        }) );
        setup(); 
}

