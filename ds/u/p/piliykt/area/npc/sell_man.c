#include <path.h>
inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("錢大包", ({ "sell man", "man", "shop" }) );
        set("long",
                "他是個神木村的商人，常帶一些奇特之物。\n"
                "你可以問問他有賣什麼東西(list),或是向他購買各種物品(buy)\n"
                ",或是向他出賣東西(sell)\n"
        );
        set("level", 10);
        set("no_fight",1);
        set("age", 35);
        set("storeroom", __DIR__"shop/shop1");
        setup();
}

void init()
{
        add_action("do_buy","buy");
        add_action("do_sell","sell");
        add_action("do_list","list");
  {
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

  }
}

