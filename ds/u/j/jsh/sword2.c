#include <weapon.h> 
#include <ansi.h>
inherit SWORD;
void create()
{
        set_name(HIW"�Ӫ����C"NOR, ({ "Tai-er sword" , "sword" }) );
        set_weight(3700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("volume",2);
                set("unit", "��"); 
                set("long", "�ӥj���C�A�㦳�j�j�����O�C\n");
        }
        init_sword(80);
        setup();
}

