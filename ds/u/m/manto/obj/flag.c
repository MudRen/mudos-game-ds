
#include <ansi.h>
inherit ITEM;
int query_autoload() { return 1; }
void create()
{
        set_name(HIR"小型國旗"NOR, ({"national flag","flag"}));
        if( clonep() )
        set_default_object(__FILE__);
        else {
set("long", HIY"上面龍飛鳳舞的寫著："HIC"台灣加油！！！！！\n\n"HIW"Ｗｅ ａｒｅ ｔｈｅ ｂｅｓｔ！！！"NOR);
        set("unit", "只");
        set("base_unit", "只");
        set("value", 10);
        }
        setup();
}
void init()
{
        object ob;

        if( this_player() && environment()==this_player() ) {
                add_action("do_wave", "wave");
        }
}

int do_wave(string arg)
{
        mapping mail;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" || arg!="flag")
                return notify_fail("你要揮舞啥？\n");

        message_vision(HIW"$N"HIW"狂熱地揮舞著手上的$n"HIW"！！\n"NOR,this_player(),this_object());
        return 1;
}
