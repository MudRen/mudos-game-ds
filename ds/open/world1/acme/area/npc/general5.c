#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����N" , ({ "fire general","general" }) );
        set("title","�i���Z�Уi �K���N" );
        set("level",30);
        set("race","�H��");
        set("age",40);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("dodge", 130);
         set_skill("godsword",50);
        set("chat_chance_combat",80);
        set("chat_msg_combat", ({
           (:command("exert godsword"):),
           (:command("cast god-fire"):),
        }) );
          set_spell("god-fire",60);
        set("long","�L�O���Z�Ъ��K���N���@�C\n");
        setup();
        carry_object(__DIR__"wp/longsword.c")->wield();
}
