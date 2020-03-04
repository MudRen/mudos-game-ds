#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"野槌軟皮甲"NOR ,({ "yeah chuya armor","armor" }) );
        set("long",@LONG
        
  這是由魔獸野槌的厚皮做製成的厚重皮甲, 皮甲上有許多吋許長的
硬質鋼毛, 由於其彈性極佳, 伸縮力很好, 所以即使體型特殊的人也
可以輕易穿上。柔軟的厚皮可以吸收大部分的衝擊力, 由於取得方法
十分困難, 是一件傳說中的防具。
        
LONG
);
        set_weight(13800);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "skin");
        	set("unit", "件");
        	set("limit_con",8);
        	set("value",7345);
	}
	set("no_sac",1);
	set("armor_prop/dex",-1);
	set("armor_prop/con",2);
	set("armor_prop/armor",28);
	set("armor_prop/shield",8);
        setup();
}

int query_autoload() { return 1; }