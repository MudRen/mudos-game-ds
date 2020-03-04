#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW"膨脹水球"NOR,({"inflation ball","ball"}));
        set("long","一顆不大的球，裡面好像裝著水又不像水的東西，不知道要幹什麼的(useit)。\n");
        set("unit","顆"); 
        set_weight(1000);
        set("no_give",1);
        set("no_sac",1);
        setup();
}
int init(string arg)
{
   if(this_player()->is_busy()) return 0;
   add_action("do_useit","useit"); 
}
int do_useit(string agg)
{
   object me=this_player();
   if(agg != "inflation") return notify_fail("你要幹什麼?(inflation)\n"); 
   {
   message_vision(HIW"$N將水球高高舉起，突然間$N身體變的輕飄飄的....\n"NOR,me);
   me->set_temp("be_inflation",1); 
   } 
   return 1;
}
int query_autoload() { return 1; }

