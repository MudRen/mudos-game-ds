#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"Magic Book"NOR, ({ "magic book", "book" }));
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long", "There's nothing special with the book, just like all the other magic books.");
                set("unit", "�� ");
                set("value", 1);
        }
        setup();
}
