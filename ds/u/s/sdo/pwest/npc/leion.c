inherit NPC;
void create()
{
	set_name("�p���Ӥ�", ({ "leion"}) );
        set("long", @LONG
�@�Ӥ��~���H�A���y�J�{���⪺�o���G�ߤ������Y�������D�C
LONG
	);
        set("level",15);
        set("age",40+random(5));
	set("race","�H��");
	set("gender","�k��");
        set("combat_exp", 1000);
        
        set("title","����");

        set("talk_reply","�A���ݨ�ڪ���l�ܡH\n");
        set("inquiry/��l", 
        "�ڪ���l�s���`���A�L�O�@�ӫD�`�u�q���y�H�C�i�O�L�n�X�ѨS�^�ӤF�C\n");
        setup();
        
}
int accept_object(object me,object ob)
{
        object obj,book,l;
        obj=this_object();
        me=this_player();
        
        if(ob->name()!="�`�����Y�y")
        	return notify_fail("���§A�A���O�ڤ��ݭn�o�ӡC\n");
        if(obj->is_busy() )
        	return notify_fail("�ڲ{�b�S�šI�I\n");
        message_vision("$N���F$n�@��"+ob->query("name")+"�C\n",me,obj);
        obj->start_busy(7);
        destruct(ob);
        message_vision(
        "$N�i�D�F$n���o���g�L�A$n�����������ڳڡA�n���e��\n"
        "����\\�A�~�U�����P��$N�A�åB���D�G�����A�g�@�ʫH�������A�L\n"
        "�|���A���I\n",me,obj);
        
	l=new_ob(__DIR__"obj/letter.c");
	l->move(this_object());
	
        command("give letter to "+me->query("id"));
        if(objectp(book=present("adventure notebook",me)) && me->query_temp("sdoquest/step1")==3)
        {
        	book->add_quests_note("fogforest",
        	"���F�o�ӡA�������ӷ|�i�D�ڤF�a�C\n");
               	me->set_temp("sdoquest/step2",1);
        }
        return 1;
}