/* hing.c write by -Acme-
   update by -Acme-
*/

#include <ansi.h>
inherit NPC;
void create()
{
    set_name("�����y", ({ "chu chung hing", "hing", "__GUARD__" }) );
    set("level", 35);
    set("race","�H��");
    set("gender","�k��");
    set("age",45);
    set("title",HIY"�����"NOR);
    set_skill("parry", 80);
    set_skill("sword", 80);
    set_skill("dodge", 80);
    set("long","�L�O�ѫ��x�ަD�����̰����x�A�������ӡA�ݨӪZ�����z�C\n");
    setup();
    carry_object(__DIR__"eq/armor")->wear();
    carry_object(__DIR__"eq/boots")->wear();
    carry_object(__DIR__"wp/sword")->wield();
}
void init()
{
    ::init();
    if(!this_object()->visible(this_player())) return;
    call_out("greeting", 1, this_player());
}

void greeting(object ob)
{
    if(ob->query_temp("SKYCITY/jail") >0 || ob->query_tmp("SKYCITY/hatred") > 0 ) {
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
        ob->add_temp("SKYCITY/jail",1);
        message_vision(HIC"���ѷ�"HIR"�j�ܡG�i�c��"+ob->name(1)+"�A�Y�F���߰\\�l�x�I�H�x���T���I�H\n"NOR,ob);
        message_vision(HIC"���ѷ�"HIR"�j�ܡG���Nť�O�A��"+ob->name(1)+"�̡A����L��j���I�I\n"NOR,ob);
    } else ob->add_temp("SKYCITY/jail",1);

    ::die();
    return;
}
