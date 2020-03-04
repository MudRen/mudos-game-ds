// armor.c
#include <armor.h>
inherit EQUIP;

void setup()
{
	int g,total;
	if(!query("volume")) set("volume",2);
	::setup();
	if( clonep(this_object()) ) return;
	set("zerg_armor_type", ZERG_SHELL);
	if(query("auto_set")==2) //�{�N�з�
	{
		g=weight();
		if(g>42000) total=((g-42000)/2300)+40;
		else if(g>25000) total=((g-25000)/1700)+30;
		else if(g>13000) total=((g-13000)/1200)+20;
		else if(g>5000) total=((g-5000)/800)+10;
		else total=g/500;
		set("zerg_armor_prop/armor",total);
		set("value",weight()*3/8);
		if(!query("limit_con"))	set("limit_con",weight()/1200);
		return;
	}
	if(!query("limit_con"))	set("limit_con",weight()/1200);
	if(!query("zerg_armor_prop/armor")) set("zerg_armor_prop/armor",weight()/500);
}

int is_armor(){ return 1; }

/* int query_autoload() { return 1; } */
