#include <ansi.h>
inherit NPC;
void create()
{
        set("title","�ɳ����T�Q�@�N�̤l" );
        set_name("�j�̤l" , ({ "shaman" }) );
        set("level",15);
        set("race","�H��");
        set("gender","�k��");
        set("age",25);
        set("long","�ɳ����J���w�[���̤l�A�w�g�|�@�I�J�����C�k��򥻪��۳�N�C\n");
        set_skill("dodge", 60);
        set_skill("sword", 50);
        set_skill("parry", 60);
        setup();
carry_object("/open/world1/acme/area/npc/wp/longsword")->wield();
add_money("coin", 1000);
}
