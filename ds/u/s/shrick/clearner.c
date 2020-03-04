// cleaner.c
#include <ansi.h>

inherit NPC;

void create()
{
         set_name( HIG "清潔機" NOR , ({ "cleaner" }) );
        set("race", "野獸");
        set("age", 3);
        set("long", "它是中央科技中心的清潔機。\n");

        set("str", 24);
        set("cor", 26);

        set("limbs", ({ "毛巾", "身體", "吸盤", "掃把", "電動刷毛" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("chat_chance", 8);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "清潔機用吸塵器在吸細菌。\n" }) );
 set_temp("apply/attack", 10);
        set_temp("apply/armor", 3);

        setup();
}

void init()
{
        call_out("incheck",3,this_player());
}
void incheck(object me)
{
        if(me->query("name") != "清潔機器")
        {
say("清潔機器發出響亮的聲音：" HIR "喂！不要亂丟垃圾ㄡ！\n" NOR);
                command("kick" + me->query("id"));
        }else
         {
                say( HIG "天下大大你好阿。 \n" NOR );
                say( HIG "天下大大你好帥。\n" NOR);
                say( HIG "天下大大你是天才。\n" NOR );
      }   
}


