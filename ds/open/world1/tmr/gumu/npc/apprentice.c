#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�k�̤l",({ "apprentice" }));
        set("long","�o�O�@��j�Ӭ����k�̤l�A���b�m�ߤ@�M���R���C�k�C\n");
        set("level",8);
        set("gender","�k��");
        set("title","�j�Ӭ�");
        set("age",19);
        setup();
        add_money("coin",300);
        carry_object("open/world1/wp/longsword.c")->wield();
}

