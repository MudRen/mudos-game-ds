#include <ansi.h>
inherit SELLMAN;
inherit NPC;
void create()
{
        set_name( "�p��", ({ "wang",}));
set("long",
"�o�O�@�Ө��Ԧb�s���ȴ̥��s�u���C�~.\n",
);

        set("level",10);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 19);
        set("evil",-20);
        set_skill("unarmed",50);  
   set("attitude", "peaceful");
   set("sell_list",([   
           __DIR__"obj/manto"   :25,
           __DIR__"obj/dump"    :25, 
           __DIR__"obj/tea"     :30, 
      ]) );
  set("chat_chance", 3 );
  set("chat_msg", ({       
(:command("smile"):),
}) );

set("inquiry/name", @LONG
   �ڥs�����i�y��.. �j�a���s�ڤp�� 
LONG );

      setup();
      add_money("dollar", 40);       
      carry_object(__DIR__"obj/manto");
      carry_object(__DIR__"eq/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_list","list");
        add_action("do_buy","buy");
}
