#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
  set_name(HIW"�j���_�C"NOR, ({ "boss sword","sword"}) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O��j���M�Ϊ��Z���C\n");
                set("value", 400);
                set("material", "platminum");
        }
    init_sword(5000);
        setup();
}

