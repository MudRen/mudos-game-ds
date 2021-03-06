// 雷霆戰車

#include <ansi.h>

inherit VEHICLE;

void create()
{
	set_name(HIG"雷霆戰車"NOR,({"power tank","power","tank"}));
	// 從外面看雷霆戰車的敘述
	set("vlong",@LONG
這台雷霆戰車是由藍藍的天所研發完成的，它具有高效能以及高火力的特性。
哇哈哈...............
LONG
	);
    set("short", HIC"雷霆戰車駕駛座"NOR);  // 戰車裡的短敘述
	// 戰車裡的長敘述
	set("long", @LONG
	╭───────╮╭───────╮╭───────╮
	│ Searching... ││      ┬      ││              │
	│              ││              ││             2│
	│              ││├    ┼    ┤││            19│
	│              ││              ││   -----+-----│
	│              ││      ┴      ││   0123456789A│
	╰───────╯╰───────╯╰───────╯
	  這裡有數個監控螢幕，無時無刻地監控著雷霆戰車地四周。
LONG
	);
	set("exits", ([ /* sizeof() == 0 */
            ]));
            
	set_max_capacity(9999999999);
	set_max_encumbrance(900000099);
	set_weight(999999999);
	set("valid_startroom", 1);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "台");
		set("value", 99999999);
	}
	setup();
}

void init()
{
	add_action("do_enter","enter");
	add_action("do_leave","leave");
	add_action("do_lookout","vlook");
	add_action("do_vgo","vgo");
}

int do_enter()
{
	object me;
	object env;
	me = this_player();
	if(!enter_vehicle(me))
		write("失敗囉...\n");
	else
		write("Ya!!!成功\了...\n");

	return 1;
}

int do_leave()
{
	object me;
	object env;
	me = this_player();
	if(!leave_vehicle(me))
		write("失敗囉...\n");
	else
		write("Ya!!!成功\了...\n");

	return 1;
}

int do_lookout(string arg)
{
	string line;
	line = look_out(arg);
	return 1;
}

int do_vgo(string arg)
{
	v_go(arg);
	return 1;
}

