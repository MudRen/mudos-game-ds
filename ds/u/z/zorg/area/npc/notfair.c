#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ԵẸ", ({"notfair"}) );
   set("long", "�A���e�N�O�|�j�K�ѨϤ����z���ѨϡI�֦��T����l���̰��ů��t�Ѩ�\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 2000);
        set("attitude", "heroism");
        set("level",100); 
        set("str",100);         set("con",100);
        set("int",100);
        set("dex",100);
        set("evil", -999);
        set("combat_exp",5000);
        set("title",HIW"�i"HIR"�K�Ѩ� "HIG"�� "HIC"�z���Ѩ�"HIW"�j"NOR);
        set_skill("unarmed",100);
        set_skill("parry", 100);  
        set_skill("fogseven", 100);  
        set_skill("fork", 100);  
        set_skill("poken", 100);  
        set_skill("dodge", 100);  
        set_skill("da-fork", 100);  
        set("env/wimpy", 10);        
        set("chat_chance", 1);      
        set("chat_msg", ({   
       "�ԵẸ���L���������D:�H���O���ݷ�����,�H���O�o�c���ڷ�.\n"
}) );
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({  
        (:command("[32mdefend [0mmichel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert poken"):), 
        (:command("exert da-fork"):),
        (:command("exert godsword"):),
        "�ԵẸ�@�y����������D:�H���O�o�c���ڷ�\n"
        }) );
        setup(); 
        carry_object("/u/z/zorg/obj/dagger.c")->wield();
        carry_object("/u/z/zorg/obj/dagger1.c")->wield();
}



