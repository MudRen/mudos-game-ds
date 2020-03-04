#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short", "�p�ӫ�");
        set("long",@LONG
�o�@���ӫǤ�_�~�����ӫǩ��㪺�p�F�ܦh�A���L���M��O�Q��
���e���C�������@�i��l�A��l�W�n�����F��b���@�ˡC���L�V�a��
���ӪF��A�Pı�V�ӶV���F�C
LONG
        );
        set("exits", ([
        "east" : __DIR__"grav1.c",
        ]));
        set("item_desc",([
        "��l" : "�@�i�ۮ�A�W����ۤ@�󲯥ҡA�A�i�H���_��(get)�C\n",
        ]));

        set("light", 0);
        setup();
}

void init()
{
	add_action("get_armors","get");
}

int get_armors(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="armor" || str=="����")
	{
	object me,b;
	me=this_player();

	message_vision(
	RED"\n��$N�����⮳�_���ҮɡA���ҩ��M�N�F�_�ӡC\n"NOR
	RED"\n�@���u�@�~�q���̺C�C�����F�X�ӡC\n"NOR,me);

	b=new(__DIR__"obj/npc/fire_beast.c" );
	b->move(__DIR__"grav2.c" );
	
        set("item_desc",([
        "��l" : "�@�i�ۮ�A�W������F��]�S���C\n",
        ]));

	set_temp("opened",1);
	return 1;
	}
}
void reset()
{
	delete_temp("opened");
	set("item_desc",([
        "��l" : "�@�i�ۮ�A�W����ۤ@�󲯥ҡA�A�i�H���_��(get)�C\n",
        ]));
	::reset();
}