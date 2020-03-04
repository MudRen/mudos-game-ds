#include <ansi.h>
#include <weapon.h>  
inherit SWORD; 
inherit F_UNIQUE; 
void create()
{
        set_name(HIB"環靈"HIR"•"HIB"冥劍"NOR, ({ "around-soul sword" , "sword" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",5);
                set("unit", "把");
                set("long", HIR"文咒修羅所持之寶劍，乃聚集數萬冤魂所煉，陰沉無比。\n"NOR);
                set("value", 30000); 
        set("replica_ob",__DIR__"shiro-sword2");
        }
        init_sword(78);
        setup();
}
void attack(object me)
{
        object ob;
        ob=this_object();

        if(!me) return;
        if(random(2) && !me->is_busy())
        {
          message_vision(HIB"環靈"HIR"•"HIB"冥劍"HIW"吸取大地的靈氣。\n"NOR ,me);
          tell_object(me,HIC "你覺得精神更好了！！\n" NOR);
        }
        me->receive_heal("mp",50+random(30));  
        return;
}

