#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "守衛" , ({ "guard" }) );
        set("level", 30);
        set("race","人類");
        set("gender","男性");
        set("age",32);
        set("int", 20);
        set("str", 60);
        set("con", 60);
        set_skill("parry", 60);
        set_skill("unarmed", 70);
        set_skill("dodge", 45);
        set("long",
   "負責守衛趙王府的守衛,凡進出趙王府的人都要經過他的檢查。\n");
        setup();
        
}


