inherit NPC;
#include <ansi.h>
void create()
{
       set_name("���Ǵ�",({"haners"}));
       set("long",@LONG
    ���Ǵ��O�b���W�Q�@���Ӳ�ұϰ_���A���M���h�F�O�СA���O�L����
�O�o�Q�������g��A��O�L�b�ĺ��Ĵ����ӤH���ξ����ȭ��C�L�t�d�B
�z�ӤH�M�a��F���������U�بƶ��A�]�A���|�B��ȡB��ȵ��C�����L�]
�n�t�d�հ��ӤH�����Ĭ�C
LONG);
       set("gender","�k��");
       set("age", 25);
       set("level", 5);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("think"):),
            (:command("say �o�ǨƱ������ڷw�Y��V���C@@"):),
             }));

	set("talk_reply","�A�Q���Q�Ȩǥ~�֡H���ȬO���ޡA��²�檺�C"); 
        setup();
        carry_object( __DIR__"wp/waterman_knife")->wield();
        carry_object( __DIR__"eq/cloth")->wear();         

}
void init()
{
        ::init();
        add_action("do_nod","nod");
	add_action("do_say","say");
}
int do_nod(string arg)
{
	object me=this_player();
	if( arg != "haners" ) return 0;
	if( me->query_temp("police")>0) { say("�A�w�g�����F���ު��u�@�F�C\n");return 1;}
	command("say �A���D���A�̪�v�w���n�A�ҥH�ڭ̧Ʊ�Ф@�ǤH�h���ޡC");
	switch(random(2)){
	case 1:
		command("say ���ڬݬݡ�a�U���D�����n....���ЧA�h���ަa�U���D�n�F�C");
		me->set_temp("police_area",1);break;
	case 2:
		command("say ���ڬݬݡ�ĤG�X�Y���i�å��l�X�J...�N�ЧA�h�ݬݦn�F�C");
		me->set_temp("police_area",2);break;
	default:
		command("say ���ڬݬݡ�ĤG�X�Y���i�å��l�X�J...�N�ЧA�h�ݬݦn�F�C");
		me->set_temp("police_area",2);break;
	}
	command("say �i��|���I�M�I�A���L��A�̳o�ǫ_�I�̨ӻ��A���Ӻ⤣�F����a�I");
	command("say �u�@������O�ѤF�ӦV�ڻ���u��C(say �u��)");
	me->set_temp("police",1);
	return 1;
}
int do_say(string arg)
{
	object me = this_player();
	int money = me->query_temp("police")*10+me->query("level")*50+me->query("popularity")*100;
	if( arg != "�u��" ) return 0;
	if( !me->query_temp("police")) return 0;
	if( me->query_temp("police") < 50 ) {say("�A�u�@���ɼ��٤�����I�ЦA�V�O�I\n");return 1;} 
	command("say ��I�u�@�����F�r�I�o�O�A���u��C");
	me->receive_money(money);
	me->add("exp", 1500+random(500));
	tell_object(me,HIW"�A�o��"+money+"���I�A���g��W�[�F!\n"NOR);
	me->delete_temp("police");
	me->delete_temp("police_area");
	return 1;
}