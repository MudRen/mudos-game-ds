inherit NPC;
inherit SELLMAN;

void create()
{
        set_name( "鐵匠", ({ "smith" }) );
        set("gender", "男性" );
	set("level",1);
        set("age", 22);
        set("long",
                "一個身材粗壯的鐵匠﹐正忙碌地工作著。\n"
                "如果你想買一些鐵器﹐可以用 list 看有哪些東西﹐用 buy 向鐵匠購買。\n"
	);
        set("combat_exp", 5);
        set("attitude", "friendly");

        set("chat_chance", 5);
        set("chat_msg", ({
                "鐵匠將一塊燒紅的鐵塊「嗤」地一聲浸入一旁的水箱中。\n",
                "鐵匠用手中的鐵鎚在鐵砧上用力敲打。\n",
                "鐵匠說道﹕站開點﹐小心別燙著了。\n",
                "鐵匠說道﹕唉 ... 真把我給忙壞了。\n",
        }));
	set("sell_list",([	
                 __DIR__"wp/sword"        : 20, 
                 __DIR__"wp/shortsword"   : 23, 
                 __DIR__"wp/shortaxe"     : 20, 
                 __DIR__"wp/dagger"       : 15, 	
                   __DIR__"wp/fist"       : 20,     
                     __DIR__"wp/fork"       : 20,     

        ]) );
            setup();
}

void init()
{
	add_action("do_list","list");
	add_action("do_buy","buy");
}


