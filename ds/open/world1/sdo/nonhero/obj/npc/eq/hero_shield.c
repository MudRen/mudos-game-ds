#include <ansi2.h>
#include <armor.h>
inherit SHIELD;

void create()
{
        set_name(HIC"英雄之盾"NOR,({"hero shield","shield"}));
        set_weight(4000);
        if( clonep() )
		set_default_object(__FILE__);
        else 
	{
        set("unit", "面");
        set("volume",5);
        set("long", @LONG
這面木造盾牌可是陪著無名英雄出生入死，幫助他無數次在緊要關頭
擋住敵人那致命的攻擊。由於當初有經過高人的處理，所以有超乎常
人想像的防禦力。
LONG
	);
       	set("value",2000);
        set("material","wood");
        }
        set("armor_prop/armor",25);
        setup();
}