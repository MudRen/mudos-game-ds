#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(MAG"變性丹"NOR, ({ "pill" }));
        set("long",
        "傳說中九天旋女遺留在人間的曠世奇丹，要是凡人吃到，好像會起某些變化。\n(請用use pill)\n"
        );
        set_weight(500);
        if(clonep() )
                set_default_object(__FILE__);
        else
        { 
                set("value",10000);
                set("unit", "顆");
        }
        setup();
}
void init()
{
        add_action("do_eat", "use");
}
int do_eat(string arg)
{
        object me ,obj;
               me = this_player();
               obj = this_object();
        if( !arg )
        return notify_fail("你要吃啥 ﹖\n");
        if (arg != obj->query("id")) return notify_fail("你要吃啥 ﹖\n");
        if (me->query("class1") == "少帥軍" ) return notify_fail(HIW"寇仲用千里傳音對你說：男兒當自強，如果您吃下此丹，將被永逐於我少帥軍門下。\n"NOR);
        if (me->query("class1") == "情城池" ) return notify_fail(HIW"情城池令：凡我門下，一律不准吃此丹。\n"NOR);
        if (me->query("class1") == "凌雲寺" ) return notify_fail(HIW"住持方丈用千里傳音對你說：阿彌陀佛，如果您吃下此丹，咱倆的師徒緣分就此結束。\n"NOR);
        if (me->query("marry_id")) return notify_fail("結了婚變性?要拋妻棄子嗎??\n");
        if (me->query("gender") == "男性")
        {
        me->set("gender","女性");
        }
       else
        {
        me->set("gender","男性");
        }           message_vision(HIW"$N一口吞下了$n，$N的身體上好像起了某些變化...\n"NOR,me,obj);
        me->unconcious();
        destruct(obj);
        return 1;
       }

