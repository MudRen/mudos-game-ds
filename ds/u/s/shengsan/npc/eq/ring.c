#include <armor.h>
#include <ansi.h>

inherit FINGER;

void create()
{
	set_name(HIC"藍藍的天專用戒指"NOR,({"bluesky ring","ring"}) );
	set("long","這枚戒指上面鑲了一顆美麗的藍藍的天。\n");
	set_weight(280);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "枚");
//		set("value",3980);
        	set("armor_prop/dodge", 10);
	}
	setup();
}

int query_autoload() { return 1; }

void init()
{
	add_action("do_show","show");
}

int do_show(string arg)
{
	object me,ob;
	string line,material;
	
	me = this_player();
	
	if(!arg)
		return notify_fail("你要看顯示什麼東西的資料阿?\n");
		
	ob = present(arg, environment(me));
	if (!ob) ob = present(arg, me);
	if(!ob) return notify_fail("你處的環境中無法找到此物件: "+arg+"。\n");
	
	material = ob->query("material");
	if(!material)
	{
		ob->set("material","plant");
		write("沒有材質...所以預設為 plant\n");
	}
	line = "";
	line += "物品名: "+ob->query("name")+"("+arg+")\t";
	line += "材質: "+ob->query("material")+"("+ob->M_chinese(material)+")\n";
	line += "=============================== 材質資訊 ================================\n";
	line += "密度: "+ob->M_density(material)+"\t";
	line += "硬度: "+ob->M_hardness(material)+"\t";
	line += "耐用: "+ob->M_durable(material)+"\t";
	line += "銳利: "+ob->M_sharp(material)+"\t";
	line += "價格: "+ob->M_prize(material)+"\n";
	line += "=========================================================================\n";
	line += "重量: "+ob->weight()+"\t";
	line += "體積: "+ob->query("volume")+"\t";
	line += "價值: "+ob->query("value")+"\t";
	line += "耐用: "+ob->query_temp("durable")+"\n";
	line += "傷害: "+ob->query("weapon_prop/damage")+"\t";
	line += "防禦: "+ob->query("armor_prop/armor")+"\n";	
	
	write(line);
	return 1;
}