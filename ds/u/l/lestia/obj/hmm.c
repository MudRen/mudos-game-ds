#define WALLITEM "極光結界"
#define WALLLONG "一個由五道極光結合而成的強力結界。\n"
#define WALLID   "lightwall"
inherit ITEM;
void create()
{
        set_name(WALLITEM,({WALLID}));
        set_weight(99999);
        set("long",WALLLONG);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "層");
                set("value",0);
                set("no_drop",1);
                set("no_get",1);
                set("no_sac",1);
                }
        setup();
}
void init()
{
add_action("do_enter","enter");
add_action("do_go","go");
}

int do_enter(string arg)
{
     int invis;
object me;
me = this_player();
// if(!arg="enter") return notify_fail("那裡只有巫師才能進去。\n");

me->move("/open/world1/acme/bonze/b19.c");
return 1;
}
int do_go(string arg)
{
int i;
object me = this_player();
if(arg="enter") return 0;
me->move("/open/world1/acme/bonze/b19.c");
return 1;
}
 
