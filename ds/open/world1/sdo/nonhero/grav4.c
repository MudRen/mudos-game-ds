#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "���ӫ�");
        set("long",@LONG
����o�A�o�{�n������F�X�Ӫ����Y�C����o�̡A�A�ߤ����g���@
�I�I���ôb�A�]���@�����ӡA���F��誺�ä�M���e���~�A�s�@�˪F��
���S���C�O���O�������A�s�ǻ����L�W�^�����ԥҤ]�S����C���D�A��
���O�F�H���H���L�A���s�o�̪�������Pı���I�ǩǪ�....
LONG
        );
        set("exits", ([
        "north" : __DIR__"fere.c",
        ]));
        set("item_desc",([
        "���":"�ݰ_�Ӧn���i�H����...�C\n",
        ]));
        set("no_clean_up", 0);
        set("light", 0);
        setup();
}

void init()
{
	add_action("hit_wall","hit");
}

int hit_wall(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="��" || str=="���")
	{
	object me;
	me=this_player();
	
	message_vision(
	HIG"\n$N�Ií���X�����V����A���䪺�����n�ӯ}�C\n"NOR
	HIG"\n�F���@�n�A��ˤF�C\n"NOR,me);

        set("long",@LONG
����o�A�o�{�n������F�X�Ӫ����Y�C����o�̡A�A�ߤ����g���@
�I�I���ôb�A�]���@�����ӡA���F��誺�ä�M���e���~�A�s�@�˪F��
���S���C�O���O�������A�s�ǻ����L�W�^�����ԥҤ]�S����C���D�A��
���O�F�H���H���䪺��Q�A���X�Ӥj�}�F�C
LONG
        );
	
	set("item_desc",([
        "���":"���k���䪺����W���X�{���@�Ӥj�}�}�C\n",
        ]));

	set("exits", ([
        "north" : __DIR__"fere.c",
	"west":__DIR__"grav5.c",
	"east":__DIR__"grav6.c",
        ]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
	set("long",@LONG
����o�A�o�{�n������F�X�Ӫ����Y�C����o�̡A�A�ߤ����g���@
�I�I���ôb�A�]���@�����ӡA���F��誺�ä�M���e���~�A�s�@�˪F��
���S���C�O���O�������A�s�ǻ����L�W�^�����ԥҤ]�S����C���D�A��
���O�F�H���H���L�A���s�o�̪�������Pı���I�ǩǪ�....
LONG
        );
	set("exits", ([
        "north" : __DIR__"fere.c",
        ]));
        set("item_desc",([
        "���":"�ݰ_�Ӧn���i�H����...�C\n",
        ]));
	delete_temp("opened");
	::reset();
}
