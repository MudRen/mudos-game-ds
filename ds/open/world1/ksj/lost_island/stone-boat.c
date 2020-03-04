#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "�ۦ�W");
  set("long", @LONG
�o�O�@���ۻs���p��A��W�L�|�L���]�S���ո��A�ۦ����^
�O�\�h�Ŧ⪺�p�ۤl�A�Φ������������A�_�S���O�������G�Q�p�ۤl
�ұƥ��A�ϱo��ӥۦ�O�B�b�����W�C
LONG
);
  set("item_desc", ([ /* sizeof() == 1 */
      "�ۻO" : "�ߦb�ۦ�W���p�ۻO�A�W�����Ӥp�W�}�A�����O��γB(use)�C\n",
     ]));
  set("exits", ([ /* sizeof() == 2 */
      "out" : __DIR__"room_add",
     ]));
  set("no_clean_up", 0);
  set("light",1);
  set("no_recall",1);
  setup();
}

void init()
{
  int i,count;
  object *inv,room;
  count=0;
  inv = all_inventory(this_object());
  room = load_object(__DIR__"room_add");
  add_action("do_use","use");

  for(i=0;i<sizeof(inv);i++)
  {
    if( living(inv[i]) && userp(inv[i]) ) count++;
  }
  
  if( count > 3)
  {
    message_vision("\n$N�]���ۦ�Ŷ��U���A�ӵw�O�Q���F�X�h�I\n\n",this_player());
    this_player()->move(__DIR__"room_add");
    tell_room(room,"�ۦ�̤F�@�̡A���ӤH�Q���F�X��...\n");
  }
}

int do_use(string arg)
{
  object me,room,*inv,z;
  me=this_player();
  if(arg != "stone") return 0;
  if(!objectp(z=present("sea stone",me) ) )
    return notify_fail("�A���W�èS���X�A�����~�i�ѨϥΡC\n");
  if(!this_object()->query_temp("moving")) 
  {
    inv = all_inventory(this_object());
    message_vision(HIC"\n$N�N�Ѯ��۴O�b�ۦ઺�p���O�W�A�ۦ๳�O�o��ʤO�����®��W��p�I\n\n"NOR,me);
    destruct(z);
    call_out("domessage",5,6);
    this_object()->set_temp("moving",1);
    this_object()->delete("exits");
    room = load_object(__DIR__"room_add");
    room->delete("exits/enter");
    tell_room(room,"�A�ݨ�ۦ�H���t��V����...\n");
    return 1;
  }
  else
  {
    tell_object(me,"�ۦప�t��������C\n");
    return 1;
  }

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==6) tell_room(this_object(),HIW "�ۦ��ƯB�b������p�A�A�uť�o�����I�I�����n...\n\n" NOR);
  else if(b==5) tell_room(this_object(), HIW "�ۦ��~��b������p....\n\n" NOR );
  else if(b==4) tell_room(this_object(), HIW "�ۦ�s��ĹL�X�Ӥj���A�@�P�n�̤F�X�U....\n\n" NOR );
  else if(b==3) tell_room(this_object(), HIY "�ۦ઺�t�׶V�ӶV�֤F�I�I\n\n" NOR );
  else if(b==2) tell_room(this_object(), HIR "�A�`�N��"HIC"�Ѯ���"HIR"�_�X�@���C��....\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIW "�����a�A�ݨ�@�Ӷ��I�A�����a�V�ӶV�j�A��ӬO�y�p�q�C\n\n" NOR );
  else
  {
    inv = all_inventory(this_object());
    tell_room(this_object(),HIR "�@�}�@�P�������ϱo�A�q�ۦ�W���F�X�h�A�����a�L�b���y�W..\n\n" NOR );
    this_object()->delete_temp("moving");
    room = load_object(__DIR__"room1");
    tell_room(room,HIW"�A�ݨ�@���p��t�ĤF�L��..\n"NOR);
    for(i=0;i<sizeof(inv);i++)
    {
      if(living(inv[i])) inv[i]->move(__DIR__"room1");
    }
    tell_room(room,HIR"�ۦ�ļ����y��A�������u�F�}�h�A..\n"NOR);
    this_object()->set("exits", ([
                       "out" : __DIR__"room_add",
                      ]));
    call_out("delay",900);
    if( userp(this_player()) )
    {
      message("world:world1:vision",
        HIW"\n\t�X�g�i��"HIY""+this_player()->name(1)+HIW"�ש��F�F�ǻ�����"HIG"�i��@�q�j"HIW"�I\n\n"NOR
        ,users());
    }
    return 1;
  }
  b--;
  call_out("domessage",5,b);
}

void delay()
{
  object room;
  room = load_object(__DIR__"room_add");
  room->set("exits", ([ /* sizeof() == 2 */
            "north" : "/open/world1/wu_sha_town/seacoun42",
            "enter" : __DIR__"stone-boat",
           ]));
}
