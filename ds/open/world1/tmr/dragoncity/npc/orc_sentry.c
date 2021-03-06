
#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
    set_name("半獸人哨兵", ({ "orc sentry", "orc", "sentry", "_CRUSH_BONE_ORC_" }) );

    set("long", @LONG
半獸人，身體呈暗綠色，有著一張猙獰的臉，他是屬於碎骨寨的小嘍囉。
LONG);

    set("title", HIW"碎骨寨"NOR);
    set("gender", "male");
    set("age", 23);
        set("level",25);

    /* 技能設定 */
    set_skill("dodge", 100);
    set_skill("axe", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);

    setup();

    set_living_name("_CRUSH_BONE_ORC_");
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
   command("war ... "+me->name(1) + "(" + me->query("id") +")..你...碎骨大軍不會放過你的！！！");  
        message_vision("$N在臨死之前對著碎骨寨的地方射出一枚信號箭...\n", this_object());
        load_object("/open/world1/tmr/crush_bone/map_23_4.c")->start_war();

  ::die();
  return;
}


