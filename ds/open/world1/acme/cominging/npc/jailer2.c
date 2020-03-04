/* jailer2.c write by -Acme-
   update by -Acme-
*/

#include <ansi.h>
inherit NPC;

void create()
{
    set_name("����", ({ "jailer", "__GUARD__" }) );
    set("level", 15);
    set("race","�H��");
    set("gender","�k��");
    set("age",40);
    set_skill("parry", 40);
    set_skill("sword", 40);
    set_skill("dodge", 40);
    set("long","�L�O�@��ݦu�ۺʺ����p�L�C\n");
    setup();
    carry_object(__DIR__"wp/sword")->wield();
}

void init()
{
    ::init();
    if( !this_object()->visible(this_player())) return;
    call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
    if(ob->query_temp("SKYCITY/jail") >0 || ob->query_temp("SKYCITY/hatred") > 0) {
        command("say �c��I�ǩR�ӡI�I");
        this_object()->kill_ob(ob);
    }
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

    if( !ob ) {
        ::die();
        return;
    }

    if( !ob->query_temp("SKYCITY/jail") ) {
        ob->add_temp("SKYCITY/jail", 1);
        message_vision(HIC"���ѷ�"HIR"�j�ܡG�i�c��"+ob->name(1)+"�A�Y�F���߰\\�l�x�I�H�x���T���I�H\n"NOR,ob);
        message_vision(HIC"���ѷ�"HIR"�j�ܡG���Nť�O�A��"+ob->name(1)+"�̡A����L��j���I�I\n"NOR,ob);
    } else ob->add_temp("SKYCITY/jail", 1);
    ::die();
    return;
}
