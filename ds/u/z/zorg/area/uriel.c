#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ר��C��", ({"uriel"}) );
   set("long", "�A���e�N�O�|�j�K�ѨϤ����ݻŤѨϡI�֦��T����l���̰��ů��t�Ѩ�\n");
        set("race", "�H��");
        set("gender", "�k��"); 
        set("age", 2000);
        set("attitude", "aggressive");
        set("level",70);
        set("evil", -999);
        set("combat_exp",5000);
        set_skill("sword", 100);
        set_skill("unarmed",100);
        set("title",HIW"�i"HIR"�K�Ѩ�"HIW"�j"NOR);
        set_skill("cloudsteps", 100);
        set_skill("thundersword", 100);
        set_skill("poken", 100);
        set_skill("parry", 100);  
        set("env/wimpy", 10);        
        set("chat_chance", 90 );      
        set("chat_msg", ({   
        (: this_object(), "random_move" :),     //�|�ۤv����  
        (:command("�H�����o�O�|���"):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        (:command("wield sword"):),
        (:command("wield sword"):),
        (:command("exert thundersword"):),
        (:command("exert poken"):),
        (:command("exert cloudsteps"):),
        (:command("�ר��C�����L�������D:�H���O�o�c���ڷ�"):),
        }) );
        setup(); 
        carry_object(__DIR__"wp/lightsaber.c");
}


