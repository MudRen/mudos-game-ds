#include <ansi.h>
inherit NPC;
void create()
{
 set_name("林繁榮",({"lin fen lon","lin"}));
 set("long",@LONG
他就是三年前到無砂上任的傳奇人物, 也就是帶領無砂邁
向繁榮之路的鎮長, 不過他的外表貌不驚人, 不聽別人提起, 
實在無法將他和林繁榮想在一起...
LONG
    );
 set("attitude", "peaceful");
 set("evil",-100);
 set("age",62);
 set("nickname",HIG"無砂鎮長"NOR);
 set("gender","男性");
 set("level",4);
 set("chat_chance",10);
set("chat_msg", ({"林繁榮笑瞇瞇的看著你... \n",
}));
 set("chat_chance_combat",200);
 setup();
 carry_object(__DIR__"eq/cloth")->wear();
}
