#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��W");
        set("long", @LONG
�o�O�@���Φˤl�s´�Ӧ����@���p��A�õL�\�m�����A�b�A�}����
�@�K���ˬ�A�ݨӬO�i�ΨӼ�����ߤp�ΡC
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "�ˬ�" : "�@�K���Ƥت��C���ˬ�A�ݨӭ��ٰ�T�A�ٳ��ϥ�(use)�C\n",
]));
        set("exits", ([ /* sizeof() == 2 */
	  "out" : __DIR__"nb4",
       ]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("douse","use");
}


int douse(string arg)
{
	object me,room,*inv;
	me=this_player();
	if(arg != "�ˬ�") return 0;
	if(!this_object()->query_temp("moving")) 
	{
		inv = all_inventory(this_object());
	        message_vision( HIW "$N���_�F���ˬ�A���򩳴��h�A����a���}�F����...\n\n" NOR ,me);
		me->start_busy(3);
		call_out("domessage",3,3);
		this_object()->set_temp("moving",1);
		this_object()->delete("exits");
		room = load_object(__DIR__"nb4");
		room->delete("exits/enter");
		room->set("long",@ROOM_LONG
�b�l����F�o�̴N�w�쩳�A���_�i�ݨ줭���˩СA�����|���@�j�q�Z
���A�N�O�����\�̰����H�]���@��ӤΡC

ROOM_LONG
);
		tell_room(room,"�A�ݨ���䪺�p��������}�F..\n");
		return 1;
	}else
	{
		tell_object(me,"��w�g�����F�C\n");
		return 1;
	}

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==3) tell_room(this_object(),HIW "�ѩ�ˬ񪺱��O�A��C�C�����e���ʤF...\n\n" NOR);
   else if(b==2) tell_room(this_object(), HIW "�u������M���A����լաA���ɦ����౰���ӹL�A�n�@�T�ѤW�����I�I\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIW "��E��F�p�ΡA�u���p���������|���ƤءA���f���i���誽�F�����C\n\n" NOR );
  else  {
	        inv = all_inventory(this_object());
	        tell_room(this_object(),HIY "�p��ש�a�F���A�A���۱�l���W�F�p��..\n\n" NOR );
		this_object()->delete_temp("moving");
		room = load_object(__DIR__"waroom");
		tell_room(room,"�A�ݨ�@���p����a�F�L��..\n");
		for(i=0;i<sizeof(inv);i++)
		{
			if(living(inv[i])) inv[i]->move(__DIR__"waroom");
		}
		tell_room(room,"�p��S���ۤ��y�}���F..\n");
		this_object()->set("exits", ([
	  		"out" : __DIR__"nb4",
       		]));
		room = load_object(__DIR__"nb4");
		tell_room(room,"�A�ݨ즳���p������}�y�F�L�Ӱ��a�b����..\n");
		room->set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"nb3",
  "enter" : __DIR__"bship",
]));
		room->set("long",@ROOM_LONG2
�b�l����F�o�̴N�w�쩳�A���_�i�ݨ줭���˩СA�����|���@�j�q�Z
���A�N�O�����\�̰����H�]���@��ӤΡC�b�A���䰱�ۤ@���p��b����
�A�ݨӥi�H�W�h�@�@�C
ROOM_LONG2
);
		return 1;
		
	}
	b--;
	call_out("domessage",3,b);
}

