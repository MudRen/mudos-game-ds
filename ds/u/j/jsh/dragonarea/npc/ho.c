#include <ansi.h>
inherit NPC;
void create()
{
        set_name("何古蒙" , ({ "gomon ho","ho","gomon","go","mon" }) );
        set("title", HIB "爛" NOR);
         set("race","人類");
         set("gender","男性");
        set("age",42);
        set("level", 25);
        set_skill("blade",50); 
        set_skill("unarmed",50);        set_skill("parry",50);
        set_skill("dodge",50);
        set("long",
            "它是武道城裡的常客, 經常到這來會會各家好手。\n");
        setup();
        carry_object(__DIR__"obj/blade2")->wield();
} 

