#include <ansi.h>
inherit ROOM;
void create()
{
 set("short",MAG"秘室"NOR);

 set("long",@LONG
這個房間陰森森的, 房內唯一的一根蠟燭豎立在一個小圓桌上, 微弱
的燭光在石塊築成的牆上投映出搖擺不定的影子, 四周有許多的架子, 箱
子, 上面都積了層厚厚的灰...

LONG
    );
        set("objects",([
__DIR__"weapon/item_box" :1,
__DIR__"weapon/eq_shelf" :1,
__DIR__"weapon/wp_shelf" :1,
__DIR__"weapon/item_shelf" :1,
]));

        set("light",1);
 set("no_clean_up", 0);
 setup();

}
void init()
{
        add_action("typeclimb","climb");
}
     int typeclimb(string arg)
{
        object me;
        me=this_player();
        if(arg != "繩索") 
         return 0;
        else {
        message_vision(
        "$N抓住繩索，慢慢的爬上去...\n\n" ,me);
        me->move(__DIR__"workroom2");
        return 1;
             }
}

