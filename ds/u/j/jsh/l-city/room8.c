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
        "���":"�@���Z�}�ª�����A�̭������D�O����a��[enter]�H\n",
        ]) );
        set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"room9", 
  //"west" : __DIR__"room6",  
  "southwest" : __DIR__"room7",])); 
set("light",1);

        setup();
}
void init()
{
        add_action("do_enter","enter");
}
int do_enter(string arg)
{
          object me,x;
          me=this_player();
          if(arg != "���") return 0;
          else { 
                        message_vision("$N������̨��F�i�h�C\n",me); 
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

