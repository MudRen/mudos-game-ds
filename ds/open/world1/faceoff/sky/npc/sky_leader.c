#include <ansi.h>
inherit NPC;
void create()
{
 set_name("苗青",({"meo chen","meo","chen"}));
 set("long",@LONG
他就是天壇的守衛長了, 也是由苗家村所派出來的....
LONG
    );
 set("attitude", "peaceful");
 set("age",34);
 set("nickname",HIC"天壇-守衛長"NOR);
 set("evil",-10);
 set("gender","男性");
 set("level",35);
 set("ten_mob",1);
 set("str",100);
 set("con",100);
 set_skill("sword", 100);
 set("chat_chance",30);
 set("chat_msg", ({"苗青朝你看了看.....\n", 
        }) );
 setup();
 carry_object(__DIR__"eq/silk_cloth")->wear();
 carry_object(__DIR__"eq/sky_sword")->wield();
}
