#include <ansi.h>
#include <armor.h>
inherit ITEM;

void create()
{
           set_name("有色的設定", ({ "rex set","set" }));
	set_weight(1);
	if( clonep() )
		set_default_object(__FILE__);  
	else
	{
		set("long","？？？？？。\n");
		set("unit","個");
	}
	setup();
}

void init()
{
	object me=this_player();
	add_action("do_rexx","rex");
}

int do_rexx(string a)
{
	object me=this_player();
	string arg,b;
	if( !a || sscanf(a ,"%s %s",b,arg)!=2 ) return notify_fail("[格式] rex <項目> <內容>\n");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	me->set(b,arg + NOR);
	write("完成。\n");
	return 1;
}
