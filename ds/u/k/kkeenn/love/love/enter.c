#include <room.h>;
#include <ansi.h>;
int welcome(object me);
inherit ROOM;
void create()
{
set("short",HIM"�������J�f"NOR);
        set("long", @LONG
�o�̴N�O�ǻ����ߤ@�y���k���k�z�a��A�ǻ����Z�L�Q�j�T�a���@��
�������A�ǻ��O�F�ʦ~���A�Z�L�Q�j���⤧�ߤ@�k�ʡ����k�P�L�����k�{
�̩ҳСA�u�O�ݥ��u���p�����Y�K�A�K�i�o���A�o��ä��ӳ��w�����ͤH
�ӳX�C
LONG
        );
  set("exits", ([
"north" : "/open/world1/wilfred/sand/room26",
"south" : "/open/world1/wilfred/sand/room27",
]));
        // set("light", 1);  ��outdoor�S��light?!.���X�޿�
        set("outdoors","land");
setup();
}
void init()
{
        ::init();
     call_out("welcome",0,this_player());
}
int welcome(object me)
{
   object ob = this_player();
	if( ob->is_corpse() ) return 1;
      if(ob->query_temp("kill_love") > 0)
        {
      message_vision(HIM"�m�������n "NOR"�u�ëܨ��c�����D�G �ֶi�Ө����a�I\n"NOR,ob);
      ob->move(__DIR__"room1.c");
                        return 1;
        }

      if(ob->query("class1") == "������")
        {
      message_vision(HIM"�m�������n "NOR"�u�ëܰ��������D�G �v�j, �A�^�ӤF��^.^ �C\n"NOR,ob);
      ob->move(__DIR__"room1.c");
      tell_room(environment(ob),ob->name()+"��ۻ������B�k, ���������몺���i�ӡC\n",({ ob }));
                        return 1;
        }
   else
        {
message_vision(HIM"�m�������n "NOR"�u�è�$N���O���������A�}�l���h�ê��������q��$N�C\n"NOR,ob);
message_vision(HIG"�u�û��G �o��B�͡A�z�����e�ӬO�n..�C\n"NOR,ob);
message_vision(HIW"[ answer killer / guest     ���� / ���[]\n"NOR,ob);
       add_action("do_answer", "answer");
                 return 1;
        }
      } 
int do_answer(string arg)
{
        object me,b;
        me=this_player();
	if( me->is_corpse() ) return 1;
 
 if(!arg) return notify_fail("�A�쩳�ӳo�̭n�F�ª� ?\n");
 if(arg=="killer")
 {
	if( me->query("level") < 25 ) return 1;
message("world:world1:vision",HIM"\n�m�����ֳ��n�G\n\t���D���O�A�����X���A�G�D"HIW+me->name()+HIM"�r��A�кɧ֦^�Ӵ��U\n"NOR,users() );
            me->set_temp("kill_love",1);  
      me->move(__DIR__"room1.c");
if( sizeof(filter_array( children(__DIR__"npc/killer"), (: clonep :) )) < 2 )
{
     b = new(__DIR__"npc/killer")->move(__DIR__"room8");
     b = new(__DIR__"npc/killer")->move(__DIR__"room9");
}
 message_vision(HIR+me->query("name")+"���y���𪺽Ķi�ӡI\n"NOR,me); 
              return 1;
 }
 
 if(arg=="guest")
 {             
    if( me->query("gender") == "�k��")   return notify_fail("�u�ëܫȮ𪺻�: ��p, �������w��k�l�C\n");
 message_vision(HIM"������ "NOR"�u�û��D�G�z�ѽжi, ������A��C�C\n"NOR,me);  
      me->move(__DIR__"room1.c");
 message_vision(HIC+me->query("name")+HIC"�a�ۤ@�y���n�_�ߨ��i�ӡI\n"NOR,me); 
        return 1;
 }
 return notify_fail("�A�쩳�ӳo�̭n�F�ª�(killer),(guest) ?\n");
}
