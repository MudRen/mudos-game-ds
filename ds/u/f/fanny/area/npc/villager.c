#include <ansi.h>
inherit NPC;
void create()
{
        set("title","�K�a��" );
        set_name("����" , ({ "villager" }) );
        set("level",10);
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
        set("long","�[�~�󦹪����H�C\n");
        set_skill("dodge", 20);
        setup();
carry_object("/open/world1/acme/area/npc/wp/sword")->wield();
add_money("coin", 300);
}
