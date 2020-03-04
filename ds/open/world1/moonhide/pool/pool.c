#include <ansi.h>
inherit ROOM;

int query_pool_npc();

void create()
{
  set("short", HIB"���H�P�}"NOR);
  set("long", @LONG 
�o�O�@�]�շt�����}�A���}�W��Q�ۤ@�����¥ժ����ťۡA�w�ۤp�p
���]�A�b��ǡA�ݥߵۼƱ��������A�C�C���۽��L�A�ӫG���}���C�Ӥj�p
�����C�������@������A������G������F�誺�ˤl�C
LONG); 
  set("item_desc",([ 
      "����":"�`�ŵL���������A�b������t�A����ۡy���H�P�}�z�|�� [�j�r]�A�B���䴡�ۤ@�� [��P]�C\n",
      "�j�r":"�y�� �H �P �}�z�C \n",
      "��P":"�@����s���P�l�A�W���g�� [�Фť��Y�����G�Ithrow xxx in pool]�C\n",
     ]) );
  set("exits", ([ /* sizeof() ==  */ 
      "east" : __DIR__"room19",
     ]));
  set("no_light",1); 
  set("no_recall",1);
  setup();
}

void init()
{
  add_action("do_throw","throw");
}

int do_throw(string arg)
{
int i;
object me,x,z;          
  me = this_player();
  if( query_temp("throw")==1) return notify_fail("��観�H��L�F�C\n");
  if(!arg || arg!="fruit in pool")
        return notify_fail("�A�n���Y����?\n");
  if(!objectp(z=present("fire fruit",me) ) )
    return notify_fail("�A�S���F��i�H��� ? \n");
  if( query_pool_npc() >0 )
        return notify_fail("�A�Q�צ�A�L�k��������h��F��C\n");

  message_vision(HIW"$N��X�@��"HIR"�����G�C\n"NOR,me); 
  this_object()->add_temp("throw", 1); 
  call_out("stop_thu", 10, this_object());
  destruct(z);

  me->start_busy(2);
  i = random(8);
  while( i == query_temp("last_mob") )  
    i = random(8);    // ���|�s�X�P���e���Ъ�npc
  
  switch (i)
  { 
    case 0:
         write("�A���Mť��@�n�G�A�b�F����I�I�I���O�������������G�F�I�S�ݨ�ڥߪ��P�l���I�I\n");
         tell_object(this_object(), "�l�������G�n�p�l�I�I�I�ݧګ��аV�A�I\n");
         x = new(__DIR__"npc/dan");
         x->move(this_object());
         x->kill_ob(this_player()); 
         me->start_busy(8);
         set_temp("last_mob",0);
         break;
    case 1:
         tell_object(this_object(), "���������M�E�_�@�}�}���������I�C\n"); 
         message("world:world1:vision", 
           HIW"\n\t�d�~���~�E�y�ȪZ���t�z���X�����A���M�ѭ����M�A�[�����h�C\n"NOR,users());
         message_vision("�ȪZ���t�S�X�@�����L�L���j�����A���G�Q��A�Q�F��Y�E�E\n",me);
         x = new(__DIR__"npc/turtle"); 
         x->move(this_object());  
         set_temp("last_mob",1);
         break;
    case 2:
         tell_object(this_object(), "���M�@�D�¼v�A�e�I�ӹL�A�Ѫŧϩ��t�F�@�b�E�E\n");
         message("world:world1:vision", 
           HIR"\n\t"+me->name(1)+"�ĳ{�ʦ~����A����i�}�@���E�P�r���I�I\n\n"NOR,users());     
         x=new(__DIR__"npc/chisel");
         x->move(this_object());    
         x->kill_ob(this_player()) ;
         set_temp("last_mob",2);
         break;
    case 3:
         tell_object(this_object(), "������G�٦b�Ť��ɡA�y�x�I�z�����F�A�uť���@�}���n�E�E�E\n");
         message("world:world1:vision",
           HIG"\n\t����ӡG��������....�ڦ��ܦh�_���A���O�A�̤H���R�o�_��...��������..\n\n"NOR,users());      
         x=new(__DIR__"npc/elf");
         x->move(this_object());   
         this_player()->start_busy(2);
         set_temp("last_mob",3);
         break;  
  case 4:
         tell_object(this_object(), "�����G���������b�Ť��A�y�N�z���@�n�A���i�����̡A�èS���ͤ��򲧪�\n\n");
         set_temp("last_mob",4);
         break; 
    case 5:
         tell_object(this_object(), "�����E�X���}�G������A�@�i�i�������|�g�X���ӥh\n"       
               "��M�I�����B�{�@����������v�I\n");  
         message("world:world1:vision", 
           HIY"\n\t�i���H�P�}�j"+HIR"�ݼɦ��A�A�X����A���}�ͪ��A�L�@�ƧK�C\n"+NOR,users());                                                
         x=new(__DIR__"npc/snake");
         x->move(this_object()); 
         x->kill_ob(this_player());
         set_temp("last_mob",5);
         break; 
    case 6:
        tell_object(this_object(), "�����E�X���}�G������,�@�i�i�������|�g�X���ӥh\n"
               "��M!�����B�{�@�����������v�I\n"); 
         message("world:world1:vision", 
           HIC"\n�i�ʧ@�j"+HIY"�Q�ﳽ(Chi lin-fish)"+HIC"��ۤj�a�j�n�۹D�J�֢�������I�j�a�n��� :D�C\n"+NOR,users()); 
         x=new(__DIR__"npc/chi-lin-fish");
         x->move(this_object()); 
         set_temp("last_mob",6);
         break; 
    case 7:
         message("world:world1:vision",HIG"\t�n�c�@�a"HIR"�c�� "HIW"�n�c�L��"HIR"�A���X����I�I\n"
HIW"\n\t�n�c�K�߻P�ݤ�"HIR"���D�G���򥲩w�A�ް_�@�}������a�I�I\n\n"NOR,users()); 
         x=new(__DIR__"npc/master_nan");
         x->move(this_object()); 
         set_temp("last_mob",7);
  }  

  return 1;
}

void stop_thu()
{
        // �R������G�O��
  delete_temp("throw"); 
  return;
}

int query_pool_npc()
{
  object pool_npc;

  while( objectp(pool_npc = find_living("pool_npc")) )
  {
    if( environment(pool_npc) ) break;

    destruct(pool_npc);
  }
  
  if( objectp(pool_npc) ) return 1;
  return 0;
}

