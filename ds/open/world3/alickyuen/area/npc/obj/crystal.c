//updated by alickyuen 26/12
#include <ansi.h>      
inherit ITEM;
void create()
{
        set_name(HIW"水晶鑽石"NOR, ({ "crystal diamond","crystal","diamond" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", HIG"傳說中為雕刻大師將水晶和鑽石燒熔後混在一起，有無上價值的珍貴寶石。\n"NOR);
                set("unit", "個");
                set("material","diamond");
set("value",500);
// set("no_buy",1);    pig shengsan弄不好
        }
}