#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIY"�Ѵ���"NOR ,({ "sky stone neck","neck" }) );
        set("long","���L�Ѵ����p�����Y�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set_weight(50);
                set("rigidity",10);
                set("unit","��");
                set("value",0);
                set("armor_prop/int", 50);
                set("armor_prop/con", 5);
                set("armor_prop/str", 5);
                set("armor_prop/dex", 1);
                set("armor_prop/armor", 20);
                              
        }
         set("wear_msg",
HIR"$N���W$n"HIR"����"HIG"�����{�ۺ��"HIM"\n"NOR);
        set("unequip_msg", HIM"$N���U$n"HIB"��A����C�C�����C\n"NOR);
        setup();
}
int query_autoload() { return 1; }

