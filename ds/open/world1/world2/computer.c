// An example doll.c
// "undead_item" 此name請勿亂用.
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("小型電腦[現代]",({"now computer","computer"}));
	set_weight(1000);
		set("value",0);
		set("no_drop",1);
		set("no_put",1);
		set("unit","台");
		set("long",@LONG
一台小型的電腦。幫助現代的巫師做一些簡單的計算。

    weight <重量>  :  顯示此重量的裝備系統的內定值.

LONG
);
	setup();
}

void init()
{
	object env;
	env=environment(this_object());
	if(!env) return;
	if(!userp(env)) return;
	if(!wizardp(env))
	{
		message_vision("正當$N要拿起$n時, $n突然化為一堆灰燼。\n",env,this_object());
		destruct(this_object());
		return;
	}
	add_action("do_weight","weight");

}

int do_weight(string arg)
{
	int g,total;
	if(!arg) return notify_fail("  指令格式: weight <重量>\n");
	if(sscanf(arg, "%d",g) != 1 ) return notify_fail("  指令格式: weight <重量>\n");
	if(g < 1 ) return notify_fail("  重量必須大於1。\n");

	if(g>42000) total=((g-42000)/2300)+40;
	else if(g>25000) total=((g-25000)/1700)+30;
	else if(g>13000) total=((g-13000)/1200)+20;
	else if(g>5000) total=((g-5000)/800)+10;
	else total=g/500;

	printf("armor_prop/armor : %d\n",total);
	printf("value : %d\n",g*3/8);
	printf("limit_con : %d\n",g/1200);
	if(g > 6000 )
	printf("armor_prop/dodge : %d \n", - g / 4500 );
	write("\n");
	return 1;
}

int query_autoload() { return 1; }
