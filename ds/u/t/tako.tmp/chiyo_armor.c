#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIB"隕石勁甲"NOR ,({ "meteoric-stone armor","armor" }) );
        set("long",@LONG
        
聽說是太古時期,天外飛來一個大石頭,快墜至地地面的時候,蚩尤
使出十成功力把它擋了下來,因富含神秘的力量,被蚩尤製成一件
盔甲,十分堅固        
LONG
);
        set_weight(10000);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
                set("material", "leather");
                set("unit", "件");
                set("limit_con",8);
        }
        set("value",7000);
        set("volume",6);
        set("no_sac",1);
        set("armor_prop/armor",45);
        set("armor_prop/shield",10);
        set("armor_prop/dodge",-6);
        set("armor_prop/dex",-2);
        set("armor_prop/con",2);
        setup();
}


