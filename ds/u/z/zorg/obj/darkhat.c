#include <armor.h>
#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
     set_name(HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR,({ "darkhat","hat" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C
\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "hat");
        set("unit", "��" );
        set("no_sell",1);
        set("value" , 1400);
        }
          set("armor_prop/armor", 200);
          set("armor_prop/dodge", 100);
          set("armor_prop/shield", 125);
          set("armor_prop/str", 15);
          set("armor_prop/con", 15);
          set("armor_prop/int", 8);
          set("armor_prop/dex", 6);
              setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
  int query_autoload() { return 1; }







#include <ansi.h>
inherit HEAD;
void create()
{
     set_name(HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR,({ "darkhat","hat" }) );
        set("long",""HIW"�i"HIG"��"HIR"��"HIC"��"HIW"�j"NOR"�W�x�z��"BLK"�`�¦�"NOR"�x����C
\n");
        set_weight(6000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "hat");
        set("unit", "��" );
        set("no_sell",1);
        set("value" , 1400);
        }
          set("armor_prop/armor", 200);
          set("armor_prop/dodge", 100);
          set("armor_prop/shield", 125);
          set("armor_prop/str", 15);
          set("armor_prop/con", 15);
          set("armor_prop/int", 8);
          set("armor_prop/dex", 6);
              setup(); 
{
  if(!wizardp(this_player())) destruct(this_object());
}
}
  int query_autoload() { return 1; }







