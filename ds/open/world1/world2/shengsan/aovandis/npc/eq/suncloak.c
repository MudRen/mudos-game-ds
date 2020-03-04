#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
	set_name("烈日披風",({"sun cloak","cloak"}) );
	set("long",@LONG
這是一件紅色的長披風，披風上面繡了一個太陽的圖案。據說這
件披風可以驅除寒氣，不知為何流落此處。堅韌的材質可以讓裝備者
受到相當不錯的保護。
[可儲存裝備]
LONG
);
    set_weight(2680);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "skin");
		set("unit", "件");
		set("limit_con",3);
        	//set("no_sell",1);
		set("no_sac",1);
		set("armor_prop/fire", 10); //火系防具.
		set("armor_prop/armor", 9);
		set("armor_prop/shield",12);
        }
	set("wear_msg",HBK"$N"HBK"將一件$n"HBK"披在身上, 整個人彷彿化為一片黑影!!\n"NOR);
	set("unequip_msg",HBK"$N"HBK"將$n"HBK"由肩上卸下, 一陣黑影漸漸消散。\n"NOR);
       set("add_value",2870);
	set("value",3215);
        setup();
}

int query_autoload() { return 1; }
