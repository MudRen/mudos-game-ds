inherit NPC;
string do_book();

void create()
{
	set_name("���Ǧ�", ({ "jialermi"}) );
        set("long", @LONG
�L�O�@��ѾǨs�A�p��������U�õۥR�����z�������C�L�Ҿ֦�����
�b�o����@�j���W�O�ݤ@�ݤG���C�ǻ��L�O���F�y���M�a�C
LONG
	);
        set("level",25);
        set("age",80);
	set("race","�H��");
	set("gender","�k��");
        set("combat_exp", 3000);
        
        set("title","�j�Ǫ�");

        set("talk_reply","��...Ū�ѬO�h���n���Ʊ��C\n");
        set("inquiry",([
        "������":"�Ѻ��F�ҫإߪ���a�A�N���æb�g���L����C\n"
        	   "�򥻤W�L�̨ä����w�P�H����D�C\n",
        "���F�y": "�O�����F�����ҥΪ��j�ѻy���A�ڬ�s�ܤ[�o...\n",
        "�g���˪L":this_object()->do_book(),
        ]));
        setup();
}
string do_book()
{
	object book,me;
	me=this_player();
	if(!me) return 0;      
        if(objectp(book=present("adventure notebook",me)))
        {
        	book->add_quests_note("fogforest",
        	"���F�q�L�g���˪L�A�ݨӧڱo�h�ݰݧ����q�L����k�F�C\n");
        	me->set_temp("sdoquest/step1",1);
        	return "�g���˪L�O�@����������L�C�s�b���ɶ�����A�کҷQ\n�������٭n�[�A�ӥB�|���ץ~�Ӫ̡Cť�����������F�B�͡A�ҥH�L���Ӫ��D�q�L����k�a\n";
        }
}	
int accept_object(object me,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="�]�k�ѥ�")
        	return notify_fail("���§A�A���O�ڤ��ݭn�o�ӡC\n");
        if(obj->is_busy() )
        	return notify_fail("�ڲ{�b�S�šI�I\n");
        message_vision("$N���F$n�@��"+ob->query("name")+"�C\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        this_player()->add("popularity",1);
        tell_object(
        "�A�o��@�I�n��I\n");
        message_vision(
        "$n��Y�����G�o....�o���O�ڰU�H�R���ѶܡH���|�b\n"
        "�A��W�H�������u�O�Ӧn�F�I\n",me,obj);
        return 1;
}