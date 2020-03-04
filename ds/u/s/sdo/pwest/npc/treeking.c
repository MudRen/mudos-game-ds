#include <ansi2.h>
inherit NPC;

void create()
{
	set_name(HIG"�g���˪L����"NOR, ({ "king of forg forest","king"}) );
        set("long", @LONG
�b�A���e���O�@�ӥ����񺡾��ê����~�k�l�A���ä��U�i�H�ݨ쵲��
���٦סC�L���a�۷O���������C
LONG
	);
        set("level",50);
        set("age",500);
	set("race","monster");
	set("gender","����");
        set("combat_exp", 20000);

        set("talk_reply","�A�y�X�g���˪L������Ʊ��H\n");
    	set("inquiry/�g���˪L", 
    	"�g���˪L�O�ھڻ��j�������Ҳ��ͪ��A�O���F�N������\n"
    	"���ð_�ӡA�����~�ɪ��I�Z�C\n");
    	set("inquiry/������",
    	"���O�Ѻ��F�Һc������a�A�]�����F�өʰ��ơA�����w�M\n"
    	"��L�رڥ���D�A�ҥH�N�ۤv����a���ð_�ӡC\n");
        setup();
}
int accept_object(object me,object ob)
{
        object obj,book;
        obj=this_object();
        me=this_player();
        book=present("adventure notebook",me);
        if(ob->name()!="���뤧�\\")
        	return notify_fail("���§A�A���O�ڤ��ݭn�o�ӡC\n");
        if(obj->is_busy() )
        	return notify_fail("�ڲ{�b�S�šI�I\n");
        message_vision("$N���F$n�@��"+ob->query("name")+"�C\n",me,obj);
        obj->start_busy(2);
        destruct(ob);
        command("smile");
        if(book->query("quests/fogforest")==1 || book->query("quests/fogforest")==2) 
        	return notify_fail("");
        if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdpquest/step1")==3 && me->query_temp("sdpquest/step2")==3 && me->query_temp("sdpquest/step3")==1)
        {
        	message_vision(
        	"$n�ݵ�$N�������ɹɺ٩_�C\n\n"
        	"$n���$N���G�S�Q��{�b�٦��H����o���몺�H���C\n"
        	"�n�a�A����N���ڵ��A�@�����U�a�C\n"
        	"�ڥi�H���ӧA���Ʊ�b�A���|���ݩʤ����䤤�@���W\n"
        	"�[�@�I�A�A�M�w�n�b��(plus �ݩ�)�ӼW�[�a�C\n"
        	"�A�M�w�n�F����A�ڷ|�����N�A�e��X�f�C�N�o�ˡA\n"
        	"�H���_�I��\n",me,obj);
        	add_action("do_plus","plus");
        	
        }
        return 1;
}
int do_plus(string arg)
{
	object book;
	
	if(!arg) return notify_fail("�Х�[plus �ݩ�(str��)]");
	if(arg=="str") { 
		this_player()->add("addition/str",1);
		tell_object("�A���O�q���ɤF�I\n");}
	if(arg=="con") {
		this_player()->add("addition/con",1);
		tell_object("�A����责�ɤF�I\n");}
	if(arg=="int") { 
		this_player()->add("addition/int",1);
		tell_object("�A�����z���ɤF�I\n");}
	if(arg=="dex") {
		this_player()->add("addition/dex",1);
		tell_object("�A���ӱ����ɤF�I\n");}
	else{return notify_fail("�ڤ��ണ�ɳo���ݩʡC\n");}
	
	if(book=this_player()->query_temp("notebook"))
	{
		book->add_quests_note("fogforest",
        	"�Q�������o��������U...\n");
        	this_player()->set_temp("sdoquest/step3",2);
        	this_player()->set_temp("sdoquest/step4",1);
        
        	book->set_quests("fogforest",2);
        	this_player()->save();
        
        	message_vision(
		HIW"�u��$n"HIW"���|����A�ۨӤ@�}�����A�N$N"HIW"�]���A����$N"HIW"�N�����F�C\n",this_player(),this_object());
        	this_player()->move(__DIR__"forestout");
        }
        return 1;
}