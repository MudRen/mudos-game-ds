#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"�^�a����"NOR, ({ "doll", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�ӫ���.");
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
        if(arg != "doll") return 0;
     message_vision(HIY"$N�Φ^�a��������¤Ѽ��o~\n\n"NOR,me);
      me->move("/open/world1/tmr/area/hotel");
        return 1;
}
