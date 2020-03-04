#include <ansi.h>
inherit ITEM;

string *longs = ({
  "這是一塊已封印的大石，上面還圍著一條條由符咒組成的麻繩，似乎因為年代已久的關係，\n上面的符紙有些脫落，有些被侵蝕，漸漸的顯露出了靈氣，令人迫不可視。\n",
  HIR"大石上還有些血跡。\n"NOR,
});

void create()
{
        set_name(HIR"封印的大石"NOR, ({ "cachet stone", "stone" }));
        set("long", longs[0] );
        set_weight(100000);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit", "塊");
                set("value", 1);
                set("no_get", 1);
                set("no_sac", 1);
        }
        setup();
}

void init()
{
        add_action("do_place", "place");
}

int do_place(string arg)
{
        object me, ob, tar;
        me = this_player();
        ob = this_object();

        if( !arg ) return notify_fail("你要祭奉什麼東西給大石？\n");
        if( !objectp(tar = present(arg, me)) )
                return notify_fail("你身上沒有這個東西喔，要怎麼祭祀呀？\n");
        if( tar->query("id") != "fox teeth" )
		return notify_fail("你把" + tar->name() + "祭奉給大石，不過似乎沒什麼事發生，於是又拿了下來！\n");
        else
        {
                this_object()->set("long", longs[0] + longs[1] );
                message_vision(HIY"$N把$n"HIY"放在" + name() + HIY"，不過一會兒，$n"HIY"漸漸消失了，遠方似乎傳來了一陣陣的殺氣！！\n"NOR, me, tar);
                destruct(tar);
        }
        write("可以開 !...:P\n");
        return 1;
}
