#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "���", ({ "man",}));
set("long",@LONG
�@�Ӧb��W�B�B�i�������.
LONG
    );
        set("level",10);
        set("gender", "�k��");
        set("race", "�H��");
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
