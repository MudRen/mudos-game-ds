inherit NPC;
string do_book();

void create()
{
	set_name("�細", ({ "random"}) );
        set("long", @LONG
�@�ӥ��Z�������A�Ѥ�}�W��õ�i�H�ݱo�X�ӥL�j�����~�b�Цa�̤u
�@�C
LONG
	);
        set("level",15);
        set("age",50);
	set("race","�H��");
	set("gender","�k��");
        set("combat_exp", 1000);
        
        set("title","����");

        set("talk_reply","�u�O�x�Z...\n");
        set("inquiry",([
        "�Ӷ�":	"�N�O�B�e�f����o�̪������A�̭������l�̪��H�U�H�ʶR�����~�C\n"
        	"���ڴN�R�F�@�����ؤl�A���G�{�b�ؤl�S�F�A���٤����D�n������\n"
        	"�F�輽�ءC�u�O�˸���...\n",
        "�x�Z":this_object()->do_book(),
        ])); 

        setup();
}
string do_book()
{
	object book,me;
	me=this_player();
	if(!me) return 0;	
	if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdoquest/step1")==2)
	{
		book->add_quests_note("fogforest",
        	"�ݨӳo�Ӱ��D���Y���A�ڬO���O�ӥh�ݬݱ��p�A���K�M��`�����U��...�C\n");
               	me->set_temp("sdoquest/step1",3);
		
		return "�N�O���@�s�Ǫ����I�����D�q���̨Ӫ��A�@�}�l�٥u�O�X�j�a\n���`�N�ɽ_�и̷m�ܧ@���A���G�{�b���M�٧����Ӷ��I�ҥH�W\n�����l�}�|�ɡA�`���D�ʪ�ܭn�h�����e�̡A�����D��ˤF�A\n";
	}
}	
int accept_object(object me,object ob)
{
        object obj;
        obj=this_object();
        me=this_player();
        
        if(ob->name()!="�Ӫ��ؤl")
        	return notify_fail("���§A�A���O�ڤ��ݭn�o�ӡC\n");
        if(obj->is_busy() )
        	return notify_fail("�ڲ{�b�S�šI�I\n");
        message_vision("$N���F$n�@��"+ob->query("name")+"�C\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        command("dance");
        command("thank "+me->query("id"));
        this_player()->add("exp",1000);
        tell_object(
        "�A�o�� 1000�I�g��ȡI\n");
        message_vision(
        "$n���G���~���ȨS�ؤl���ذաI\n",me,obj);
        return 1;
}