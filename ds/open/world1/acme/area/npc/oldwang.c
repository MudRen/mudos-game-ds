#include <ansi.h>
inherit NPC;
inherit SELLMAN;
void create()
{
        set_name( "�Ѥ�", ({ "old wang","wang"}));
        set("long", "�o�O�@�쥿��Ԫ��۫ݫȩx�����p�G�C\n\n"
                      + "  �ݦs�f�Х� <list> \n"
                     + "  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n");
           set("level",3);
        set("title","���p�G");
        set("gender", "�k��");
        set("race", "�H��");
        set("age", 42);
        set("no_fight",1);
        set("combat_exp",2000);         //�Լ�(���bmob level��100�����k���y)
//      set("env/wimpy", 20);           //�k�]wimpy (20%)
        set("evil",-20);                //���c�� 20 (�������c, �t���})
        set_skill("blade",40);          // �ޯ�(�۩w)
        set_skill("parry",20);          //
        set_skill("dodge",30);          //
        set("attitude", "peaceful");   //�ũM�� NPC�C
        set("talk_reply","�h�R�I�F��N�����F�j���o..����..");
                   //�`�N. �n�]�w�f�~�M��
        set("sell_list",([
      __DIR__"obj/manto" : 10,
        __DIR__"obj/water" : 10,
       __DIR__"obj/leg" : 10,
    __DIR__"obj/soup" : 10,
    __DIR__"obj/wine" : 10,
      "/open/always/torch" : 30,
        ]) );
        setup();
          add_money("coin", 120);           //�a����
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
        switch( random(3) ) {
           case 0:
               say("�Ѥ����D�G�w����{�A�аݳo��" + RANK_D->query_respect(ob)
                                + "�M�ݭn�Ǥ���O?\n");
               break;
           case 1:
               say( "�Ѥ����q�a���D�R�o��" + RANK_D->query_respect(ob)
                                + "�M�жi�жi�C\n");
               break;
           case 2:
               say("�Ѥ����D�G�o��" + RANK_D->query_respect(ob)
                                + "�M�i�Ӷ��{�l, �n�~��W����C\n");
               break;
        }
}

int talk_action(object me)	
{
 object book;
 if(!book=me->query_temp("notebook")) return 0;
 command("smile "+me->query("id") );
 if(random(2))
 {
 	command("say �����C�@�ذs�i���O�s�����~�C");
 	command("say �ר�O���@�ذs�A�W�s�y�N�M�l�z�A�o�ذs�Q���@�P�A�ܤF�O�ү����H�ѫo�Ҧ��Фߤ��ơC");
 	command("say ���L�ȩx�p�G�Q�@�|�䤤�����A�i��ݭn�A���@�Ǯɤ�C");
 	command("say �]�������Ȧs���X�~�N�M�l�e�Ǥ�l�Q��{���T���F�C");
 	command("sigh");
 	command("say �y�N�M�l�z���C�y�����O�ɡA�����w�g�ɤO���s�F�A�Ыȩx���̡C");
 	book->add_quests_note("SadSworder","�y�N�M�l�z�O�@�ط����@�P���s�A���߱��{�e�A�άO�u�����ҧx�v���H���̷R�C");
 }
 else {
 	command("say ����j�L�C�ѳ��ӳo�̳ܰs�C");
 	command("say �i�������ѤU���X�~�N�M�l�e�}�l�Q�@�W�j�s�m���F�C");
 	command("think");
 	command("say ���Lť���x���w�g���L�F�A�i���餧���N�n�ݱ٤F�a�C");
 	book->add_quests_note("SadSworder","�y�N�M�l�z�Q�@�W�j�s�m���F�A�ӳo�W�j�s���N�Q�ݱ١C");
 }
 return 1;
}