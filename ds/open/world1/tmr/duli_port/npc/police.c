/*  garrison.c

    Copyright (C) 1994-2000 Annihilator <annihilator@muds.net>

    This program is a part of ES2 mudlib. Permission is granted to use,
    modify, copy or distribute this program provided this copyright notice
    remains intact and subject to the restriction that this program MAY
    NOT be used in any way for monetary gain.

    Details of terms and conditions is available in the Copyright.ES2 file.
    If you don't receive this file along with this program, write to the
    primary author of ES2 mudlib: Annihilator <annihilator@muds.net>
*/

#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("巡邏警察", ({ "police"}) );

    set_attr("con", 20);
    set_attr("str", 20);
    set_attr("dex", 18);
    set_attr("cor", 18);
    set_race("human");
    advance_stat("gin", 200);
    advance_stat("hp", 200);

    set_skill("twohanded blade", 60);
    set_skill("parry", 50);
    set_skill("unarmed", 50);
    set_skill("dodge", 50);

    set("long",@long
這是一個負擔巡邏杜尼港，維持治安的警察。
long
);
    set("vendetta_mark", "duli_port");
    set("chat_chance", 5);
    set("chat_msg", ({
                "巡邏警察大搖大擺地走來走去...\n",
                (: random_move :),
                "巡邏警察惡狠狠的瞪了你一眼，喝道：「沒事的，別在這兒逗留，想要犯法啊。」\n",
                "巡邏警察「呸」了一聲，竟然隨地吐了一口濃痰......\n",
   }));
    /*
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "berserk" :)
    }));
    */

    setup();
	set_level(15);
        /*
    set_temp("apply", ([
        "attack": 100,
        "defense": 100,
        "intimidate": 100,
        "wittiness": 100,
    ]));
        */
    carry_object(__DIR__"obj/guard-armor")->wear();
    carry_object(__DIR__"obj/bigblade")->wield("twohanded blade");
   
}

int accept_fight(object ob)
{
        return 0;
}

