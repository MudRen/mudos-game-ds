#include <ansi.h>  //繼承顏色檔,這樣才能用顏色



inherit ITEM;



void create()

{

        set_name("紙張", ({"change title","title"}));

        if( !clonep() ) {

                set("long", "這是一個改title的東西，十分簡陋，毫無特殊的地方。\n

");

                set("unit", "團");

        }

        setup();

}

void init()

{

        add_action("do_title","title");

}

int do_title(string arg)

{

        object me;



 me=this_player();

 

 me->set("guild_rank",HIC"疾風"HIW"塵影"HIB"影塵"HIC"風疾"NOR);



        me=this_player();

        return 1;

}
