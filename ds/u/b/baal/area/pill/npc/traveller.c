#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "旅客", ({ "traveller",}));
set("long",
"這是一個在十萬大山遊玩, 目前待在此休息的旅客.\n",
);

        set("level",9);
        set("gender", "男性");
        set("race", "人類");
        set("age", 33);
        set("evil",-20);
   set("attitude", "peaceful");
  set("chat_chance", 3 );                     
set("chat_msg", 
({
(:command("smile"):),
}) );
      setup();
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/longsword")->wield();
      carry_object(__DIR__"eq/fur_waist")->wear();
      carry_object(__DIR__"eq/cloth")->wear();

}                 

