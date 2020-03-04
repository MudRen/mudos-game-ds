#include <ansi.h>

void start_shutdown();
inherit NPC;

void create()
{
        set_name( HIW"���ե�NPC"NOR, ({ "test man", "man" }) );
        set("long","\n");

        set("age", 7777);
        set("level", 100);
        set("max_hp", 50000);
        set("max_mp", 50000);
        
        set("str", 100);
        set("int", 100);
        set("con", 100);
        set("dex", 100);

        set("combat_exp", 5000000);

        set_skill("staff", 100);
        set_skill("unarmed", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);

        set_temp("apply/attack", 500);
        set_temp("apply/defense", 500);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 500);

        setup();
}

void init()
{
     int i;
     object ob=this_object(),me=this_player(),*inv;
     inv = all_inventory(me);

     if( !sizeof(inv) ) return;
     for( i=0;i<sizeof(inv);i++){
         if ( inv[i]->query("equipped") == "worn" ){
         command("hi");     
         inv[i] -> unequip();
         message_vision("$N���W��$n�����F���\n",me,inv[i]);
         destruct(inv[i]);
         }
     }
}
