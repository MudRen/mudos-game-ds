#include <ansi.h>
inherit ITEM;

mixed *sortinv(object env);

void create()
{
	set_name(HIC"藍天測試儀(數量)"NOR,({"tttt"}));
	set("long","這是一個水藍測試儀。\n");
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","個");
		set("value",9999);
	}
	setup();
}

void init()
{
	add_action("do_tttt","tttt");
}

int do_tttt()
{
	object me,env,*inv;
	int i,j;

	me = this_player();
	env = environment(me);

	inv = F_QUANTITY->sortinv(env);

	for(i=0;i<sizeof(inv);i++)
	{
		printf("%O\n",inv[i]);
	}

	j = 1;
	for(i=0;i<sizeof(inv);i++)
	{
		if( i+1 < sizeof(inv) )
		{
			if( base_name(inv[i])==base_name(inv[i+1]) 
			&& base_name(inv[i])!="/obj/user")
				j++;
			else
			{
				write(chinese_number(j)+" 個"+inv[i]->query("name")+"\n");
				j = 1;
			}
		}
		else write(chinese_number(j)+" 個"+inv[i]->query("name")+"\n");
	}

	return 1;
}

mixed *sortinv(object env)
{
	object *inv;
	object invtmp;

	int i,j,k;

	if(!env) return 0;
	inv = all_inventory(env);

	for(i=0;i<sizeof(inv);i++)
	for(j=i;j<sizeof(inv);j++)
	{
		if( strcmp(base_name(inv[i]),base_name(inv[j]))==1 )
		{
			invtmp = inv[j];
			for(k=j;k>=i+1;k--)
				inv[k] = inv[k-1];
			inv[i] = invtmp;
		}
	}
	return inv;
}