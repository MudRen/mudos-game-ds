#include <ansi.h>
inherit NPC;
void create()
{
        set_name("秘密客", ({ "mimi guard","guard" }) );
        set("long","長年守在古墓密室下的神秘人，目的在防止出沒的怪獸。\n");
        set("level",20+random(15));
        set("age",38+random(4)); 
        set("title",HIG"秘"NOR);
        set("combat_exp", 30000);
        set("chat_chance",12 );
        set("chat_msg", ({
  "秘密客說：快走快走，這裡很危險，隨時會有怪獸出沒!!\n", 
})); 
        set_skill("parry", 80);
        set_skill("unarmed", 90);
        set_skill("dodge", 130);
        setup();
        carry_object(__DIR__"obj/mi-gloves")->wear(); 
} 
void die() 
{
    object ob; 
    if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);

    if( !ob ) { 
        ::die();
        return;
    } 
//    ob->add("popularity",1); 
    message_vision("$N哈哈一笑死了。\n", this_object() );
    ::die();
    return;
}
