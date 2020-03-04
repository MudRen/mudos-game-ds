#include <ansi.h>
#include <path.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name(HIC "��U�ѤH"NOR, ({ "match-maker"}));
        set("long", "�L�O����۶Ǧܤ����@�쯫�g�A�M���H�o���u\n"
                    "�A�������H�צ����ݡA�L�ݰ_�ӥվw�ܯݡA�M\n"
                    "ħ�i�ˡC\n"
           );
        set("level",1);
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 200);
        set("evil",-20);                //���c�� 20 (�������c, �t���})
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("no_fight",1);
        set("talk_reply","�A�n�����A�o���u�ܡH");
        set("sell_list",([
        __DIR__"obj/choco" : 10,
        ]) );
        setup();
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
{
       object ob;
        ::init();
        if( interactive(ob = this_player()) && !is_fighting() )
        {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
           case 0:
               say("��U�ѤH���D�G�o��" + RANK_D->query_respect(ob)
                                + "�M�ӶR�Ǳ��H���J�O�a�C\n");
               break;
           case 1:
               say("��U�ѤH���D�R�o��" + RANK_D->query_respect(ob)
                                + "�M�R����e�e���H�a�C\n");
               break;
        }
}
