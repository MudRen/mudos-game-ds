// 可影印的雜誌(複製品)
inherit ITEM;

void create()
{
	set_name("PLAYGIRL(複製)",({"playgirl magazine","magazine","playgirl"}) );
	set("long",@LONG
PLAYGIRLPLAYGIRL			PLAYGIRL
PLAYGIRL	PLAYGIRL	PLAYGIRL	PLAYGIRL
PLAYGIRL	PLAYGIRL	PLAYGIRL	PLAYGIRL
PLAYGIRL	PLAYGIRL	PLAYGIRL	PLAYGIRL
PLAYGIRL	PLAYGIRL	PLAYGIRL	PLAYGIRL
PLAYGIRLPLAYGIRL		PLAYGIRL
PLAYGIRL			PLAYGIRLPLAYGIRLPLAYGIRLPLAYGIRL
PLAYGIRL			PLAYGIRL	PLAYGIRL
PLAYGIRL			PLAYGIRL	PLAYGIRL
PLAYGIRL			PLAYGIRL	PLAYGIRL
PLAYGIRL		lay		PLAYGIRLPLAYGIRL	irl
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
