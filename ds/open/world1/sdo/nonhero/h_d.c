#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "�^�����Φa�U");
        set("long",@LONG
�I���@�n�A�A�������^���b���a�A�A�[��F�@�U�|�P�A���\�\�h�h
���Z�\�K�ަb���A���L�o�]���ʦb�K�d�l���A�]�W�F��A�ҥH�A�S��k
�\Ū�A�b�F�誺����W�d���@�ǨǪ��r(word)�C
LONG
        );
        set("exits", ([
        //"up" : "u/s/sdo/workroom.c",
	//"out": "/open/world1/tmr/area/hotel",
	"up":"/open/world1/cominging/area/herohouse1.c",
        ]));
        set("item_desc",([
        "word" : "����W���̵}�g�ۡG"+HIW+"�X��Ŷ���A�٧ڦ��s�C\n"NOR,
        ]));
        set("no_clean_up", 0);
        set("light", 1);
        setup();
}

void init()
{
        add_action("open_hole","say");
}

int open_hole(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="�٧ڦ��s" || str=="�X��Ŷ��")
	{
	object me;
	me=this_player();

	message_vision(
	HIG"\n$N�C�n�u�D�G"+str+"�C\n"NOR
	HIG"\n$Nť��|�P�T�_�F�@�}�^�n�C\n"NOR
	HIG"\n$N�ݨ�n�䪺��W�X�{�F�@�Ӥj�}�C\n"NOR,me);

	set("exits",([
	//"up":"u/s/sdo/workroom.c",
        "south" : __DIR__"gravgate.c",
	"up":"/open/world1/cominging/area/herohouse1.c",
	]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
	set("exits", ([
        //"up" : "u/s/sdo/workroom.c",
	//"out": "/open/world1/tmr/area/hotel",
	"up":"/open/world1/cominging/area/herohouse1.c",
        ]));
	delete_temp("opened");
	::reset();
}