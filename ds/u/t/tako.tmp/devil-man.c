#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"��"HIC"ù��"NOR, ({ "black lou king","king" }) );
        set("long","�t�Ѭɪ���ɪ̡C\n");
        set("level",40);
        set("age",1212);

        
        set("max_hp",25000);
        set("chat_chance_combat",10);
        
        set("title",HIR"�t��"HIB"�Q�D");
        set("nickname",HIC"�g��"NOR);   
        set_skill("combat", 78);             
        set_skill("parry", 81);
        set_skill("unarmed", 71);
        set_skill("dodge", 89);
        set_skill("sword", 91 );
        setup();
        carry_object(__DIR__"devil-sword")->wield();
}
