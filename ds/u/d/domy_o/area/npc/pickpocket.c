#include <ansi.h>
inherit NPC;
void create()
{
        set_name( "扒手", ({ "pickpocket",}));
        set("long", "一個躲躲藏藏的扒手，正在看東看西。\n"
        );
        set("level",10);
        set("title","外地人");
        set("gender", "男性");
        set("race", "人類");
        set("age", 42);
        set("attitude", "peaceful");   //溫和的 NPC。
 set("chat_chance", 4 );  //動作機率
  set("chat_msg", ({       //動作內容
"扒手趁$n不住意時，趁機往$n的口袋撈來撈去\n",
(:command("grin"):),
(:command("shrug"):),
}) );

        setup();
        add_money("coin",100);
}




