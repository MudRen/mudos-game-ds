#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "小販", ({ "vendor",}));
set("long",
"一個賣給過往行人貨品的小販.\n",
);

        set("level",7);
        set("gender", "男性");
        set("race", "人類");
        set("age", 19);
   	set("attitude", "peaceful");
   	set("sell_list",([   
           __DIR__"obj/tea2"    :25, 
	   __DIR__"obj/wine"     :30, 
	   __DIR__"obj/torch"     :20, 
	   __DIR__"obj/mountain_vegetable"     :20, 
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
