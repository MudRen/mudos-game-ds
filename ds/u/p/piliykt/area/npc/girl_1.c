#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "趙書宇" , ({ "zhug-book-girl","girl" }) );
        set("level", 6);
        set("race","人類");
        set("gender","女性");
        set("age",18);
        set("int", 30);
        set("str", 10);
        set("con", 12);
        set_skill("parry", 5);
        set_skill("unarmed", 10);
        set_skill("dodge", 15);
        set("long",
   "趙王唯一的女兒, 看起來美麗動人,知書達禮的樣子。\n");
        setup();
carry_object(__DIR__"eq/helmet_2.c")->wear();
        
}


