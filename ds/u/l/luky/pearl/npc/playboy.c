//oceaner.c
#include <ansi.h>
inherit NPC;
void create()
{
set_name("大學男孩",({"play boy","boy"}));
set("level",25);
set("age",21);
set("long","一個無所事是的青年人, 一對賊眼不斷的瞄著路過的漂亮美眉。\n");
set("gender", "男性");
set_skill("tenken",20);
map_skill("unarmed","tenken");
set("coin",300+random(280));
set("chat_chance",5);
set("chat_msg",({
  (:command,"drool":),
}) );
set_temp("apply/armor",100+random(50));
set_temp("apply/damage",random(20));
set_temp("apply/dodge",50+random(30));
        setup();
set_skill("unarmed",160);
set("chat_chance_combat", 25);
set("chat_msg_combat", ({
(: this_object(), "random_move" :),
HIR"\n年輕人大叫: 「有種就不要跑∼﹗等我朋友來你就完了﹗」\n"NOR,
HIW"\n年輕人想逃可是被攔住了...跑不掉\n"NOR,
     }) );
//carry_object(__DIR__"item/glasses")->wear();
}
