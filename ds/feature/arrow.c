// food.c

#include <dbase.h>
#include <name.h>

inherit COMBINED_ITEM;

void setup()
{
	::setup();
	if(!stringp(query("unit"))) set("unit","��");
	if(!query("base_weight")) set("base_weight",100);
	if(!query("base_volume")) set("base_volume",0.1);
}

int is_arrow() { return 1; }
