#include <ansi.h>
inherit NPC;
void create()
{
        set_name( HIY"阿爾基諾專業獵人"NOR , ({ "great hunter","hunter" }) );
        set("level", 35);
        set("con", 40);
        set("age",54);
        set("str", 50);
        set("dex",50);
        set("int",50);
        set("attitude","heroism");
        set_skill("parry", 60);
        set_skill("unarmed", 80);
        set_skill("sword",80);
        set_skill("dodge", 60);
        set("long","
眼前這位身著精裝的獵人，是阿爾基諾王成派來獵殺
沼澤怪的，由於其獎金相當高，因此獵人們更是爭先恐後
的搶著這個位子座。但是，唯有最專業的獵人才能甚任此
職業喔。\n");
        set("chat_chance", 20 );
        set("chat_msg",({HIC"專業獵人說道:沼澤怪物，你在哪裡？\n"NOR,
           (:command("tender"):),
           (:command("random_move"):),
           (:command("kill monster"):),
         }) );
        set("chat_chance_combat", 17);
        set("chat_msg_combat", ({HIR"專業獵人大喝 : 「可惡的傢伙∼﹗受死吧﹗」\n"NOR,
           (:command("bite "+this_player()->query("id")):),
            }) );
     setup();
}      
