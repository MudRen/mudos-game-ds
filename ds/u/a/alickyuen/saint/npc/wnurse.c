#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "護士" , ({"nurse"}) );
set("long", "一個在這間醫院�堣u作的護士，她正在忙碌地工作。\n");       
        set("race", "人類");
set("gender","女性");
        set("age",20); 
        set("attitude", "friendly");
        set("level", 10);
        setup();
        
}


