#include <ansi.h>
inherit GAME_GIFT;

void create()
{
        set_name(HIW"�Ѧa����"NOR, ({ "the world by me","world","me" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("level",1);
                set("unit", "��");
                set("long","�Ѧa���ڡA�~��F"+query("level")+"���P�C(help gift)\n");
                }
        setup();
}
int query_autoload() { return 1; }

