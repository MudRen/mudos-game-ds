#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "�p�ӫ�");
        set("long",@LONG
�o�@���ӫǤ�_�~�����ӫǩ��㪺�p�F�ܦh�A���L���M��O�Q��
���e���C�������@�Ӧ��L�A���L�W�n�����F��b���@�ˡC���L�V�a��
���ӪF��A�Pı����|�P���Ů�y�ʳt�׶V�ӶV�֤F�C
LONG
        );
        set("exits", ([
        "west" : __DIR__"grav1.c",
        ]));
        set("item_desc",([
        "���L" : "�@�ӫܤj���L�l�A�W����ۤ@���H�ҡA�n���i�H���_��(get)�C\n",
        ]));
        set("light", 0);
        setup();
}

void init()
{
	add_action("get_leggingss","get");
}

int get_leggingss(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="leggings" || str=="�H��")
	{
	object me,b;
	me=this_player();

	message_vision(
	HIC"\n$N�����⮳�_�L�l�̪��H�ҮɡA�H�ҤƧ@�@�}�g�������F�C\n"NOR
	HIC"\n�@���u�@�~���H�ۨg���X�{�b$N�����e�C\n"NOR,me);

	b=new(__DIR__"obj/npc/wind_beast.c" );
	b->move(__DIR__"grav3.c" );
	
        set("item_desc",([
        "���L" : "�@�ӫܤj���L�l�A�W������F��]�S���C\n",
        ]));

	set_temp("opened",1);
	return 1;
	}
}
void reset()
{
	delete_temp("opened");
	set("item_desc",([
        "���L" : "�@�ӫܤj���L�l�A�W����ۤ@���H�ҡA�n���i�H���_��(get)�C\n",
        ]));
	::reset();
}