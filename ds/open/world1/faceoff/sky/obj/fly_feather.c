#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"�����"NOR, ({ "feather", }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�@�ڦФ�.");
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
     message_vision(HIY"$N�έ���Э���Q�U�j�s�o~\n\n"NOR,me);
      me->move("/u/f/faceoff/area/sky/ten1");
        return 1;
}
