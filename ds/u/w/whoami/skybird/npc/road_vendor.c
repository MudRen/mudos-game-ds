#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "�p�c", ({ "vendor",}));
set("long",
"�@�ӽ浹�L����H�f�~���p�c.\n",
);

        set("level",7);
        set("gender", "�k��");
        set("race", "�H��");
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
