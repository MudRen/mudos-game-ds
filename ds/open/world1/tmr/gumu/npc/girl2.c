#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���m�k�l",({ "yellow-shirt girl","girl" }));
        set("long","�o�O�@��j�Ӭ����k�̤l�A�����M�R�X���A�u�O�N�H�H���A�S������S�O�����C\n");
        set("level",20);
        set("gender","�k��");
        set("title","�j�Ӭ�");
        set_skill("unarmed",50);
        set_skill("sword",50);
        set_skill("parry",50);
        set_skill("dodge",50);
        set_skill("girl-sword",50);
        map_skill("sword","girl-sword");
        set("age",19);
        setup();
        add_money("coin",300);
        carry_object("open/world1/wp/longsword.c")->wield();
        carry_object(__DIR__"obj/yellow-shirt")->wear();
        carry_object(__DIR__"../obj/fengmi");
        carry_object(__DIR__"../obj/bishou");
}

