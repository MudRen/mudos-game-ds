#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���Ťk�̤l",({ "apprentice" }));
        set("long","�o�O�@��j�Ӭ����k�̤l�A���b�m�ߤ@�M���R���C�k�C\n");
        set("level",18);
        set("gender","�k��");
        set("title","�j�Ӭ�");
        set("age",24);
        set_skill("sword",40);
        set_skill("girl-sword",40);
        map_skill("sword","girl-sword");
        setup();
        add_money("coin",300);
        carry_object("open/world1/wp/longsword.c")->wield();
        carry_object("open/world1/eq/cloth.c")->wear();
}

