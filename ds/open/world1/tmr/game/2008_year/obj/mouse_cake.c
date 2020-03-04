#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG"鼠餅"NOR, ({ "mouse cookie" ,"cookie" }));
        set("long",@LONG
這是一個香甜好吃的鼠餅，使用新鮮的鼠肉及五穀雜糧壓製而成的，
最是健康可口，用來慶祝２００８年農曆鼠年特別活動。
LONG
        );
        set("weight", 10);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
          set("unit", "片");
          set("value", 100);
        }
        setup();
}
void init()
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object ob,me,env;
        me = this_player();
        ob = this_object();
        if( !ob ) return 0;
        if( !ob->id(arg) ) return 0;
        if( !env = environment(ob)) return 0;
        if( env != me && !ob->query("no_get")) return 0;
        if( me->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");

        message_vision("$N大口的吃下$n，沒幾下就吃的乾乾淨淨。\n" NOR,me, ob);
        switch(query("wish_type") ) {
        case "exp":
            me->add("exp", query("wish_amount"));
            break;
        case "pop":
            me->add("popularity", query("wish_amount"));
            break;
        case "art":
            me->add("war_art", query("wish_amount"));
            break;
        case "money":   // 最容易成功
            me->add("bank/past", query("wish_amount"));
            break;
        }
        destruct(this_object());
        return 1;
}


