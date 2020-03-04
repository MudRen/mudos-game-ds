#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( HIY"賣花的小姑娘"NOR, ({ "flower girl","girl","seller"}));
        set("long", "一個可愛的小姑娘，手裡拎著一個花籃，裡面裝滿了多采多姿的花。\n\n"
        );
        set("level",3);
        set("title","小販");
        set("gender", "女性");
        set("race", "人類");
        set("age", 15);
        set("evil",-20);                //邪惡度 20 (正的表邪惡, 負表善良)
        set("attitude", "peaceful");   //溫和的 NPC。
        set("talk_reply","想買花嗎？可以用看看我的花籃，有很多花唷(list)。");

        set("sell_list",([   
         __DIR__"obj/hyacinth"    : 10,
        ]));

//set("chat_chance", 3 );
// set("chat_msg", ({
//"王大發笑笑的說: 大老闆, 要不要買點東西<take>啊? 我賣的東西<show>是附近最便宜的喔!\n",
//(:command("dance master"):),
//(:command("coffee wang"):),
//}) );

set("inquiry/flower", @LONG
   花最可愛了，這裡的人都愛花唷。
LONG );

      setup();
      add_money("coin", 150);
      carry_object(__DIR__"item/bag");
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
