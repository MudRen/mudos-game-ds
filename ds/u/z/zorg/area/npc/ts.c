#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�P�ڹC��", ({"traveller seller", "seller","traveller"}) );
        set("long", "�L�쥻�O�@��צ~�b�P�ڤ��ȹC���ȫ�,�ѩ�̪��ݮȶO
�ҥH�}��c���`�Ϋ~.�S�Q��ͷN���M����.������榨�F�ӤH�I
�L���b���ʤ@�Ǩ������Z��\n");
        set("race", "���]");
        set("gender", "�k��"); 
        set("age", 86);
        set("attitude", "heroson");
        set("level", 5);
        set("evil", -99);
        set("combat_exp",400);
        set("chat_chance", 1 );    
        set("chat_msg", ({    
        "�P�ڹC�Ӧb�o����¶�F�X¶�}�F�X�}�u������v�C\n",  
        (:command("say �N��ګK�y�@�I�աI�I"):),
        (:command("say �o������n���Z�������I�I�I"):),
}) );
        set("chat_chance_combat",16);
        set("chat_msg_combat", ({
        (:command("say �z........�o....�o�ӬP�y���|�o�Ӽˤl�O�H�H�H"):),
        (:command(""):),
        }) );
        setup(); 
}

