inherit NPC;

void create()
{
        set_name("�ȫ�",({"traveler"}));
        set("long","�@�ӱq�~�a�Ӫ��ȫȡA�����۴���A�ݵ۴¤Ѵ򪺴���C\n");
        set("gender","�k");
        set("attitude", "peaceful");
	set("age",20);
       set("level",2);
	set("race","�H��");
        set("chat_chance",5);
        set("chat_msg",({
          "�ȫȳ�仡�D�G�¤Ѵ�ʪ���}�A�u�D�H�����o�@���������ڡC\n",
          "�ȫȮ��_�F�s���ܤF�f�u�ʪ��C�v�A�@�y�������ˤl�C\n",
         }) );
	setup();
	carry_object(__DIR__"eq/jade")->wear();
      add_money("silver",5);
}
int accept_fight(object who)
{
        if(!is_fighting())
        {
                say("�ȫȻ��D�G�u"+ RANK_D->query_respect(who) + "�A�������o���M���R�A���O�C�����n��l�A�֭n�M�A���[�ڡI�I�v\n");
        }
        return 0;
}


