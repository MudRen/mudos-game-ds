#include <armor.h>

inherit BOOTS;
#include <ansi.h>
void create()
{
        set_name(HIW"�i"HIG"��"HIR"��"HIC"�u"HIW"�j"NOR,({"darkboots","boots"}) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"�u"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C\n");
     set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","��");
        set("no_sell",1);
        set("value",5000);           
        set("material","boots"); 
        set("armor_prop/con", 10) ;     
        set("armor_prop/str", 10) ;     
        set("armor_prop/int",5);
        set("armor_prop/dex",10);
        set("armor_prop/armor",100);
        set("armor_prop/parry",100);
        set("armor_prop/dodge",300);
        }
        setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
} 
 int query_autoload() { return 1; }












