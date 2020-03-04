#include <ansi.h>
inherit ROOM;
string look_well(object me);
static int water=1;
void create()
{
	set("short", "����");
        set("long", @LONG
          �o�̦��ӯ}�ª�����(well)�C
LONG
);
	set("exits",([
	"east" : __DIR__"map_5_7",
	"south" : __DIR__"map_6_6",
	"north" : __DIR__"map_4_6",
	"west" : __DIR__"map_5_5",
	]));
        set("item_desc",([      
        "well" : (:look_well:),
        ])      );

    set("objects", ([
       __DIR__"../npc/beast_butterfly_1" : 2,
    ]));
	set("outdoors","land");
	set("light",1);
        setup();
	set("map_long",1);     //show map as long

}

string look_well(object me)
{
	if(water) return "�o�f����������ܰ��C\n";
	else return "�o�f�����G�w�g���F�ܤ[�F�C�ѩ󤫨ä��`�A��(jump)�U�h�]���|���ˡC\n";
}

int query_well()
{
	return water;
}

void set_water(int full)
{
	string waterlong,nowaterlong;
	object *inv=({}),room;
	waterlong=@HAVEWATER
�o�Ӥ��������G�������ɡA�������F�\�h����C
HAVEWATER;
	nowaterlong=@NOWATER
�o�Ӥ����G���F�ܤ[�A�������F�\�h����������C
NOWATER;
	if(full==0)
	{
		if(water==1)
		{
			water = 0;
			inv = all_inventory(this_object());
			if(sizeof(inv)) inv->move(this_object(), 1);	
			this_object()->set("no_clean_up",1);
			if(room=find_object(__DIR__"well1"))
			{
				room->set("long",nowaterlong);
				room->delete("no_recall");
				tell_room(room,HIC+"\n\t��M���@�}�Ŷ��ᦱ�A������M�����F�I�I\n\n"+NOR);
			}
			if(room=find_object(__DIR__"well2"))
			{
				room->set("long",nowaterlong);
				room->delete("no_recall");
				tell_room(room,HIC+"\n\t��M���@�}�Ŷ��ᦱ�A������M�����F�I�I\n\n"+NOR);
			}
		}
	}
	else
	{
		if(water==0)
		{
			water = 1;
			this_object()->set("no_clean_up",0);
			inv = all_inventory(this_object());
			if(sizeof(inv)) inv->move(this_object(), 1);
			if(room=find_object(__DIR__"well1"))
			{
				room->set("no_recall",HIC"�A�Q���檺�L�k�M�߽ШD���U"NOR);
				room->set("long",waterlong);
				tell_room(room,HIC+"\n\t��M���@�}�Ŷ��ᦱ�A�����q�|���K���J�A���f�󤧤��I�I\n\n"+NOR);
				inv = all_inventory(room);
				if(sizeof(inv)) inv->water_effect();
			}
			if(room=find_object(__DIR__"well2"))
			{
				room->set("long",waterlong);
				room->set("no_recall",HIC"�A�Q���檺�L�k�M�߽ШD���U"NOR);
				tell_room(room,HIC+"\n\t��M���@�}�Ŷ��ᦱ�A�����q�|���K���J�A���f�󤧤��I�I\n\n"+NOR);
				inv = all_inventory(room);
				if(sizeof(inv)) inv->water_effect();
			}
		}
	}
}

void init()
{
	if(water) return;
	add_action("do_jump","jump");
}

int do_jump(string arg)
{
	if(!arg)
	{
		write("�A�Q��(jump into)�����?\n");
		return 1;
	}
	if(arg=="into well")
	{
		message_vision("$N�����̸��F�U�h�C\n",this_player());
		this_player()->move(__DIR__"well1");
		if(!this_player()->query_temp("invis"))
			tell_room(environment(this_player()),this_player()->name()+"�q�W�����F�U�ӡC\n",({this_player()}));
		return 1;
	}
	write("�A�Q��(jump into)�����?\n");
	return 1;
}

void reset()
{
	if(this_object()->query("no_clean_up")) return;
	::reset();
}

int handle_well_effect(object me)
{
	if(!water) return 1;
	if(random(me->query_skill("swim"))<20)
	{
		message_vision("$N�]���L�k�I�l��o�ܵh�W�C\n",me);
		me->set_temp("temp/death_type","[[1;36m���Ũ��`[0m]");
		me->receive_damage("hp",me->query("max_hp")/10);
	}
	return 1;
}
