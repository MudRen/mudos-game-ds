#include <ansi.h>

inherit ROOM;
void create()
{
	set("short", "�L��");
        set("long", HIY"�o�̦��@�Ӳ`�`�����}, �ݨӴN�O���n�����~�ҤF\n"NOR);
	set("exits",([
	"west" : __DIR__"map_9_8",
	]));
 set("item_desc",([
        "���}":"�@�Ӥp�p�����}, �A�i�H��F��(put xxx in ���})�i�h�ݬ�.\n"
    ]));        setup();
        set("map_long",1);     //show map as long
}

void init()
{
        add_action("do_put","put");
}

int do_put(string arg)
{
        object me,tackle,f;
      object room = environment(this_player());
        me=this_player();
      if( arg!="tackle in ���}") return 0;
        if(!objectp(tackle=present("gold tackle",me) ) )
                return notify_fail("�A���W�èS���i�H�ϥ��������C\n");
        message_vision("$N���_�@�ӵo�۶�����~���������i���}�C\n",me);
	if (room->temp("catch") == 0)
	{
     message_vision(HIY "���M�@���å��p���ĤF�X�ӡI�I\n" NOR,me);
    	f=new(__DIR__"npc/light_fish");
        	f->move("/u/f/faceoff/testmap/map_9_9");        
	room->set_temp("catch",1);
	}
	else
	{
message_vision("���O$N����]�S�o�{...�C\n",me);
	}
return 1;        
}
