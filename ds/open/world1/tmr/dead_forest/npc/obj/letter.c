// 七彩之矢(Rainbow-arrow)  解迷物品
inherit ITEM;

void create()
{
		set_name( "書信", ({ "letter" , "_RAINBOW_ARROW_QUEST_"}));
        set("long",@long
這是一封書信，由於信封尚未開口，你無法得知裡面寫了什麼。
long
			);
        set("unit", "封");
        set("weight" , 100 );
        set("value" , 0);
        setup();
}