#include <ansi.h>
#include <weapon.h>

inherit F_UNIQUE;
inherit STAFF;
void create()
{
  set_name( "神官法杖" , ({ "clorgy wand","wand" }) );
  set_weight(1200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "把");
    set("long", "藍諾村的神官用法杖，居有不可思議的魔力。" HIC "\n高級治癒術(heal)\n" NOR );
    set("material", "wood");
    set("value",10000);
    set("volume",1);
  }
    set("limit_int",25);
  init_staff(4);
  setup();
}

void init()
{
        add_action("do_heal","heal");
}

int do_heal(string arg)
{
        object me;
        me=this_player();

        if( arg )
                if( environment(me) );
        if( me->is_busy() )
                  return notify_fail("你的上一個動作還沒有完成，不能施展法術。\n");
        if( me->query("mp") < 60 )
                return notify_fail("你的精神能量不足，無法施放此法術。\n");
        if( me->query_temp("heal"))
                return notify_fail("你已正在施展中了，不能再用了。\n");
        message_vision( NOR "$N唸著：" HIW "\n大地之母的瑪法啊，請伸出妳那崇高的手，治癒其傷痕吧！\n" HIC "\n\t○高級治癒術○\n"NOR,me);

        me->set_temp("heal",1);
        me->start_busy(3);
        call_out("do_fullheal",2, me);
        call_out("do_clean",4,me);
        return 1;
}

int do_fullheal(object me)
{
    if(!me) return 0;
      message_vision(HIC"\n$N全身散發出淡淡的藍光，$N身上的傷口明顯的變少了。\n\n"NOR,me);
      me->receive_heal("hp",random(70)+50);
      me->receive_damage("mp",50);
      return 0; 
}

int do_clean(object me)
{
          if(!me) return 0;
          me->delete_temp("heal");
          return 1;
}
