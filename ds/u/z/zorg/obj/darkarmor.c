#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"�ԥ�"HIW"�j"NOR,({ "darkarmor","armor" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"�ԥ�"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
         set_weight(12000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "armor");
        set("unit", "��" );
        set("no_sell",1);
        set("value",3000);
        }
set("armor_prop/armor",300);
set("armor_prop/dodge",100);
set("armor_prop/dex",6);
set("armor_prop/int",6);
set("armor_prop/con",10);
set("armor_prop/str",10);
        setup();
 {
  if(!wizardp(this_player())) destruct(this_object());
}
}
 int query_autoload() { return 1; }










