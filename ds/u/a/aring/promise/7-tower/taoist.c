#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ѹD�h",({"taoist"}) );
        set("long",
"�L�Ҩƨƪ��D�h�C"
        );
        set("age",45);
        set("level",1);
        set("race","�H��");
        set("attitude", "peaceful");
        set("unarmed",20);
        set("chat_chance",5);
        set("chat_msg",({
                (:command("stare"):),
                }) );
        set_skill("unarmed",20);
        setup();                
        add_money("coin",100);
}

void die()
{
   object obj,ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }   
      message("world:world1:vision","\n\n\t"HIW"�ԤΤj�n�H�S�ۡG�~�M�Q�A���ѯ}�F�A���ڥu�n���A�ʩR�F�I�I\n\n"NOR,users());
      obj=new(__DIR__"npc/evil2")->move(this_object()); 
                     ::die();
        return;
}

