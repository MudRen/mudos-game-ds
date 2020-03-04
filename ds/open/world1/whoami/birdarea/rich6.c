#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;
void end_war();
void start_war();

string *place=({"village1","village2","village3","village4","village5",
                "village6","village7","village11","village12","village10"
               });

void create()
{
 set("short","�I�v�@��");
 set("long",@LONG
�o�̬O�o�Ӧ�v�̭��̤��_���������A���O�A���[��O����
�`�H�٬O�o�{�F�o�����K���a�I�A�b�A���}�U���G���@�D�t���A 
�����D�o���K�s���t���᭱���۬ƻ򤣥i�i�H�����K�C 
LONG);

 set("exits",([ 
               "down":__DIR__"jail",
               "west":__DIR__"rich5", ]));  
 setup();
 create_door("down","�K��","up",DOOR_LOCKED,"nokey"); 
}        

varargs int unlock_door(string dir, int from_other_side)
{
        object env,npc,me=this_player();
        if( :: unlock_door(dir, from_other_side) )
        {

        env=this_object();
        if(!objectp(npc=find_living("_Fox_Village_Guard_") ) && env->query("_Fox_Village_Guard_")==1 )
           env->delete("_Fox_Village_Guard_");
        if( me->query_skill("pick_lock") < random(120) && env && env->query("_Fox_Village_Guard_")!=1 )
        {
      message_vision("�]��$N�}��ޥ�����H�A�@�Ӥ��d���N��ʤF�ʺ����u�áC\n",me); 
      message("world:world1:vision",
HIY"\n\t����j�q�D�G�Ӧ���"+me->query("name")+"�x���T���A���n�R�F�I�I\n"NOR,users() );
      message_vision("�y�����I�v�����u�öɱ_�ӥX�A�y�ɤ������R���y�����S�Ȱ_�@�ѭ��ɡC\n",me); 
          env->start_war(1);
          env->set("_Fox_Village_Guard_",1);
          
        }        
        }
        return :: unlock_door(dir, from_other_side) ;
} 

void start_war()
{
        int i;
        object g;
//���ަu��(patrol guard)  -> 5 ��
//----------------------------------
//�X�p(total)              -> 5 ��

        for (i=0;i<=4;i++)
        {
        g=new(__DIR__+"npc/patrol_guard");
        g->move(__DIR__+place[random(sizeof(place))] );
        } 

     call_out("end_war",60);
    return;
}

void end_war()
{
        object npc;
        if(objectp(npc=find_living("_Fox_Village_Guard_") ) )
        {
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else 
          this_object()->delete("_Fox_Village_Guard_");
return;
}


