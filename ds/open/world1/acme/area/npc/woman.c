#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���H",({"woman"}));
        set("level",5);
        set("race","�H��");
        set("gender","�k��");
        set("int",1);
        set("talk_reply","�ڦb����ت���A�A�i�O�ñħr�C");
        set("age",35);
        set("long","�o�O�@���o�ܾ�������H�A�����b�ȤW´�ۦ�A�C\n");
        setup();
}
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
void greeting(object ob)
{
        object me;
        me=this_player();
        if( !ob || environment(ob) != environment() ) return;
        switch( random(3) ) {
           case 0:
               say("���H���D�G�o��" + RANK_D->query_respect(ob)
                                + "���L�G����O�H�a�̨өO�H\n");
               break;
           case 1:
               say("���H�Ω_�Ǫ������ˤF�A�@�U�C\n");
               break;
           case 2:
               say("���H���D�G�o��" + RANK_D->query_respect(ob)
                                + "�ЧA�X�h�A�O�ö]��O�H�a�̡C\n");
               break;
      }
}
