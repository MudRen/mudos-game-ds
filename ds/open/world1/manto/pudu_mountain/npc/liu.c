#include <ansi.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("劉小販" , ({ "liu seller","seller" }) );
        set("level",20);
        set("race","人類");
        set("age", 33);
         set("no_fight",1);
        set("long","這位是專做南北貨生意買賣的小販，長相老實，是個正經的生意人。\n");
        set("chat_chance",8);
        set("chat_msg",({
           (:command("sweat"):),
        }) );
        set("storeroom",__DIR__"shop");
    set("no_kill",1);
        setup();
}
void init()
{
  add_action("do_buy","buy");
  add_action("do_sell","sell");
  add_action("do_list","list");
}


