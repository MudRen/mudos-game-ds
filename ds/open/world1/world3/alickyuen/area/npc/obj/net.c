#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"電子捕捉球"NOR, ({ "monstor ball","ball" }) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "這是一個捕捉(catch)動物用的電子捕捉球。\n"
"電子籠是沒基本架構的，你看的時候也只是能見到小動物，\n"
"但其實是由紅外線的光線做成一個電子捕捉球來把動物困起來。\n");
                set("unit", "個");
                set("value",0);
// set("material","rubber");  電子籠是沒基本架構的,看上去也只是得一隻小動物,
// 但其實是由紅外線之類的光線做成一個電子籠來把動物放起來
        }
        setup();
}

void init()
{ 
        add_action("do_catch","catch");
}

int do_catch(string arg)
{
        object me,obj;
        me=this_player();
        if( !arg ) return notify_fail("你想捕捉誰？\n");
   if(me->is_busy() ) return notify_fail("你正忙著。\n");
        if(!objectp(obj = present(arg, environment(me)))) return notify_fail("這裡沒有這種東西。\n");
        if( !obj->is_character() || obj->is_corpse() ) return notify_fail("你只能捕捉活的生物。\n");
         if(userp(obj)) return notify_fail("你不能夠捕捉玩家哦。\n");
        message_vision("$N一手拿起電子捕捉球，一手準備去抓住$n。\n",me,obj);
if (arg != "wildanimal") 
        {
                message_vision("這不是你要捕捉的動物。\n"NOR,me,obj);
        }
        else {
        if( random(100) > 70 )
	{
message_vision("$N一手把$n放了進電子捕捉球。\n",me,obj);
                me->add("Find_An/animal",1);
                set("long", "這是一個捕捉(catch)動物用的電子捕捉球。\n"
"電子籠是沒基本架構的，你看的時候也只是能見到小動物，\n"
"但其實是由紅外線的光線做成一個電子捕捉球來把動物困起來。\n"
        "你看見電子籠上寫著一個字：\n"
YEL"　　　　　　　　　｜－－－－－｜\n"NOR
YEL"　　　　　　　　　　　　"+me->query("Find_An/animal")+"　　\n"NOR
YEL"　　　　　　　　　｜－－－－－｜\n"NOR
        );
                destruct(obj);
	}
	else
	{
	message_vision("小動物察覺到$N的舉動，呆了一會。\n",me);
	me->start_busy(1);
	}
        }
        return 1;
}
