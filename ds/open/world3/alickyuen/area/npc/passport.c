#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "工作人員" , ({"official"}) );
set("long", "一位負責批發通行證的工作人員。\n");       
        set("race", "人類");
        set("age",50); 
        set("level", 10);
        setup();
        
}


