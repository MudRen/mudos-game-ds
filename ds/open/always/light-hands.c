#include <armor.h>
#include <ansi.h>
inherit WRISTS;

void create()
{
        set_name(HIY"��"HIW"��"HIR"�@��"NOR, ({ "light hands","hands" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","���������L�~�S�O���ʬ����ӢߡC���o�۷L�z�����A�Q���_�S�C");
                set("unit", "��");
                set("value",9999);
                set("no_sell", 1);
                set("no_auc", 1);
        }
        set("armor_prop/shield", 5); 
        set("armor_prop/con", 1);
        set("armor_prop/dex", 1);
        setup();
}
int query_autoload() { return 1; }
