#include <ansi.h>
inherit NPC;
void create()
{
        set_name("施無受", ({ "shi wu shou","shi","shou" }) );
        set("gender", "男性" );
        set("long",
            "他是施迅的父親，他的個性和施迅卻是天壤之別，他淡泊\n"
            "名利，故長年居住在此，為了不受外界的打擾而在外頭設\n"
            "了二道陣形，平凡人是不易破解的。\n"
           );
        set("age",70);
        set("level",35);
       set_skill("unarmed",95);
        set_skill("parry",70);
        set_skill("dodge",85);
        set("chat_chance_combat",90);
        set("chat_msg_combat", ({
              "施無受咆哮道：惡賊！去死吧！\n",
         }) );
        setup();
carry_object(__DIR__"eq/boots")->wear();
carry_object(__DIR__"eq/cloth")->wear();
}
