#include <ansi.h>
inherit NPC;
void create()
{
        set("title","�ɳ����T�Q�G�N�̤l" );
        set_name("�p�̤l" , ({ "shaman" }) );
        set("level",10);
        set("race","�H��");
        set("gender","�k��");
        set("age",18);
        set("long","�ɳ����J�����[���s�̤l�C\n");
        set_skill("dodge", 40);
        set_skill("parry", 40);
        set_skill("sword", 30);
        setup();
carry_object("/open/world1/acme/area/npc/wp/sword")->wield();
add_money("coin", 300);
}
