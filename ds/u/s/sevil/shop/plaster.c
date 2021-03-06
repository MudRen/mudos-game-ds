#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("狗皮膏藥",({"dog plaster","plaster"}) );
        set("long",@long
一張不知是從什麼動物身上拔下的皮，上頭厚厚地塗了一層膏藥，似
乎是尋常百姓用於跌打損傷，聞著那黝黑、發出惡臭地的藥味，令人懷疑
是不是騙人的膏藥。或許能貼看看吧。(use plaster on 部位)
long
);
        set_weight(100);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
        set("value",120);
        set("unit","張");
        set("material","fur");
        }
        setup();
}

int do_use(object me,string arg)
{
        string type;
        if(!arg) return notify_fail("用法: use plaster on <部位>。\n");
        if(environment(this_object())!=me) return 0;
        if(sscanf(arg,"on %s",type)!=1) return notify_fail("用法: use plaster on <部位>。\n");

        if(type!="left_leg" &&
           type!="right_leg" &&
           type!="left_arm" &&
           type!="right_arm" &&
           type!="body" && 
           type!="head"
        )
	 return notify_fail("狗皮膏藥只能貼在傷口(head,body,left_leg,right_leg,left_arm,right_arm)上。\n");

        if(me->is_busy() ) return notify_fail("你正忙著，沒有空貼藥。\n");
        if(me->query("wound/"+type) < 1) return notify_fail("你的"+to_chinese(type)+"並沒有傷口。\n");
        message_vision("$N一把拿起狗皮膏藥貼往自已"+to_chinese(type)+"的傷口，只聽「斯」地一聲，傷口發出一股惡臭......\n",me);
        me->receive_curing(type,2);
//        me->start_busy(1);
        destruct(this_object());
        return 1;
}

