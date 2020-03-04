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
    set_name("�˪L�u��", "forest garrison", "garrison");

    set_race("human");

    set_skill("twohanded sword", 60);
    set_skill("blunt", 100);
    set_skill("sword", 100);
    set_skill("parry", 90);
    set_skill("unarmed", 80);
    set_skill("dodge", 90);
    set_skill("blade", 70);
    set_skill("berserk", 150);

    set("long",@long
�o�O�@�ӭt�d�O�@�����H���˪L���u�áA���~��N��@��H��ժZ���O�C
long
);
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
        (: command, "berserk" :)
    }));

    setup();
    set_level(20);
      carry_object(__DIR__"obj/heavy-sword")->wield();
    carry_object(__DIR__"obj/steel-gloves")->wear();
}

int accept_fight(object ob)
{
        return 1;
}


