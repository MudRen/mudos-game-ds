#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("電子記事本", ({ "electric note book","note","book" }) );
        set("long","一本電子記事本，內�堸O載了一些東西，你可以嘗試讀取。\n");
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
                set("value", 0);
                set("material","iron");
        }
        setup();
}

void init()
{
        add_action("do_read","read");
}

int do_read(string arg)
{
        object me,to;
        me = this_player();
        if( !arg || arg!="book" ) return 0;

        message_vision("$N打開電子日記的電源，看了看裡頭的東西。\n",me);
          tell_object(me,
CYN"\n某年某月某日 星期日 天氣：○    

我今天照常去教堂祈禱，當我向聖母像祈禱的時候，突然一片強光，

實在太可怕了.....接著我就忘了之後發生的事情。\n" NOR);

        return 1;
}

