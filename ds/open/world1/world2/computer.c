// An example doll.c
// "undead_item" ��name�ФŶå�.
#include <ansi.h>
inherit ITEM;
void create()
{
	set_name("�p���q��[�{�N]",({"now computer","computer"}));
	set_weight(1000);
		set("value",0);
		set("no_drop",1);
		set("no_put",1);
		set("unit","�x");
		set("long",@LONG
�@�x�p�����q���C���U�{�N���Ův���@��²�檺�p��C

    weight <���q>  :  ��ܦ����q���˳ƨt�Ϊ����w��.

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
		message_vision("����$N�n���_$n��, $n��M�Ƭ��@����u�C\n",env,this_object());
		destruct(this_object());
		return;
	}
	add_action("do_weight","weight");

}

int do_weight(string arg)
{
	int g,total;
	if(!arg) return notify_fail("  ���O�榡: weight <���q>\n");
	if(sscanf(arg, "%d",g) != 1 ) return notify_fail("  ���O�榡: weight <���q>\n");
	if(g < 1 ) return notify_fail("  ���q�����j��1�C\n");

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
