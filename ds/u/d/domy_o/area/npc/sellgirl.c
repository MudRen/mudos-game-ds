inherit NPC;
inherit SELLMAN;

void create()
{
        set_name( "情趣用品部小姐", ({ "sellgirl" }) );
        set("gender", "女性" );
        set("level",40);
        set("age", 22);
        set("long",
                "一個身材窈窕的小姐﹐正看著雜誌。\n"
                "如果你想買一些情趣用品﹐可以用 list 看有哪些東西﹐再 buy 。\n"
        );
        set("combat_exp", 5);
        set("attitude", "friendly");
      set("sell_list",([      
                 __DIR__"ep/candom"        : 1000, 
                 __DIR__"ep/sm_armor"   : 1500, 
                 __DIR__"wp/sm_whip"     : 1800, 
                 __DIR__"item/blue_pill"       : 300,         
                       ]) );
            setup();
}

void init()
{
        add_action("do_list","list");
        add_action("do_buy","buy");
}

