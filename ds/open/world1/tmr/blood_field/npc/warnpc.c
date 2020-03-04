#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("幼年龍", ({ "young dragon", "dragon" }) );
    set("long", @LONG
這是一隻年幼的小龍，正在這附近玩耍。
LONG);
	set("race","dragon");
    set("title","血腥荒野");
    set("gender", "male");
    set("age", 10);
    set("level",5);
    setup();
}

void die()
{
   object me;
   if( !me = query_temp("last_damage_from") )
        me = this_player(1);
   if( !me )
   {
     ::die();
     return;
   }
        command("war ... "+me->name(1) + "(" + me->query("id") +")...無知的凡人！！夜禍不會放過你的！！！");  
        load_object("/open/world1/tmr/blood_field/map_40_40.c")->start_war();

  ::die();
  return;
}


