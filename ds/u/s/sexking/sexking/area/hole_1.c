#include <ansi.h>
inherit ROOM;
string look_string();
void create()
{
  set ("short", HIR"�ʦL���]"NOR);
  set ("long", @LONG
�o�̴N�O�ǻ������ʦL���]�F�A�u���u�����i�̭̤~����
��D�ԫʦL���]������A���g�i�J�ʦL���]�D�Ԫ��H���d�ʤH�A
����F�̫ᬡ�ۥX�Ӫ��o�u�����ӤH�A�o����i�h���W�n�N�]
���û����o�즿��W���q�|�C
LONG
);
        set("light",1);
        set("no_clean_up", 0);
        set("outdoors","land");
        set("exits", ([ /* sizeof() == 2 */
        "enter" : __DIR__"hole_2",
  ]));
        setup();
}
void init()
{
       object me;
       ::init();
       me=this_player();
       add_action("do_guard", "go");
       add_action("do_guard2","sneak");
}
int do_guard(string arg)
{
 if( (arg!= "enter") || !this_player()->visible(this_object()) ) return 0;

     {
     if(this_player()->query_temp("sexking/hole")>=1)
     { 
     message_vision(HIY"$N��i���w�w�a��ʦL���]�A��M�Q�@�D�벴�����~���n�F��A�����b�Ҧ��H�����e�C\n"NOR,this_player());
     this_player()->delete_temp("the-hole");
     this_player()->move(__DIR__"hole_fly");
     this_player()->start_busy(4);
     call_out("flop1",3,this_player());
     return 1;        
     }
    else
 {
  message_vision(HIY"$N�V�e��F�@�B�A�o�Q���W�䧮���j�j�O�q���F�F�^�ӦR�F�X�f��C\n"NOR,this_player());
  return 1;
}
}
}
int do_guard2(string arg)
{
    if( (arg!= "enter") || !this_player()->visible(this_object()) ) return 0;
     {
     if(this_player()->query_temp("sexking/hole")>=1)
     { 
     message_vision(HIY"$N��i���w�w�a��ʦL���]�A��M�Q�@�D�벴�����~���n�F��A�����b�Ҧ��H�����e�C\n"NOR,this_player());
     this_player()->delete_temp("the-hole");
     this_player()->move(__DIR__"hole_fly");
     this_player()->start_busy(4);
     call_out("flop1",3,this_player());
     return 1;        
     }
 else
  {
  message_vision(HIY"$N�V�e��F�@�B�A�o�Q���W�䧮���j�j�O�q���F�F�^�ӦR�F�X�f��C\n"NOR,this_player());
  return 1;
  }
}
}
void flop1(object me)
{
        if(!me) return;
        if (me->query_temp("the-hole")==1) return 0;
        tell_object(me,HIM"�A����������_�F��ı�A���F�L�ӡC\n");
        me->move(__DIR__"hole_2");
        tell_room(environment(me),me->query("name")+"��M�q�@�D�벴�����~�����F�X��\n"NOR,me);
        return;
}
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 3:
         case 2:        tell_object(me,"�A���@�ة_�S���Pı..��������m��..�C\n");
                        return 1;
         
         case 1:
         case 0:        tell_object(me,"�]�f�̧j�X�N�N����..�O�A�Ԥ���Ÿ�ݰ_�ӡC\n");
                        return 1;
default:       return 1;
        }
}

 


