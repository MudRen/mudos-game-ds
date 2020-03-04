#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short","�^�����Ӥj��");
        set("long",@LONG
��L�}�}��A�Ө�@�ӥ۫ǡC�o�O�@�ӫܰ��b���۫ǡA�èS���@
��L�H�������N����C�۫Ǫ��n�観�@���۪��A�ݰ_�ӫD�`�I���A��
�Ӥ��O�H�O�ү�}�Ҫ�,�Ӫ����䦳�@�ӥb�H�����۸O�C
LONG
        );
        set("item_desc",([
        "�۪�":"�o�O�@���ܨI�������A���W�g�ۡG�����u�����q���h�Ӷ}�C\n",
        "�۸O":"�۸O�W�g�ۡy���q�z��Ӥj�r�A�ӥB�o�ӥ۸O�ݰ_�ӬO�i�H���(turn)���C\n",
        ]));
        set("light", 0);
        set("exits",([
        "north" : __DIR__"h_d.c",
        ]));
        set("light", 0);
        setup();
}

void init()
{
	add_action("open_door","turn");
}

int open_door(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="�۸O")
	{
	object me;
	me=this_player();
	
	message_vision(
	HIG"\n$N�ΤO����ۥ۸O�A�V�O������ۡC\n"NOR
	HIG"\n��ɥ۸O����۪��ɡA���C�C�����}�F�C\n"NOR,me);

        set("item_desc",([
        "�۪�":"�o�O�@���ܨI�������A���W�g�ۡG�����u�����q���h�Ӷ}�C\n"
               "�۪��{�b�Q���}�F�C\n",
        "�۸O":"�۸O�W�g�ۡy���q�z��Ӥj�r�A���L���{�b�w�g�Q��ʹL�F�C\n",
        ]));

	set("exits",([
	"north":__DIR__"h_d.c",
        "south" : __DIR__"grav1.c",
	]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
	set("exits", ([
        "north":__DIR__"h_d.c",
        ]));
        set("item_desc",([
        "�۪�":"�o�O�@���ܨI�������A���W�g�ۡG�����u�����q���h�Ӷ}�C\n",
        "�۸O":"�۸O�W�g�ۡy���q�z��Ӥj�r�A�ӥB�o�ӥ۸O�ݰ_�ӬO�i�H���(turn)���C\n",
        ]));
	delete_temp("opened");
	::reset();
}