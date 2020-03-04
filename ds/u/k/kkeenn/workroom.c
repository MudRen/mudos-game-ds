#include <room.h>;
#include <ansi.h>;
inherit ROOM;
string *members = ({ });
void create()
{
set("short",HIC"�s���t�a"NOR);
set("long","
�~��  �~���~��  �~���~�w�w�w���~�w�w�w���~��  �~���~��  �~��
�x�x�~���x�x�x�~���x�x�~�w�w���x�~�w�w���x�����x�x�x�����x�x
�x�����~���x�����~���x���w��  �x���w��  �x  �����x�x  �����x
�x�~�������x�~�������x�~�w��  �x�~�w��  �x�~��  �x�x�~��  �x
�x�x�����x�x�x�����x�x���w�w���x���w�w���x�x�����x�x�x�����x
����  ��������  �������w�w�w�����w�w�w������  ��������  ����
");
set("exits", ([
"wiz":"/open/world3/meetroom",
"future":"/open/world3/tmr/basic/hotel",
"now":"/open/world2/lichi_town_2/map_5_26",
"past":"/open/world1/tmr/area/hotel",
 ]) );
set("valid_startroom", 1);
set("objects",([
]) );
set("light",1);
setup();
call_other("/obj/board/kkeenn_b", "???");
}
void init()
{
        if( userp(this_player()) )
                call_out("delay", 0, this_player());
 add_action("do_move","move");
 add_action("do_trans","trans");
        if( getuid(this_player()) == "kkeenn" )
        {
                add_action("do_control", "control");
        }
}

void delay(object me)
{
        write("

 "HIW"\t(�Q��"HIC"�C�s�L(Kkeenn)"HIW"�����h, �Х�move)\n
"NOR);
}
int do_move(string arg)
{
 object me = this_player();
 if(!arg) return notify_fail("�A�Q�h���̣��S\n");
 if(arg == "love")   //������(�j�N)   
{
 message_vision(HIW+me->query("name")+"�j�n�����X�ت��a�y"HIM"������"HIW"�z�I\n"NOR,me);
  me->move("/open/world1/kkeenn/love/enter"); 
 message_vision(HIY+me->query("name")+"�����ΥX�{�b�@�}�j�������I\n"NOR,me);    
   return 1;
   }
if(arg == "secret")  //�a�U��(����)
 
  {
 message_vision(HIW+me->query("name")+"�j�n�����X�ت��a�y"CYN"�a�U��"HIW"�z�I\n"NOR,me);
  me->move("/open/world3/kkeenn/secret-area/enter"); 
 message_vision(HIY+me->query("name")+"�����ΥX�{�b�@�}�j�������I\n"NOR,me);    
   return 1;
   }
if(arg == "light")  //�W���l�V�m��(����)
   {
 message_vision(HIW+me->query("name")+"�j�n�����X�ت��a�y"HIY"�W���l�V�m��"HIW"�z�I\n"NOR,me);
  me->move("/open/world3/super-light-area/1"); 
 message_vision(HIY+me->query("name")+"�����ΥX�{�b�@�}�j�������I\n"NOR,me);    
   return 1;
   }
else
   {
    write("Sorry, �C�s�L�èS���g�o�ӻ���...\n"); 
    write("͢�ѤH�a����즳�G\n1. ������(love) 2.�a�U��(secret) 3.�W���l�V�m��(light)\n");
   return 1; 
   }
      return 1;
}
int do_trans(string arg)
{
 object me = this_player();
 if(!arg) return notify_fail("�A�Q�h���̣��S\n");
 if(arg == "work")   
   {
 message_vision(HIW+me->query("name")+"�j�n�����X�ت��a�y"HIC"�줽��"HIW"�z�I\n"NOR,me);
  if( member_array(getuid(me), members) != -1 || getuid(me) == "kkeenn" )
    {
     tell_room(this_object(), me->name()+"�����κ������S..\n", ({ me }));
     me->move(__DIR__"workroom1.c");
     tell_room(load_object(__DIR__"workroom1.c"),me->name()+"�q���U�����W�ɦܦ��a�C\n", ({ me }));
           return 1;
    }
else return notify_fail("�A�S���o��C�s�L���P�N�i�J�C\n");
    }
 return 1;
}
int do_control(string arg)
{
        if( !arg ) return notify_fail("�榡: control <�H�W>\n");
        if( member_array(arg, members) != -1 )
        {
                members -= ({ arg });
                write("�R���i�i�X�H�� "+arg+"�C\n");
                return 1;
        }
        else
        {
                members += ({ arg });
                write("�W�[�i�i�X�H�� "+arg+"�C\n");
                return 1;
        }
        return notify_fail("�榡: control <�H�W>\n");
}
string *query_members() { return members; }
