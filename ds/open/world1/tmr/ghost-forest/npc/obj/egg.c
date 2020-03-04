#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("鬼鵰蛋",({"chisel egg","egg"}));
        set("long",@long
一顆大約有成人頭圍的鳥蛋，似乎為兇鳥  鬼鵰所生，其殼堅硬勝鐵
，傳聞以大量人血(blooding)能令其組織毀壞成粉。
long
                );
        set_weight(3000);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "顆");
        set("value",100);
                set("blood",0);
        }
        setup();
}

void init()
{
        add_action("do_blooding","blooding");
}

int do_blooding()
{
        object me,ob,powder;
        me=this_player();
        ob=this_object();

        if(me->is_busy() || me->is_fightint() )
                return notify_fail("你正忙著，沒空做其他事。\n");
        if(me->query("hp") < 20 ) 
                return notify_fail("依你目前的狀態，是無法再失血的。\n");
        message_vision(HIR "$N猛一咬舌，吐了幾口鮮血在一顆蛋上。\n"NOR ,me);
        ob->add("blood",1);
        set("long",
"一顆大約有成人頭圍的鳥蛋，似乎為兇鳥  鬼鵰所生，傳聞需以大量\n"
"人血餵食(blooding)，方能孵化。上頭沾有"+(string)ob->query("blood")+"點血斑。\n"
                );

        me->receive_damage("hp",9+random(5) );
        me->start_busy(2);

         if(ob->query("blood") > 30)
        {
         message_vision("「嘶」地一聲，$N身上的一顆鳥蛋漸漸地變成一團粉末。\n",me);
        powder=new(__DIR__"powder");
        powder->move(me);
        destruct(ob);
        }
        return 1;
}

