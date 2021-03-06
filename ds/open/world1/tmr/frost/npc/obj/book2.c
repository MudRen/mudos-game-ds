#include <ansi.h>
        
inherit ITEM;

void create()
{
          set_name("雲笈七籤-說戒部",({"against book", "book"}) );
        set_weight(80);
        set("long",@long
這是道派道藏中最有名「雲笈七籤」中的說戒部。裡頭記載
了十戒、太上洞玄靈寶消魔寶真安志智慧本願大戒、太霄瑯書十
善十惡及微定志經十戒等戒條。
封面旁用硃砂寫著一行符文，不知道跟著念(read)會發生什麼事。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","本");
                set("value",0);
        }
        setup();
}

void init() 
{
        add_action("summon_book", "read");
}

int summon_book(string arg)
{
        object me;
        if(arg != "符文")
                return notify_fail("你想要念什麼？\n");

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
 
    if(me->query("hp") < 100 )
          return notify_fail("你的身體狀況不佳，不能念出經文。\n");

    message_vision(CYN "$N拿起雲笈七籤-說戒部大聲念出十戒的內容。\n"NOR ,me);
    if(me->query("evil") < -500 ) {
                tell_object(me,HIM"你覺得魔力從你體內源源不絕的生出來。\n"NOR);
                  me->receive_heal("mp", me->query("max_mp")/3);
                me->start_busy(1);
    } else {
                tell_object(me,HIC"你覺得心中的惡念減了許\多。\n"NOR);
                me->add("evil",-50);
                me->start_busy(1);
        }
    
    destruct( this_object() );
    return 1;
}

