#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short",HIC"��"NOR);
   set("long","
�i�H�Ǧ����}���a�A�q���ǻ������j���C
");
    
  set("exits", ([ /* sizeof() == 1 */
      "out" : __DIR__"snow6",
     ]));
  set("no_clean_up", 0);
  set("light",1);
  set("no_kill",1);
  set("no_fight",1);
  set("no_recall",1);
  setup();

}

void init()
{
        add_action("douse","push");
}


int douse(string arg)
{
        int t;
        object me,room,*inv;
        me=this_player();
        if(arg != "�۽�") return 0;
        if(!this_object()->query_temp("moving")) 
        {
                inv = all_inventory(this_object());
                message_vision(HIW "$N���F�@�U�۽��A������ʰ_�ӤF�I�I\n\n"NOR,me);
                me->start_busy(3);
                call_out("domessage",3,3);
                this_object()->set_temp("moving",1);
                this_object()->delete("exits");
                room = load_object(__DIR__"snow6");
                room->delete("exits/enter");
                room->set("long",@ROOM_LONG
�b�o���a�̩~�M�٦������B���p�ˡA�o�@�I�N�ҩ��F���a�ͺA��
�Ҫ��ǲ��C���w���}�F���a�A�e���F�j���C
ROOM_LONG
);
                tell_room(room,HIG"��w�w���X�o�F�I�I\n"NOR);
                return 1;
        }else
        {
                tell_object(me,HIR"��w�g�����������H�v�I�I\n"NOR);
                return 1;
        }

}
int domessage(int b)
{
  object *inv,room;
  object me = this_player();
  int i;
  if(b==3) tell_room(this_object(),HIW+me->query("name")+HIW"���F�U�b�Ǫ��۽��A�����������F�I�I\n\n" NOR);
  else if(b==2) tell_room(this_object(), HIW "����ȳ~�W�B�ѳ��a�A�@�L�ͺA�ܤơI�I\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIW "��t�׺������w�M�U�ӡA�Q���֭n��F�ت��a�F�C\n\n" NOR );
  else  {

                inv = all_inventory(this_object());
                tell_room(this_object(),HIR "��w�w����p�a���F�I�I\n\n" NOR );
                this_object()->delete_temp("moving");
                room = load_object(__DIR__"o1");
                tell_room(room,HIY"�A�ݨ�������a���I�I\n"NOR);
                for(i=0;i<sizeof(inv);i++)
                {
                        if(living(inv[i])) inv[i]->move(__DIR__"o1");
                }
                tell_room(room,HIC"�@�U���A��~�M�����F�H�I\n"NOR);
                this_object()->set("exits", ([
                        "out" : __DIR__"snow6",
                ]));
                room = load_object(__DIR__"snow6");
                tell_room(room,HIY"�@�����A��S�w�w���a���F�I�I\n"NOR);
                room->set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"snow5",
  "enter" : __DIR__"boat",
]));
                room->set("long",@ROOM_LONG2
�b�o���a�̩~�M�٦������B���p�ˡA�o�@�I�N�ҩ��F���a�ͺA��
�Ҫ��ǲ��C���䦳�@�p��A���G�i�H�Q�Φ���A���}���a�C
ROOM_LONG2
);
                return 1;
                
        }
        b--;
        call_out("domessage",3,b);
}


