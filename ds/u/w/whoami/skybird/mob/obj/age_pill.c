#include <ansi.h>
inherit ITEM;
void create()
{ 
  set_name(HIR"返"HIY"老"HIG"還"HIB"童"HIM"丹"NOR, ({ "age pill","pill" }));
  set("long","一顆奇特的妙藥，你感覺的到這顆藥所散發出的不尋常氣息•\n");
  set_weight(70); 
  if(clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "顆");
    set("value",30000);
  }
  setup();
}

void init()
{
  add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        string type,msg;
        object ob,me,env,*target; 
        int x;
        me = this_player();
        ob = this_object();
        target = all_inventory(environment(me));
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");

        if( me->is_fighting() ) me->start_busy(2);
        message_vision("$N從懷中拿出了一顆"HIC"七彩藥丸"NOR"，隨即吞了下去•\n" NOR,me);
        if( me->query("age") < 25 )
        {
                tell_object(me,WHT"你吞下這顆冰冰的藥丸，身體並沒有產生什麼變化•\n"NOR); 
                destruct(ob);
                return 1;      
        } else {
                tell_object(me,HIY"一股氣流直衝你的七經八脈，體內的氣勢完全失去了控制！！\n"NOR);
                message_vision("$N發出一聲慘叫，馬上昏了過去•\n",me);
                me->unconcious(); 
                  me->set("age_modify",-1);
                me->set("hp",1);
                me->set("mp",1);                
                me->set("ap",1);
        destruct(ob);
        } 
        return 1;
}

