/**
 *	Shadow's boots
 *	以踏水鞋為範本改編.
 */
#include <armor.h>
#include <ansi.h>
inherit BOOTS;

void create()
{
	set_name(HIW"雪羽"NOR, ({ "snow feather boots","boots" }) );
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
    此靴潔白如雪，於泥濘中疾行亦不染上塵埃。細看之下，驚
覺此靴乃由無數鳥羽以精巧無比的手法層層編織而成，交叉編織
的技法恰到好處地將鳥羽稀疏的末端嵌入鞋身，只露出皎白整齊
的羽身，乍看之下雙腳猶如腳踏兩雪白飛鳥般飄逸如仙。
LONG
    );
		set("unit", "雙");
		set("material", "cloth");
		set("needaward", 9);
		set("value", 1);
		set("no_drop", 1);
		set("can_give", 1);

		
		set("wear_msg", HIW"$N"HIW"穿上了一雙雪羽，四周流動的空氣也跟著飄逸起來！"NOR);
		set("unequip_msg", HIW"$N"HIW"脫下了雪羽，輕舞飛揚的氣流也隨之沈寂！\n"NOR);
		
		set_weight(100);
		set("armor_prop/dex",5);
		set("armor_prop/dodge",50);
		set("armor_prop/armor",10);
	}

	
	setup();
}

int query_autoload() { return 1; }
/*
    大地極北有名山一座名為「浩月」，此山人煙罕至，神秘非
常。山中珍禽異獸無數，有一神鳥「雪雉」，樣似鳳凰而鳴若黃
鶯，振翅可飛逾萬里，據聞若以雪雉之羽編織為靴，裝備之人可
一日千里宛如
*/