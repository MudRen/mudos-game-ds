#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"�u��"HIC"�çL"NOR , ({ "guard" }) );
        set("level", 50);
        set("con", 55);
        set("age",30);
        set("str", 70);
        set("dex",10);
        set("int",10);
        set_skill("parry", 60);
        set_skill("unarmed", 80);
        set_skill("dodge", 60);
        set("long","�U�Q�������A���\�O��n�çL�C\n");
        set("chat_chance", 5 );
        set("chat_msg",({HIW"��e�çL���D�G�A�n�I�w����{�W�s�x��!\n"NOR,
           (:command("smile"):),
        }) );
       setup();
}      
