#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "護士長" , ({"nurse leader","leader","nurse"}) );
set("long", "他就是在這間醫院�堣u作的護士的護士長，你可以問問他關於護士的問題看看。\n");       
        set("race", "人類");
set("gender","女性");
        set("age",40); 
        set("attitude", "friendly");
        set("level", 50);
        setup();
        
}


