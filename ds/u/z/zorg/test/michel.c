#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�̦���", ({"michel"}) );
   set("long", "�A���e�N�O�|�j�K�ѨϤ����j�ѨϪ��̦���!�֦���d�ѨϧL�Ϊ��v�O,
���P�Z���ѨϧܿŨäj�����\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 3000);
        set("attitude", "heroism");
        set("level",70);
        set("evil", -999);
        set("combat_exp",5000);
        set_skill("sword", 100);
        set_skill("dodge", 100);
        set_skill("poken", 100);
        set_skill("cloudsteps", 100);
        set_skill("thundersword", 100);
        set_spell("god-benison", 100);
        set_skill("unarmed",100);
        set("title",HIW"�i"HIR"�K�Ѩ�"NOR" "HIG"��"NOR" "HIC"�j�ѨϪ�"HIW"�j"NOR);
        set_skill("parry", 100);  
        set("chat_chance", 3);  
        set("chat_msg", ({     
        "�̦��ǭ��L�������D:�H���O���ݷ�����,�H���O�o�c���ڷ�.\n"
}) ); 
        set("chat_chance_combat",190);
        set("chat_msg_combat", ({ 
        (:command("[32mdefend [0muriel"):), 
        (:command("cast god-benison on $n"):), 
        (:command("cast god-benison"):), 
        (:command("exert thundersword"):), 
        (:command("exert poken"):), 
        (:command("exert cloudsteps"):), 
        "�̦��Ǥ@�y��������D:�H���O�o�c���ڷ�\n"
        }) );
        setup();  
        carry_object("u/z/zorg/obj/sword2.c")->wield();
}

