#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "鎮民", ({ "man",}));
set("long",@LONG
一個在鎮上處處可見的鎮民.
LONG
    );
        set("level",10);
        set("gender", "男性");
        set("race", "人類");
        set("age", 33);
        set("evil",-20);
set("attitude", "peaceful");
set("chat_chance",3);                     
set("chat_msg", 
({
(:command("idle"):),
}) );
      setup();
      carry_object(__DIR__"eq/fur_waist")->wear();
      carry_object(__DIR__"eq/cloth")->wear();
      add_money("coin",300);
}                 
