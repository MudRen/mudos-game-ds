#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("�P�ڥj����", ({"traveller Antiquer","antiquer"}) );
        set("long", "�@��M�����������b�P�ڤ��@�ǡ��L���N�������_���ӤH�A�L�ҽ�
���F��ݰ_�Ӯ��_���ӥB���Z�S�Ϊ��A���L���Ū��ܧA�˥i�H��
�ݥL�˩��b��Ǭƻ�A�����w�A�|���N�~����ì���C
PS�L���i��=�����S�����O�y\n"); 
        set("limbs", ({ "�Y��", "����", "�}", "�k��","����","�ݤf" }) );     �@  set("verbs", ({ "hoof","crash" }));  
        set("race", "���]");
        set("gender", "�k��"); 
        set("age", 80);
        set("attitude", "heroson");
        set("level", 7);
        set("evil", -99);
        set("combat_exp",700); 
        set("storeroom","/u/z/zorg/area/shop"); //�`�N. �n�إߤ@��room��F��
        set("chat_chance", 1 );    
        set("chat_msg", ({    
        "�P�ڥj�����z�q�D�G�ӡ�����ӡ���I�I�I�C\n",  
        "�P�ڥj�����z�q�D�G�K����y�������I�I�I�C\n",  
        (:command(""):),
}) );
        set("chat_chance_combat",16);
        set("chat_msg_combat", ({
        (:command("say �z............"):), 
        "�P�ڥj�����z�q�D�G�����T�����I�I�C\n",  
        "�P�ڥj�����z�q�D�G�ϡ��H���աI�I�I�C\n",  
        }) );
        setup(); 
}
void init()
{
        add_action("do_sell","sell");
        add_action("do_list","list");
        add_action("do_buy","buy");
}



