#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIR"落紅"NOR, ({ "loa hone","hone" }) );
        set("level",35);
        set("combat_exp",20000);
set("exp",20000);
        set("evil",200);
        set("long",@LONG
原不是蚩尤的手下,也曾跟蚩尤出生入死的去
搏得天下,武功不在蚩尤之下,跟蚩尤創下了輝
煌的戰績,感情絕不比親兄弟差但是有一天,蚩
尤打造了把第一神兵 虎魄 ,開始喪失了人性,殺
穆不斷,幾百萬條的生命,就慘死在他的手上,武
功邪力爆增的他,也幾度差點把落紅送上黃泉,
落紅不甘,上前阻止蚩尤,惹來殺身之禍,事後的
蚩尤清醒了,發現了他不能挽回的事,於是蚩尤
求助虎魄的神力,把蚩尤十分之一的壽命撥給了
落紅,但落紅是因虎魄而再生的,所以那顆紅色
的心,也被 虎魄 感染了,蚩尤也打造了一把地神
兵,取名為落紅劍,因被邪力感染的他,再度為蚩
尤稱臣,生命的殺穆,就此展開
LONG
);  

      set("age",1645284);
        set("attitude","killer");
        set("gender","男性");
        set("title",HIG"蚩尤護衛"NOR);
        set_skill("unarmed",80);
        set_skill("dodge",100);
        set_skill("parry",80);
        set_skill("sword",100);
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
"落紅說:護駕 ~ ~ ~ ~ 護駕 ~ ~ ~ ~。\n\n",
"落紅說:可惡!! 敢打擾老子我.. !! 。\n\n"                       }) );
       setup();
       carry_object("/u/t/tako/red@sword.c")->wield();
}



