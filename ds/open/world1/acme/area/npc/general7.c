#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����N" , ({ "water general","general" }) );
        set("title","�i���Z�Уi �K���N" );
        set("level",30);
        set("race","�H��");
        set("age",40);
        set("con", 45);
        set("str", 40);
        set("dex",40);
        set("int",40);
        set_skill("force", 100);
        set_skill("blade", 100);
        set_skill("sword", 100);
        set_skill("parry", 100);
        set_skill("unarmed",100);
        set_skill("dodge", 130);
        set("long","�L�O���Z�Ъ��K���N���@�C\n");
        setup();
        carry_object(__DIR__"wp/longsword.c")->wield();
}
