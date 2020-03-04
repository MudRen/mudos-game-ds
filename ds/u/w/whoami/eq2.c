#include <armor.h>
#include <ansi.h>

inherit HANDS;

void create()
{
        set_name(HIY "日月護星手" NOR ,({ "sun-moon gloves","gloves" }) );
        set("long",@LONG
這是一雙造型非常富有巧思的護手，這雙護手上繡有一幅「日月拱星」
的巧工圖，繡工之精，直把這幅難以繪製的圖發揮到盡善盡美、讚為觀止
的境界，真可謂是巧奪天工也不為過。
LONG);
        set_weight(3000);
        if ( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("volume",2);
                set("unit", "雙");
                set("value",2500);
        }
        setup();
        call_out("eq_check",1);
}

void eq_check()
{
  object me = environment(this_object());
  if( !this_object() || !me ) return; 
  if( me->query_temp("armor/hands")==this_object() 
   && me->query_temp("combine_eq") == 0){
      me->add_temp("combine_eq",1);
    }
}

