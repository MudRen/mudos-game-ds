#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "小王", ({ "wang",}));
set("long",
"這是一個辛勤在龍井客棧打零工的青年.\n",
);

        set("level",10);
        set("gender", "男性");
        set("race", "人類");
        set("age", 19);
        set("evil",-20);
        set_skill("unarmed",50);  
   set("attitude", "peaceful");
   set("sell_list",([   
           __DIR__"obj/manto"   :25,
           __DIR__"obj/dump"    :25, 
           __DIR__"obj/tea"     :30, 
      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       
(:command("smile"):),
}) );

set("inquiry/name", @LONG
   我叫做王勇慶啦.. 大家都叫我小王 
LONG );

      setup();
      add_money("dollar", 40);       
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
