#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short","�ӫǤ���");
        set("long",@LONG
�o�̴N�O�ǻ������L�W�^�����ӤF�C��W�G���F�g�|�L�W�^����
�֡B��H�κq���A�i�H�ݥX��ɾԪ����G�P�H�εL�W�^���O�a�ðꪺ
���|���ޡC�e�褣���B���@�Ӿ�����ä�A���Ӵä���G�ĤޥX�A��
�n�_�ߡA���A����ı���Q�e���@���s���C���L��Ǫ�������G���I��
�ӹ�l�C
LONG
        );
	set("item_desc",([
	"���":"���k���䪺����A�Pı���I�����A�n���@��N�|�}���ˤl�C\n",
	]));
        set("exits",([
        "north":__DIR__"gravgate.c",
	"south":__DIR__"fere.c",
        ]));
        set("light", 0);
        setup();
}

void init()
{
	add_action("kick_well","kick");
}

int kick_well(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="��" || str=="���")
	{
	object me;
	me=this_player();

	message_vision(
	HIG"\n$N���R���ϥX�@�ۤG�s��A���䪺�����n�ӯ}�C\n"NOR
	HIG"\n�F���@�n�A��ˤF�C\n"NOR,me);

        set("long",@LONG
�o�̴N�O�ǻ������L�W�^�����ӤF�C��W�G���F�g�|�L�W�^����
�֡B��H�κq���A�i�H�ݥX��ɾԪ����G�P�H�εL�W�^���O�a�ðꪺ
���|���ޡC�e�褣���B���@�Ӿ�����ä�A���Ӵä���G�ĤޥX�A��
�n�_�ߡA���A����ı���Q�e���@���s���C��Ǫ�����X�{�F�}�}�C
LONG
        );
        set("item_desc",([
        "���":"���k���䪺����W���X�{���@�Ӥj�}�}�C\n",
        ]));

	set("exits",([
	"east":__DIR__"grav3.c",
	"west":__DIR__"grav2.c",
        "north":__DIR__"gravgate.c",
	"south":__DIR__"fere.c",
	]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
        set("long",@LONG
�o�̴N�O�ǻ������L�W�^�����ӤF�C��W�G���F�g�|�L�W�^����
�֡B��H�κq���A�i�H�ݥX��ɾԪ����G�P�H�εL�W�^���O�a�ðꪺ
���|���ޡC�e�褣���B���@�Ӿ�����ä�A���Ӵä���G�ĤޥX�A��
�n�_�ߡA���A����ı���Q�e���@���s���C���L��Ǫ�������G���I��
�ӹ�l�C
LONG
        );
	set("item_desc",([
	"���":"���k���䪺����A�Pı���I�����A�n���@��N�|�}���ˤl�C\n",
	]));

	set("exits", ([
        "north":__DIR__"gravgate.c",
	"south":__DIR__"fere.c",
        ]));
	delete_temp("opened");
	::reset();
}