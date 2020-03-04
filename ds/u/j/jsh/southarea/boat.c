#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�p��W");
        set("long", @LONG
�o�O�@���Τ���H���Ӧ����p��A�b��e���A�����÷�l�A�
�V�e�@���A��Ӹj�ۤ@�����b�C
LONG
        );
        set("item_desc", ([ /* sizeof() == 1 */
  "���b" : "�@���¥զ⪺���b, �ˤl�Q���i�R, ���G�O�Ψө��Ϊ�(slap)�C\n",
]));
        set("exits", ([ /* sizeof() == 2 */
          "out" : __DIR__"startroom",
       ]));
        set("light",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{
        add_action("dolphin","slap");
}


int dolphin(string arg)
{
        int t;
        object me,room,*inv;
        me=this_player();
        if(arg != "���b") return 0;
        if(!this_object()->query_temp("moving")) 
        {
                inv = all_inventory(this_object());
                message_vision( HIB "$N�����b����I���F�U�h�A���b�C�C�\\�ʧ��ڡA�w�w������X����.....\n\n" NOR ,me);
                me->start_busy(4);
                call_out("domessage",3,3);
                this_object()->set_temp("moving",1);
                this_object()->delete("exits");
                room = load_object(__DIR__"startroom");
                room->delete("exits/enter");
                room->set("long",@ROOM_LONG
�o�̬O���䪺�����A��¶�ۥ|���A�@��L�ڡA�u�@���n�観�@���p�q�C
ROOM_LONG
);
                tell_room(room,"�A�ݨ�p��w�w�����}�F����....\n");
                return 1;
        }else
        {
                tell_object(me,"�p��w�g���}��ݤ��컷�B�F�C\n");
                return 1;
        }

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==3) tell_room(this_object(),HIC "���b�C�C����A��]�C�C�����n�貾�ʤF...\n\n" NOR);
   else if(b==2) tell_room(this_object(), HIC "�e�ݪ������A���p�Q�M���}�A��ӲӪ�����Q�F�W�� . . .\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIG "���b�������C�F�U�ӡA��ӬO�쩤�F�A�u���@���Z�K���˪L . . .\n\n" NOR );
  else  {
                inv = all_inventory(this_object());
                tell_room(this_object(),HIW "�A�U�F��W�F�y, ���i�F�s����������..\n\n" NOR );
                this_object()->delete_temp("moving");
                room = load_object(__DIR__"room1");
                tell_room(room,"�A�ݨ�@�����b��ۤp���^��F..\n");
                for(i=0;i<sizeof(inv);i++)
                {
                        if(living(inv[i])) inv[i]->move(__DIR__"room1");
                }
                tell_room(room,"���b���Y�N��.....\n");
                this_object()->set("exits", ([
                        "out" : __DIR__"startroom",
                ]));
                room = load_object(__DIR__"nb4");
                tell_room(room,"�A�ݨ�@�����b��ۤp���^��F..\n");
                room->set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"/open/world1/wu_sha_town/seacoun42",
  "enter" : __DIR__"boat",
]));
                room->set("long",@ROOM_LONG2
�o�̬O���䪺�����A��¶�ۥ|���A�@��L�ڡA�u�@���n�観�@���p�q�C�b�A�n�䰱�ۤ@���p��C
ROOM_LONG2
);
                return 1;
                
        }
        b--;
        call_out("domessage",3,b);
}

