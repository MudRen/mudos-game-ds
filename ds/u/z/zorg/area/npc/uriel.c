#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�Q�z�C��", ({"uriel"}) );
   set("long", "�A���e�N�O�|�j�K�ѨϤ����ݻŤѨϡI�֦��T����l���̰��ů��t�Ѩ�\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 2000);
        set("attitude", "heroism");
        set("level",100);
        set("str",100);   
        set("con",100);
        set("int",100);
        set("dex",100);
        set("evil", -999);
        set("combat_exp",5000);
        set("title",HIW"�i"HIR"�K�Ѩ� "HIG"�a "HIC"�ݻŤѨ�"HIW"�j"NOR);
        set_skill("unarmed",100);
        set_skill("parry", 100);  
        set_skill("cloudsteps", 100);  
        set_skill("dagger", 100);  
        set_skill("poken", 100);  
        set_skill("dodge", 100);  
        set_skill("sky-dagger", 100);  
        set("env/wimpy", 10);        
        set("chat_chance", 1);      
        set("chat_msg", ({   
       "�Q�z�C�����L�������D:�H�����o�O�|���,�H���O�o�c���ڷ�.\n"
}) );
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({  
        (:command("defend michel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert poken"):), 
        (:command("exert sky-dagger"):),
        (:command("exert cloudsteps"):),
        "�Q�z�C���@�y����������D:�H���O�o�c���ڷ�\n"
        }) );
        setup(); 
        carry_object("/u/z/zorg/obj/dagger.c")->wield();
        carry_object("/u/z/zorg/obj/dagger1.c")->wield();
}




