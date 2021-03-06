#include <armor.h>
#include <ansi.h>
inherit SURCOAT;

void create()
{
	set_name(HBK"闇月披風"NOR,({"dark moon cloak","cloak"}) );
	set("long",@LONG
這是一件黑色的長披風，披風上面繡了一個新月形標誌。據說這
件披風是以前闇月教的鎮教之寶，不知為何流落此處。這件披風有著
吸收光線的力量，可以讓裝備者的位置不易被敵人所發現。
[可儲存裝備]
LONG
);
	set_weight(9200);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "件");
		set("limit_con",3);
        	//set("no_sell",1);
		set("no_sac",1);
		set("armor_prop/dodge", 14);
		set("armor_prop/armor", 18);
		set("armor_prop/shield",21);
        }
	set("wear_msg",HBK"$N"HBK"將一件$n"HBK"披在身上, 整個人彷彿化為一片黑影!!\n"NOR);
	set("unequip_msg",HBK"$N"HBK"將$n"HBK"由肩上卸下, 一陣黑影漸漸消散。\n"NOR);
	set("value",12215);
        setup();
}

int query_autoload() { return 1; }