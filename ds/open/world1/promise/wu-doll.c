#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("吳鍾"HIR"娃娃"NOR, ({ "wu doll","doll",}) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","
與八極門開山祖師的樣子雷同，十分可愛的娃娃
\n"NOR);
                set("unit", "隻");
                set("material", "gold");
                set("no_sell",1);
               set("no_drop",1);
               set("no_auc",1);
               set("no_get",1);
              set("no_give",1);   
                set("value",4800);
        }
              setup();

}
int query_autoload() { return 1; }

