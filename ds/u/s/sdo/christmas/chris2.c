#include <ansi2.h>
inherit ROOM;

int go_rebus();

void create()
{
	set("short", "�Ť��l����");
	set("long", @LONG
�A�����b�o�Ӥs�Y�W���l�����ԳB�C�]���o�Ӥs�Y�Q�����H�k��
�A�]�����ߤH�N�b���إߤF�@���l���������I�A�H��K��Ӫ��H�L��
�o�̡C����ߤF�@�ӵP�l�C
LONG
	);
	set("item_desc",([
        	"�P�l":"�Q�n�^�h�̡A�Хηf���^�{���Ť��l��(take bus)�C\n"
        ]));
        set("exits", ([
        	"north" : __DIR__"chris3",
	]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);
	set("outdoors", "land");

	setup();
}
void init()
{
	::init();
	add_action("do_take","take");
}
int do_take(string arg)
{
	object me;
	me=this_player();
	
	if(!me) return 0;
	if(!arg || arg!="bus") return notify_fail("�A�Q�f����F��^�h�ڡH\n");
	me->start_busy(4);
	call_out("go_rebus",2,0);
	return 1;
}
int go_rebus()
{
	object me;
	me=this_player();
	
	if(!me) return 0;
	tell_object(me,HIW"\n�A���b�o�̡A�ݨ��l���ѻ���a��C\n"NOR
		       HIW"\n���l�����U�Ӥ���A�A���}�l���������A���F�i�h�C\n\n"NOR);
	me->move(__DIR__"airbus2");
	return 1;
}