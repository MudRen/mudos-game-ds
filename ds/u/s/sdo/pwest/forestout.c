#include <ansi2.h>
inherit ROOM;

int do_exp(object me);

void create()
{
	set("short", "�g���˪L�X�f");
	set("long", @LONG
�o�̴N�O�g���˪L���X�f�A�]�N�O�����ת���ҡC�ݬݥ|�P��
��A�u�໡���H�D�`����߮��ءC�M�֪��L���j�ӡA�`�O��A�ɪ��X
������A���H�ȳ~���Ҳ֦b�K�ɶ����������L�v�L�ܡC�e��O�@�j��
���諸���C
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("outdoors", "land");

	setup();
}
void init()
{
	call_out("do_exp",1,0);
}
int do_exp(object me)
{
	object book;
	int j,exp;
	string *msg;
	me=this_player();
	book=present("adventure notebook",me);
	
	if(!me) return 0;
	if(!book) return 0;
	if(book->query("quests/fogforest")!=1)
	{
		book->add_quests_note("fogforest",
		"�ȳ~��F�o�̡A�]�t���h�����F�F�g���˪L�����K�]���A�O���K�F�C[���ȵ���]\n");
		
		book->set_quests("fogforest",1);
		msg=book->query_quest_note("fogforest");
                j=sizeof(msg);
                exp=10000*j + random(10000);
                        
                tell_object(
                HIW"���ߧA�����F�o�ӥ��ȡI\n\n"NOR
                HIW"�A�o��F%d�I�g��ȡA�o��F%d�I�n��I\n\n"NOR,exp,j);
			
		this_player()->add("exp",exp);
		this_player()->add("popularity",j);
        	this_player()->save();
        	return 1;
        }
        return 1;
}