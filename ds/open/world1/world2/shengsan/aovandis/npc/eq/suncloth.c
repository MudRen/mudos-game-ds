#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("烈日戰服" ,({ "sun cloth","cloth" }) );
        set("long",@LONG
一看就知道這不是一件普通的衣服。火紅色的布料摸起來
就像是鐵絲般的堅韌，袖緣還繡有金黃色的邊，看起來十分的
搶眼。
[可儲存裝備]
LONG
);
        set_weight(1800);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        	set("material", "cloth");
        	set("unit", "件" );
		set("no_sac",1);
	}
	set("value",3280);
	set("armor_prop/fire", 8); //火系防具.
	set("armor_prop/armor", 13);
	set("armor_prop/unarmed", 5);
	set("armor_prop/combat", 5);
	set("armor_prop/shield",8);
        setup();
}
int query_autoload() { return 1; }
