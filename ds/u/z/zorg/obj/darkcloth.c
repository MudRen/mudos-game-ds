#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR ,({ "darkcloth","cloth" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C
\n");
        set_weight(800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "cloth");
        set("unit", "��" );
        set("no_sell",1);
        set("value",150);
        }
          set("armor_prop/armor",300);
          set("armor_prop/parry",200);
          set("armor_prop/dodge",200);
          set("armor_prop/str",12);
          set("armor_prop/con",12);
          set("armor_prop/int",7);
          set("armor_prop/dex",7);
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
 int query_autoload() { return 1; }











