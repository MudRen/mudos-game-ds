#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"��������"NOR, ({ "gold tackle","tackle" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�i");
                set("value", 3000);
                set("long", "�@�i�Ϊ����s��������, �Q�����Ȥ���");
                }
        setup();
}
