#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"飛鳳羽"NOR, ({ "feather", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根羽毛.");
                }
        setup();
}
int query_autoload() { return 1; }
void init()
{
       add_action("typeuse","use");
}
     int typeuse(string arg)
{
        object me;
        me=this_player();
        if(arg != "feather") return 0;
     message_vision(HIY"$N用飛鳳羽飛到十萬大山囉~\n\n"NOR,me);
      me->move("/u/f/faceoff/area/sky/ten1");
        return 1;
}
