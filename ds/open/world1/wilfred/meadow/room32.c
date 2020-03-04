// �}�� & �Ԫ������� room
// �n�h��... @@  �N�N�N     wilfred@DS

#include <ansi.h>

int is_war();
void start_war(object me);

inherit ROOM;
void create()
{
  set ("short", "�]��");
  set ("long", @LONG
�o�̬O�@�����ƤV���誺�Ŧa�A�P���²�檺�]���F�_�ӡA�b
�J�f�B�����p�p���P�l�A�W���g�ۡG�y���դh�z�A�b�Ŧa������
���ߵۤ@�ڬW�l�A���@�ӤH���A���G������S�O���γ~�C
LONG
);
  set("exits", ([
  "south" : __DIR__"room27",
]));
  set("item_desc", ([
  "�W�l" : "�o�O�@�ڬ��G�H�X���ʪ����Y�W�l�A���ߦb�]�椤���A�i�H�ΨӸj���(lock_up)\n",
]));
  set("no_clean_up", 0);
  setup();
}

void init()
{
  add_action("do_lock_up","lock_up");
}

int do_lock_up()
{
   object *inv = all_inventory(this_object()) ;
  int i, index = 0;

  if(this_player()->is_busy()) return notify_fail("�A���b��.\n");
  if( query("is_war") ) 
        return notify_fail("�J�Ӥ@�ݡA�o�ڬW�l�v�g�Q�Y���O������I�F�A�n�n���Y�A�٬O���n�Τ���n�C\n");

  for(i=0;i<sizeof(inv);i++)
    if(base_name(inv[i]) == __DIR__"npc/npc1")
    {
      inv[i]->set("chat_chance",30);
      inv[i]->set("chat_msg", ({
"�����ܤ��w���n�Y�̸��A�N�}�U�F�l��o�|�B���q�C\n",
(: command("cow") :),
}) );
      index++;
    }

  if(index) message_vision(HIC"$N�N���c�c����b�W�l�W�C\n"NOR,this_player());
    else return notify_fail("�o�̨S�����C\n");

   if(index > 4) // ��15������5���Y�|�}cow war by tmr 2007/01/24
  {
    for(i=0;i<sizeof(inv);i++)
            if(base_name(inv[i]) == __DIR__"npc/npc1")
            destruct(inv[i]);
    set("is_war",1);
    message_vision(HIW"�y�N����I�I�I�I�I�z$N���Ǫ��@��������M�o�g�몺���F�_�ӡA�@�Y���b�W�l�W�I�I\n"+
                   "\t���j���W�l�S�p�ܮz���_�l��@�I�N�_�I�I��l�����@�o�ۥѡA�ɯɶX���k�X�F�]��I\n"NOR,this_player());
   call_out("start_war",3,this_player());
  }

  this_player()->add_busy(2);
  return 1;
}

int is_war()
{
        object cow;
        while( objectp(cow=find_living("cow_war")) )
        {
                if( !environment(cow) )
                {
                        destruct(cow);
                        cow = 0;
                }
                break;
        }
        return objectp(cow);
}

void start_war(object me)
{
  /*
     -------------------------
     ���F����   x 10
     ���謺��   x 10
     ���n����   x 10
     ���_����   x 10
     �j������   x 10
     ���Ԭ���   x 10
     �ƨg����   x 10  // ���S��
     -------------------------
               +) 70 ��
  */

    int i,j;
   object master;
  if(!me) return;

  for(i=0;i<10;i++)
  {
    for(j=3;j<10;j++)
      new(__DIR__"npc/npc"+j)->move(__DIR__"room"+(4+random(25)));
  }
  message("world:world1:vision",
  HIG"\n\t�i�z�_����j"HIY+me->name(1)+"���V���j�嬺���ĥX�]��I�ް_��l�����T���I\n\n"+
  HIY"\t\t�������Q�j�q�o�g���������ڡA�V�ä����I\n\n"NOR,users() );

  if( objectp(master = find_living("cow_master")) )
    master->command("tchat* why");

  call_out("end_war", 300);
  return;
}

void end_war()
{
  if( is_war() )  {
    call_out("end_war", 10);
    return;
  }
  delete("is_war");
  message("world:world1:vision",
    YEL"\n\t�i�z�_�����j"HIM"���o�U���n�⤧�U�A�������V�ó����v��o����C\n\n"NOR,users() );
  return;
}
