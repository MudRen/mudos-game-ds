#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIW"�����"NOR, ({ "mine-fan stone", "FAKE_STONE" }));
        set("long", "�@�ө_�S�����Y, �ڻ��i�H��_����. \n");
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "��");
                  set("value", 0);
                set("no_give", 1);
                set("no_put",1);
                set("no_sell", 1);
        }
        setup();
}

