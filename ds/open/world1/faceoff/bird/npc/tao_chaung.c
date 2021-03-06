#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "陶章", ({ "tao chung","tao","chung"}));
set("long",
"這是一個已經退隱江湖的江湖怪人, 據說他的興趣竟然是做\n"
"一個小販! 如今他也退隱到天梟的隱士樓來過他無憂無慮的\n"
"叫賣生活。\n",
);

        set("level",22);
        set("gender", "男性");
        set("race", "人類");
        set("age", 56);
        set("evil",-20);
        set_skill("unarmed",70);  
        set_skill("parry",50); 
        set_skill("dodge",40);       
   set("attitude", "peaceful");   //溫和的 NPC。
   set("sell_list",([   
           __DIR__"item/bag"    : 25, //表示每買一個袋子會扣15點補給點數
           __DIR__"item/dump"   : 10, //除非有特殊理由否則不可設為0 (無限量供應)
           __DIR__"item/pill1"  :30,  
      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       
"陶章似乎樂在叫賣中....!\n",
(:command("smile"):),
}) );

set("inquiry/name", @LONG
   我叫做陶章啦.. 
LONG );

      setup();
      add_money("dollar", 400);       
      carry_object(__DIR__"obj/pill1");
      carry_object(__DIR__"eq/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
