// �i�H�q�ʥh�ۭq�Ʋz...
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�y����������");
        set("long", @LONG
�o�O�y���������@�a�������A�b�o�̦��\�h���H�b�ɥ��\�I�A���G
�Pı�_�����Z���H�𪺡A�������O�b���̦��ܦn���f�O�A�]�����Ȳ��h
�]���T�F�W���A�b�o�̦��\�h�W�H���ӹL�A�Ҧp�Ѧ������ѷݥH�ΰa��
�P���A���ӳ��O�j�a�ռ���Ԫ��H���A�W���O�Ʋz�ǡA���Ѧۻs�Ʋz��
�A�ȡA�ӧ��ƫh�o�ۤv�ǳƦn�F�A�Y�ǳƦn�K�V�����q�ʩж��a�C
LONG
        );
        set("exits", ([
  "west" : __DIR__"po2",
  "up" : __DIR__"po2e-u",
]));
               set("item_desc",([
  "���" : "�o�O���󩱸̪����A���L�]�����O�ѫȤ�ҥH���w���h�ĤO�C\n",
]));
set("objects",([
__DIR__"npc/old-yang" : 1,
]));
        set("light", 1);
        set("no_fight", 1);
        set("no_magic", 1);
        set("no_goto",1);
        set("no_recall",1);
        set("no_clean_up", 0);
        set("valid_startroom", 1);
        set("map","hotel");
        setup();
}
 
void init()
{
  add_action("do_put","put");
  add_action("do_run","run");
}

int do_run()
{
  write("�ѷ���A���D�G�o��ȭ��A�z�٬O�X�F���A�γo�ӫ��O�a�C\n");
  return 1;
}
int do_put()
{
  write("�ѷ���A���D�G�o��ȭ��A�z�٬O�X�F���A�γo�ӫ��O�a�C\n");
  return 1;
}

int valid_leave(object me, string dir)
{
        int i, j=0;
        object *obs = all_inventory(me);
if( dir!="up")
 {  
   for(i=0; i<sizeof(obs); i++)
        {
        if(obs[i]->query("id") == "wealfish soup"  ||
           obs[i]->query("id") == "freshsha soup" )
         {
           message_vision("$N��U�@��$n�C\n",me,obs[i]);
           destruct(obs[i]);
           j++;
         }
        }
       if(j) message_vision("�ѷ��s����a�W���F�覬�B���b�C\n",me);
       return ::valid_leave(me, dir);
 } 
if( dir=="up" && me->query_temp("cook") <=0 || !me->query_temp("cook") )
    { 
       return notify_fail("�A�٨S�V�����I�p�ШϥζO�I\n");
    }   
 else 
   { 
     for(i=0; i<sizeof(obs); i++)
        {
        if(obs[i]->query("id") == "wealfish soup"  ||
           obs[i]->query("id") == "freshsha soup" )
         {
           message_vision("$N��U�@��$n�C\n",me,obs[i]);
           destruct(obs[i]);
           j++;
         }
        }
       if(j) message_vision("�ѷ��s����a�W���F�覬�B���b�C\n",me);
       return ::valid_leave(me, dir);
    }
}






