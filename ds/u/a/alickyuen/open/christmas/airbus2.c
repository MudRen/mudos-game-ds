#include <ansi2.h>
inherit ROOM;

int go_bus();
int down_rebus();

void create()
{
	set("short", "�Ť��l����");
	set("long", @LONG
�o�̬O�Ť��l���������C�]���b�ܰ��šA�ҥH�����D�`���n�C��
�B�o�x�l���g�L�Q���Y�檺���աA�ҥH�w���ʵL�áC�q���~��X�h�A
���U���Фl���ܪ��p�p���C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);

	setup();
}
void init()
{
	object me;
	me=this_player();
	
	if(!me) return;
	
	me->start_busy(4);
	call_out("go_bus",2,0);
}
int go_bus()
{
	object me;
	me=this_player();
	
	if (!me) return 0;
	
	tell_object(me,HIW"\n�C�C���A�^��F���W�a�I���Ԩ��ǡC\n"NOR);
		       
	call_out("down_rebus",2,0);
}
int down_rebus()
{
	object me;
	me=this_player();

	if(!me) return 0;
	
	tell_object(me,HIW"\n\n�@�}�n�̡A�l�����F�U�ӡC\n"NOR
		       HIW"\n�A���}�F�����A���F�X�h�C\n"NOR);
	
	me->move(__DIR__"chris1");
	return 1;
}