#include <ansi.h>
inherit NPC;
void create()
{
        set_name("蟒蛇",({ "big snake","snake" }) );
        set("level",22);
        set("race", "野獸");
        set("age", 5);
        set("long", "一隻極為凶狠的蟒蛇，吐著紅紅的舌頭。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}
void init()
{
        ::init();

if(userp(this_player() ) && this_object()->visible(this_player()))
  {
   message_vision("$N怒吼一聲，開始攻擊$n！！\n",this_object(),this_player() );
        this_object()->kill_ob(this_player() ); 
        }
        return;
}

