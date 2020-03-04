#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�a���}��");
	set("long", @LONG
�A���B�b�@�Ӧa���}�ޤ��A�ѩ󶧥��L�k�Ӯg�i�ӡA�ҥH�|�g�ɬO�º�
�����@���A�A�u��j�j���۩������e�i�C�A�`�N��a�W���Ӥ���A�٦��Ǿl
�u�A�����D�O��˪��ͪ��d�U�o�Ӥ���C
LONG
	);
	set("current_light", 4);
	set("no_clean_up", 0);
	set("objects", ([ /* sizeof() == 1 */
	  __DIR__"npc/troll4" : 2,
	  __DIR__"npc/troll5" : 2,
	  __DIR__"npc/troll6" : 1,
	]));
  set("item_desc",([
      "����" : "���襤�٦��Ǿl�u�A�A�i�H�ΨӯN�@�Ǧ�(grill)�C\n",
     ]));
	set("exits", ([ /* sizeof() == 2 */
 "north" : __DIR__"cave2",
]));

	setup();
}

void init()
{
  add_action("do_throw","grill");
}


void call_troll() {
	object mobp;
	if(query_temp("is_grill")) return;

	if( query_temp("meats") < 3 + random(3) ) {
              message_vision( "�N�ת������V�ӶV�@��......\n" NOR, this_player());
		 return;
	}

  mobp = new(__DIR__"npc/troll7"); 
  mobp->move(environment(this_player()));   
  message_vision( HIG "���M�A�@���e�j���ͪ��X�{�F�I�I\n" NOR, this_player(), mobp);
  mobp->force_me("lick");
  set_temp("is_grill",1);
    call_out("stop_throwed", 300 + random(60));
}

int do_throw(string arg)
{ 
  object me=this_player(), meat; 
	if(me->is_busy())
		return notify_fail("�A�����ۡA�S���ůN�סC\n");
  if( query_temp("is_grill") )
		return notify_fail("�A�o�{�������ä����A�ȮɵL�k�N�סC\n");
  if(!arg || arg != "meat")
		return notify_fail("�A�Q�n�N����F��H\n");
  if(!objectp(meat=present("_BEEF_MEAT_",me) ) )
    return notify_fail("�o�ӪF��L�k���ӯN�C\n");

  message_vision( HIY "$N�N$n"HIY"��b����W�N�A�N�ۯN�ۡA�@�}�׭����ƤF�X�h�A�R����Ӭ}�ޡC\n" NOR, me, meat);
  destruct(meat);
  add_temp("meats",1);
  me->start_busy(2);  
  call_out("call_troll", 2);

  return 1;
}

void stop_throwed()
{
  if(!this_object()) return; 
	delete_temp("is_grill");
	delete_temp("meats");
}

