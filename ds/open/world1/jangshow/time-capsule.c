#include <ansi.h> 
inherit ITEM ; 
void create()
{
        set_name(HIC"�ɪŽ��n"NOR,({"time capsule","capsule"})); 
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",1);
        set("long","�@���z�������F��A�̭��{�{���I�I���~�A�����D�O������Ϊ�\n"); 
             }
        setup();
}

void init()
{
     add_action("do_eat","eat");
     return;
}
int do_eat(string arg)
{
 object me,it,z;
 me=this_player(); 
    if(!objectp(z=present("time capsule",me) ) )
                          return notify_fail("�A�S���F��i�H�Y�� ? \n");
   if(!arg || arg=="") return notify_fail("�A�Q�n�Y����H\n");
   {
    if(arg=="capsule")
    { 
     message_vision(""+me->name()+"�@�f��N���n�]�F�U�h�A���G��������C\n",me); 
     me->add_temp("capsule",1);
     call_out("do_move_room",5,me); 
    }
   }
   return 1;
}

int do_move_room()
{
    object me=this_player(),room;   
    if(me->query_temp("capsule")==1)  
    {    message_vision(HIW""+me->name()+"�ư��@�D�������Ķ��d�I�����b�a���u���W�F�I\n"NOR,me); 
room = load_object("/open/world1/jangshow/mage_room/room1"); 
    me->move(room); 
    me->delete_temp("capsule");  
    destruct(this_object()); 
    return 1;
    } 
    else {return 0;}
}


