// 可影印的雜誌(複製品)
inherit ITEM;

void create()
{
	set_name("第四波(複製)",({"forth magazine","magazine","forth"}) );
	set("long",@LONG
這是一本雜誌...名叫「第四波」...嘻...嘻...嘻...
LONG
	);
	set_weight(300);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",1);
		set("unit","本");
	}

	setup();
}

int can_copy()
{
	return 1;
}

int is_magzine()
{
	return 1;
}

int is_copy()
{
	return 1;
}
