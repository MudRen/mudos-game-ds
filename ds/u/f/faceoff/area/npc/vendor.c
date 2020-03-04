#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "商客", ({ "vendor",}));
set("long",
"一個要前往泰源天國的商客.\n",
);

        set("level",10);
        set("gender", "男性");
        set("race", "人類");
        set("age", 19);
   	set("attitude", "peaceful");
   	set("sell_list",([   
           __DIR__"obj/manto"   :25,
           __DIR__"obj/dump"    :25, 
           __DIR__"obj/bag"     :30, 
	   __DIR__"obj/wine"     :30, 
      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       


(:command("smile"):),
}) );
      setup();
      add_money("dollar", 40);       
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/cloth")->wear();
      carry_object(__DIR__"eq/fur_waist")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
