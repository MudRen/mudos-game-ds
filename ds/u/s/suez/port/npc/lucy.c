#include <ansi.h>
inherit NPC;
int notice();
void create()
{
       set_name(HIM"�S��"NOR,({"lucy"}));
       set("long",@LONG
    �o�O��Ȥ��Ҫ��ѰO���A���G�b������Ʊ��W�o�H�A�i�H�ݰݬݡC��
���w�����W���򦣡C
LONG
);
       set("gender","�k��");
       set("age", 18);
       set("level", 3);

       set("chat_chance", 3);
       set("chat_msg", ({
            (:command("hmm"):),
             }));

	set("talk_reply","��...(�ݨӦo�S�`�N��A�A�A�̦n���o�`�N��A�C)");    
       setup(); 
       carry_object( __DIR__"eq/dress")->wear();         

}
void init()
{
        ::init();
        add_action("do_say","say");
}
void relay_emote(object ob, string verb, object me)
{	
        if( !userp(ob) ) return 0;
        switch(verb) {
        case "sex":
                command("slap "+ob->query("id") );
                command("say �ޡI�A�ӹL���F�I");	
                break;
        case "kiss":
                command("blush " );
		notice();	
                break;
	case "kick":
		command("say �ڡH");
		notice();
                break;
	case "slap":
		command("say �ڡH");
		notice();
                break;
	case "pat":
		command("say �ڡH");
		notice();
                break;
	case "kok":
		command("say �ڡH");
		notice();
                break;
	case "beep":
		command("say �ڡH");
		notice();
                break;
        default:
                break;
        }
}
int notice()
{
	object me;
	int i;
	me=this_player();
	i=me->query_temp("light_to_future");
        if( me->query("sarsass_1") > 0 )  
	{
		command("say �x�S�ڬO���O�b���̬ݹL�A�S\n");
		return 1;
	}
	switch(i){
	case 1:
		command("say ��p�A�ڲ{�b�߱����n�C�ЧA���Ƨֻ��C(say)");break;
	case 2:
		command("say ��...�A���@�N�����ܡS");
		me->delete_temp("light_to_future");
		break;
	case 3:
		command("say �ڡI�O�A�I�Ʊ��쪺���ˤF�S�S���D�a�S��ı�o�n��i��...");break;
	case 4:
		tell_object(me,YEL"�A�����F�⪺�ǳƸ��S�軡�����s�h��...\n"NOR);
		command("jump");
		command("say ���ڬݨ�O��o�X���~�A�O�צn�F�a�I�Ӧn�F�I");
		tell_object(me,CYN"�A�����ߥ�ԵۡA�n���X�u�ۡS(say no)�εۤ����S(say yes)\n"NOR);
		me->set_temp("light_to_future",5);
		break;
	case 5:
		command("say �Ʊ��쩳��ˤF�S�O���\\�F�ܡS");
		tell_object(me,CYN"�A�����ߥ�ԵۡA�n���X�u�ۡS(say no)�εۤ����S(say yes)\n"NOR);
		break;

	default:
	command("say �аݱz������ƶܡS");
	me->set_temp("light_to_future",1);
		break;
	}
	return 1;
}
void do_say(string arg)
{
	object me=this_player();
	if(me->query_temp("light_to_future")==1)
	{
	 if(arg == "�W�o" || arg =="�Ʊ�" || arg =="����" )
	{
	 tell_object(me,"�S��n���Y�J�Ӫ����q�A�@��C\n");
	 command("say ���ڭ̳o�̦��@�Ӥp�p�����D....");
	 command("say �q�o�̤@������A�����a�V�C");
	 command("say �a�V�W���@�y�����D��ɦ�H�سy���O��C");
	 command("say ���e�o�̥u�O�Ӻ����A���ӻݭn�O��A�ҥH�]�S�H�h�z�|�C");
	 command("say ���O�̪񦳳\\�h�ө��F��j�����Ӳ�...�O��N�ܦ�������...");
	 command("say ���M���e�ڭ̤]�����H�W�h�A�Q�n�Ұʳo�ӿO��C");
	 command("say ���O�O�𪺵��c�S���H���L...�ҥH�ܤ����L�k�ҰʡC");
	 command("say �{�b�ӷ|�X1000���A������k�ҰʿO�𪺤H�C");
	 command("say �ݧA�n���������ƪ��ˤl�A�A�@�N�ոլݶܡS�@�N���ܽп�J(nod lucy)");
	 me->set_temp("light_to_future",2);
	 add_action("do_nod","nod");
	}
	 return ;
	}
	if(me->query_temp("light_to_future")==5)
	{
	 switch(arg){
	 case "yes":
		tell_object(me,HIG"�A�Q�F�Q...��F...�N���N���a�I\n"NOR);
		command("say �o�ǬO�A���S�ҡI���§A�I");
		me->receive_money(1000);
		me->add("exp", 1500+random(500));
		tell_object(me,HIW"�A�o��1000���I�A���g��W�[�F!\n"NOR);
		me->delete_temp("light_to_future");
		me->set("sarsass_1",1);
		break;
	 case "no":
		tell_object(me,HIY"���M���Ԥ߱��o�����A���O�۹ꪺ�A�M�w�٬O�n���X�u�ۡI\n"NOR);
		command("say �O�ܡS�S�O�o�Ӽˤl.....");
		command("say ���L�٬O���§A�A���M�S���S�ҡA���O�ڷ|�O�o�A���n�ߪ��C");
		me->add("exp", 2000+random(500));
                me->add("popularity",1);
		tell_object(me,HIW"�A���g��W�[�F�I�A���n��W�[�F!\n"NOR);
		me->delete_temp("light_to_future");
		me->set("sarsass_1",1);
		break;
	 default: break;
	 }
	return;
	}
}
void do_nod(string arg)
{
	object me=this_player();
	if(me->query_temp("light_to_future")==2)
	{
	if(arg == "lucy"){
	command("say �O�ܡS�Ӧn�F�I���N���U�A�F�I");
	command("smile");
	me->set_temp("light_to_future",3);
	}
	return;
	}
return;
}
