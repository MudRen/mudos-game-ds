#include <ansi.h>
inherit EQUIP;
void create()
{
	set_name("大便二型", ({ "detector_v2" }) );
	set_weight(1);
	set("unit", "坨");
	set("long","這個大便可以擦在物品的表面(detect), 就可以得知該物品的強度了....\n");
	set("value", 1);
	set("no_drop",1);
	set("no_sell",1);
	set("no_give",1);
}
void init()
{
	add_action("do_detect", "detect");
}
int limit_lv,limit_skill,limit_str,limit_con,limit_int,limit_dex,str,con,int2,dex,bio,bar,wit,sou,tec,hit,attack;
int food,water;
int do_detect(string arg)
{
	object ob;
	string replica_ob;
	string long,name,type;
	int dodge,parry,block,shield,armor,damage,arrow_d,value,show_damage,weight,light;
	if( !arg ) return notify_fail("你要把大便擦在哪裡?\n");
	if( arg ) ob = present(arg, (this_player()));
	else ob = this_player()->query_opponent();
	if( !ob ) return notify_fail("你身上沒這玩意兒..\n");
	if( this_player()->query("id") != "dung") {
		if( !wizardp(this_player()) )
			return notify_fail("你不是巫師所受權可以使用此物品的人!\n");
	}
	limit_lv = ob->query("limit_lv");
	limit_skill = ob->query("limit_skill");
	limit_str = ob->query("limit_str");
	limit_con = ob->query("limit_con");
	limit_int = ob->query("limit_int");
	limit_dex = ob->query("limit_dex");
	str = ob->query("weapon_prop/str") + ob->query("armor_prop/str");
	con = ob->query("weapon_prop/con") + ob->query("armor_prop/con");
	int2 = ob->query("weapon_prop/int2") + ob->query("armor_prop/int2");
	dex = ob->query("weapon_prop/dex") + ob->query("armor_prop/dex");
	bio = ob->query("weapon_prop/bio") + ob->query("armor_prop/bio");
	bar = ob->query("weapon_prop/bar") + ob->query("armor_prop/bar");
	wit = ob->query("weapon_prop/wit") + ob->query("armor_prop/wit");	
	sou = ob->query("weapon_prop/sou") + ob->query("armor_prop/sou");
	tec = ob->query("weapon_prop/tec") + ob->query("armor_prop/tec");
	hit = ob->query("weapon_prop/hit") + ob->query("armor_prop/hit") + ob->query("weapon_prop/attack") + ob->query("armor_prop/attack");
	dodge = ob->query("weapon_prop/dodge") + ob->query("armor_prop/dodge");
	parry = ob->query("weapon_prop/parry") + ob->query("armor_prop/parry");
	block = ob->query("weapon_prop/block") + ob->query("armor_prop/block");
	dodge = dodge + parry + block;
	shield = ob->query("weapon_prop/shield") + ob->query("armor_prop/shield");	
	armor = ob->query("weapon_prop/armor") + ob->query("armor_prop/armor");
	damage = ob->query("weapon_prop/damage") + ob->query("armor_prop/damage");
	arrow_d = ob->query("arrow/damage");
	value = ob->query("value");
	replica_ob = ob->query("replica_ob");
	name = ob->query("name");
	long = ob->query("long");
	show_damage = ob->query("armor_prop/show_damage") + ob->query("weapon_prop/show_damage");
	weight = ob->query_weight();
	light = ob->query_temp("has_light");
	
	message_vision("$N把一些大便抹在"+name+"的上面.\n",this_player());
	tell_object(this_player(),"你可以仔細看到"+name+"的表面上浮現了一些文字和數字:\n");
	tell_object(this_player(),long);
	if(limit_lv!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"此物品等級不夠就不能使用喔!\n");
		else tell_object(this_player(),"此物品需要等級 "+limit_lv+" 級才能使用.\n");
	}
	if(limit_skill!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"此物品技能等級不足就無法運用喔!\n");
		else tell_object(this_player(),"此物品需要該技能 "+limit_skill+" 級才能使用.\n");
	}
	if(limit_str!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"此物品力量小於某數就拿不動喔!\n");
		else tell_object(this_player(),"此物品需要力量 "+limit_str+" 才能使用.\n");
	}
	if(limit_con!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"此物品體格小於某數就拿不動喔!\n");
		else tell_object(this_player(),"此物品需要體格 "+limit_con+" 才能使用.\n");
	}
	if(limit_int!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"此物品悟性小於一定程度就不知道如何使用喔!\n");
		else tell_object(this_player(),"此物品需要悟性 "+limit_int+" 才能使用.\n");
	}
	if(limit_dex!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"此物品敏捷度不夠就無法使用喔!\n");
		else tell_object(this_player(),"此物品需要敏捷 "+limit_dex+" 才能使用.\n");
	}
	if(str!=0) tell_object(this_player(),"增加力量 "+str+" 點.\n");
	if(con!=0) tell_object(this_player(),"增加體格 "+con+" 點.\n");
	if(int2!=0) tell_object(this_player(),"增加悟力 "+int2+" 點.\n");
	if(dex!=0) tell_object(this_player(),"增加敏捷 "+dex+" 點.\n");
	if(bio!=0) tell_object(this_player(),"增加素質[生物] "+bio+" 點.\n");
	if(bar!=0) tell_object(this_player(),"增加素質[獸性] "+bar+" 點.\n");
	if(wit!=0) tell_object(this_player(),"增加素質[魔法] "+wit+" 點.\n");
	if(sou!=0) tell_object(this_player(),"增加素質[心靈] "+sou+" 點.\n");
	if(tec!=0) tell_object(this_player(),"增加素質[科技] "+tec+" 點.\n");
	if(hit!=0) tell_object(this_player(),"增加命中率 "+hit+" 點.\n");
	if(dodge!=0) tell_object(this_player(),"增加閃避率 "+dodge+" 點.\n");
	if(shield!=0) tell_object(this_player(),"增加魔法防禦力 "+shield+" 點.\n");
	if(armor!=0) tell_object(this_player(),"增加物理防禦力 "+armor+" 點.\n");
	if(damage!=0) tell_object(this_player(),"增加物理攻擊力 "+damage+" 點.\n");
	if(arrow_d!=0) tell_object(this_player(),"箭的殺傷力: "+arrow_d+" 點.\n");
	if(replica_ob) tell_object(this_player(),"而且此物品是獨一無二, 絕無僅有的喔!\n");
	if(show_damage!=0) tell_object(this_player(),"而且此物品可以看穿敵方受傷程度喔!\n");
	if(value!=0) tell_object(this_player(),"此物品價值 "+value+" 枚古幣.\n");
	if(weight!=0) tell_object(this_player(),"此物重 "+weight+" 個單位值.\n");
	if(light!=0) tell_object(this_player(),"此物會發光.\n");
	if(ob->query_autoload()) tell_object(this_player(),"此物可保存.\n");
	if(ob->query("female_only")) tell_object(this_player(),"此物僅女性能用.\n");
	if(ob->query("male_only")) tell_object(this_player(),"此物僅男性能用.\n");
	if(type=ob->query("armor_type")) {
		if(type == "armor") tell_object(this_player(),"此物是鎧甲類.\n");
		if(type == "cloth") tell_object(this_player(),"此物是衣物類.\n");
		if(type == "shield") tell_object(this_player(),"此物是盾牌類.\n");
		if(type == "surcoat") tell_object(this_player(),"此物是披風類.\n");
		if(type == "wrists") tell_object(this_player(),"此物是護腕類.\n");
		if(type == "waist") tell_object(this_player(),"此物是腰帶類.\n");
		if(type == "neck") tell_object(this_player(),"此物是項鍊類.\n");
		if(type == "finger") tell_object(this_player(),"此物是戒指類.\n");
		if(type == "boots") tell_object(this_player(),"此物是鞋靴類.\n");
		if(type == "hands") tell_object(this_player(),"此物是手套類.\n");
		if(type == "head") tell_object(this_player(),"此物是盔帽類.\n");
	}
	if(type=ob->query("skill_type")) {
		if(type == "sword") tell_object(this_player(),"此物是劍類.\n");
		if(type == "blade") tell_object(this_player(),"此物是刀類.\n");
		if(type == "axe") tell_object(this_player(),"此物是斧類.\n");
		if(type == "hammer") tell_object(this_player(),"此物是鎚類.\n");
		if(type == "throwing") tell_object(this_player(),"此物是投擲類.\n");
		if(type == "dagger") tell_object(this_player(),"此物是匕類.\n");
		if(type == "whip") tell_object(this_player(),"此物是鞭類.\n");
		if(type == "gun") tell_object(this_player(),"此物是鎗類.\n");
		if(type == "bow") tell_object(this_player(),"此物是弓類.\n");
		if(type == "fork") tell_object(this_player(),"此物是矛戟類.\n");
		if(type == "staff") tell_object(this_player(),"此物是棍杖類.\n");
		if(type == "fist") tell_object(this_player(),"此物是拳指類.\n");
	}
	if(ob->is_food()) {
		tell_object(this_player(),"此物是食物,");
		if(food=ob->query("food_remaining")) tell_object(this_player()," 可食用 "+food+" 次.\n");
		else tell_object(this_player()," 可食用 1 次.\n");
	}
	if(ob->is_water()) {
		tell_object(this_player(),"此物是液體.\n");
		if(water=ob->query("water_remaining")) tell_object(this_player()," 可飲用 "+water+" 次.\n");
		else tell_object(this_player()," 可飲用 1 次.\n");
	}
	if(ob->is_pill()) {
		tell_object(this_player(),"此物是藥物.\n");
		if(food=ob->query("food_remaining")) tell_object(this_player()," 可食用 "+food+" 次.\n");
		tell_object(this_player()," 可食用 1 次.\n");
	}
	if(ob->query("heal_hp")) tell_object(this_player(),"此物使用後補充HP: "+ob->query("heal_hp")+".\n");
	if(ob->query("heal_mp")) tell_object(this_player(),"此物使用後補充MP: "+ob->query("heal_mp")+".\n");
	if(ob->query("heal_ap")) tell_object(this_player(),"此物使用後補充AP: "+ob->query("heal_ap")+".\n");
	if(ob->query("heal_head")) tell_object(this_player(),"此物使用後回復頭部損傷: "+ob->query("heal_head")+"%.\n");	
	if(ob->query("heal_hand")) tell_object(this_player(),"此物使用後回復手部損傷: "+ob->query("heal_hand")+"%.\n");
	if(ob->query("heal_foot")) tell_object(this_player(),"此物使用後回復腳部損傷: "+ob->query("heal_foot")+"%.\n");
	if(ob->query("heal_body")) tell_object(this_player(),"此物使用後回復軀幹損傷: "+ob->query("heal_body")+"%.\n");

	return 1;
}

int query_autoload() { return 1; }
