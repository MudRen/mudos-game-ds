inherit NPC;
void create()
{	
	set_name("��Y�R", ({ "selina"}) );
        set("long", @LONG
�b�A���e���O�@����R������C���ժ��ֽ��A�M�@�Y�G�R�����v�A��
�A�b�F�@�U�A�o�إX�������G�M�u��b���F�����W����C
LONG
	);
        set("level",30);
        set("age",80);
	set("race","�H��");
	set("gender","�k��");
        set("combat_exp", 7000);
        
        set("title","����");

        set("talk_reply","�A�n�A�H�����_�I�̡C\n");
        setup();

}
void init()
{
	add_action("do_inquiry","inquiry");
}
int do_inquiry(string arg)
{
	object book,me,b;
	me=this_player();
	
	if(!me) return 0;
	if(me->query_temp("sdoquest/step2")!=2) return 0;
	if(arg != "�q�L��k" || arg != "�q�L����k") return 0;        
        if(objectp(book=present("adventure notebook",me)))
        {
        	me->start_busy(10);
        	write(
        	"��Y�R���G�g���˪L���̻٬O�Ӧ۩�@�����j�������A\n"
        	"�ӥѴ˪L�����|�د���c�����ɡA�u�n�����������A���ɴN�|�û��s�b�C\n"
        	"�ҥH�۹諸�A�i�H�ھگ��𪺺����ӱ������T���X�f�C\n"
        	"�Q�n�q�L�A�N�n�O�n�o�@���j�Ѫ��֡C\n\n"
        	"��Y�R��������F�_��~~~\n\n"
        	"�y�����_���ꪺ�ѯ����A�ХΨ���b���շ��쬰�ڭ̲M�����c�F�z\n"
        	"�y�åB�߱��礩�^�H����@�B�a�f�����z�A���F��ܶ·t���դO�F�z\n"
        	"�y�i�h�̪����ө{�p�n�W�䪺������K���F�z\n"
        	"�y����b�鸨���ɦ��H�ۮ۪᭻�ͱۦ��k�I�z\n");
        	book->add_quests_note("fogforest",
        	"�A�c�c���O�U��k�A�ש�n�²��I�e�i�F�C\n");
        	me->set_temp("sdoquest/step2",3);
        	if(me->query_temp("sdoquest/step2")==3 && me->query("evil") <= -200)
        	{
        		b=new_ob(__DIR__"obj/tearofelf.c");
        		b->move(this_object());
        		
        		write(
        		"��Y�R���G�o��_�I�̡A�е��@��...\n\n"
        		"�ڧƱ�A�b�q�L�g���˪L�e�A���̷ӳo�ӪF�誺���ܡA\n"
        		"�b�˪L�̧�@�ӤH�A�åB��o�F��浹�L�A�L�|���A��\n"
        		"�U���C\n");
        		command("give tear to "+me->query("id"));
        		me->set_temp("sdoquest/step3",1);
        	}
        }
        return 1;
}