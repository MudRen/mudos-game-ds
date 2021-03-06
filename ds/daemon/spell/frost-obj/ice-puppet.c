#include <ansi.h>

inherit ITEM;

void create()
{
        // 代償 ITEM，以「COMPENSATORY_ITEM」為識別
        set_name(HIW"冰晶傀儡" NOR, ({ "ice puppet","ice-puppet","puppet", "COMPENSATORY_ITEM"}) );
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",@LONG
一塊維妙維肖的冰晶傀儡，散發著絲絲寒氣。這個冰晶傀儡刻畫的
是一個風華絕代，容姿優雅至無以復加的清逸美女，身長玉立，弱
質纖纖中透出無比堅強的氣質。清澈的眸子閃動著深不可測的智能
和光芒，像每刻都在向你傾訴著某種難以言喻的玄機。
你可以查看(verify)這個傀儡還能承受多少傷害。
LONG
);
                set("unit", "塊");
                set("no_give",1);
        set("value",1);
                set("no_get",1);
                set("no_put",1);
        }
       setup();
}

void do_dest() {
        destruct(this_object());
}

void init()
{
        if( !living(environment(this_object())) ) {
              //  message_vision("沒幾下子$N就融解成一灘水了。\n", this_object());
                call_out( "do_dest", 1);
                return;
        }
        if( !environment(this_object())->query_spell("ice-puppet") ) {
                // 沒有學過 ice-puppet
                set("hp", 0);
                return;
        }
        add_action("do_check","verify");
}

int do_check() {
        tell_object(this_player(), "冰晶傀儡還可以承受"+query("hp")+"點的傷害。\n");
        return 1;
}

void update_pet(object me) {
        // 可以代償的血
        set("hp", me->query_int()*5
                  + me->query_spell("ice-puppet")*5
                + me->query_wit()*100
        );
}

// Don't Clone
int query_unique() { return 1; }


