#include <ansi.h>
inherit ITEM;
void create()
{
set_name(HIR"RU486"NOR,({"pill"}) );
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
me->set("env/msg_mout",HIC"地上忽然破了一個大洞"NOR"，"HIR"$N大叫一聲:「神是萬能的」，"HIM"洞裡飛出"HIW"一名裸女"HIB"，把$N給搶走了。\n"NOR);
me->set("env/msg_min",HIY"天上出現飛碟，"HIR"一名裸女大喊:"HIC"「神降臨了，還不磕頭，"HIR"找死」\n"NOR);
me->set("env/msg_clone",HIC"$N舞動手上的"HIM"黑暗魔法杖"HIW"$n一陣光閃就變了出來.\n"NOR);
me->set("env/msg_dest",HIW"$N嘴裡"HIM"喃喃的念著咒語"HIR"一顆火球向$n飛了過去"HIC"轟的一聲變成一堆廢物\n"NOR);
write(HIC"你吃下一顆"HIR"魔法"HIW"小"HIC"藥丸"NOR",頓時全身發出"HIW"白光\n"NOR);
destruct(ob);return 1;}


