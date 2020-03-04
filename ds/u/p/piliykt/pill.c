#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIR"魔法"HIW"小"HIC"藥丸"NOR,({"pill"}) );
set("pill","LONG");
set_weight(1);
if( clonep() )
set_default_object(__FILE__);
else{set("unit","個");set("value",50000); }
setup();
}

void init()
{add_action("do_eat","eat");}

int do_eat(string arg)
{object me = this_player();object ob = this_object();
if( !this_object() ) return 0;if( !this_object()->id(arg) ) return 0;
me->set("env/msg_mout",HIW"$N揮動手上的"HIB"黑暗魔仗"NOR","HIY"一陣光閃,"HIR"$N消失的"HIC"無影無蹤.\n"NOR);
me->set("env/msg_min",HIC"轟的一聲"HIW"一陣光閃"HIY"忽然$N"HIM"走了出來.\n"NOR);
me->set("env/msg_clone",HIC"$N舞動手上的"HIM"黑暗魔法杖"HIW"$n一陣光閃就變了出來.\n"NOR);
me->set("env/msg_dest",HIW"$N嘴裡"HIM"喃喃的念著咒語"HIR"一顆火球向$n飛了過去"HIC"轟的一聲變成一堆廢物\n"NOR);
write(HIC"你吃下一顆"HIR"魔法"HIW"小"HIC"藥丸"NOR",頓時全身發出"HIW"白光\n"NOR);
destruct(ob);return 1;}

