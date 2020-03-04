#include <ansi.h>
inherit EQUIP;
void create()
{
	set_name("�j�K�G��", ({ "detector_v2" }) );
	set_weight(1);
	set("unit", "�@");
	set("long","�o�Ӥj�K�i�H���b���~������(detect), �N�i�H�o���Ӫ��~���j�פF....\n");
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
	if( !arg ) return notify_fail("�A�n��j�K���b����?\n");
	if( arg ) ob = present(arg, (this_player()));
	else ob = this_player()->query_opponent();
	if( !ob ) return notify_fail("�A���W�S�o���N��..\n");
	if( this_player()->query("id") != "dung") {
		if( !wizardp(this_player()) )
			return notify_fail("�A���O�Ův�Ҩ��v�i�H�ϥΦ����~���H!\n");
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
	
	message_vision("$N��@�Ǥj�K�٦b"+name+"���W��.\n",this_player());
	tell_object(this_player(),"�A�i�H�J�Ӭݨ�"+name+"�������W�B�{�F�@�Ǥ�r�M�Ʀr:\n");
	tell_object(this_player(),long);
	if(limit_lv!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"�����~���Ť����N����ϥγ�!\n");
		else tell_object(this_player(),"�����~�ݭn���� "+limit_lv+" �Ť~��ϥ�.\n");
	}
	if(limit_skill!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"�����~�ޯ൥�Ť����N�L�k�B�γ�!\n");
		else tell_object(this_player(),"�����~�ݭn�ӧޯ� "+limit_skill+" �Ť~��ϥ�.\n");
	}
	if(limit_str!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"�����~�O�q�p��Y�ƴN�����ʳ�!\n");
		else tell_object(this_player(),"�����~�ݭn�O�q "+limit_str+" �~��ϥ�.\n");
	}
	if(limit_con!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"�����~���p��Y�ƴN�����ʳ�!\n");
		else tell_object(this_player(),"�����~�ݭn��� "+limit_con+" �~��ϥ�.\n");
	}
	if(limit_int!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"�����~���ʤp��@�w�{�״N�����D�p��ϥγ�!\n");
		else tell_object(this_player(),"�����~�ݭn���� "+limit_int+" �~��ϥ�.\n");
	}
	if(limit_dex!=0) {
		if(!wizardp(this_player())) tell_object(this_player(),"�����~�ӱ��פ����N�L�k�ϥγ�!\n");
		else tell_object(this_player(),"�����~�ݭn�ӱ� "+limit_dex+" �~��ϥ�.\n");
	}
	if(str!=0) tell_object(this_player(),"�W�[�O�q "+str+" �I.\n");
	if(con!=0) tell_object(this_player(),"�W�[��� "+con+" �I.\n");
	if(int2!=0) tell_object(this_player(),"�W�[���O "+int2+" �I.\n");
	if(dex!=0) tell_object(this_player(),"�W�[�ӱ� "+dex+" �I.\n");
	if(bio!=0) tell_object(this_player(),"�W�[����[�ͪ�] "+bio+" �I.\n");
	if(bar!=0) tell_object(this_player(),"�W�[����[�~��] "+bar+" �I.\n");
	if(wit!=0) tell_object(this_player(),"�W�[����[�]�k] "+wit+" �I.\n");
	if(sou!=0) tell_object(this_player(),"�W�[����[���F] "+sou+" �I.\n");
	if(tec!=0) tell_object(this_player(),"�W�[����[���] "+tec+" �I.\n");
	if(hit!=0) tell_object(this_player(),"�W�[�R���v "+hit+" �I.\n");
	if(dodge!=0) tell_object(this_player(),"�W�[�{�ײv "+dodge+" �I.\n");
	if(shield!=0) tell_object(this_player(),"�W�[�]�k���m�O "+shield+" �I.\n");
	if(armor!=0) tell_object(this_player(),"�W�[���z���m�O "+armor+" �I.\n");
	if(damage!=0) tell_object(this_player(),"�W�[���z�����O "+damage+" �I.\n");
	if(arrow_d!=0) tell_object(this_player(),"�b�����ˤO: "+arrow_d+" �I.\n");
	if(replica_ob) tell_object(this_player(),"�ӥB�����~�O�W�@�L�G, ���L�Ȧ�����!\n");
	if(show_damage!=0) tell_object(this_player(),"�ӥB�����~�i�H�ݬ�Ĥ���˵{�׳�!\n");
	if(value!=0) tell_object(this_player(),"�����~���� "+value+" �T�j��.\n");
	if(weight!=0) tell_object(this_player(),"������ "+weight+" �ӳ���.\n");
	if(light!=0) tell_object(this_player(),"�����|�o��.\n");
	if(ob->query_autoload()) tell_object(this_player(),"�����i�O�s.\n");
	if(ob->query("female_only")) tell_object(this_player(),"�����Ȥk�ʯ��.\n");
	if(ob->query("male_only")) tell_object(this_player(),"�����Ȩk�ʯ��.\n");
	if(type=ob->query("armor_type")) {
		if(type == "armor") tell_object(this_player(),"�����O�Z����.\n");
		if(type == "cloth") tell_object(this_player(),"�����O�窫��.\n");
		if(type == "shield") tell_object(this_player(),"�����O�޵P��.\n");
		if(type == "surcoat") tell_object(this_player(),"�����O�ܭ���.\n");
		if(type == "wrists") tell_object(this_player(),"�����O�@����.\n");
		if(type == "waist") tell_object(this_player(),"�����O�y�a��.\n");
		if(type == "neck") tell_object(this_player(),"�����O������.\n");
		if(type == "finger") tell_object(this_player(),"�����O�٫���.\n");
		if(type == "boots") tell_object(this_player(),"�����O�c�u��.\n");
		if(type == "hands") tell_object(this_player(),"�����O��M��.\n");
		if(type == "head") tell_object(this_player(),"�����O���U��.\n");
	}
	if(type=ob->query("skill_type")) {
		if(type == "sword") tell_object(this_player(),"�����O�C��.\n");
		if(type == "blade") tell_object(this_player(),"�����O�M��.\n");
		if(type == "axe") tell_object(this_player(),"�����O����.\n");
		if(type == "hammer") tell_object(this_player(),"�����O����.\n");
		if(type == "throwing") tell_object(this_player(),"�����O���Y��.\n");
		if(type == "dagger") tell_object(this_player(),"�����O�P��.\n");
		if(type == "whip") tell_object(this_player(),"�����O�@��.\n");
		if(type == "gun") tell_object(this_player(),"�����O����.\n");
		if(type == "bow") tell_object(this_player(),"�����O�}��.\n");
		if(type == "fork") tell_object(this_player(),"�����O�ٴu��.\n");
		if(type == "staff") tell_object(this_player(),"�����O�ҧ���.\n");
		if(type == "fist") tell_object(this_player(),"�����O������.\n");
	}
	if(ob->is_food()) {
		tell_object(this_player(),"�����O����,");
		if(food=ob->query("food_remaining")) tell_object(this_player()," �i���� "+food+" ��.\n");
		else tell_object(this_player()," �i���� 1 ��.\n");
	}
	if(ob->is_water()) {
		tell_object(this_player(),"�����O�G��.\n");
		if(water=ob->query("water_remaining")) tell_object(this_player()," �i���� "+water+" ��.\n");
		else tell_object(this_player()," �i���� 1 ��.\n");
	}
	if(ob->is_pill()) {
		tell_object(this_player(),"�����O�Ī�.\n");
		if(food=ob->query("food_remaining")) tell_object(this_player()," �i���� "+food+" ��.\n");
		tell_object(this_player()," �i���� 1 ��.\n");
	}
	if(ob->query("heal_hp")) tell_object(this_player(),"�����ϥΫ�ɥRHP: "+ob->query("heal_hp")+".\n");
	if(ob->query("heal_mp")) tell_object(this_player(),"�����ϥΫ�ɥRMP: "+ob->query("heal_mp")+".\n");
	if(ob->query("heal_ap")) tell_object(this_player(),"�����ϥΫ�ɥRAP: "+ob->query("heal_ap")+".\n");
	if(ob->query("heal_head")) tell_object(this_player(),"�����ϥΫ�^�_�Y���l��: "+ob->query("heal_head")+"%.\n");	
	if(ob->query("heal_hand")) tell_object(this_player(),"�����ϥΫ�^�_�ⳡ�l��: "+ob->query("heal_hand")+"%.\n");
	if(ob->query("heal_foot")) tell_object(this_player(),"�����ϥΫ�^�_�}���l��: "+ob->query("heal_foot")+"%.\n");
	if(ob->query("heal_body")) tell_object(this_player(),"�����ϥΫ�^�_�߷F�l��: "+ob->query("heal_body")+"%.\n");

	return 1;
}

int query_autoload() { return 1; }