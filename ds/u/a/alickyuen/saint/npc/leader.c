#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "院長" , ({"leader"}) );
set("long", "在你面前站著的正是這間醫院的院長，如果你有什麼關於醫院的問題你可以請教他看看。\n");       
        set("race", "人類");
        set("age",70); 
        set("attitude", "friendly");
        set("level", 10);
        setup();
        
}


