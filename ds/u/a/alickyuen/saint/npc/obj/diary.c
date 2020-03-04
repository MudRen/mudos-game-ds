#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("電子記事本", ({ "electric note book","note","book" }) );
        set_weight(20);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("long",
                        "一本電子記事本，內�堸O載了一些東西，你可以嘗試讀取。\n");
                set("value", 0);

        }
}

void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
        object me,to;
        me = this_player();
        if( !arg ) return 0;
if(arg != "電子記事本" && arg !="electric note book" && arg !="note" && arg !="book" ) return 0;
if( me->query_temp("readdi") )
{
    return 0;
}
        message_vision("$N打開電子日記的電源，看了看裹頭的東西。\n",me);
tell_object(me, HIW"某年某月某日，星期日，晴    \n\n"NOR 
HIW"我今天照常去教堂祈禱，當我向聖母像祈禱的時候，突然一片強光，\n"NOR
HIW"實在太可怕了...接著我就忘了之後發生的事情。\n\n\n\n\n"NOR
YEL"你想了一想，怪不得那神父整日提心吊膽，究竟教堂�埵酗@些什麼？\n"NOR);
        me->set_temp("readdi",1);
        return 1;

}