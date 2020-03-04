#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "���");
        set("long", @LONG
�I�b�A���e�O�y�y�y����������A������O�N�m���u���A�����a½��
����A�b��������ɬO�H�����e�A�٦��n�X��b�ꪺ�ͭ��b��������B��
�I�C�A�`�N�������ߵۤ@�y�۬W�A�W�Y�\�۪��ɬ֡A�����D����@�ΡC
LONG
        );
  set("item_desc",([
      "���ɬ�" : "���ɬ֥i�H�ΨӲ��ͥP�A�n�O���Ȧ����ܡA�i�H�ո��\\��(arrange)�@�ǥͦצb�̭��C\n",
     ]));
        set("exits",([
        "south" : __DIR__"map_11_13",
        "north" : __DIR__"map_9_13",
        "west" : __DIR__"map_10_12",
        "east" : __DIR__"map_10_14",
        ]));
        setup();
        set("map_long",1);     //show map as long
}

void init()
{
  add_action("do_throw","arrange");
}


void call_troll() {
        object mobp;
        if(query_temp("is_grill")) return;

        if( query_temp("meats") < 3 + random(3) ) {
             message_vision( "���½�ʪ���F�`�F...\n" NOR, this_player());
             return;
        }

        // �a�Ⱖ�L
        mobp = new("/open/world1/tmr/unquiet_manor/npc/demon.c"); 
        mobp->delete("chat_msg");
        mobp->move(environment(this_player()));  
        mobp = new("/open/world1/tmr/unquiet_manor/npc/demon.c"); 
        mobp->delete("chat_msg");
        mobp->move(environment(this_player()));  
        mobp = new("/open/world1/tmr/unquiet_manor/npc/corpse_king.c"); 
        mobp->move(environment(this_player()));  
        message_vision( HIG "���M�A�q����`�B�_�X�T�D���v�A��{����n�ɥR����y�ӫǡI�I\n" NOR, this_player(), mobp);
        set_temp("is_grill",1);
        call_out("stop_throwed", 180 + random(60));
}

int do_throw(string arg)
{ 
  object me=this_player(), meat; 
        if(me->is_busy())
                return notify_fail("�A�����ۡA�S���Ű��ơC\n");
  if( query_temp("is_grill") )
                return notify_fail("�A�o�{���ɬָ̭��٦��ǸH�סC\n");
  if(!arg || arg != "meat")
                return notify_fail("�A�Q�n�\\����F��H\n");
  if(!objectp(meat=present("_BLOOD_MEAT_",me) ) )
    return notify_fail("�o�ӪF��L�k�o�˨ϥΡC\n");

  message_vision( HIM "$N�p���l�l�N$n"HIM"�\\��b���ɬ֤��C\n" NOR, me, meat);
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



