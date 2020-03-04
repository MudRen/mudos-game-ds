#include <ansi2.h>
inherit ROOM;

int go_airbus();

void create()
{
	set("short", HIW"�ﳷ�H�j�ɳ��W�B"NOR);
	set("long", @LONG
�o�̬O�ﳷ�H�j�ɪ����W�B�C�����M�J��î���O�\�h�n���W�ѥ[
���ɪ������A���b���W���d�i�e�E���߰ݡA���u��W���ˤ����R���A
�Ȥp�j�b�ѻ��ۡC����h�O�@�ӪŤ��l�����Ԩ��B�C�᭱�٦��Ʀ�u
�@�H�����b���i���X���B�z�U�ؤj�j�p�p���Ʊ��A�A�`�N�������W
�K�ۤ@�i���i�C
LONG
	);
	set("item_desc",([
        	"���i":"���ѥ[���ʪ̡A�Ц��d�i�n�O(register)�C\n"
        ]));
        set("objects",([
	__DIR__"obj/record_board.c":1,
	]));
        set("exits", ([
        	"down" : "/open/world1/tmr/area/inn_3f",
	]));
	set("current_light", 1);
	set("no_clean_up", 0);
	set("no_recall",1);

	setup();
}
void init()
{
	::init();
	add_action("do_register","register");
}
int do_register()
{
	object me,ob,obj;
	me=this_player();
	
	if(!me) return 0;
	me->start_busy(3);
	tell_object(me,HIW"\n�u�@�H���ˤ������G���±z���ѥ[�A�еy�ݤ@�|�C\n"NOR);
	if(!objectp(ob=present("christmas book",me)))
	{
		tell_object(me,HIW"\n�u�@�H���ݤF�ݧA�ỡ�G�z���W�n���S�����ʤ�U�A���ڵ��z�@���a�C\n"NOR);
		ob=new(__DIR__"obj/christmas_book");
		obj=present("adventure notebook",me);
		ob->move(environment(obj));
	}
	call_out("go_airbus",2,0);
	return 1;
}
int go_airbus()
{
	object me;
	me=this_player();
	
	if(!me) return 0;
	tell_object(me,HIW"\n�A���b�Ԩ��ǡA�ݨ��F�l���ѻ���a��C\n"NOR
		       HIW"\n���l�����U�Ӥ���A�A���}�l���������A���F�i�h�C\n\n"NOR);
	me->move(__DIR__"airbus");
	return 1;
}