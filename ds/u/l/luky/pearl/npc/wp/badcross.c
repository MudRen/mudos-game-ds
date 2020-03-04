#include <ansi.h>.
#include <weapon.h>
inherit STAFF;
int do_wield(object me, object ob);
void create()
{
set_name("損毀的十字架",({"bad cross","cross","wand"}));
set_weight(21000);
  if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "這是一把損毀的魔杖。\n");
  set("value",1);
                set("material", "steel");
        }
init_staff(1);
        setup();
}
void init()
{
 add_action("do_invoke","invoke");
 add_action("do_recharge","recharge");
}

int do_invoke(string arg)
{                        
 object me;
 me=this_player();
 if(!me) return 0;
 if(this_object()==present(arg,me))
	return notify_fail("你的魔杖已損毀無法再使用\n");
 else return 0;
}

int do_recharge(string arg)                     
{                                           
 object me;                          
 int time;
 me = this_player();              
 if(!me) return 0;
 if(this_object()==present(arg,me))
	return notify_fail("你的魔杖已損毀無法再使用\n");
 else return 0;
}
