inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(HIR "���s�]"NOR, ({ "pearl" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�o�O�@���Ѥd�~���s�ҷһs���]���]�A�䤤�n���٦�����;
                set("unit", "��");
                set("value",100);
        }
        set_temp("has_light",1);        //�o��.
        setup();
}
