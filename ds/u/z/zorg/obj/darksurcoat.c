#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"【"HIG"闇"HIR"之"HIC"披風"HIW"】"NOR ,({ "darksurcoat","surcoat" }) );
        set("long",""HIW"【"HIG"闇"HIR"之"HIC"披風"HIW"】"NOR"上泛透著"BLK"深黑色"NOR"ㄉ闇光。
\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "surcoat");
        set("unit", "件" );
        set("no_sell",1);
        set("value",400);
        set("armor_prop/armor", 180);
        set("armor_prop/parry", 150);
        set("armor_prop/dodge", 135);
        set("armor_prop/str", 15);
        set("armor_prop/con", 15);
        set("armor_prop/int", 10);
        set("armor_prop/dex", 10);
        }
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }











