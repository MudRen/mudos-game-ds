        
        
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("傲雲天", ({ "pike-master-guard","guard" }) );
        set("title",HIG "槍將" NOR);
        set("level", 38);
        set("race","人類");
        set("gender","男性");
        set("age",32);
        set("str", 80);
        set("con", 50); 
add("addition_armor",40);
add("addition_damage",70);        
set_skill("fork", 100);
        set_skill("parry", 40);
        set_skill("unarmed", 50);
        set_skill("dodge", 60);
        set("long",
   "一位王爺的護衛，身手非凡武藝高強，槍法更是出神入化。\n");
        setup();
        carry_object(__DIR__"wp/pike_1.c")->wield();
        carry_object(__DIR__"eq/cloak_1.c")->wear();

}

