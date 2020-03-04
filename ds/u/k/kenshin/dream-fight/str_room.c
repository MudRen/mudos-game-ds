#include <path.h>
#include <ansi.h>
#include <command.h>
inherit ROOM;

void create()
{
        set("short", HIY"��Z"NOR);
        set("long", @LONG
"HIC"�p�A�Ҩ��o�O�@����Z�A�̭�����F�賣�S���A�����u���@�Ӹ�\n"
"HIC"�@�����j����A�M�@�i�K�b����W��"NOR"�ϥΤ�U("HIC"vote)�C\n"NORLONG
        );

        set("exits", ([ /* sizeof() == 1 */
 "west" : __DIR__"hall2",
        ]) );
        set("item_desc", ([ 
                "vote": HIC"�w��ϥ�"HIR"Kenshin"HIC"�P�������A�����~�w�q�LISO9002���\n"                        
                        HIC"�~��O�ҡA����S���D�A�Цw�ߨϥΡC\n"
                         HIC"�п�`�H�U�B�J�A�_�h�ڴN�e�A"HIB"�@��T�o"HIC"�A�٦�"HIM"�@���w�J
                         "HIM"��"HIC"�A���K�A�e�A"HIY"�@�����J�|"HIC"�A���A�n�n��"HIR"�L�ͤ�"HIC"�I�I\N"
                         "HIG"�B�J�@: �Х�"HIC"sit on toilet\n"
                         "HIG"�B�J�G: "HIW"�ǳƵ����a�A�����I�I\n"
                         "HIW"�̫�A���±z���ϥΡA�ï��A�ȳ~�r�֡I�I\n"
                                                                HIY"Kenshin ��\n"NOR,                        ]) );
        set("light",1);
        set("no_clean_up", 0);
        set("no_fight",1);
        set("no_kill",1);
        setup();
}

void init()
{
 add_action("do_sit","sit");
}

int do_sit(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file,name;
 me=this_player();
 if(!arg) return 0;
 if(me->query_temp("ride"))
 {
        write(HIC" �A��ť���L�M���W�Z�Ҫ��ƶ�??\n"NOR);
        return 1;
 }
  if(me->is_busy())
 {
        write("�A�W�@�Ӱʧ@�٨S�����C\n");
        return 1;
 }
 if(sscanf(arg, "on %s", arg)==1)
 {
  if(arg=="bed")
  {
   if(name=this_object()->query_temp("on_use"))
   {
        if(name == me->query("name")) write(HIC"�A�w�g���W����W�W�Z�ҤF!!\n"NOR);
        else write(HIY"����A�n���W�����,"+name+"�m���A�@�B�W�F����C\n"NOR);
        return 1;
   }
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if(sscanf(file,"/open/world1/%s",buffer1)!=1
     && sscanf(file,"/open/always/%s",buffer1)!=1 )
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   this_object()->set_temp("on_use",me->name());
   call_out("empty",8);
   me->start_busy(6);
   me->disable_player(HIC" ===�W�Z�Ҥ�===\n"NOR);
   tell_room(this_object(),me->name()+"�@�Ѹ��઺���W�F����W�A�}�l�F�L��������!!\n",({ me }));
   message("system", HIG"�A�߶}�F�Ҧ����дo�A�����u�����Ӱ���A�@�Ѹ��઺���U�h�F!!\n"NOR,me);

   call_out("step1",3,me);
   call_out("step2",8,me);
      return 1;
  } 
 }
 else return 0;
}

void empty()
{
 this_object()->delete_temp("on_use");
}

void step1(object me)
{
 if(!me) return;
 message("system", HIW"\n�A��M�Pı�����ŵM�}�ԤF�_�ӡE�E�E\n\n"NOR,me);
 me->set_temp("block_msg/all", 1);
 message_vision(HIR"�Z�Ҥ��X�{�F$N���@�}�}���G�s�n!!\n"NOR,me);
}

void step2(object me)
{
 if(!me) return;
 this_object()->delete_temp("on_use");
 message_vision(HIW"��M���A�����O�[�j�A�����Okenshin�P�������A��$N�l�i�F�����@��!!\n"NOR,me);
 me->move(__DIR__"r2");
 me->set("startroom",__DIR__"r2");
 me->save();
 me->set_temp("block_msg/all", 0);
 message("system", HIG"�@�}�w�t, "HIB"�A�����Ӫ��ɭԫo�Ө�F�@�Ӥ��P���@�ɨӡE�E�E�C\n\n",me);
 me->set_temp("block_msg/all", 1);
 message_vision("�ѤW��M���ӤH�v, $N�q�W���F�U�ӡE�E�E\n",me);
}


