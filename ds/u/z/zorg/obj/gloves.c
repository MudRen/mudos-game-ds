#include <armor.h>
inherit HANDS;
void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"�M��"HIW"�j"NOR,({ "darkgloves","gloves" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"�M��"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(700);
        set("material", "gloves");
        set_default_object(__FILE__);
        set("no_sell",1);
        set("value",300);
        }
         set("armor_prop/armor", 150);
         set("armor_prop/parry", 200);
         set("armor_prop/shield", 150);
         set("armor_prop/dodge", 136);
         set("armor_prop/dex", 10);
         set("armor_prop/str", 10);
         set("armor_prop/con", 15);
         set("armor_prop/int", 5);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
int query_autoload() { return 1; }


