#include <weapon.h>

inherit WHIP;

void update_viper();

void create()
{
      set_name("測試蛇",({"viper"}) );
      set("long","一條粗約小指的小蛇。\n");
      set_weight(100);
      if (clonep() )
             set_default_object(__FILE__);
     else {
        set("unit","隻");
        set("volume",1);
        set("material","iron");
        }
        init_whip(12);
        setup();
}
void update_viper()
{
   int i,j;
        i=this_object()->query("viper_power");
        j= i / 5;
        set("long","一條粗約小指的小蛇。"+(j==0 ? "\n":"身上有"+(string)j+"個紫色班點\n" ) );
        return;
}
void init()
{
        add_action("do_name","name");
        add_action("do_feed","feed");
}

int do_feed(string arg)
{
        object ob,me;
        me=this_player();
        ob=this_object();
        if(me->is_busy() )
                return notify_fail("你正忙著，沒空中。\n");
        if(me->is_fighting() )
                return notify_fail("你正忙著，沒空中。\n");

        if(!arg || !ob->id(arg) )
                return notify_fail("你要餵那條蛇?");
        message_vision("$N伸出了腳趾頭讓$n咬住，大大地吸了一口血。\n",me,ob);
        ob->add("viper_power",1);
        update_viper();
        me->start_busy(1);
        me->receive_damage("hp",10);
        return 1;       
}

