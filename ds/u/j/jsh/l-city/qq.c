/* Thief �M�Ѥ� -War */
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
test
LONG
        ); 
        set("item_desc",([ 
        "���":"�@���Z�}�ª�����A���f�W�F�@�D��[pick]�A�̭������D�O����a��H\n",
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room9", 
  //"west" : __DIR__"room6",  
  "southwest" : __DIR__"room7", 
])); 
set("light",1);

        setup();
}
void init()
{
        add_action("do_pick","pick");
}
int do_pick(string arg)
{
          object me,x;
          me=this_player(); 
          if(!me->query_class == "thief" ) return 0;
           if(arg != "���") return 0;
          else { 
                        message_vision(HIC"$N�ϥX�s�骺����E�y�}��z...�⦹��������}�F...$N���i����̥h�C\n"NOR,me);  
                        }else
                        {
                        message_vision(HIC"$N�ϥX�s�骺����E�y�}��z...���O���ѤF........\n"NOR,me);
                        me->start_busy(100);
                        }
            message("world:world1:vision",HIR"\n\t�}ù�h�L�j�ۡG�T���ڡI�I���H�T���ڡI�I\n"
                             +HIB"\n\t�}ù�N�x"+HIR"�j�ۡG�ӤH�ڡI�N"+HIG""+me->name(1)+""+HIR"���ڮ��U�I\n\n"+NOR,users());  
            {
            me->move(__DIR__"jail");
            x=new(__DIR__"jailer");
            x->move(this_player());
            x->kill_me(this_player());
            x=new(__DIR__"jailer");
            x->move(this_player());
            x->kill_me(this_player());      
            }
            return 1;
          }
}


