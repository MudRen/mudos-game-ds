#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
	set_name("�~�~",({"year monster","monster"}) );
	set("long",@LONG
�@������ƤH�Ϊ��~�~�A�Q�W�Ѱt�U�Ө�C���|����(prize)�M�I
��(change)���ʡC�A�i�H�� llist �ݬݦ����Ǽ��~�C
LONG
);
	set("age",5000);
	set("level",200);
        set("attitude", "peaceful");
	set("race","�H��");
        set("gender", "�k��" );
	set("chat_chance",10);
	set("chat_msg",({
	"�~�~�����a��ۧA���Y�C\n",
      "�~�~���D�G�u�~�ש�����ʡI�I�@���u���g��Ȥ@�d�I�N�i�H�F�C\n",
	"�~�~�t�ۻ��֪��q���A���G�D�`���ּ֡C�C\n",
	}) );
	setup();
}


void init()
{
	::init();
	add_action("do_prize","prize");
	add_action("do_change","change");
	add_action("do_list","llist");
}

int do_prize()
{
	int i,j;
	object me,obj;
	me=this_player();
	if(me->query("exp") < 1000)
		return notify_fail("����@���ݭn 1000 exp�C\n");
		
	message_vision("$N�����i�h�~�~���L�ڸ̰ʤF�ʡA�H�J���X�F�@�i�m��C\n",me);
	obj=new(__DIR__"year_paper");
	j=random(300);
	if(j==0) obj->set_level(1);
	else if(j<5) obj->set_level(2);
	else if(j<15) obj->set_level(3);
	else if(j<30) obj->set_level(4);
	else if(j<50) obj->set_level(5);
	else if(j<75) obj->set_level(6);
	else if(j<105) obj->set_level(7);
	else if(j<140) obj->set_level(8);
	else if(j<200) obj->set_level(9);
	else obj->set_level(10);
	obj->move(me);
	me->add("exp",-1000);
	return 1;
}

int do_change()
{

	object paper,me;
	int lv;

	me=this_player();

	if(!objectp(paper=present("year paper",me) ) )
		return notify_fail("�A���W�èS���i�I��������C\n");
	lv=paper->query("level");
	switch(lv)
	{
	case 1:
	break;
	case 2:
	break;
	case 3:
	break;
	case 4:
	break;
	case 5:
	break;
	case 6:
	break;
	case 7:
	break;
	case 8:
	break;
	case 9:
	break;
	case 10:
	break;

	}		
	destruct(paper);
	return 1;
}

int do_list()
{
	tell_object(this_player(),@long

������U�L�~�S�O����
-----------------------------------------------------
�Ĥ@�S���G�n�� 100
�ĤG�S���G�n�� 50
�ĤT�S���G�n�� 30
�ĥ|�S���G�n�� 10
�Ĥ��S���G�g��� 10000
�Ĥ��S���G�g��� 5000
�ĤC�S���G�g��� 3000
�ĤK�S���G�g��� 1000
�ĤE�S���G�g��� 500
�ĤQ�S���G�g��� 100

long
);

return 1;
}
