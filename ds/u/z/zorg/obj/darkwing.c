#include <armor.h>
#include <ansi.h>
inherit SURCOAT;
void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"�l"HIW"�j"NOR ,({ "darkwing","wing" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"�l"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C
\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(850);
        set("material", "surcoat");
        set("unit", "��" );
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











