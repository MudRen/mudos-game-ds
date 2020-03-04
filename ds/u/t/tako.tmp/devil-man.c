#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIR"黑"HIC"羅煞"NOR, ({ "black lou king","king" }) );
        set("long","暗天界的領導者。\n");
        set("level",40);
        set("age",1212);

        
        set("max_hp",25000);
        set("chat_chance_combat",10);
        
        set("title",HIR"暗天"HIB"霸主");
        set("nickname",HIC"狂神"NOR);   
        set_skill("combat", 78);             
        set_skill("parry", 81);
        set_skill("unarmed", 71);
        set_skill("dodge", 89);
        set_skill("sword", 91 );
        setup();
        carry_object(__DIR__"devil-sword")->wield();
}
