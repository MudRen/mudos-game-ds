#include <ansi.h>
#define SOPHER "/u/s/sopher/"
inherit ROOM;
void create()
{
        set ("short", HIC"HANS���ήɪŵ��_�h��"NOR);
        set ("long", @LONG
�o�̴N�O�ɪŵ��_�F�I�A�h�ۨԨ褣�w���߽�W�F�Ĥ@�B
�A�µۧ��ܾ��v���ؼн�X�@�j�B�I(step)
LONG);  
        
        set("exits", ([
        "south" : __DIR__"time",
        "step" : __DIR__"road1",
        ]) );
        set("no_clean_up", 0);
        set("light",1);
        setup();
        
        }
void init()
{ 
       add_action("do_step","step");
}
int do_step()
{
  object me;
  me=this_player();
  tell_object(me, HIW "�A�����F�k�}�A�p���l�l����X�F�Ĥ@�B.\n\n"NOR);
  tell_object(me, HIR "��M�I�I�A�Q�o��h���l��F�I\n\n" NOR );
  tell_object(me, HIC "�A�|�P�����Һ����_�F�ܤơI\n\n\n" NOR );
  tell_object(me, HIB "�A�����@���A���F�L�h\n" NOR );
  tell_object(me, HIW "�A�C�}�F�����A�A�o�{�A��F�j�N�H...\n" NOR );
 return 0;
}          
