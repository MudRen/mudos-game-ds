#include <ansi.h>
inherit ROOM;

void create()
{
 set("short","�s��");
        set("long",@LONG
�A����s���F�I�o�̤Q����D�A�u���@�i�K�۲ũG���j�ۡA�n���ʦL�ۤ���C
LONG
        );
        
        set("outdoors","land");
 set("item_desc",([
     "�j��":"�j�ۨSԣ�n�ݪ��A�ݬݲũG�a�I\n",
     "�ũG":"�A�ݵ۳o�ӲũG�ɡA��Mť��@�ӲӷL���n���b�A���仡�G�u���U��(tear)���U��(tear)...�v\n"
     ]));
        setup();

 }
int n=1;
void init()
{
        add_action("do_tear", "tear");
}
int do_tear(string arg)
{
        object me,obj;
        me=this_player();

        if (arg != "�ũG" && arg !="��" )
                return 0;
      if(n !=0) {
      message_vision(HIY"$N�ΤO���U�ũG�A�u���@�D�����ѲũG���E�g�ӥX�T�T\n"NOR ,me);
       obj=new(__DIR__"npc/player-ghost");
       obj->move(environment(me ) );       
     message_vision(HIR"$P�j���G�u�������T�T�ש�ۥѤF�T�T�ڭn�j�x�ѤU�T�T�v\n"NOR,obj);
     n=0;
      }else
     {
      message_vision(HIW"$N���n���U�ũG�ɡA��M�V��h�F�X�B�A���G�Q����F��u�}���ˤl�C\n"NOR ,me);

        }
   return 1;
        }
