#include <path.h>
#include <weapon.h>
#include <ansi.h>
inherit F_UNIQUE;
inherit SWORD;
void create()
{
	set_name(HIC"七星倒峰劍"NOR,({"sevenstar barb sword","sword","sevenstar"}));

	set_weight(5000+random(1000));
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",HIB"這把劍輕巧柔軟，可是在你抽出這把劍時，確發現這把劍的嗜血和可怕\n"
		      "之處，在劍峰上隱隱有些許的血滴流露出來。傳說這把件是古代時異人\n"
		      "用血和玄鐵譸成的，所以這一把件是無比的鋒利和無比的血腥。\n"NOR);
                set("unit", "把");
		set("value",950);
		set("sword",60);
		set("material", "starring");
		set("limit_lv",25);
		set("limit_str",30);
		set("limit_dex",20);
	}
	init_sword(70);
	set("wield_msg","$N從背後的劍袋中抽出一把$n，登時一片血光從$N的身上散發出來！\n");
	set("unwield_msg", "$N將手中的$n小心收好。\n");
	set("replica_ob", __DIR__"longsword.c");
	setup();
}
void attack(object me,object victim)
{
	int damage,str,dex,random1;
	if( random(200)>150)
	{
	str = me->query("str")-random(20);
	dex = me->query("dex")-random(18);
	random1 = 1+random(2);
	damage = random1*(str+dex);
        victim->receive_damage("hp", damage, me );
	message_vision(
	"\n"
	+HIY"七星倒鋒劍在劍尖一滴一滴的血流隱隱的如水柱般的流了出來。\n"NOR
	+HIG"一股聲音從劍中咆哮了出來∼∼∼．．．．．．\n"NOR
        +HIR"倏地間，在$N眼前一片血光之色！！！從劍中發出一道黑氣往$N而去。\n"NOR
	+HIB"結果造成$N"+damage+"點的傷害！！！！\n"NOR
	,victim);
	return;
	}
}
