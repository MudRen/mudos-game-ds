#include <armor.h>
#include <ansi.h>
inherit FINGER;

void create()
{
	set_name(HIB"藍冰戒"NOR, ({ "Blue ice ring","ring" }) );
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", @LONG
    相傳在上古黃帝時代有一座落於東北的湛藍冰海，冰海中隱
藏著千年難得的水晶礦石，然而冰海終年浸沐在層層冰雪中，群
山環繞的地利更使此處凡人難以侵犯，除非武功高強之士否則定
難入山取石！而藍冰戒正是蓋世霸王「項羽」隻身潛入冰海取得
礦石並說得當代名匠「肖月」為之精雕細琢而成的戒指。
LONG
    );
		set("unit", "只");
		set("value", 1);
		set("no_drop", 1);
		set("can_give", 1);
				
		set("wear_msg", HIB"$N"HIB"戴上了藍冰戒，一層水藍色的薄霧隱約籠罩著$N"HIB"！"NOR);
		set("unequip_msg", BLU"$N"BLU"拿下了藍冰戒，水藍薄霧也慢慢飄散於空中...\n"NOR);
		
		set_weight(100);
		set("armor_prop/int", 10);
		set("armor_prop/armor", 5);
		set("armor_prop/shield", 10);		
	}
	
	setup();
}

int query_autoload() { return 1; }
