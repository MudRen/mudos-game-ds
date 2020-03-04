inherit NPC;
inherit SHOPMAN;
void create()
{
        set_name("礦工頭",({ "mineral collector","collector" }));
        set("long","商人顧用來收集礦石的工人。\n");
        set("level", 10);
        set("age",35);
        set("chat_chance", 8);
        set("chat_msg", ({
             "礦工頭喊著:採來凡礦石賣給我就對了。\n"
}));
        set("storeroom",__DIR__"obj/mineralroom");
        setup();
}
void init()
{
  add_action("do_sell","sell");
}
