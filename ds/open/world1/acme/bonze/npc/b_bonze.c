#include <ansi.h>
inherit NPC;
void create()
{
        set_name("廣亮" , ({ "gwong leung bonze","gwong","bonze" }) );
        set("level",30);
         set("title","凌雲寺 監寺");
        set("race","人類");
        set("gender","男性");
        set("age",50);
        set_skill("wuchen-staff",80);
        set_spell("recite-sutra",80);
        set("long","他是凌雲寺的監寺，臉生的白白肥肥的，但卻十分和藹。\n");
        set("chat_chance", 3 );
        set("chat_msg",({
          (: random_move :),
                (:command("exert wuchen-staff"):),
        }) );
        set("chat_chance_combat",10);
        set("chat_msg_combat", ({
                (:command("cast recite-sutra"):),
        }) );
        setup();
          carry_object(__DIR__"wp/staff3")->wield();
}
