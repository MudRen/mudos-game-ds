#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�y��" , ({ "hunter" }) );
        set("level",15);
        set("race","�H��");
        set("gender","�k��");
        set("age",35);
        set_skill("parry", 20);
        set_skill("bow",20);
        set_skill("dodge", 20);
        set("long","�L�O�@���y�H�C\n");
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
           (:command("shoot"):),
        }) );        setup();
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/arrow.c");
        carry_object(__DIR__"wp/bow.c")->wield();
}
