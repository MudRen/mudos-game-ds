inherit EQUIP;

void create()
{
	set_name("�j�K", ({ "detector", "glass", "device" }) );
	set_weight(300);
	set("unit", "��");
	set("long",
		"�o�Ӥj�K�i�H��b�O�H�y�W(detect), �ɥH�o����誺�j��,\n"
		"��M�]�i�H��b�ۤv���y�W....�{�Ѥ@�U�ۤv...:D�C\n");
	set("value", 100000);
	set("type", "misc");
	set("apply", ([
		"�Y��":	0,
	]) );
}

void init()
{
	add_action("do_detect", "detect");
}

int do_detect(string arg)
{
	object ob ;
	int hp, mp, sk, dodge, hit, damage, armor, exp, str, int2;
        int power, spellpower, allpower,exp3;
        int hp2, mp2, sk2, dodge2, hit2, damage2, armor2, exp2, str2, int3;
	string skill,name;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

	if( !ob ) return notify_fail("�A�n�����֪��԰��O�S\n");

        dodge = dodge2 = (int)ob->query_temp("apply/dodge"); dodge = dodge*(2/3); dodge2 = dodge2;
        hit = hit2 = (int)ob->query_temp("apply/hit"); hit = hit/2; hit2 = hit2/4;
        damage = damage2 = (int)ob->query_temp("apply/damage"); damage = damage*6; damage2 = damage2*4;
        armor = armor2 = (int)ob->query_temp("apply/armor"); armor = armor*4; armor2 = armor2*6;
        exp = exp2 = (int)ob->query("combat_exp"); exp = exp/350;  
        exp3 = (int)ob->query("magicexp"); exp3 = exp3/233; exp2 = (exp+exp3)/2;  
    	name = ob->query("name"); 
	if( stringp(skill = ob->query("attack_skill")) )
		sk = sk2 = ob->query_skill(skill);
	else
		sk = sk2 = 0;
        sk = sk*7; sk2 = sk2*5;
	power = dodge + hit + damage + exp + armor; 
        spellpower = dodge2 + hit2 + damage2 + exp2 + armor2;
        printf("�j�K���%s�������Z�O�O: %d\n",name,power);
        printf("�j�K���%s�������k�O�O: %d\n",name,spellpower);
        spellpower = spellpower*(3/2);
        allpower = ( power + spellpower ) / 2;
	printf("�j�K���%s�������`�X�ԤO�O: %d\n",name,allpower);

	return 1;
}
